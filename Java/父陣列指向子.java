import java.util.*;
class CShape // 父類別CShape
{
    public double area()
    {
        return 0.0;
    }
}
class CCircle extends CShape // 改寫了父類別的area() method，可用來傳回圓形物件的面積
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
class CSquare extends CShape // 改寫了父類別的area() method，可用來傳回正方形物件的面積
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
class CTriangle extends CShape // 改寫了父類別的area() method，可用來傳回三角形物件的面積
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
	public static void main(String[] args) // 建立圓形、正方形與三角形物件各兩個，並印出個別的面積
    {
		CShape shp[]=new CShape[6]; // 所有的子類別物件均是由父類別的陣列變數指向它
        shp[0]=new CCircle(2.0);
        shp[1]=new CCircle(3.0);
        shp[2]=new CSquare(4.0);
        shp[3]=new CSquare(5.0);
        shp[4]=new CTriangle(3.0,3.0);
        shp[5]=new CTriangle(5.0,4.0);

        System.out.println("面積1 = "+shp[0].area());
        System.out.println("面積2 = "+shp[1].area());
        System.out.println("面積3 = "+shp[2].area());
        System.out.println("面積4 = "+shp[3].area());
        System.out.println("面積5 = "+shp[4].area());
        System.out.println("面積6 = "+shp[5].area());

		System.out.println("面積最大 = "+largest(shp));
	}
	public static double largest(CShape shp[]) // 找出並印出所有物件裡面積的最大值
	{
		double max = 0.0;

		for (int i = 0; i < 6; i++)
			if (shp[i].area() >= max)
				max = shp[i].area();
        return max;
	}
}