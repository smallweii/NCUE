import java.util.*;
class CSphere {
    private int x; // ��ߪ�x �y��
    private int y; // ��ߪ�y �y��
    private int z; // ��ߪ�z �y��
    private double radius; // ��y���b�|

    public CSphere(int a, int b, int c, double r) // ���޼ƪ��غc��
    {
    	x=a;
    	y=b;
    	z=c;
    	radius=r;
    }
    public double distance(CSphere cir) // �Ǧ^2�Ӳy���ߤ������Z��
    {
    	return Math.sqrt((this.x - cir.x)*(this.x - cir.x) + (this.y - cir.y)*(this.y - cir.y) + (this.z - cir.z)*(this.z - cir.z));
    }
    public boolean isIntersect(CSphere cir) // �P�_2�Ӳy��O�_�|�IĲ�A��2�Ӳy���ߪ��Z��<=2�y�b�|���M�ɡA��2�y�Y���IĲ������
    {
        boolean touch;
        if (this.distance(cir) <= (this.radius + cir.radius))
        	touch = true;
        else
        	touch = false;
        return touch;
    }
    public void show()
    {
    	System.out.println("x="+x+", y="+y+", z="+z+", radius="+radius);
    }
}
public class S0454028 {
	public static void main(String[] args) { // �إߤG�ӷs���y�骫��A�L�X2�Ӳy���ߤ������Z���çP�_2�Ӳy��O�_�|�IĲ
		CSphere cir1 = new CSphere(7,4,5,2);
		CSphere cir2 = new CSphere(6,2,8,3);

		cir1.show();
		cir2.show();

		System.out.println("2�y��ߪ��Z�� = "+cir1.distance(cir2));
		System.out.print("2�y");
		if (cir1.isIntersect(cir2) == true)
			System.out.print("��");
		else
			System.out.print("�S��");
		System.out.print("�IĲ");
	}
}