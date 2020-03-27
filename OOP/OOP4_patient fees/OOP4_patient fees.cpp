#include<iostream>
using namespace std;

class PatientAccount{ // 建立一個叫 PatientAccount的 class存病人住院天數和總花費 
	public:
		static int Days;
		static int Charges;
		PatientAccount() // default constructor
		{
			Days = 0;
			Charges = 0;
		}
};
int PatientAccount::Days = 0; // 新的病人就把天數和費用歸零 
int PatientAccount::Charges = 0;

class Surgery{ // 建立一個叫 Surgery的 class存五種手術的費用，還可更新 class PatientAccount的 Charges 
	public:
		int set_surgery(string surgery)
		{
			if (surgery == "surgery1")
			{
				PatientAccount::Days++; // 每種手術都需住院一天  
				PatientAccount::Charges += 1000;
			}
			if (surgery == "surgery2")
			{
				PatientAccount::Days++;
				PatientAccount::Charges += 2000;
			}
			if (surgery == "surgery3")
			{
				PatientAccount::Days++;
				PatientAccount::Charges += 3000;
			}
			if (surgery == "surgery4")
			{
				PatientAccount::Days++;
				PatientAccount::Charges += 4000;
			}
			if (surgery == "surgery5")
			{
				PatientAccount::Days++;
				PatientAccount::Charges += 5000;
			}
		}
};
class Pharmacy{ // 建立一個叫 Pharmacy的 class存五種藥品的費用，還可更新 class PatientAccount的 Charges 
	public:
		int set_medication(string medication)
		{
			if (medication == "medication1")
				PatientAccount::Charges += 100;
			if (medication == "medication2")
				PatientAccount::Charges += 200;
			if (medication == "medication3")
				PatientAccount::Charges += 300;
			if (medication == "medication4")
				PatientAccount::Charges += 400;
			if (medication == "medication5")
				PatientAccount::Charges += 500;
		}
};
int main()
{
	string surgery, medication;
	char answer;
	PatientAccount p1; // 宣告一個 PatientAccount的物件叫 p1 
	Surgery s1; // 宣告一個 Surgery的物件叫 s1 
	Pharmacy m1; // 宣告一個 Pharmacy的物件叫 m1 
	
	do{
		PatientAccount(p1); // 歸零 Days、Charges 
		cout << "******************************" << endl; // 印出menu
		cout << "*            Menu            *" << endl;
		cout << "*                            *" << endl;
		cout << "* Daily rate: $2000/day      *" << endl;
		cout << "*                            *" << endl;
		cout << "* Surgery Types              *" << endl;
		cout << "*     surgery1: $1000/day    *" << endl;
		cout << "*     surgery2: $2000/day    *" << endl;
		cout << "*     surgery3: $3000/day    *" << endl;
		cout << "*     surgery4: $4000/day    *" << endl;
		cout << "*     surgery5: $5000/day    *" << endl;
		cout << "*                            *" << endl;
		cout << "* Medication Types           *" << endl;
		cout << "*     medication1: $100      *" << endl;
		cout << "*     medication2: $200      *" << endl;
		cout << "*     medication3: $300      *" << endl;
		cout << "*     medication4: $400      *" << endl;
		cout << "*     medication5: $500      *" << endl;
		cout << "******************************" << endl;
	
		do{
			cout << "Please enter a type of surgery: ";
			cin >> surgery;
			s1.set_surgery(surgery); // 呼叫 s1的 set_surgery，依照輸入的手術增加天數及費用 
			do{
				cout << "Please enter a type of medication: ";
				cin >> medication;
				m1.set_medication(medication); // 呼叫 m1的 set_medication，依照輸入的藥物增加費用 
				cout << "More medication? Enter<y/n>: "; // 可依輸入y/n來判斷是否繼續重複輸入 
				cin >> answer;
			} while (answer == 'y' || answer == 'Y'); // 只要輸入y/Y迴圈就可繼續執行 
			
			cout << "Does the patient check out of the hospital? Enter<y/n>: ";
			cin >> answer;
			PatientAccount::Charges += 2000 * PatientAccount::Days; // 加上每天的住院費用 
		} while (answer == 'n' || answer == 'N');
		
		cout << "Total charges: " << PatientAccount::Charges << endl;
		cout << "More patient? Enter<y/n>: ";
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');
	
	system("pause");
	return 0;
}
