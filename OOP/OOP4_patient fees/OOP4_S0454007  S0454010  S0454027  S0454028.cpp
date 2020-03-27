#include<iostream>
using namespace std;

// S0454007 �L���R 
class PatientAccount{ // �إߤ@�ӥs PatientAccount�� class�s�f�H��|�ѼƩM�`��O 
    public:
        static int Days;
        static int Charges;
        PatientAccount() // constructor�]�w��� 
 		{
     		Days = 0;
     		Charges = 0;
 		}
};

int PatientAccount::Days = 0; // �s���f�H�N��ѼƩM�O���k�s 
int PatientAccount::Charges = 0;

// S0454028 �d��� 
class Surgery{ // �إߤ@�ӥs Surgery�� class�s���ؤ�N���O�ΡA�٥i��s class PatientAccount�� Charges 
	public:
		void set_surgery(string surgery)
		{
			if (surgery == "surgery1")
			{
				PatientAccount::Days++; // �C�ؤ�N���ݦ�|�@��
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

// S0454010 ��ɵ� 
class Pharmacy{ // �إߤ@�ӥs Pharmacy�� class�s�����ī~���O�ΡA�٥i��s class PatientAccount�� Charges 
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

// S0454027 ���R�z 
int main()
{
	// �Ǹ�      �m�W    �t�d���� 
	// S0454007  �L���R  class PatientAccount 
	// S0454028  �d���  class Surgery 
	// S0454010  ��ɵ�  class Pharmacy
	// S0454027  ���R�z  main
	
	// �}�o���D                   �ѨM��k
	// �խ��������D�ت���Ū���P   ���q�H�o�X���� 
	// �ܼƦW�٤��P               �H�j�h�ƪ��R�W���D 
	Surgery S1; // �ŧi�@��Surgery���s����sS1 
	Pharmacy M1; 
	char answer, ans, again;
	string x,y;
    do{
    	PatientAccount(); // �k�sDays�BCharges 
		while(1)
		{
			cout << "******************************" << endl; // �L�Xmenu 
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
    		S1.set_surgery(y); // �I�sS1��set_surgery�A�̷ӿ�J����N�W�[�ѼƤζO�� 
	
			do{
	    		cout << "Please enter a type of medication : ";
    			cin >> x;
	    		M1.get_price(x); // �I�sM1��get_price�A�̷ӿ�J���Ī��W�[�O�� 
	    		cout << "More medication ? Enter<y/n> : "; 
	    		cin >> answer;
			} while (answer == 'y' || answer == 'Y');
	
			cout << "Whether out of the hospital or not? Enter<y/n> : ";
			cin >> ans;
	
			PatientAccount::Charges += 2000 * PatientAccount::Days; // �[�W�C�Ѫ���|�O�� 
	
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
