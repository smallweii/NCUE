#include<iostream>
#include<fstream>
#include<string>
#include<ctype.h>
#include "S0454028_Inventory.h"
using namespace std;

void AddRecord(Inventory &, fstream &); // �s�W���� 
void DisplayRecord(Inventory &, fstream &); // ��ܬ�����ù� 
void ChangeRecord(Inventory &, fstream &); // �ܧ���� 

void AddRecord(Inventory &record, fstream &file) // �s�W���� 
{
	file.seekg(0L, ios::end); // ����в����ɮ׵��� 
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

void DisplayRecord(Inventory &record, fstream &file) // ��ܰO����ù� 
{
	int order;
	string ItemDescription, QuantityOnHand, WholesaleCost, RetailCost, Date, line;
	
	cout << "Please open the file to check which data you want to display ..." << endl
	     << "Enter a number of the order of the data(�ĴX��) : ";
	cin >> order;
	
	for (int i = 0; i < order; i++) { // ��e�������Ū�L������ 
		getline(file, ItemDescription);
		getline(file, QuantityOnHand);
		getline(file, WholesaleCost);
		getline(file, RetailCost);
		getline(file, Date);
		getline(file, line);
	}
	cout << ItemDescription << endl // �L�X���Щҫ���m���r�� 
	     << QuantityOnHand << endl
	     << WholesaleCost << endl
	     << RetailCost << endl
	     << Date << endl;
}

void ChangeRecord(Inventory &record, fstream &file) // �ܧ���� 
{
	int order;
	string ignore;
	
	cout << "Please open the file to check which data you want to change ..." << endl
	     << "Enter a number of the order of the data(�ĴX��) : ";
	cin >> order;
	
	order = (order - 1) * 6;
	for (int i = 0; i < order; i++)
		getline(file, ignore); // ��e�������Ū�L������ 
	
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
