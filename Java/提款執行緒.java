import java.util.*;
class CPostOffice
{
    private static int sum = 10000; // �b��즳10000��
    public synchronized static void withdraw(int n, String name)
    {
    	int temp = sum;
    	temp = temp - n;
    	try
    	{
    		Thread.sleep((int)(2000 * Math.random())); // Math.random()�|����0~1�������B�I�ƶüơA2000 * Math.random()�ܦ�0~2000�������B�I�ƶü�
    	}
    	catch(InterruptedException e){}
    	sum = temp;
    	if (sum < n)
    	    System.out.println("�l�B����!");
    	else
    		System.out.println(name + "�l�����" + n + "��,�Ѿl" + sum);
    }
}
class CCustomer extends Thread // �qThread���O�����X�l���O
{
    private String name;
    public CCustomer(String str)
    {
    	name = str;
    }
    public void run()
    {
    	for (int i = 0; i < 8; i++) // ����8���A�C���H������0-2000��
    		CPostOffice.withdraw((int)(Math.random() * 10) * 200, name);
    }
}
public class S0454028
{
	public static void main(String[] args)
    {
        CCustomer ncue = new CCustomer("���v�j");
        CCustomer road = new CCustomer("���_��");

        ncue.start(); // �إ�2�Ӱ����
        road.start();
    }
}