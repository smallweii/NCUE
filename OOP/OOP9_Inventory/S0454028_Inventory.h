#ifndef INVENTORY_H
#define INVENTORY_H
#include<string>
using namespace std;
 
struct Inventory{ // �إߤ@�ӥs Inventory�� struct 
	string ItemDescription; // �ӫ~�y�z 
	int QuantityOnHand; // �{���q 
	int WholesaleCost; // ��o�� 
	int RetailCost; // �s��� 
	string Date; // ��� 
};
#endif
