#include<iostream>
#include<fstream>
#include<string>
#include<ctype.h>
using namespace std;

struct Inventory{ // 建立一個叫 Inventory的 struct 
	string ItemDescription; // 商品描述 
	int QuantityOnHand; // 現有量 
	int WholesaleCost; // 批發價 
	int RetailCost; // 零售價 
	string Date; // 日期 
};

void AddRecord(Inventory &, fstream &); // 新增紀錄 
void DisplayRecord(Inventory &, fstream &); // 顯示紀錄到螢幕 
void ChangeRecord(Inventory &, fstream &); // 變更紀錄 

int main()
{
	fstream file("inventory.txt", ios::in | ios::out); // 開檔，讀和寫為同檔 
	if (!file) { // 檢查檔案是否成功開啟 
		cout << "Can't open the file!" << endl;
		exit(1); // 在不正常情形下，中斷程式的執行 
	}
	char choice, answer;
	Inventory record; // 建立一個儲存型態為 Inventory的物件叫 record 
	
	do {
		cout << "******************************************" << endl
		     << "*                  Menu                  *" << endl
		     << "*   (a) Add new records to the file      *" << endl
		     << "*   (b) Display any record in the file   *" << endl
		     << "*   (c) Change any record in the file    *" << endl
		     << "******************************************" << endl
		     << "Which one do you want to do? Enter<a/b/c> : ";
		cin >> choice;
		
		if (toupper(choice) == 'A')
			AddRecord(record, file);
		if (toupper(choice) == 'B')
			DisplayRecord(record, file);
		if (toupper(choice) == 'C')
			ChangeRecord(record, file);
		
		cout << endl << "Again? Enter<y/n> : "; // 可依輸入y/n來判斷是否繼續重複輸入 
		cin >> answer;
		file.clear(); // 清除指標 
		file.seekg(0L, ios::beg); // 把指標移到檔案開頭 
	} while (toupper(answer) == 'Y'); // 只要輸入y/Y迴圈就可繼續執行 
	
	file.close(); // 關檔 
	system("pause");
	return 0;
}

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
