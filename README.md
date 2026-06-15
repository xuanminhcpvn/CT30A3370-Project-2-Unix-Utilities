# CT30A3370-Project-2-Unix-Utilities
## Introduction
This project implements four programs **my-cat**, **my-grep** and **my-zip** **my-unzip** pairs. **My-car program**can read from file(s) and print file contents to the terminal. **My-grep program** can search for a given string in files or standard input and will output matching content, line by line.**My-zip** compresses input files using run-length encoding(RLE). RLE replace consecutive repeated characters with a pair (count, character) and writes the result in binary format. When multiple files are given as input, they are treated as a single continuous input stream in **my-zip** and thus can lose some info when unzipping. **my-unzip** just reverse **my-zip** operation by reading the compressed binary format, printing back characters repeatedly (count) times to the terminal like 5a4b => aaaaa bbbb.


## Point proposal
-Everything submitted compiles and works at least on some level. (Required, 1 points)

-The documentation is appropriate, correct and the repository is available (Required, 0 point)

-The documentation is detailed, and the provided source code is reasonably well commented. (1 point)

-my-cat works as instructed (1 point)

-my-grep works as instructed (1 point)

-my-zip and my-unzip "should" works as instructed (1 point)

**TOTAL:= 5**

### Requirements

* Ubuntu 22.04 or similar Linux environment.
# Installations
(For valgrind + gcc compiler): sudo apt-get update && sudo apt-get install build-essential valgrind 
```bash
git clone https://github.com/xuanminhcpvn/CT30A3370-Project-2-Unix-Utilities.git
cd CT30A3370-Project-2-Unix-Utilities
make all
* Different ways to run :
./my-cat file.txt //to read a file
./my-cat file1.txt file2.txt ... //to read multiple files

./my-grep search_term file.txt //search for a term in file.txt and output to terminal
./my-grep search_term file1.txt file2.txt ... //search for a term in multiple files 
./my-grep search_term //check if the user's input matches the search term

For my-zip + my-unzip, they can be tested by running the zip-unzip-test.sh script found in the repository

chmod +x zip-unzip-test.sh //If I didn't already make it executable
./zip-unzip-test.sh

Or just run them by yourself:
printf "lorem ipsum..." > input_file.txt
./my-zip input_file.txt > output_binary.z
hexdump -C output_binary.z //to somwewhat view binary output
./my-unzip output_binary.z unzipped_output.txt
```
### Useful Make command

```bash)
make clean         # Remove miscellaneous, executable and debug files (in this project they are mostly all .txt files)
make valgrind      # Perform memory leaks check only for my-grep for now

```
## Project Structure
```
.
  ├── my-cat.c
  ├── my-grep.c
  ├── my-zip.c
  ├── my-unzip.c
  ├── zip-unzip-test.sh
  ├── Makefile
  ├── README.md
```
