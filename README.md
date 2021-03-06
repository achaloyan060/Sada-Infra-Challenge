# Summary 
This project is a solution to SADA's infra challenge #2 (read file and create files and sort).  
The project performs the following:
- reads a file called "loomings.txt" and creates files with each non-blank line
- sorts the files in order of increasing size 
- prints the files with identical content
- makes a new file "loomings-clean.txt" that does not contain the duplicate line

# How to use it
Execute run.sh and visually inspect the output. The produced files can be accessed in the output directory.

# What this project contains
At the root directory, this project contains a README.md file, a CMakeLists.txt file that is used to build a Makefile with CMake, and a run.sh script intented to be executed from a shell.

## Source
This directory contains all the source files necessary to run the project: challenge2.cpp and md5.cpp. The challenge2.cpp file contains the main program that produces the necessary outputs, and the md5.cpp file is a helper file that calculates hash digests of files.

## Include
This directory contains the header file md5.h.

## Data
This directory contains the "loomings.txt" file that the program uses as an input. 

## Documentation
This directory contains a description of the project, what it does, how it works, how to build and run the project, how it is designed and what bugs and limitations exist for the future enhancements.

## Build
This is an empty directory that will be filled when cmake is run to build the Makefile with the run.sh script. The executable challenge2 file will also be in this directory.

## Output
This is an empty directory that will be filled with the project output files when the run.sh script is executed.
