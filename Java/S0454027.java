//姓名 : 楊靜慧(S0454027)
//作答情形 :
import java.util.*;
public class Q1 {
    public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
            String str = scanner.nextLine();
        	StringTokenizer st = new StringTokenizer(str);
            int n = st.countTokens();
            int a[] = new int[n];
            int t = 0;
            while (st.hasMoreTokens()) {
                a[t] = Integer.parseInt(st.nextToken());
                t++;
            }
            if (a[0] == 1){
            	long num = a[1];
		    	long f1 = 0, f2 = 1, sum = 0;
		    	if (a[1] == 1)
		    		System.out.print("1");
		    	else if(a[1] == 0)
		    		System.out.print("0");
		    	else{
		    		for (int i = 2; i <= num; i++){
            	        sum = f1 + f2;
            	        f1 = f2;
                    	f2 = sum;
                    }
                    System.out.print(sum);
		    	}
            }
            if (a[0] == 2){
            	int arr[] = new int[20];
            	int i, j, s;
            	for (i = a[1];; i++){
            		for (j = 2; j < i; j++){
            			if (i % j == 0)
            				break;
            		}
            		if (i == j){
            			int k = i, p = 0;
            			while(k / 10 != 0){
            				arr[p] = k % 10;
            				p++;
            				k = k / 10;
            			}
            			arr[p] = k;
            			int leng = p;
            			if (leng % 2 == 0){ // aba
            				for (s = 0; s < leng / 2; s++){
            				    if (arr[s] == arr[p])
            				    	p--;
            				    else
            				    	break;
            			    }
            			    if (s == p){
            			    	System.out.print(i);
            					break;
            			    }

            			}
            			else { // ab
            				for (s = 0; s < leng / 2; s++){
            					if (arr[s] == arr[p])
            						p--;
            					else
            						break;
            				}
            				if (s == p + 1){
            					System.out.print(i);
            					break;
            				}
            			}
            		}
            	}
            }
            if (a[0] == 3){
            	int i, j;
            	for (i = a[1];;i++){
            		for (j = 0; j <= i; j++){
            			if (j*j == i){
            				System.out.print(i);
            				break;
            			}
            		}
            		if (j*j == i)
            			break;
            	}
            }
            if (a[0] == 4){
            	for (int i = a[1];;i++){
            		int sum = 0;
            		for (int j = 1; j < i; j++){
            			if (i % j == 0)
            				sum = sum + j;
            		}
            			if (sum > i){
            			System.out.print(i);
            			break;
            		}
                }
           }
      }
}
