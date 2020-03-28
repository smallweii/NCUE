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
		angle = 180.0 / 2; // 90度 
	else // 第一象限 
		angle = atan(fabs(y / x)) * 180.0 / PI; // fabs()為取絕對值，記得#include<cmath>及#define PI 3.1415926 
	
	if (x < 0 && y >= 0) // 第二象限 
		angle = 180.0 - angle;
	else if (x < 0 && y < 0) // 第三象限 
		angle = 180.0 + angle;
	else if (x > 0 && y <= 0) // 第四象限 
		angle = 2 * 180.0 - angle;
	
	return angle;
}

float GetDist(float x1, float y1, float x2, float y2) {
	float x, y, dist;
	
	x = x2 - x1;
	y = y2 - y1;
	dist = x * x + y * y;
	
	return sqrt(dist); // 開根號 
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
	
	sort(arr + 1, arr + 5); // 由小排到大 ps:sort()要#include<algorithm> 
	
	for (int i = 0; i < sizeof(arr) / sizeof(float); i++)
		cout << arr[i] << " ";
	cout << endl;
	// -----------------------------------------------------------
	cout << GetDist(x1, y1, x2, y2) << endl;
	// -----------------------------------------------------------
	system("pause");
	return 0;
}
