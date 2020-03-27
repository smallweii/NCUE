#include<iostream>
#include<fstream>
#include<string>
#include<ctype.h>
#include "S0454028_Inventory.h"
using namespace std;

void AddRecord(Inventory &, fstream &); // 新增紀錄 
void DisplayRecord(Inventory &, fstream &); // 顯示紀錄到螢幕 
void ChangeRecord(Inventory &, fstream &); // 變更紀錄 

void AddRecord(Inventory &record, fstream &file) // 新增紀錄 
{
	file.seekg(0L, ios::end); // 把指標移到檔案結尾 
	cout << "Item description : ";
	cin >> record.ItemDescription;
	cout << "Quantity on hand : ";
	cin >> record.QuantityOnHand;
	cout << "Wholesale cost : ";
	cin >> record.WholesaleCost;
	cout << "Retail cost : ";
	cin >> record.RetailCost;
	cout << "Date added to inventory(YYYY/MM/DD) : ";
	cin >> record.Date;
	cout << "Please open the file to check !!!!!!" << endl;
	
	file << "Item description : " << record.ItemDescription << endl
	     << "Quantity on hand : " << record.QuantityOnHand << endl
	     << "Wholesale cost : " << record.WholesaleCost << endl
	     << "Retail cost : " << record.RetailCost << endl
	     << "Date added to inventory(YYYY/MM/DD) : " << record.Date << endl << endl;
}

void DisplayRecord(Inventory &record, fstream &file) // 顯示記錄到螢幕 
{
	int order;
	string ItemDescription, QuantityOnHand, WholesaleCost, RetailCost, Date, line;
	
	cout << "Please open the file to check which data you want to display ..." << endl
	     << "Enter a number of the order of the data(第幾組) : ";
	cin >> order;
	
	for (int i = 0; i < order; i++) { // 把前面的資料讀過忽略掉 
		getline(file, ItemDescription);
		getline(file, QuantityOnHand);
		getline(file, WholesaleCost);
		getline(file, RetailCost);
		getline(file, Date);
		getline(file, line);
	}
	cout << ItemDescription << endl // 印出指標所指位置的字串 
	     << QuantityOnHand << endl
	     << WholesaleCost << endl
	     << RetailCost << endl
	     << Date << endl;
}

void ChangeRecord(Inventory &record, fstream &file) // 變更紀錄 
{
	int order;
	string ignore;
	
	cout << "Please open the file to check which data you want to change ..." << endl
	     << "Enter a number of the order of the data(第幾組) : ";
	cin >> order;
	
	order = (order - 1) * 6;
	for (int i = 0; i < order; i++)
		getline(file, ignore); // 把前面的資料讀過忽略掉 
	
	cout << "Item description : ";
	cin >> record.ItemDescription;
	cout << "Quantity on hand : ";
	cin >> record.QuantityOnHand;
	cout << "Wholesale cost : ";
	cin >> record.WholesaleCost;
	cout << "Retail cost : ";
	cin >> record.RetailCost;
	cout << "Date added to inventory(YYYY/MM/DD) : ";
	cin >> record.Date;
	cout << "Please open the file to check !!!!!!" << endl;
	
	file << "Item description : " << record.ItemDescription << endl
	     << "Quantity on hand : " << record.QuantityOnHand << endl
	     << "Wholesale cost : " << record.WholesaleCost << endl
	     << "Retail cost : " << record.RetailCost << endl
	     << "Date added to inventory(YYYY/MM/DD) : " << record.Date << endl << endl;
}
