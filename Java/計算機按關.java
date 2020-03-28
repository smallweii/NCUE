import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class S0454028
{
    static JFrame frm = new JFrame("­pºâ¾÷");
    static Container cp = frm.getContentPane();

    static JTextField txt1 = new JTextField();
    static JButton btn1 = new JButton("1");
    static JButton btn2 = new JButton("2");
    static JButton btn3 = new JButton("3");
    static JButton btn4 = new JButton("4");
    static JButton btn5 = new JButton("5");
    static JButton btn6 = new JButton("6");
    static JButton btn7 = new JButton("7");
    static JButton btn8 = new JButton("8");
    static JButton btn9 = new JButton("9");

    public static void main(String[] args)
    {
    	txt1.setHorizontalAlignment(JLabel.RIGHT); // ´å¼Ð¾a¥k
    	frm.setSize(205, 225);
        frm.setLayout(null);

    	cp.add(txt1);
    	cp.add(btn1);
    	cp.add(btn2);
    	cp.add(btn3);
    	cp.add(btn4);
    	cp.add(btn5);
    	cp.add(btn6);
    	cp.add(btn7);
    	cp.add(btn8);
    	cp.add(btn9);

    	txt1.setBounds(20, 5, 150, 20);
    	btn1.setBounds(20, 30, 50, 50);
    	btn2.setBounds(70, 30, 50, 50);
    	btn3.setBounds(120, 30, 50, 50);
    	btn4.setBounds(20, 80, 50, 50);
    	btn5.setBounds(70, 80, 50, 50);
    	btn6.setBounds(120, 80, 50, 50);
    	btn7.setBounds(20, 130, 50, 50);
    	btn8.setBounds(70, 130, 50, 50);
    	btn9.setBounds(120, 130, 50, 50);

    	Actlis actlis = new Actlis();
    	btn1.addActionListener(actlis);
    	btn2.addActionListener(actlis);
    	btn3.addActionListener(actlis);
    	btn4.addActionListener(actlis);
    	btn5.addActionListener(actlis);
    	btn6.addActionListener(actlis);
    	btn7.addActionListener(actlis);
    	btn8.addActionListener(actlis);
    	btn9.addActionListener(actlis);

    	Winlis winlis = new Winlis();
    	frm.addWindowListener(winlis);

        frm.setVisible(true);
    }
    static class Actlis implements ActionListener
    {
    	public void actionPerformed(ActionEvent e)
    	{
    		if (e.getSource() == btn1)
    			txt1.setText("1");
    		if (e.getSource() == btn2)
    			txt1.setText("2");
    		if (e.getSource() == btn3)
    			txt1.setText("3");
    		if (e.getSource() == btn4)
    			txt1.setText("4");
    		if (e.getSource() == btn5)
    			txt1.setText("5");
    		if (e.getSource() == btn6)
    			txt1.setText("6");
    		if (e.getSource() == btn7)
    			txt1.setText("7");
    		if (e.getSource() == btn8)
    			txt1.setText("8");
    		if (e.getSource() == btn9)
    			txt1.setText("9");
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