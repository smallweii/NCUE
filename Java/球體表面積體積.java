import java.util.*;
class CSphere {
    private int x; // 圓心的x 座標
    private int y; // 圓心的y 座標
    private int z; // 圓心的z 座標
    private int radius; // 圓球的半徑
    double pi = 3.14;

    void setLocation(int x, int y, int z) // 設定圓球之圓心的位置
    {
    	this.x = x;
    	this.y = y;
    	this.z = z;
    }
    void setRadius(int r) // 設定圓球之半徑
    {
    	radius = r;
    }
    double surfaceArea() // 傳回CSphere 物件的表面積(4πr2)
    {
    	return 4 * pi * radius * radius;
    }
    double volume() // 傳回CSphere 物件的體積(4/3πr3)
    {
    	return (double)4 / 3 * pi * radius * radius * radius;
    }
    void showCenter() // 顯示CSphere 物件之圓心座標
    {
    	System.out.println("x="+x+", y="+y+", z="+z);
    }
}
public class S0454028 {
    public static void main(String[] args) {
        CSphere cs = new CSphere(); // 建立一個圓球物件，設定球體的中心點(3,4,5)及半徑(2)，並顯示球體的中心點、表面積及體積

        cs.setLocation(3,4,5);
        cs.setRadius(2);
        cs.showCenter();

        System.out.println("surface area="+cs.surfaceArea());
        System.out.println("volume="+cs.volume());
    }
}
