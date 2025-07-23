# Word/Digit Frequency Analyzer in C
A C-based text analysis program that processes large alphanumeric text files (200,000+ words) to compute detailed statistics about word lengths, starting characters, and digit frequency. This project showcases fundamental systems programming skills including file I/O, argument parsing, array-based counting, and conditional filtering. 

## Features
- Counts total word frequency from an input `.txt` file
- Reports how many words exist for each length (1 to 20+ characters)
- Detects and flags overflow words exceeding 20 characters
- Computes how many words begin with each letter (A-Z)
- Tallies the count of each digit (0-9) when non-letter filtering is enabled
- Supports a `-p` flag to skip non-letters and treat digits separately
- Handles large files efficiently with loops and conditionals

## Sample Output
```
$ ./first MobyDick.txt
Program Name is: ./first

Flag is off. Non-letters will count as part of a word

Number of words that have 1 character(s) in them: 6409
Number of words that have 2 character(s) in them: 32778
...
Number of words that have 20 character(s) in them: 23
------------------------------------------------------------------------------------ 
Number of words that have overflow: 35
------------------------------------------------------------------------------------ 
Number of words that start with A: 21787
Number of words that start with B: 10952 
...
Number of words that start with T: 35106
...
------------------------------------------------------------------------------------ 
Total number of words that start with an alphabet in the file: 209970
------------------------------------------------------------------------------------ 
Number of digits for 0: 0
Number of digits for 1: 0
Number of digits for 2: 0 
Number of digits for 3: 15 
...
------------------------------------------------------------------------------------ 
Total Word Count for the text file: 214112```

```
## How to Compile and Run
```
# Compile
gcc -o first FirstProject.c

# Run without filtering (punctuation/digits treated as part of a word)
./first <filename.txt>

OR

# Run WITH -p flag to filter out punctuation and count digits separately
./first -p <filename.txt>

```


## Project Structure
```
FirstProject.c # main source code
MobyDick.txt   # sample larger input file for testing
input.txt      # alternate smaller input file for testing
README.md      # about the project
```

## Design Notes
- Uses fixed-size arrays (`int wordLen[20]`, `int alphabetCount[26]`, `int numDigit[10]`) to avoid dynamic memory allocation
- Handles edge cases such as number of arguments, overflow word lengths, and when the file hits EOF + doesn't store the last word
- Case-insensitive: treats both uppercase and lowercase letters as same letters
- Filters non-letter ASCII ranges using the `-p` flag that the user sets


## Tools Used
- Language: C
- Compiler: GCC
- System: macOS


## About this Project

* This short personal project was built to exercise my C programming skills:
  - Focuses on correctness and edge case handling
  - Works with low-level I/O
  - Able to write efficient, readable, and testable code

