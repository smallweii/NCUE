import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*;

public class S0454028 {

	static JFrame frm = new JFrame("�ӤH��Ƶn��");
	static JLabel lab1 = new JLabel("�ǥͭӤH�򥻸��");
	static JLabel lab2 = new JLabel("�Ǹ�: ");
	static JTextField txt1 = new JTextField();
	static JLabel lab3 = new JLabel("�m�W: ");
	static JTextField txt2 = new JTextField();
	static JLabel lab4 = new JLabel("�ʧO: ");
	static JRadioButton rb1 = new JRadioButton("�k��");
	static JRadioButton rb2 = new JRadioButton("�k��");
	static ButtonGroup bg1 = new ButtonGroup();
	static JLabel lab5 = new JLabel("�a�}: ");
	static String[] s = {"�x�_��", "�x����", "�x�n��", "������"};
	static JComboBox combo1 = new JComboBox(s);
	static JButton btn1 = new JButton("�s�W�s��");
	static JButton btn2 = new JButton("����ɮפ��e");
	static JTextArea txa1 = new JTextArea();
	static JScrollPane scr1 = new JScrollPane(txa1);
	static String str;

    public static void main(String[] args) { //throws IOException {

    	Container cp = frm.getContentPane(); // ���o�����e��
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

        //FileReader fr = new FileReader(str); // Ū��
        //BufferedReader bfr = new BufferedReader(fr);


        //fr.close();

    }

    static class ActLis implements ActionListener {

    	public void actionPerformed(ActionEvent e) {

    		String gender = rb1.getText(); // �k��

    		if (rb2.isSelected()) // �k��
    			gender = rb2.getText();

			if (e.getSource() == btn1) { // �s�W�s��
				try
				{
					str = txt1.getText()+","+txt2.getText()+","+gender+","+combo1.getSelectedItem();
				}
				catch
				{
					FileWriter fw = new FileWriter("D:\\java.txt"); // �g��
        			BufferedWriter bfw = new BufferedWriter(fw);

        			bfw.write(str); // �g�J�r���w�İ�
    				bfw.newLine(); // �g�J����Ÿ�
        			bfw.flush(); // �N�w�İϤ�����Ƽg���ɮ׸�

        			fw.close();
				}
			}

    		if (e.getSource() == btn2) // ����ɮפ��e
    			txa1.append(str+"\r\n"); // ���[�r��ܨC��᭱
    	}
    }

    static class WinLis extends WindowAdapter {

		public void windowClosing(WindowEvent e) {

			frm.dispose();
			System.exit(0);
		}
	}
}