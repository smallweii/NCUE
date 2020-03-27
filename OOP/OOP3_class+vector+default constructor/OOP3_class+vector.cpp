#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Heading{ //建立一個叫 Heading的 class 
	 private:
 		 string company;
 		 string report;

	 public:
	 	 void set_data(string s1, string s2)
		 {  
 		 	 if (!s1[0]) //字串裡的第一個字元沒東西，表示使用者沒輸入字串名稱 
				 s1 = "ABC Industries"; //內定 company name的 default value為 ABC Industries 
			 if (!s2[0])
 				 s2 = "Report"; //內定 report name的 default value為 Report
         	 company = s1; 
 			 report = s2;
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
		string s1, s2;
		Heading head1; //建立儲存型態為 Heading的物件叫 head1 
 		vector<Heading> head_vec; //建立儲存型態為 Heading的 vector叫 head_vec 
		do{
			cout << "Please input a company name: ";
 			getline(cin, s1); //抓使用者輸入的字串，若抓到換行符號也算一個動作 
			cout << "Please input a report name: ";
 			getline(cin, s2);

 			head1.set_data(s1, s2); //把s1, s2傳到 set_data函數裡 
			head_vec.push_back(head1); //把 head1的資料 push進 head_vec裡 

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
 			for (vector<Heading>::iterator it = head_vec.begin(); it != head_vec.end(); it++)//從 head_vec.begin開始印，印到 head_vec.end 
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
