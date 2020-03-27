#include<iostream>
using namespace std;

class PatientAccount{ // �إߤ@�ӥs PatientAccount�� class�s�f�H��|�ѼƩM�`��O 
	public:
		static int Days;
		static int Charges;
		PatientAccount() // default constructor
		{
			Days = 0;
			Charges = 0;
		}
};
int PatientAccount::Days = 0; // �s���f�H�N��ѼƩM�O���k�s 
int PatientAccount::Charges = 0;

class Surgery{ // �إߤ@�ӥs Surgery�� class�s���ؤ�N���O�ΡA�٥i��s class PatientAccount�� Charges 
	public:
		int set_surgery(string surgery)
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
class Pharmacy{ // �إߤ@�ӥs Pharmacy�� class�s�����ī~���O�ΡA�٥i��s class PatientAccount�� Charges 
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
	PatientAccount p1; // �ŧi�@�� PatientAccount������s p1 
	Surgery s1; // �ŧi�@�� Surgery������s s1 
	Pharmacy m1; // �ŧi�@�� Pharmacy������s m1 
	
	do{
		PatientAccount(p1); // �k�s Days�BCharges 
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
	
		do{
			cout << "Please enter a type of surgery: ";
			cin >> surgery;
			s1.set_surgery(surgery); // �I�s s1�� set_surgery�A�̷ӿ�J����N�W�[�ѼƤζO�� 
			do{
				cout << "Please enter a type of medication: ";
				cin >> medication;
				m1.set_medication(medication); // �I�s m1�� set_medication�A�̷ӿ�J���Ī��W�[�O�� 
				cout << "More medication? Enter<y/n>: "; // �i�̿�Jy/n�ӧP�_�O�_�~�򭫽ƿ�J 
				cin >> answer;
			} while (answer == 'y' || answer == 'Y'); // �u�n��Jy/Y�j��N�i�~����� 
			
			cout << "Does the patient check out of the hospital? Enter<y/n>: ";
			cin >> answer;
			PatientAccount::Charges += 2000 * PatientAccount::Days; // �[�W�C�Ѫ���|�O�� 
		} while (answer == 'n' || answer == 'N');
		
		cout << "Total charges: " << PatientAccount::Charges << endl;
		cout << "More patient? Enter<y/n>: ";
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');
	
	system("pause");
	return 0;
}
