#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream file("T24.txt", ios::in);
	if (!file) {
		cout << "Can't open the file!" << endl;
		exit(1);
	}
    int n;
    file >> n;
    
    for (int i = 0; i < n; i++){    // 記得回來改值 
        int m;   // 幾艘船
        file >> m;
        
        int time[100][2];
        
        for (int j = 0; j < m; j++){
            file >> time[j][0] >> time[j][1];  
        }
        for (int j = 0; j < m - 1; j++){
            for (int k = 0; k < m - 1 ; k ++){
                if (time[k][0] > time[k + 1][0]){
                    swap(time[k][0],time[k + 1][0]);
                    swap(time[k][1],time[k + 1][1]);
                }
                else if (time[k][0] == time[k + 1][0]){
                    if (time[k][1] < time[k + 1][1]){
                        swap(time[k][0],time[k + 1][0]);
                        swap(time[k][1],time[k + 1][1]);
                    }
                }                                   
            }
        }
        /*for (int j = 0; j < m; j++){
            cout << time[j][0] << " " << time[j][1] << endl; 
        }*/
		
		int maxleave = 0;
		
		for(int j = 0; j < m; j++){
		    if (time[j][1] > maxleave)
			    maxleave = time[j][1]; 
		}
		int harbor[101][101][2], num[101] = {0};
		bool flag[101] = {0};
		int count = 0;
		
		for (int j = 0; j < m; j++){   // 給定每個港口最長時間 
			harbor[j][0][0] = 0;
			harbor[j][0][1] = maxleave + 1;
		}
		for (int j = 0; j < m; j++){       // 跑每艘要停的船
			int sign[101] = {0}, x = 0;   // sign陣列存幾號船可以包含時間, x記有幾個港口可停 
			
			for (int k = 0; k < count + 1; k++){   // 對count + 1個港口做判斷  
				while (time[j][0] >= harbor[k][num[k]][1]){  // 若要停進來的船 進來時間 > 港口最外邊的船的離開時間  POP掉資料 
                    harbor[k][num[k]][0] = 0;
					harbor[k][num[k]][1] = 0;
					num[k]--;
				} 
				if (time[j][0] >= harbor[k][num[k]][0] && time[j][1] <= harbor[k][num[k]][1]){
					sign[x] = k;  // k : 0~count
					x++;
				} 
			}
			if (x == 1){
				num[sign[x - 1]]++;
				harbor[sign[x - 1]][num[sign[x - 1]]][0] = time[j][0];
				harbor[sign[x - 1]][num[sign[x - 1]]][1] = time[j][1];
				if (flag[sign[x - 1]]== 0){
				    flag[sign[x - 1]] = 1;
					count++;
			    }
			}else if (x != 0){
				//int min = 1000000000000;
				int chose = 0;
				
				for (int k = 0; k < x; k++){
					int y = harbor[sign[k]][num[sign[k]]][1] - time[j][1];
					/*if (y < min){
					    min = y;
				        chose = k;
					} */ 
				}
				num[sign[chose]]++;
				harbor[sign[chose]][num[sign[chose]]][0] = time[j][0];
				harbor[sign[chose]][num[sign[chose]]][1] = time[j][1];
				if (flag[sign[chose]]== 0){
				    flag[sign[chose]] = 1;
				    count++;
			    }
			}				
		}
		/*for (int k = 0; k < count + 1; k++){
				cout << k << " " ;
				for (int l = 0; l <= num[k]; l++){
					cout <<  harbor[k][l][0] << " " <<  harbor[k][l][1]  << "  " ;
			   	}
				cout << endl;
			}*/
		cout << count << endl;
    }
    file.close();
    system("pause");
    return 0;
}
