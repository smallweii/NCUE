import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class S0454028 extends JFrame implements ActionListener
{
	static S0454028 frm = new S0454028();
	//static Frame frm = new Frame("smallwei");
	//static Label lab = new Label("�p���n��");
	static JButton btn = new JButton("�p���n��");
	static Container cp = frm.getContentPane(); // ���o�����e��

	public static void main(String[] args)
	{
		cp.add(btn);
		cp.setLayout(new FlowLayout()); // �]�w���e�h�������t�m
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