import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class S0454028 {

	static JFrame frm = new JFrame("四則運算");
	static JLabel lab1 = new JLabel("四則運算");
	static JTextField txt1 = new JTextField();
	static String[] s = {"+", "-", "*", "/"};
	static JComboBox combo1 = new JComboBox(s);
	static JTextField txt2 = new JTextField();
	static JLabel lab2 = new JLabel();
	static int n1, n2, sum = 0;
	static float d_sum = 0;

    public static void main(String[] args) {

    	Container cp = frm.getContentPane(); // 取得視窗容器
        frm.setLayout(null);

		lab1.setBounds(120, 20, 100, 20);
        cp.add(lab1);
        
		txt1.setBounds(50, 60, 50, 20);
		cp.add(txt1);

    	combo1.setBounds(120, 60, 50, 20);
	   	cp.add(combo1);
		
		txt2.setBounds(190, 60, 50, 20);
		cp.add(txt2);
		
		lab2.setBounds(120, 100, 150, 20);
		cp.add(lab2);
		
		txt1.addKeyListener(new KeyLis());
		txt2.addKeyListener(new KeyLis());
		combo1.addItemListener(new ItemLis());
    	frm.addWindowListener(new WinLis());

        frm.setSize(300, 200);
        frm.setVisible(true);
        //frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    static class KeyLis extends KeyAdapter {

		public void keyReleased(KeyEvent e) {
			
			n1 = Integer.parseInt(txt1.getText());
    		n2 = Integer.parseInt(txt2.getText());
    		
    		if (combo1.getSelectedItem() == "+")
    		    sum = n1 + n2;
    		if (combo1.getSelectedItem() == "-")
    		    sum = n1 - n2;
    		if (combo1.getSelectedItem() == "*")
    		    sum = n1 * n2;
    		lab2.setText(n1 + " " + combo1.getSelectedItem() + " " + n2 + " = " + sum);
    		   
    		if (combo1.getSelectedItem() == "/") {
    			sum = n1 / n2;
    		    d_sum = (float)n1 / n2;
    		    
    		    if (sum == d_sum) // 整除
    		        lab2.setText(n1 + " " + combo1.getSelectedItem() + " " + n2 + " = " + sum);
    		    else
    		    	lab2.setText(n1 + " " + combo1.getSelectedItem() + " " + n2 + " = " + d_sum);
    		}
    		lab2.setForeground(Color.blue);
    	}
	}

    static class ItemLis implements ItemListener {
    	
        public void itemStateChanged(ItemEvent e) {
        	
           if (e.getStateChange() == ItemEvent.SELECTED) {
        	   n1 = Integer.parseInt(txt1.getText());
       	       n2 = Integer.parseInt(txt2.getText());
       		
       		   if (combo1.getSelectedItem() == "+")
       		       sum = n1 + n2;
       		   if (combo1.getSelectedItem() == "-")
       		       sum = n1 - n2;
       		   if (combo1.getSelectedItem() == "*")
       		       sum = n1 * n2;
       		   lab2.setText(n1 + " " + combo1.getSelectedItem() + " " + n2 + " = " + sum);
       		   
       		   if (combo1.getSelectedItem() == "/") {
    			   sum = n1 / n2;
    		       d_sum = (float)n1 / n2;
    		    
    		       if (sum == d_sum) // 整除
    		          lab2.setText(n1 + " " + combo1.getSelectedItem() + " " + n2 + " = " + sum);
    		       else
    		    	  lab2.setText(n1 + " " + combo1.getSelectedItem() + " " + n2 + " = " + d_sum);
    		   }
       		   lab2.setForeground(Color.blue);
           }
        }
    }

    static class WinLis extends WindowAdapter {

		public void windowClosing(WindowEvent e) {

			frm.dispose();
			System.exit(0);
		}
	}
}