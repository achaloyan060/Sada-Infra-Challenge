# What this project does 
This project reads an input file called "loomings.txt" and creates files that contain each non-blank line of the input file. It also generates a hash digest for each of those files and stores those hashes in separate files. It then sorts the created files by size from smallest to largest and prints the results. Then the program finds the two files that have identical content and prints the duplicated text. Finally, the program makes a new file called "loomings-clean.txt" that containts the contents of "loomings.txt" without the duplicate line.

# How this project works
This project is executed by the run.sh script in the root directory and it is built with cmake. All cmake generated files are stored in the build directory. The project uses an input file from the data directory and stores the resulting output files in the output directory. 

# How to build and run the project
To build and run this project, execute the run.sh script in the root directory. 

# Design
This project uses an md5 algorithm to compose hash digests for the files. The files used in this project were downloaded from https://create.stephan-brumme.com/hash-library/

# Bugs and limitations
Currently, the program is harcoded to only read an input file called "loomings.txt". In the future, the program can be adjusted to read any file contained in the data directory, specified in the command line arguments by the user. 
