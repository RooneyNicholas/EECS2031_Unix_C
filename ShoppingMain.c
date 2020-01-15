#include <stdio.h>
#include <string.h>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"


char PrintMenu() {

   printf("MENU\n");
   printf("a - Add item to cart\n");
   printf("r - Remove item from cart\n");
   printf("c - Change item quantity\n");
   printf("i - Output items' descriptions\n");
   printf("o - Output shopping cart\n");
   printf("q - Quit\n\n");
   printf("Choose an option:\n");
 
   char input;
   scanf(" %c", &input);
   return input;
}

void ClearInput() {
   char c;
   c = getchar();
   while(c != '\n' && c != EOF) {
      c = getchar();
   }
}

int main() {
   
   ShoppingCart shoppingCart;
   shoppingCart.cartSize = 0;
   
   printf("Enter Customer's Name:\n");
   fgets(shoppingCart.customerName, 256, stdin);
   sscanf(shoppingCart.customerName, "%[^\n]s", shoppingCart.customerName);
   printf("Enter Today's Date:\n");
   fgets(shoppingCart.currentDate, 256, stdin);
   sscanf(shoppingCart.currentDate, "%[^\n]s", shoppingCart.currentDate);
   printf("\n");
   printf("Customer Name: %s\n", shoppingCart.customerName);
   printf("Today's Date: %s\n\n", shoppingCart.currentDate);
   
   int done = 0;
   while(!done) {
      char input = PrintMenu();
      
      switch (input) {
         ItemToPurchase item;
         case 'a':
            ClearInput();
            printf("ADD ITEM TO CART\n");
            printf("Enter the item name:\n");
            fgets(item.itemName, 256, stdin);
            sscanf(item.itemName, "%[^\n]s", item.itemName);
            printf("Enter the item description:\n");
            fgets(item.itemDescription, 256, stdin);
            sscanf(item.itemDescription, "%[^\n]s", item.itemDescription);
            printf("Enter the item price:\n");
            scanf("%d", &item.itemPrice);
            printf("Enter the item quantity:\n");
            scanf("%d", &item.itemQuantity);
            shoppingCart = AddItem(item, shoppingCart);
            printf("\n");
            break;
         case 'r':
            ClearInput();
            printf("REMOVE ITEM FROM CART\n");
            printf("Enter name of item to remove:\n");
            char itemToRemove[256];
            fgets(itemToRemove, 256, stdin);
            sscanf(itemToRemove, "%[^\n]s", itemToRemove);
            shoppingCart = RemoveItem(itemToRemove, shoppingCart);
            printf("\n");
            break;
         case 'c':
            ClearInput();
            printf("CHANGE ITEM QUANTITY\n");
            printf("Enter the item name:\n");
            fgets(item.itemName, 256, stdin);
            sscanf(item.itemName, "%[^\n]s", item.itemName);
            printf("Enter the new quantity:\n");
            scanf("%d", &item.itemQuantity);
            shoppingCart = ModifyItem(item, shoppingCart);
            break;
         case 'i':
            PrintDescriptions(shoppingCart);
            printf("\n");
            break;
         case 'o':
            PrintTotal(shoppingCart);
            int total = GetCostOfCart(shoppingCart);
            if(total) {
               printf("Total: $%d\n\n", total);  
            }
            break;
         case 'q':
            done = 1;
            break;
      }
   }
 
 return 0;  
}
