#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Heading{ //建立一個叫 Heading的 class 
	private:
		string company;
		string report;
	
	public:
		Heading(string c = "ABC Industries", string r = "Report") //預設 company name和 report name的 default value
		{
			company = c; //constructor
			report = r;
		}
		friend void show_oneline(Heading); //友誼函數的原型 //友誼函數 : 把不屬於某 class之成員的函數存到該 class裡的成員
		friend void show_fourlines(Heading);
};
void show_oneline(Heading head) //定義友誼函數(印一行)，可存取 Heading裡私有的成員 
{
	cout << endl << head.company << " " << head.report << endl;
}
void show_fourlines(Heading head) //定義友誼函數(印四行)，可存取 Heading裡私有的成員 
{
	cout << endl;
	for (int i = 0; i < 45; i++) //置中印字串 
		cout << "*";
	cout << endl;
	for (int i = 0; i < 22 - head.company.length() / 2; i++)
		cout << " ";
	cout << head.company << endl; 
	for (int i = 0; i < 22 - head.report.length() / 2; i++)
		cout << " ";
	cout << head.report << endl;
	for (int i = 0; i < 45; i++)
		cout << "*";
	cout << endl;
}
int main()
{
	char answer;
	do{	
		string c, r;
		Heading head1; //建立儲存型態為 Heading的物件叫 head1
		vector<Heading> head_vec; //建立儲存型態為 Heading的 vector叫 head_vec 
		do{
			cout << "Please input a company name: ";
			getline(cin, c); //抓使用者輸入的字串，若抓到換行符號也算一個動作 
			cout << "Please input a report name: ";
			getline(cin, r);
			
			if (c[0] && r[0]) //若 company name和 report name都不是空字串，就都傳入 Heading的 constructor 
			{
				Heading head1(c, r);
				head_vec.push_back(head1); //把 head1的資料 push進 head_vec裡 
			}
			if (c[0] && !r[0]) //若 company name不是空字串，就傳入 Heading的 constructor
			{                  //以及 report name是空字串，就使用 default value 
				Heading head1(c);
				head_vec.push_back(head1);
			}
			if (!c[0] && r[0]) //若 company name是空字串，就使用 default value
			{                  //以及 report name不是空字串，就傳入 Heading的 constructor
				Heading head1("ABC Industries", r);
				head_vec.push_back(head1);
			}
			if (!c[0] && !r[0]) //若 company name和 report name都是空字串，就都使用 default value
			{                   //字串裡的第一個字元沒東西，表示使用者沒輸入字串名稱
				Heading head1;
				head_vec.push_back(head1);
			}
			cout << endl << "Again? Enter<y/n>: "; //可依輸入y/n來判斷是否繼續重複輸入  
			cin >> answer;
			getchar(); //讀掉換行符號 
		} while (answer == 'y' || answer == 'Y'); //只要輸入y/Y迴圈就可繼續執行  
		
		int format;
		cout << "Which one do you want to show, one-line or four-line format? Enter<1/4>: "; //問使用者要印幾行的格式 
		cin >> format;
		cout << endl;
		
		if (format == 1) //使用者要印一行的格式 
		{
			cout << "One-line format:" << endl;
			for (vector<Heading>::iterator it = head_vec.begin(); it != head_vec.end(); it++) //從 head_vec.begin開始印，印到 head_vec.end
				show_oneline(*it);
		}
		if (format == 4) //使用者要印四行的格式 
		{
			cout << "Four-line format:" << endl;
			for (vector<Heading>::iterator it = head_vec.begin(); it != head_vec.end(); it++)
				show_fourlines(*it);  
		}
		cout << endl << "Again? Enter<y/n>: ";
		cin >> answer;
		getchar();
	} while (answer == 'y' || answer == 'Y');
	
	system("pause");
	return 0;
}
