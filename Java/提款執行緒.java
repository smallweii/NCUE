import java.util.*;
class CPostOffice
{
    private static int sum = 10000; // 帳戶原有10000元
    public synchronized static void withdraw(int n, String name)
    {
    	int temp = sum;
    	temp = temp - n;
    	try
    	{
    		Thread.sleep((int)(2000 * Math.random())); // Math.random()會產生0~1之間的浮點數亂數，2000 * Math.random()變成0~2000之間的浮點數亂數
    	}
    	catch(InterruptedException e){}
    	sum = temp;
    	if (sum < n)
    	    System.out.println("餘額不足!");
    	else
    		System.out.println(name + "郵局領取" + n + "元,剩餘" + sum);
    }
}
class CCustomer extends Thread // 從Thread類別延伸出子類別
{
    private String name;
    public CCustomer(String str)
    {
    	name = str;
    }
    public void run()
    {
    	for (int i = 0; i < 8; i++) // 提款8次，每次隨機扣除0-2000元
    		CPostOffice.withdraw((int)(Math.random() * 10) * 200, name);
    }
}
public class S0454028
{
	public static void main(String[] args)
    {
        CCustomer ncue = new CCustomer("彰師大");
        CCustomer road = new CCustomer("光復路");

        ncue.start(); // 建立2個執行緒
        road.start();
    }
}