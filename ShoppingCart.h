#include "ItemToPurchase.h"

#ifndef SHOPPING_CART
#define SHOPPING_CART

typedef struct ShoppingCart {
   char customerName[256];
   char currentDate[256];
   ItemToPurchase cartItems[10];
   int cartSize;
} ShoppingCart;

ShoppingCart AddItem(ItemToPurchase item, ShoppingCart shoppingCart);
ShoppingCart RemoveItem(char itemName[], ShoppingCart shoppingCart);
ShoppingCart ModifyItem(ItemToPurchase item, ShoppingCart shoppingCart);
int GetNumItemsInCart(ShoppingCart shoppingCart);
int GetCostOfCart(ShoppingCart shoppingCart);
void PrintTotal(ShoppingCart shoppingCart);
void PrintDescriptions(ShoppingCart shoppingCart);

#endif
