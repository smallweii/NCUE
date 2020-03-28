import java.util.*;
class CSphere {
    private int x; // ��ߪ�x �y��
    private int y; // ��ߪ�y �y��
    private int z; // ��ߪ�z �y��
    private int radius; // ��y���b�|
    double pi = 3.14;

    void setLocation(int x, int y, int z) // �]�w��y����ߪ���m
    {
    	this.x = x;
    	this.y = y;
    	this.z = z;
    }
    void setRadius(int r) // �]�w��y���b�|
    {
    	radius = r;
    }
    double surfaceArea() // �Ǧ^CSphere ���󪺪��n(4�kr2)
    {
    	return 4 * pi * radius * radius;
    }
    double volume() // �Ǧ^CSphere ������n(4/3�kr3)
    {
    	return (double)4 / 3 * pi * radius * radius * radius;
    }
    void showCenter() // ���CSphere ���󤧶�߮y��
    {
    	System.out.println("x="+x+", y="+y+", z="+z);
    }
}
public class S0454028 {
    public static void main(String[] args) {
        CSphere cs = new CSphere(); // �إߤ@�Ӷ�y����A�]�w�y�骺�����I(3,4,5)�Υb�|(2)�A����ܲy�骺�����I�B���n����n

        cs.setLocation(3,4,5);
        cs.setRadius(2);
        cs.showCenter();

        System.out.println("surface area="+cs.surfaceArea());
        System.out.println("volume="+cs.volume());
    }
}
