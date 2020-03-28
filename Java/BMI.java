import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class S0454028
{
    static JFrame frm = new JFrame("BMI指數計算");
    static JLabel lab1 = new JLabel("BMI指數計算");
    static JLabel lab2 = new JLabel("身高(cm) : ");
    static JTextField txt1 = new JTextField();
    static JLabel lab3 = new JLabel("體重(kg) : ");
    static JTextField txt2 = new JTextField();
    static JLabel lab4 = new JLabel("診斷結果 : ");
    static JLabel lab5 = new JLabel();
    static JButton btn1 = new JButton("看結果");

    public static void main(String[] args)
    {
    	Container cp = frm.getContentPane(); // 取得視窗容器
        frm.setLayout(null);

		lab1.setBounds(120, 20, 100, 20);
        cp.add(lab1);

		lab2.setBounds(50, 60, 100, 20);
		cp.add(lab2);

		txt1.setBounds(115, 60, 100, 20);
		cp.add(txt1);

		lab3.setBounds(50, 100, 100, 20);
		cp.add(lab3);

		txt2.setBounds(115, 100, 100, 20);
		cp.add(txt2);

		lab4.setBounds(50, 140, 100, 20);
		cp.add(lab4);

		lab5.setBounds(115, 140, 200, 20);
		cp.add(lab5);

		btn1.setBounds(105, 180, 100, 30);
		cp.add(btn1);

		Actlis actlis = new Actlis();
		btn1.addActionListener(actlis);

		Winlis winlis = new Winlis();
    	frm.addWindowListener(winlis);

        frm.setSize(325, 300);
        frm.setVisible(true);
        //frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    static class Actlis implements ActionListener
    {
    	public void actionPerformed(ActionEvent e)
    	{
    		if (e.getSource() == btn1)
    		{
    			float h, w, b;
    			h = Float.parseFloat(txt1.getText()) / 100;
    			w = Float.parseFloat(txt2.getText());
    			b = w / h / h;

            	if (b < 18.5)
    				lab5.setText("BMI = " + b + " (體重過輕)");
				else if (b < 24)
    				lab5.setText("BMI = " + b + " (正常範圍)");
				else if (b < 27)
    				lab5.setText("BMI = " + b + " (過重)");
				else if (b < 30)
    				lab5.setText("BMI = " + b + " (輕度肥胖)");
				else if (b < 35)
    				lab5.setText("BMI = " + b + " (中度肥胖)");
				else
    				lab5.setText("BMI = " + b + " (重度肥胖)");

    			if (18.5 <= b && b < 24)
    				lab5.setForeground(Color.blue); // 正常範圍以藍色顯示
    			else
    				lab5.setForeground(Color.red); // 其他以紅色顯示
    		}
    	}
    }
    static class Winlis extends WindowAdapter
    {
    	public void windowClosing(WindowEvent e)
    	{
    		frm.dispose();
    		System.exit(0);
    	}
    }
}