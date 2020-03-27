#ifndef INVENTORY_H
#define INVENTORY_H
#include<string>
using namespace std;
 
struct Inventory{ // 建立一個叫 Inventory的 struct 
	string ItemDescription; // 商品描述 
	int QuantityOnHand; // 現有量 
	int WholesaleCost; // 批發價 
	int RetailCost; // 零售價 
	string Date; // 日期 
};
#endif
