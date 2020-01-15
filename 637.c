#include <stdio.h>
#include <string.h>
#include <ctype.h>

int GetNumOfNonWSCharacters (const char text[]) {
   int itr = 0;
   int counter = 0;
   while (text[itr]) {
      if (text[itr] != ' ' && text[itr] != '\n') {
         counter++;  
      }
      itr++;
   }
   return counter;
}

int GetNumOfWords (const char text[]) {
   int itr = 0;
   int counter = 0;
   while (text[itr]) {
      if (text[itr] == ' ' && text[itr + 1]) {
         if(text[itr + 1] != ' ') {
            counter++;  
         }
      }
      itr++;
   }
   return counter + 1;
}

void FixCapitalization(char text[]) {
   int textITR = 0;
   int periodLocations[256] = {};
   int periodCounter = 0;
   
   //Find location of all periods in string
   while (text[textITR]) {
      if (text[textITR] == '.'){
         periodLocations[periodCounter] = textITR;
         periodCounter++;
      }
      textITR++;
   }
   
   //Make first character of string uppercase
   if (text[0] >= 'a' && text[0] <= 'z') {
      text[0] = toupper(text[0]);  
   }
   
   //Find first character after whitespace and make it uppercase
   //Assumes first character after whitespace is alphabetical
   int periodITR = 0;
   while (periodLocations[periodITR]) {
      while (text[periodLocations[periodITR]] == ' ' || text[periodLocations[periodITR]] == '.') {
         periodLocations[periodITR]++;  
      }
      text[periodLocations[periodITR]] = toupper(text[periodLocations[periodITR]]);
      periodITR++;
   }
}

//Searches for exclamation points and replaces them with periods.
void ReplaceExclamation(char text[]) {
   int itr = 0;
   while (text[itr]) {
      if (text[itr] == '!') {
         text[itr] = '.';  
      }
      itr++;
   }
}

/*
Find the location of all extra whitespaces
Create a new string
Write contents of original string to new string, skipping the location of extra whitespaces
Point original string to new string
*/
char * ShortenSpace(char text[]) {
   int itr = 0;
   int extraWhitespaceLoc[256] = {};
   char newString[256];
   while (text[itr]) {
      if (text[itr] == ' ' && text[itr + 1]) {
         if (text[itr + 1] == ' ') {
             extraWhitespaceLoc[itr] = 1;
         }
      }
      itr++;
   }
   
   itr = 0; 
   int jItr = 0;
   for( ; text[itr]; itr++) {
      if (extraWhitespaceLoc[itr]) {
         itr++;  
      }
      if (text[itr] != '\n') {
         newString[jItr] = text[itr];
         jItr++;
      }
   }
   strcpy(text, newString);
   return text;
}

char PrintMenu() {
   
   printf("MENU\n");
   printf("c - Number of non-whitespace characters\n");
   printf("w - Number of words\n");
   printf("f - Fix capitalization\n");
   printf("r - Replace all !'s\n");
   printf("s - Shorten spaces\n");
   printf("q - Quit\n\n");
   printf("Choose an option:\n");
   
   char input;
   scanf(" %c", &input);
   return input;
}

int main(void) {
   
   int MAX_LENGTH = 256;

   printf("Enter a sample text:\n\n");
   char sampleText[MAX_LENGTH];
   fgets(sampleText, MAX_LENGTH, stdin);
   printf("You entered: ");
   printf("%s\n", sampleText);
   
   int done = 0;
   while(!done) {
      char input = PrintMenu();
      switch (input) {
      case 'c':
         printf("Number of non-whitespace characters: %d\n\n", GetNumOfNonWSCharacters(sampleText));
         break;
      case 'w':
         printf("Number of words: %d\n\n", GetNumOfWords(sampleText));
         break;
      case'f':
         FixCapitalization(sampleText);
         printf("Edited text: %s\n", sampleText);
         break;
      case 'r':
         ReplaceExclamation(sampleText);
         printf("Edited text: %s\n", sampleText);
         break;
      case 's':
         strcpy(sampleText, ShortenSpace(sampleText));
         printf("Edited text: %s\n", sampleText);
         break;
      case 'q':
         done = 1;
         break;
      default:
         break;
      }
   }
   return 0;
}
