#include <stdio.h>

int main(void) {
   int arrowBaseHeight;
   int arrowBaseWidth;
   int arrowHeadWidth;
   
   printf("Enter arrow base height:\n");
   scanf("%d", &arrowBaseHeight);
   
   printf("Enter arrow base width:\n");
   scanf("%d", &arrowBaseWidth);
   
   printf("Enter arrow head width:\n");
   scanf("%d", &arrowHeadWidth);
   
   while (arrowHeadWidth <= arrowBaseWidth) {
      printf("Enter arrow head width:\n");
      scanf("%d", &arrowHeadWidth);
   }
   
   printf("\n");
   
  for(int i = 0; i < arrowBaseHeight; i++) {
      for(int j = 0; j <  arrowBaseWidth; j++) {
       printf("*");  
      }
      printf("\n");
  }
  for(int i = 0; i < arrowHeadWidth; i++){
      for(int j = i; j < arrowHeadWidth; j++) {
       printf("*");  
      }
      printf("\n");
  }
   
   return 0;
}
