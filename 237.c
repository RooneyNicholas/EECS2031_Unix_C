#include <stdio.h>
#include <math.h>                  // Note: Needed for math functions in part (3)

int main(void) {
   double wallHeight;
   double wallWidth;
   double wallArea;

   printf("Enter wall height (feet):\n");
   scanf("%lf", &wallHeight);
   printf("Enter wall width (feet):\n");
   scanf("%lf", &wallWidth);
   
   // Calculate and output wall area
   wallArea = wallHeight * wallWidth;
   printf("Wall area: %.2lf square feet\n", wallArea);
   
   const int GALLON_COVERAGE = 350;
   printf("Paint needed: %.2lf gallons\n", wallArea / GALLON_COVERAGE);
   printf("Cans needed: %.0lf can(s)\n", ceil(wallArea / GALLON_COVERAGE));

   return 0;
}
