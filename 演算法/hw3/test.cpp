#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cmath>
#include<algorithm>
#define PI 3.1415926
using namespace std;

float GetAngle(float x1, float y1, float x2, float y2) {
	float x, y, angle;
	
	x = x2 - x1;
	y = y2 - y1;
	
	if (x == 0)
		angle = 180.0 / 2; // 90�� 
	else // �Ĥ@�H�� 
		angle = atan(fabs(y / x)) * 180.0 / PI; // fabs()��������ȡA�O�o#include<cmath>��#define PI 3.1415926 
	
	if (x < 0 && y >= 0) // �ĤG�H�� 
		angle = 180.0 - angle;
	else if (x < 0 && y < 0) // �ĤT�H�� 
		angle = 180.0 + angle;
	else if (x > 0 && y <= 0) // �ĥ|�H�� 
		angle = 2 * 180.0 - angle;
	
	return angle;
}

float GetDist(float x1, float y1, float x2, float y2) {
	float x, y, dist;
	
	x = x2 - x1;
	y = y2 - y1;
	dist = x * x + y * y;
	
	return sqrt(dist); // �}�ڸ� 
}

int main() {
	float x1, y1, x2, y2;
	
	cout << "input two dots: ";
	cin >> x1 >> y1 >> x2 >> y2;
	cout << GetAngle(x1, y1, x2, y2) << endl;
	// -----------------------------------------------------------
	float arr[5] = {1.1, 4.4, 2.2, 6.6, 3.3};
	
	for (int i = 0; i < sizeof(arr) / sizeof(float); i++)
		cout << arr[i] << " ";
	cout << endl;
	
	sort(arr + 1, arr + 5); // �Ѥp�ƨ�j ps:sort()�n#include<algorithm> 
	
	for (int i = 0; i < sizeof(arr) / sizeof(float); i++)
		cout << arr[i] << " ";
	cout << endl;
	// -----------------------------------------------------------
	cout << GetDist(x1, y1, x2, y2) << endl;
	// -----------------------------------------------------------
	system("pause");
	return 0;
}
