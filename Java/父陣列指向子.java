import java.util.*;
class CShape // �����OCShape
{
    public double area()
    {
        return 0.0;
    }
}
class CCircle extends CShape // ��g�F�����O��area() method�A�i�ΨӶǦ^��Ϊ��󪺭��n
{
	private double pi = 3.14;
    private double radius;

    public CCircle(double r)
    {
        radius = r;
    }
    public double area()
    {
        return pi * radius * radius;
    }
}
class CSquare extends CShape // ��g�F�����O��area() method�A�i�ΨӶǦ^����Ϊ��󪺭��n
{
	private double edge;

	public CSquare(double e)
	{
		edge = e;
	}
	public double area()
    {
        return edge * edge;
    }
}
class CTriangle extends CShape // ��g�F�����O��area() method�A�i�ΨӶǦ^�T���Ϊ��󪺭��n
{
	private double bottom, height;

	public CTriangle(double b, double h)
	{
		bottom = b;
		height = h;
	}
	public double area()
    {
        return (bottom * height) / 2;
    }
}
public class S0454028
{
	public static void main(String[] args) // �إ߶�ΡB����λP�T���Ϊ���U��ӡA�æL�X�ӧO�����n
    {
		CShape shp[]=new CShape[6]; // �Ҧ����l���O���󧡬O�Ѥ����O���}�C�ܼƫ��V��
        shp[0]=new CCircle(2.0);
        shp[1]=new CCircle(3.0);
        shp[2]=new CSquare(4.0);
        shp[3]=new CSquare(5.0);
        shp[4]=new CTriangle(3.0,3.0);
        shp[5]=new CTriangle(5.0,4.0);

        System.out.println("���n1 = "+shp[0].area());
        System.out.println("���n2 = "+shp[1].area());
        System.out.println("���n3 = "+shp[2].area());
        System.out.println("���n4 = "+shp[3].area());
        System.out.println("���n5 = "+shp[4].area());
        System.out.println("���n6 = "+shp[5].area());

		System.out.println("���n�̤j = "+largest(shp));
	}
	public static double largest(CShape shp[]) // ��X�æL�X�Ҧ�����̭��n���̤j��
	{
		double max = 0.0;

		for (int i = 0; i < 6; i++)
			if (shp[i].area() >= max)
				max = shp[i].area();
        return max;
	}
}