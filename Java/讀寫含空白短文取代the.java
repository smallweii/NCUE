import java.util.*;
import java.io.*;
public class S0454028
{
	public static void main(String[] args) throws IOException
    {
    	FileReader fr = new FileReader("C:\\file_practice_2.txt"); // 讀檔
        BufferedReader bfr = new BufferedReader(fr);

        FileWriter fw = new FileWriter("C:\\out2.txt"); // 寫檔
        BufferedWriter bfw = new BufferedWriter(fw);

	    String str = bfr.readLine(); // 每次讀一行，此檔案只有一行
        System.out.println("此篇短文的字元數(含空白)共有 " + str.length());

        int space = 0, count = 0;
        for (int i = 0; i < str.length(); i++)
           	if (str.charAt(i) == ' ')
           	    space++;
        System.out.println("不含空白的字元數共有 " + (str.length() - space));

        String s[] = str.split(" "); // 將字串切割成陣列(多個空白會切成多個陣列元素)
        for (int i = 0; i < s.length; i++)
        	if (s[i].equals("the") == true) // 比較s[i]裡的字串是否與 " the " 相同
        		count++;
	    System.out.println("共有 " + count + " 個字串被取代");

        String replacedstr = str.replaceAll("the", "THE"); // 把短文內所有的字串 " the " 以 " THE " 取代
        bfw.write(replacedstr); // 寫入字串到緩衝區

    	bfw.flush(); // 將緩衝區內的資料寫到檔案裡
    	fr.close(); // 關檔
    	fw.close(); // 關檔
    }
}