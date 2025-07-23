# Word/Digit Frequency Analyzer in C
A C-based text analysis program that processes large alphanumeric text files (200,000+ words) to compute detailed statistics about word lengths, starting characters, and digit frequency. This project showcases fundamental systems programming skills including file I/O, argument parsing, array-based counting, and conditional filtering. 

## Project Structure
```
FirstProject.c # main source code
MobyDick.txt   # sample larger input file for testing
input.txt      # alternate smaller input file for testing
README.md      # about the project
```

<br>

## Features
- Counts total word frequency from an input `.txt` file
- Reports how many words exist for each length (1 to 20+ characters)
- Detects and flags overflow words exceeding 20 characters
- Computes how many words begin with each letter (A-Z)
- Tallies the count of each digit (0-9) when non-letter filtering is enabled
- Supports a `-p` flag to skip non-letters and treat digits separately
- Handles large files efficiently with loops and conditionals

<br>

## Sample Outputs

WITHOUT the `-p` flag:

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

<br>

WITH the `-p` flag:
```
$ ./first -p MobyDick.txt
Program Name is: ./first 

Flag turned on. Non-letters will be skipped. 

Number of words that have 1 character(s) in them: 6681 
Number of words that have 2 character(s) in them: 35121 
...
Number of words that have 20 character(s) in them: 6 
------------------------------------------------------------------------------------ 
Number of words that have overflow: 5 
------------------------------------------------------------------------------------ 
Number of words that start with A: 21824 
Number of words that start with B: 11048 
...
Number of words that start with Z: 19 
Total number of words that start with an alphabet in the file: 211844 
------------------------------------------------------------------------------------ 
Number of digits for 0: 170 
Number of digits for 1: 162 
Number of digits for 2: 78 
...
Number of digits for 9: 49 
------------------------------------------------------------------------------------ 
Total Word Count for the text file: 213850 
```

<br>

## How to Compile and Run

1. Compile <br>
`gcc -o first FirstProject.c`

2. Run without filtering (punctuation/digits treated as part of a word) <br>
`./first <filename.txt>`

OR

2. Run WITH -p flag to filter out punctuation and count digits separately <br>
`./first -p <filename.txt>`

<br>

## How It Works
This program analyzes an input text file in the following stages:
1. **Argument Handling**
   - Accepts input by command-line: `./first <filename.txt>` or `./first -p <filename.txt>`
   - `-p` flag enables strict alphanumeric filtering (skips punctuation/digits when counting words)

2. **File Processing**
   - Reads the file character-by-character
   - Accumulates word lengths until a word-ending character is found (`space`, `newline`, or `tab`)
   - Filters punctuation and handles digits separately when `-p` flag is active

3. **Data Aggregation**
   - Tracks how many words fall into each length category (1–20+ characters)
   - Counts words starting with each letter of the alphabet (A–Z)
   - Separately counts digit occurrences (0–9) when `-p` flag is active

4. **Reporting**
   - Outputs all statistics in a readable format to stdout
   - Outputs number of words that exceed 20 characters (overflow)
   - Output includes total word count and alphabet-start statistics

<br>

## Design Notes
- Uses fixed-size arrays (`int wordLen[20]`, `int alphabetCount[26]`, `int numDigit[10]`) to avoid dynamic memory allocation
- Handles edge cases such as number of arguments, overflow word lengths, and when the file hits EOF + doesn't store the last word
- Case-insensitive: treats both uppercase and lowercase letters as same letters
- Filters non-letter ASCII ranges using the `-p` flag that the user sets

<br>

## Tools Used
- Language: C
- Compiler: GCC
- System: macOS

<br>

## About this Project

* This short personal project was built to exercise my C programming skills:
  - Focuses on correctness and edge case handling
  - Works with low-level I/O
  - Able to write efficient, readable, and testable code
 
<br>
 
## Ideas for Future Improvement
- Add support for lowercase/uppercase letter separation
- Maybe add histograms or some visual aspect??
- Make it work for other file formats, such as `.csv` or `.json` files

