#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

typedef struct ItemToPurchase {
   char itemName[256];
   char itemDescription[256];
   int itemPrice;
   int itemQuantity;
} ItemToPurchase;

void MakeItemBlank(ItemToPurchase * item);
void PrintItemCost(ItemToPurchase item);
void PrintItemDescription(ItemToPurchase item);

#endif
