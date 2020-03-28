import java.util.*;
class CSphere {
    private int x; // 圓心的x 座標
    private int y; // 圓心的y 座標
    private int z; // 圓心的z 座標
    private double radius; // 圓球的半徑

    public CSphere(int a, int b, int c, double r) // 有引數的建構元
    {
    	x=a;
    	y=b;
    	z=c;
    	radius=r;
    }
    public double distance(CSphere cir) // 傳回2個球體圓心之間的距離
    {
    	return Math.sqrt((this.x - cir.x)*(this.x - cir.x) + (this.y - cir.y)*(this.y - cir.y) + (this.z - cir.z)*(this.z - cir.z));
    }
    public boolean isIntersect(CSphere cir) // 判斷2個球體是否會碰觸，當2個球體圓心的距離<=2球半徑之和時，此2球即有碰觸的情形
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
	public static void main(String[] args) { // 建立二個新的球體物件，印出2個球體圓心之間的距離並判斷2個球體是否會碰觸
		CSphere cir1 = new CSphere(7,4,5,2);
		CSphere cir2 = new CSphere(6,2,8,3);

		cir1.show();
		cir2.show();

		System.out.println("2球圓心的距離 = "+cir1.distance(cir2));
		System.out.print("2球");
		if (cir1.isIntersect(cir2) == true)
			System.out.print("有");
		else
			System.out.print("沒有");
		System.out.print("碰觸");
	}
}