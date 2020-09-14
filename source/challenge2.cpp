
#include <iostream>
#include <fstream>
#include <string>
#include <md5.h>
#include <vector>
#include <algorithm> 

using namespace std;

//finds two files with identical content and returns their indices as a pair of integers
pair<int, int> findIdenticalHashDigests(vector< pair<string, string> > vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = i+1; j < vect.size(); j++)
        {
            if (vect[i].first.compare(vect[j].first) == 0)
                return make_pair(i, j);
        }
    }
}

//creates a new file identical to original file (loomings.txt) but omits the duplicate line
void makeCleanFile(string omit_str)
{
    ifstream file("data/loomings.txt");
    string str;
    ofstream cleanFile("output/loomings-clean.txt");
    bool found = false;
    int skip_line = 1;
    
    while (getline(file, str))
    {
        if (skip_line == 0)
            cleanFile << endl;
        else 
            skip_line--;

        if (str.compare(omit_str) == 0)
        {
            if (!found)
            {
                found = true;
                cleanFile << str;
            }
            else
                skip_line = 2;
        }
        else
            cleanFile << str;
    }

    cleanFile.close();
    
}

void readFile()
{
    ifstream file("data/loomings.txt");
    string str;
    int index = 1;
    vector< pair<int, string> > files_with_sizes;
    vector< pair<string, string> > files_with_hashes;

    while (getline(file, str)) 
    {
        if (!str.empty())
        {
            //create file containing each none-blank line
            string name = "file-" + to_string(index);
            ofstream outfile("output/"+name);
            outfile << str;
            outfile.close();
            index++;

            //create file with hash digest
            MD5 hasher;
            unsigned char* content = new unsigned char[str.length()];
            copy(str.begin(), str.end(), content);
            content[str.length()] = 0;
            hasher.add(content, str.length());
            string digest = hasher.getHash();
            ofstream outfileHash("output/"+name+".hash");
            outfileHash << digest;
            outfileHash.close();

            //store data about file size and hash digest
            files_with_sizes.push_back(make_pair(str.length(), name));
            files_with_hashes.push_back(make_pair(digest, name));

        }
    }
    
    cout << "Total number of lines: " << index-1 << endl;

    //print sorted (by size) file names
    cout << "Files sorted by size:" << endl;
    sort(files_with_sizes.begin(), files_with_sizes.end());
    for (int i = 0; i < files_with_sizes.size(); i++)
    {
        cout << files_with_sizes[i].second  << ": " 
             << files_with_sizes[i].first << " bytes" << endl;
    }

    //print file with identical content
    pair<int, int> identical_files = findIdenticalHashDigests(files_with_hashes);
    ifstream ifs("output/"+files_with_hashes[identical_files.first].second);
    string file_content((istreambuf_iterator<char>(ifs)),
                   (istreambuf_iterator<char>()));
    cout << files_with_hashes[identical_files.first].second << " and "
        << files_with_hashes[identical_files.second].second << " have identical content."
        << endl << "Original duplicated text: \n" << file_content << endl;

    //make the clean file
    makeCleanFile(file_content);

}

int main(int argc, char** argv) 
{
    readFile();
    return 0;
}
