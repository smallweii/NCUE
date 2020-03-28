import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class S0454028
{
    static JFrame frm = new JFrame("BMI���ƭp��");
    static JLabel lab1 = new JLabel("BMI���ƭp��");
    static JLabel lab2 = new JLabel("����(cm) : ");
    static JTextField txt1 = new JTextField();
    static JLabel lab3 = new JLabel("�魫(kg) : ");
    static JTextField txt2 = new JTextField();
    static JLabel lab4 = new JLabel("�E�_���G : ");
    static JLabel lab5 = new JLabel();
    static JButton btn1 = new JButton("�ݵ��G");

    public static void main(String[] args)
    {
    	Container cp = frm.getContentPane(); // ���o�����e��
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
    				lab5.setText("BMI = " + b + " (�魫�L��)");
				else if (b < 24)
    				lab5.setText("BMI = " + b + " (���`�d��)");
				else if (b < 27)
    				lab5.setText("BMI = " + b + " (�L��)");
				else if (b < 30)
    				lab5.setText("BMI = " + b + " (���תέD)");
				else if (b < 35)
    				lab5.setText("BMI = " + b + " (���תέD)");
				else
    				lab5.setText("BMI = " + b + " (���תέD)");

    			if (18.5 <= b && b < 24)
    				lab5.setForeground(Color.blue); // ���`�d��H�Ŧ����
    			else
    				lab5.setForeground(Color.red); // ��L�H�������
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