#include <stdio.h>
#include <string.h> // for strcmp function 

// #define MAXCHAR 5 // max number of characters for buffer
#define MAXWORDLEN 20 // max number of characters for a word in wordLen array
#define ALPHABETMAX 26 // max number of characters for alphabet
#define DIGITMAX 10 // max number of single digits

// 1. reads file input

    // • Take file as a command line argument argc argv
    // Example: ProgramName filename
    int main(int argc, char** argv) {
        
        printf("Program Name is: %s \n", argv[0]);

        int flag = 0; // flag is off

        // Checks if the number of arguments passed into the command line is correct
        if((argc == 3) && (strcmp(argv[1], "-p") == 0)) {
            flag = 1; // flag is on
            printf("\nFlag turned on. Non-letters will be skipped. \n\n");

        } else if(argc == 2) {
            printf("\nFlag is off. Non-letters will count as part of a word\n\n");
            
        } else {
            printf("\nWrong number/Incorrect use of arguments for %s program \n", argv[0]);
            printf("Use 2 or 3 arguments when running. Try again.\n\n");
            return -1;
        }

        // • Get filename from argv[1] or argv[2]
        // • Open file with permission to read only
        FILE* file;

        // "-p" flag is off
        if(flag == 0) {
            file = fopen(argv[1], "r"); \
        
        // "-p" flag is on
        } else {
            file = fopen(argv[2], "r");
        }
        
        // check if file is available
        if(file == NULL) {
            printf("Could not open input file. \n");
            printf("Run program as ProgramName -p FileName or ProgramName FileName \n");
            return -1;
        }

        // 2. processing the file
        // • Create a buffer, data type needs to be char[] as the buffer will 
        //   store a fixed number of characters
        int c;
        int wordLen[MAXWORDLEN];
        int alphabetCount[ALPHABETMAX];
        int numDigit[DIGITMAX];
        int wordCount;

        for(int i = 0; i <= MAXWORDLEN; i++) {
            wordLen[i] = 0; // initializing wordLen array to all zeros
        }

        for(int i = 0; i < ALPHABETMAX; i++) {
            alphabetCount[i] = 0; // initializing alphabetCount array to all zeros
        }

        for(int i = 0; i < DIGITMAX; i++) {
            numDigit[i] = 0; // initializing numDigit array to all zeros
        }

        char currChar;
        int currLen = 0; // what if the first character is a space, newline, or tab? 

        // • Loop over our input file (character by character)
        while((c = fgetc(file)) != EOF) {
            currChar = c;
            // finished word indicators
            if((currChar == ' ') || (currChar == '\n') || (currChar == '\t')) {
                // just ended a word
                if(currLen > 0) {
                    // check if word is longer than 20 characters
                    if(currLen <= MAXWORDLEN) {
                        // store size of word in wordLen array
                        wordLen[currLen]++;
                    }
                    // word is longer than 20 characters 
                    else {
                        // Increment overFlow count by 1 at index 0
                        wordLen[0]++;
                    }
                    // reset wordLen array back to index 0 to reuse
                    currLen = 0;   
                }
                // else if currLen = 0, nothing happens b/c 
                // that means there is more whitespace

            } // end of "big" if branch

            // beginning of a new word, assuming it is a character
            else {
                if((flag == 1) && (((currChar >= 33) && (currChar <= 47)) || ((currChar >= 58) && (currChar <= 64)))) {
                    continue;  
                } else if((flag == 1) && (currChar >= '0' && currChar <= '9')) {
                    numDigit[currChar - '0']++;
                    continue;
                }

                // already inside a word
                if(currLen > 0) {
                    currLen++;
                }
                // store starting letter in alphabetCount array
                // currLen = 0
                else {

                    wordCount++;
                    // Number of words that start with each letter of the alphabet
                    // Check if starting letter is capital case or lower case
                    if((currChar > 'A') && (currChar < 'Z')) {
                        alphabetCount[currChar - 'A']++;
                    } else {
                        alphabetCount[currChar - 'a']++;
                    }
                    currLen++;
                }
            } // end of "big" else branch
        } // end of while loop

        // When file hits EOF and doesn't store the last word
        if(currLen > 0) {
            // store size of last word in wordLen array
            // check if word is longer than 20 characters
                if(currLen <= MAXWORDLEN) {
                    // store size of word in wordLen array
                    wordLen[currLen]++;
                }
                // word is longer than 20 characters 
                else {
                    // Increment overFlow count by 1 at index 0
                    wordLen[0]++;
                }
        }

        // print all the array contents
        for(int i = 1; i <= MAXWORDLEN; i++) {
            printf("Number of words that have %d character(s) in them: %d \n", i, wordLen[i]);
        }

        printf("------------------------------------------------------------------------------------ \n");

        printf("Number of words that have overflow: %d \n", wordLen[0]);

        printf("------------------------------------------------------------------------------------ \n");

        int sum = 0;
        for(int i = 0; i < ALPHABETMAX; i++) {
            printf("Number of words that start with %c: %d \n", i + 'A', alphabetCount[i]);
            sum += alphabetCount[i];    
        }

        printf("Total number of words that start with an alphabet in the file: %d \n", sum);

        printf("------------------------------------------------------------------------------------ \n");

        for(int i = 0; i < DIGITMAX; i++) {
            printf("Number of digits for %d: %d \n", i , numDigit[i]);
        }

        printf("------------------------------------------------------------------------------------ \n");

        printf("Total Word Count for the text file: %d \n", wordCount);

        // close file
        fclose(file);
        return 0;

    } // end of main function
    
// other considerations:
// • when a word does not start with a letter or number
// • when some lines are only newlines


// 3. Print output (up to me):
//  Just make sure all the information that you collected is printed.



// char charBuff[MAXCHAR]; // stores fixed number of characters from text file

// for(int i = 0; i < MAXCHAR; i++) {
//     charBuff[i] = 0; // initializing charBuff array to all zeros
// }



// // printf("%c", c);
// printf("New Buffer Array: ");
// // Move them into the buffer, until it is full.
// for(index = 0; index < MAXCHAR; index++) {
//     charBuff[index] = c;
//     printf("%c", charBuff[index]);
//     c = fgetc(file);
// }

// printf("\n");



// • When the buffer is full, we will now need to process it, 
// so we will loop over the buffer, character by character and 
// collect some information:
//for(index = 0; index < MAXCHAR; index++) {
    // set current character to process the character at the incremented index
    // currChar = charBuff[index]; // maybe a problem could be here???
// }


// break; // for one iteration of charBuff array, going to delete this line for entire file to run

// Fill up the buffer repeatedly until the input is exhausted 
// (Make it its own function.)