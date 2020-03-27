#include<iostream>
using namespace std;

// S0454007 林怡靜 
class PatientAccount{ // 建立一個叫 PatientAccount的 class存病人住院天數和總花費 
    public:
        static int Days;
        static int Charges;
        PatientAccount() // constructor設定初值 
 		{
     		Days = 0;
     		Charges = 0;
 		}
};

int PatientAccount::Days = 0; // 新的病人就把天數和費用歸零 
int PatientAccount::Charges = 0;

// S0454028 吳曉維 
class Surgery{ // 建立一個叫 Surgery的 class存五種手術的費用，還可更新 class PatientAccount的 Charges 
	public:
		void set_surgery(string surgery)
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

// S0454010 文怡華 
class Pharmacy{ // 建立一個叫 Pharmacy的 class存五種藥品的費用，還可更新 class PatientAccount的 Charges 
	public:
		int get_price(string med)
		{
			if (med == "medication1")
				PatientAccount::Charges += 100;  
				
			if (med == "medication2")
				PatientAccount::Charges += 200;
			
			if (med == "medication3")
				PatientAccount::Charges += 300;
				
			if (med == "medication4")
				PatientAccount::Charges += 400;
			
			if (med == "medication5")
				PatientAccount::Charges += 500;
		}
};

// S0454027 楊靜慧 
int main()
{
	// 學號      姓名    負責部分 
	// S0454007  林怡靜  class PatientAccount 
	// S0454028  吳曉維  class Surgery 
	// S0454010  文怡華  class Pharmacy
	// S0454027  楊靜慧  main
	
	// 開發問題                   解決辦法
	// 組員之間對題目的解讀不同   溝通以得出結論 
	// 變數名稱不同               以大多數的命名為主 
	Surgery S1; // 宣告一個Surgery的新物件叫S1 
	Pharmacy M1; 
	char answer, ans, again;
	string x,y;
    do{
    	PatientAccount(); // 歸零Days、Charges 
		while(1)
		{
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
	
			cout << "Please enter a type of surgery : ";
			cin >> y;
    		S1.set_surgery(y); // 呼叫S1的set_surgery，依照輸入的手術增加天數及費用 
	
			do{
	    		cout << "Please enter a type of medication : ";
    			cin >> x;
	    		M1.get_price(x); // 呼叫M1的get_price，依照輸入的藥物增加費用 
	    		cout << "More medication ? Enter<y/n> : "; 
	    		cin >> answer;
			} while (answer == 'y' || answer == 'Y');
	
			cout << "Whether out of the hospital or not? Enter<y/n> : ";
			cin >> ans;
	
			PatientAccount::Charges += 2000 * PatientAccount::Days; // 加上每天的住院費用 
	
			if(ans == 'y' || ans == 'Y')
			{
				cout << "The charges the patient should pay : ";
	    		cout << PatientAccount::Charges << endl;
				break;
			}	
		}
    	cout << "Do you want to do it again ? Enter<y/n> : ";
    	cin >> again;
	} while (again == 'y' || again == 'Y');

	system("pause");
	return 0;	    
}
