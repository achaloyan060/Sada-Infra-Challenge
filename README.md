# Summary 
This project is a solution to SADA's infra challenge #2 (read file and create files and sort). It reads a file called "loomings.txt", creates files with each non-blank line, sorts them in order of increasing size, prints the files with identical content, and makes a new file "loomings-clean.txt" that does not contain the duplicate line. 

# How to use it
Execute run.sh and visually inspect the output. The output files produced can be accessed in the output directory.

# What this project contains
At the root directory, this project contains a README.md file, a CMakeLists.txt file that is used to build a Makefile with cmake, and a run.sh script that can be run from a shell to run the code and produce results.

## Source
This directory contains all the source files necessary to run the project: challenge2.cpp and md5.cpp. The challenge2.cpp file contains the main program that produces the necessary outputs and the md5.cpp file is a helper file that calculates hash digests of files.

## Data
This directory contains the "loomings.txt" file that the program uses to read. 

## Documentation
This directory contains a description of the project, what it does, how it works, how to build and run the project, how it is designed and what bugs and limitations exist for the future enhancements.

## Build
This is an empty directory that will be filled when cmake is run to build the Makefile with the run.sh script. The executable challenge2 file will also be here.

## Output
This is an empty directory that will be filled with the project output files when the run.sh script is run.
