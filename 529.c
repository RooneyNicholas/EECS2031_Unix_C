#include <stdio.h>

void UpdateRating (int *playersNumberAr, int *playersRatingAr, int MAX_ELEMENTS) {
   printf("Enter a jersey number:\n");
   int number;
   scanf("%d", &number);
   printf("Enter a new rating for player:\n");
   int newRating;
   scanf("%d", &newRating);
   
   int index = -1;
   for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (*playersNumberAr == number) {
         index = i;
        }
        playersNumberAr++;
   }
   if (index != -1) {
      playersRatingAr += index;
      *playersRatingAr = newRating;
   }
}

void OutputAboveRating (int *playersNumberAr, int *playersRatingAr, int MAX_ELEMENTS) {
      printf("Enter a rating:\n");
      int rating;
      scanf("%d", &rating);
      printf("ABOVE %d\n", rating);
      for (int i = 0; i < MAX_ELEMENTS; i++) {
         if (*playersRatingAr > rating) {
            printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, *playersNumberAr, *playersRatingAr);
         }
         playersNumberAr++;
         playersRatingAr++;
      }
      printf("\n");
}

void ReplacePlayer (int *playersNumberAr, int *playersRatingAr, int MAX_ELEMENTS) {
   printf("Enter a jersey number:\n");
   int number;
   scanf("%d", &number);
   printf("Enter a new jersey number:\n");
   int newNumber;
   scanf("%d", &newNumber);
   printf("Enter a rating for the new player:\n");
   int newRating;
   scanf("%d", &newRating);
   
   for (int i = 0; i < MAX_ELEMENTS && *playersNumberAr != number; i++) {
        playersNumberAr++;
        playersRatingAr++;
   }
   
   if (*playersNumberAr == number) {
       *playersNumberAr = newNumber;
       *playersRatingAr = newRating;
   }
   printf("\n");
}

void OutputRoster (int *playersNumberAr, int *playersRatingAr, int MAX_ELEMENTS) {
   printf("ROSTER\n");
   for (int i = 0; i < MAX_ELEMENTS; i++) {
      printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, *playersNumberAr, *playersRatingAr);
      playersNumberAr++;
      playersRatingAr++;
   }

   printf("\n");
}

int main (void) {

   const int MAX_ELEMENTS = 5;
   int playersNumberAr[MAX_ELEMENTS];
   int playersRatingAr[MAX_ELEMENTS];
   
   //Initial user input for numbers and ratings
   for (int i = 0; i < 5; i++) {
      printf("Enter player %d's jersey number:\n", i + 1); //+1 to print list from 1 - 5
      int playerNumber;
      scanf("%d", &playerNumber);
      playersNumberAr[i] = playerNumber;
      
      printf("Enter player %d's rating:\n\n", i + 1); //+1 to print list from 1 - 5
      int playerRating;
      scanf("%d", &playerRating);
      playersRatingAr[i] = playerRating;
   }
   
   OutputRoster(playersNumberAr, playersRatingAr, MAX_ELEMENTS);
   
   //print menu and loop until quit is selected
   char input = '0';
   while(input != 'q') {
      printf("MENU\n");
      printf("u - Update player rating\n");
      printf("a - Output players above a rating\n");
      printf("r - Replace player\n"); 
      printf("o - Output roster\n");
      printf("q - Quit\n\n");
      printf("Choose an option:\n");
      
      scanf(" %c", &input); //space before format specifier skips the whitespace(in this case newline char) of previous input
      
      switch (input) {
         case 'u':
            UpdateRating(playersNumberAr, playersRatingAr, MAX_ELEMENTS);
            break;
         case 'a':
            OutputAboveRating(playersNumberAr, playersRatingAr, MAX_ELEMENTS);
            break;
         case 'r':
            ReplacePlayer(playersNumberAr, playersRatingAr, MAX_ELEMENTS);
            break;
         case 'o':
            OutputRoster(playersNumberAr, playersRatingAr, MAX_ELEMENTS);
            break;
         default:
            break;
      }
      
   }

   return 0;
}
