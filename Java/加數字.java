import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class S0454028 {

	static JFrame frm = new JFrame("����ƥ�B�z");
	static JTextArea txa1 = new JTextArea();
	static JScrollPane scr1 = new JScrollPane(txa1);
	static JLabel lab1 = new JLabel("�Ʀr�`�X : ");
	static JLabel lab2 = new JLabel("0");

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Container cp = frm.getContentPane(); // ���o�����e��
		frm.setLayout(null);

		scr1.setBorder(BorderFactory.createTitledBorder("�T��"));
		scr1.setBounds(20, 15, 245, 180);
		cp.add(scr1);

		lab1.setBounds(20, 210, 70, 30);
		cp.add(lab1);

		lab2.setBounds(170, 210, 100, 30);
		cp.add(lab2);

    	txa1.addKeyListener(new KeyLis());
    	frm.addWindowListener(new WinLis());

		frm.setSize(300, 300);
		frm.setVisible(true);
		// frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	static class KeyLis extends KeyAdapter {

		public void keyReleased(KeyEvent e) {

    		String str = txa1.getText(), num;
    		long sum = 0;

    		for (int i = 0; i < str.length(); i++) {
                if (Character.isDigit(str.charAt(i))) { // �P�_�r�����Ʀr
    				sum += (long)str.charAt(i) - 48; // �r��������,0��ASCLL�X��48
    			}
    		}
    		num = Long.toString(sum); // �������r��
    		lab2.setText(num);
    	}
	}

	static class WinLis extends WindowAdapter {

		public void windowClosing(WindowEvent e) {

			frm.dispose();
			System.exit(0);
		}
	}
}