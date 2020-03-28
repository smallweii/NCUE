import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class S0454028 extends JFrame implements ActionListener
{
	static S0454028 frm = new S0454028();
	//static Frame frm = new Frame("smallwei");
	//static Label lab = new Label("小維好高");
	static JButton btn = new JButton("小維好高");
	static Container cp = frm.getContentPane(); // 取得視窗容器

	public static void main(String[] args)
	{
		cp.add(btn);
		cp.setLayout(new FlowLayout()); // 設定內容層的版面配置
		cp.setBackground(Color.green);
		btn.addActionListener(frm);
		frm.setTitle("smallwei");
		frm.setSize(300, 300);
		//frm.setBackground(Color.green);
		frm.setLocation(150, 150);
		//frm.add(lab);
		frm.setVisible(true);
	}
	public void actionPerformed(ActionEvent e)
	{
		if (cp.getBackground() == Color.green)
			cp.setBackground(Color.pink);
		else
			cp.setBackground(Color.green);
	}
}