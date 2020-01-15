#include <stdio.h>
#include <string.h>

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

ShoppingCart AddItem(ItemToPurchase item, ShoppingCart shoppingCart) {
   if(shoppingCart.cartSize < 10) {
      shoppingCart.cartItems[shoppingCart.cartSize] = item;
      shoppingCart.cartSize++;
   } else {
      printf("Cart Full!\n");
   }
   return shoppingCart;
}

ShoppingCart RemoveItem(char itemName[], ShoppingCart shoppingCart) {
   int itemFound = 0;
   //printf("You are trying to remove \'%s\' from the cart.\n", itemName);
   for(int itr = 0; itr < shoppingCart.cartSize; itr++) {
      if(strcmp(itemName, shoppingCart.cartItems[itr].itemName) == 0) {
         itemFound = 1;
         for(; itr < shoppingCart.cartSize - 1; itr++) {
            shoppingCart.cartItems[itr] = shoppingCart.cartItems[itr + 1];
         }
         shoppingCart.cartSize--;
      }
   }
   if(!itemFound) {
      printf("Item not found in cart. Nothing removed.\n");  
   }
   return shoppingCart;
}

ShoppingCart ModifyItem(ItemToPurchase item, ShoppingCart shoppingCart) {
   int itemFound = 0;
   for(int itr = 0; itr < shoppingCart.cartSize; itr++) {
      if(strcmp(item.itemName, shoppingCart.cartItems[itr].itemName) == 0) {
         itemFound = 1;
         shoppingCart.cartItems[itr].itemQuantity = item.itemQuantity;
      }
   }
   if(!itemFound) {
      printf("Item not found in cart. Nothing modified.\n\n");
   }
   return shoppingCart;
}

int GetNumItemsInCart(ShoppingCart shoppingCart) {
   return shoppingCart.cartSize;
}

int GetCostOfCart(ShoppingCart shoppingCart) {
   int totalCost = 0;
   for(int itr = 0; itr < shoppingCart.cartSize; itr++) {
        totalCost += shoppingCart.cartItems[itr].itemPrice * shoppingCart.cartItems[itr].itemQuantity;
   }
   return totalCost;
}

void PrintTotal(ShoppingCart shoppingCart) {
   if(shoppingCart.cartSize > 0) {
      printf("OUTPUT SHOPPING CART\n");
      printf("%s's Shopping Cart - %s\n", shoppingCart.customerName, shoppingCart.currentDate);
      int totalItemQuantity = 0;
      for(int itr = 0; itr < shoppingCart.cartSize; itr++) {
          totalItemQuantity += shoppingCart.cartItems[itr].itemQuantity;
      }
      printf("Number of Items: %d\n\n", totalItemQuantity);
      for(int itr = 0; itr < shoppingCart.cartSize; itr++) {
         PrintItemCost(shoppingCart.cartItems[itr]);  
      }
   } else {
      printf("OUTPUT SHOPPING CART\n");
      printf("%s's Shopping Cart - %s\n", shoppingCart.customerName, shoppingCart.currentDate);
      printf("Number of Items: 0\n\n");
      printf("SHOPPING CART IS EMPTY\n\n");
      printf("Total: $0\n");
   }
   printf("\n");
}

void PrintDescriptions(ShoppingCart shoppingCart) {
   for(int itr = 0; itr < shoppingCart.cartSize; itr++) {
      PrintItemDescription(shoppingCart.cartItems[itr]);
   }
}
