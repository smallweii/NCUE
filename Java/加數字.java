import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class S0454028 {

	static JFrame frm = new JFrame("按鍵事件處理");
	static JTextArea txa1 = new JTextArea();
	static JScrollPane scr1 = new JScrollPane(txa1);
	static JLabel lab1 = new JLabel("數字總合 : ");
	static JLabel lab2 = new JLabel("0");

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Container cp = frm.getContentPane(); // 取得視窗容器
		frm.setLayout(null);

		scr1.setBorder(BorderFactory.createTitledBorder("訊息"));
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
                if (Character.isDigit(str.charAt(i))) { // 判斷字元為數字
    				sum += (long)str.charAt(i) - 48; // 字元轉長整數,0的ASCLL碼為48
    			}
    		}
    		num = Long.toString(sum); // 長整數轉字串
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