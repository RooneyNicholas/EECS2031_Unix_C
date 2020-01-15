#include <stdio.h>
#include <string.h>

int service(char service[128]) {
   if(strcmp(service, "Oil change") == 0) {
      return 35;  
   }
   else if (strcmp(service, "Tire rotation") == 0) {
      return 19;  
   }
   else if (strcmp(service, "Car wash") == 0) {
      return 7;
   }
   else if (strcmp(service, "Car wax") == 0) {
      return 12;
   }
   return 0;
}

int main(void) {

   printf("Davy's auto shop services\n");
   printf("Oil change -- $35\n");
   printf("Tire rotation -- $19\n");
   printf("Car wash -- $7\n");
   printf("Car wax -- $12\n\n");
   
   int price1 = 0;
   int price2 = 0;
   
   printf("Select first service:\n");
   char firstServiceP1[20];
   char firstServiceP2[20];
   scanf("%s", firstServiceP1);
   if(strcmp(firstServiceP1, "-") != 0){
      strcat(firstServiceP1, " ");
      scanf("%s", firstServiceP2);
      strcat(firstServiceP1, firstServiceP2);
      price1 = service(firstServiceP1);
   } else {
      strcpy(firstServiceP1, "No service");   
   }
   
   printf("Select second service:\n\n");
   char secondServiceP1[20];
   char secondServiceP2[20];
   scanf("%s", secondServiceP1);
   if(strcmp(secondServiceP1, "-") != 0){
      strcat(secondServiceP1, " ");
      scanf("%s", secondServiceP2);
      strcat(secondServiceP1, secondServiceP2);
      price2 = service(secondServiceP1);
   } else {
      strcpy(secondServiceP1, "No service");   
   }
   
   printf("Davy's auto shop invoice\n\n");
   printf("Service 1: %s", firstServiceP1);
   if(price1) {
      printf(", $%d\n", price1);
   } else {
      printf("\n");  
   }
   printf("Service 2: %s", secondServiceP1);
   if(price2) {
      printf(", $%d\n\n", price2);
   }
   else {
      printf("\n\n");  
   }
   printf("Total: $%d\n", price1 + price2);

   return 0;
}
