import java.util.*;
import java.io.*;
public class S0454028
{
	public static void main(String[] args) throws IOException
    {
    	FileReader fr = new FileReader("C:\\file_practice.txt"); // 讀檔
        BufferedReader bfr = new BufferedReader(fr);

        FileWriter fw = new FileWriter("C:\\out.txt"); // 寫檔
        BufferedWriter bfw = new BufferedWriter(fw);

        String str;
        while ((str = bfr.readLine()) != null) // 每次讀一行，直到檔案結束
        {
        	StringTokenizer st = new StringTokenizer(str);
			int n = st.countTokens(); // 計算Token數(多個空白不會切成多個陣列元素)
			int arr[] = new int[n];
			int i = 0;
			while (st.hasMoreTokens())
			{
  				arr[i] = Integer.parseInt(st.nextToken());
  				i++;
			}

        	double sum = 0;
        	for (int j = 0; j < n; j++)
        		sum += arr[j];

        	double ave = sum / n;
        	bfw.write(Double.toString(ave)); // 寫入字串到緩衝區
        	bfw.newLine(); // 寫入換行符號
        }

    	bfw.flush(); // 將緩衝區內的資料寫到檔案裡
    	fr.close(); // 關檔
    	fw.close(); // 關檔
    }
}