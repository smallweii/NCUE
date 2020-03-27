#include<iostream>
#include<string>
using namespace std;

void sort(struct Student *stu, int n);
float average(struct Student *std, int n);

struct Student{
		string name;
		int score;
		int number;
	};//建立一個名為Student的結構，成員有以string為型態的name、以int為型態的score和number
int main()
{
	int n;
	char answer;
	
	do {
		cout << "How many pairs do you want to test? ";
		cin >> n;
		
		Student *stu;//結構指標指到動態記憶體配置的位置 
		stu = new Student[n];//新要的空間，代表動態記憶體配置 
		if (!stu)//沒要到空間，代表記憶體配置失敗  
		{
			cout << "Memory allocation error!" << endl;
			exit(1);//在不正常情形下，中斷程式的執行  
		}
		for (int i = 0; i < n; i++)//輸入學生們的名字和成績 
		{
			stu[i].number = i + 1;
			cout << "Please enter Student" << i + 1 << "'s name: ";
			cin >> stu[i].name;
			cout << "Please enter Student" << i + 1 << "'s score: ";
			cin >> stu[i].score;
			
			while (stu[i].score < 0)//避免使用者輸入負數的成績，要為非負數才能進入以下函式 
			{
				cout << stu[i].score << " is a nagetive number!" << endl;
				cout << "Please enter Student" << i + 1 << "'s score: ";//若為負數，要求使用者重新輸入成績 
				cin >> stu[i].score;
			}
		}
		sort(stu, n);//進入sort函式來從小到大排序 
		cout << endl << "After sort:" << endl;
		for (int i = 0; i < n; i++)
			cout << "Student" << stu[i].number << " "<< stu[i].name << " : " << stu[i].score << endl;
		cout << endl << "The average score is " << average(stu, n) << endl;//進入average函式來計算平均成績 
		delete [] stu;//還空間 
		stu = NULL;//記憶體已被利用完，故把指標指向NULL 
		
		cout << endl << "Do you want to test it again? <enter y/n>: ";//可依輸入y/n來判斷是否繼續重複輸入 
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');//只要輸入Y/y迴圈就可繼續執行 
		
	system("pause");
	return 0;
}
void sort(struct Student *stu, int n)
{
	for (int j = 0; j < n; j++)
		for(int i = 0; i < n - 1; i++)
		{
			if (stu[i + 1].score < stu[i].score)//若後面 < 前面(名字 分數)就一起交換 
			{
				Student temp = stu[i + 1];
				stu[i + 1] = stu[i];
				stu[i] = temp;
			}
		}
}
float average(struct Student *stu, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += stu[i].score;
    float ave = (float)sum / n;
    return ave;
}
