import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*;

public class S0454028 {

	static JFrame frm = new JFrame("個人資料登錄");
	static JLabel lab1 = new JLabel("學生個人基本資料");
	static JLabel lab2 = new JLabel("學號: ");
	static JTextField txt1 = new JTextField();
	static JLabel lab3 = new JLabel("姓名: ");
	static JTextField txt2 = new JTextField();
	static JLabel lab4 = new JLabel("性別: ");
	static JRadioButton rb1 = new JRadioButton("男生");
	static JRadioButton rb2 = new JRadioButton("女生");
	static ButtonGroup bg1 = new ButtonGroup();
	static JLabel lab5 = new JLabel("地址: ");
	static String[] s = {"台北市", "台中市", "台南市", "高雄市"};
	static JComboBox combo1 = new JComboBox(s);
	static JButton btn1 = new JButton("新增存檔");
	static JButton btn2 = new JButton("顯示檔案內容");
	static JTextArea txa1 = new JTextArea();
	static JScrollPane scr1 = new JScrollPane(txa1);
	static String str;

    public static void main(String[] args) { //throws IOException {

    	Container cp = frm.getContentPane(); // 取得視窗容器
        frm.setLayout(null);

		lab1.setBounds(140, 20, 160, 20);
        cp.add(lab1);

		lab2.setBounds(20, 60, 40, 20);
		cp.add(lab2);
		txt1.setBounds(60, 60, 100, 20);
		cp.add(txt1);

		lab3.setBounds(200, 60, 40, 20);
		cp.add(lab3);
		txt2.setBounds(240, 60, 100, 20);
		cp.add(txt2);

		lab4.setBounds(20, 120, 40, 20);
		cp.add(lab4);
		rb1.setBounds(60, 120, 55, 20);
		cp.add(rb1);
		rb2.setBounds(115, 120, 55, 20);
		cp.add(rb2);
		bg1.add(rb1);
     	bg1.add(rb2);

		lab5.setBounds(200, 120, 40, 20);
		cp.add(lab5);
    	combo1.setBounds(240, 120, 90, 30);
	   	cp.add(combo1);

		btn1.setBounds(40, 180, 130, 30);
		cp.add(btn1);

		btn2.setBounds(200, 180, 130, 30);
		cp.add(btn2);

		//txa1.setBounds(20, 230, 345, 165);
	   	//cp.add(txa1);
		scr1.setBorder(BorderFactory.createTitledBorder(""));
    	scr1.setBounds(20, 230, 345, 165);
    	cp.add(scr1);

		btn1.addActionListener(new ActLis());
		btn2.addActionListener(new ActLis());
    	frm.addWindowListener(new WinLis());

        frm.setSize(400, 450);
        frm.setVisible(true);
        //frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //FileReader fr = new FileReader(str); // 讀檔
        //BufferedReader bfr = new BufferedReader(fr);


        //fr.close();

    }

    static class ActLis implements ActionListener {

    	public void actionPerformed(ActionEvent e) {

    		String gender = rb1.getText(); // 男生

    		if (rb2.isSelected()) // 女生
    			gender = rb2.getText();

			if (e.getSource() == btn1) { // 新增存檔
				try
				{
					str = txt1.getText()+","+txt2.getText()+","+gender+","+combo1.getSelectedItem();
				}
				catch
				{
					FileWriter fw = new FileWriter("D:\\java.txt"); // 寫檔
        			BufferedWriter bfw = new BufferedWriter(fw);

        			bfw.write(str); // 寫入字串到緩衝區
    				bfw.newLine(); // 寫入換行符號
        			bfw.flush(); // 將緩衝區內的資料寫到檔案裡

        			fw.close();
				}
			}

    		if (e.getSource() == btn2) // 顯示檔案內容
    			txa1.append(str+"\r\n"); // 附加字串至每行後面
    	}
    }

    static class WinLis extends WindowAdapter {

		public void windowClosing(WindowEvent e) {

			frm.dispose();
			System.exit(0);
		}
	}
}