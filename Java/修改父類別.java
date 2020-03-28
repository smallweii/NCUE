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
		CCircle cir1=new CCircle(2.0);
        CCircle cir2=new CCircle(3.0);
        CSquare squ1=new CSquare(4.0);
        CSquare squ2=new CSquare(5.0);
        CTriangle tri1=new CTriangle(3.0,3.0);
        CTriangle tri2=new CTriangle(5.0,4.0);

        System.out.println("面積1 = "+cir1.area());
        System.out.println("面積2 = "+cir2.area());
        System.out.println("面積3 = "+squ1.area());
        System.out.println("面積4 = "+squ2.area());
        System.out.println("面積5 = "+tri1.area());
        System.out.println("面積6 = "+tri2.area());

        double arr[] = new double[6];
		arr[0] = cir1.area();
		arr[1] = cir2.area();
		arr[2] = squ1.area();
		arr[3] = squ2.area();
		arr[4] = tri1.area();
		arr[5] = tri2.area();

		System.out.println("面積最大 = "+largest(arr));
	}
	public static double largest(double arr[]) // 找出並印出所有物件裡面積的最大值
	{
		double max = 0.0;

		for (int i = 0; i < 6; i++)
			if (arr[i] >= max)
				max = arr[i];
        return max;
	}
}