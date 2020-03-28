import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class S0454028
{
    public static void main(String[] args)
    {
    	JFrame frm = new JFrame("個人資料登錄");
    	Container cp = frm.getContentPane(); // 取得視窗容器
        frm.setLayout(null);

		JLabel lab1 = new JLabel("學生個人基本資料");
		lab1.setBounds(140, 15, 160, 20);
        cp.add(lab1);

		JLabel lab2 = new JLabel("姓名: ");
		lab2.setBounds(10, 80, 40, 20);
		cp.add(lab2);
		JTextField txt1 = new JTextField("王小明");
		txt1.setBounds(50, 80, 125, 20);
		cp.add(txt1);

		JLabel lab3 = new JLabel("性別: ");
		lab3.setBounds(10, 140, 40, 20);
		cp.add(lab3);
		JRadioButton rb1 = new JRadioButton("男生", true);
		rb1.setBounds(50, 140, 60, 20);
		cp.add(rb1);
		JRadioButton rb2 = new JRadioButton("女生");
		rb2.setBounds(110, 140, 60, 20);
		cp.add(rb2);
		//CheckboxGroup grp = new CheckboxGroup();
		//ckb1.setCheckboxGroup(grp); // 將ckb1加入grp群組中
		//ckb2.setCheckboxGroup(grp);
		//ckb1.setState(true); // 將ckb1設為選取狀態

		JLabel lab4 = new JLabel("系所: ");
		lab4.setBounds(10, 200, 40, 20);
		cp.add(lab4);
		String[] s = {"資訊工程系", "企業管理系", "資訊管理系", "英語系", "國文系"};
		JComboBox combo1 = new JComboBox(s);
    	combo1.setBounds(50, 200, 95, 25);
	   	cp.add(combo1);

		JLabel lab5 = new JLabel("興趣: ");
		lab5.setBounds(10, 260, 40, 20);
		cp.add(lab5);
		Checkbox ckb3 = new Checkbox("打籃球", true);
		ckb3.setBounds(50, 260, 60, 20);
		cp.add(ckb3);
		Checkbox ckb4 = new Checkbox("游泳");
		ckb4.setBounds(117, 260, 40, 20);
		cp.add(ckb4);
		Checkbox ckb5 = new Checkbox("慢跑", true);
		ckb5.setBounds(170, 260, 40, 20);
		cp.add(ckb5);

		JPanel p1 = new JPanel();
		cp.add(p1);
		JTextArea txa1 = new JTextArea(10, 30);
    	//txa1.setBounds(5, 300, 370, 80);
	   	p1.add(txa1);
		JScrollPane scr1 = new JScrollPane(txa1); // 建立垂直捲軸scr
		scr1.setBorder(BorderFactory.createTitledBorder("自我介紹"));
    	scr1.setBounds(5, 295, 375, 50);
    	cp.add(scr1);

		JButton btn = new JButton("存 檔");
		btn.setBounds(155, 360, 70, 30);
		cp.add(btn);

        frm.setSize(400, 450);
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}