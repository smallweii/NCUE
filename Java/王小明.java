import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class S0454028
{
    public static void main(String[] args)
    {
    	JFrame frm = new JFrame("�ӤH��Ƶn��");
    	Container cp = frm.getContentPane(); // ���o�����e��
        frm.setLayout(null);

		JLabel lab1 = new JLabel("�ǥͭӤH�򥻸��");
		lab1.setBounds(140, 15, 160, 20);
        cp.add(lab1);

		JLabel lab2 = new JLabel("�m�W: ");
		lab2.setBounds(10, 80, 40, 20);
		cp.add(lab2);
		JTextField txt1 = new JTextField("���p��");
		txt1.setBounds(50, 80, 125, 20);
		cp.add(txt1);

		JLabel lab3 = new JLabel("�ʧO: ");
		lab3.setBounds(10, 140, 40, 20);
		cp.add(lab3);
		JRadioButton rb1 = new JRadioButton("�k��", true);
		rb1.setBounds(50, 140, 60, 20);
		cp.add(rb1);
		JRadioButton rb2 = new JRadioButton("�k��");
		rb2.setBounds(110, 140, 60, 20);
		cp.add(rb2);
		//CheckboxGroup grp = new CheckboxGroup();
		//ckb1.setCheckboxGroup(grp); // �Nckb1�[�Jgrp�s�դ�
		//ckb2.setCheckboxGroup(grp);
		//ckb1.setState(true); // �Nckb1�]��������A

		JLabel lab4 = new JLabel("�t��: ");
		lab4.setBounds(10, 200, 40, 20);
		cp.add(lab4);
		String[] s = {"��T�u�{�t", "���~�޲z�t", "��T�޲z�t", "�^�y�t", "���t"};
		JComboBox combo1 = new JComboBox(s);
    	combo1.setBounds(50, 200, 95, 25);
	   	cp.add(combo1);

		JLabel lab5 = new JLabel("����: ");
		lab5.setBounds(10, 260, 40, 20);
		cp.add(lab5);
		Checkbox ckb3 = new Checkbox("���x�y", true);
		ckb3.setBounds(50, 260, 60, 20);
		cp.add(ckb3);
		Checkbox ckb4 = new Checkbox("��a");
		ckb4.setBounds(117, 260, 40, 20);
		cp.add(ckb4);
		Checkbox ckb5 = new Checkbox("�C�]", true);
		ckb5.setBounds(170, 260, 40, 20);
		cp.add(ckb5);

		JPanel p1 = new JPanel();
		cp.add(p1);
		JTextArea txa1 = new JTextArea(10, 30);
    	//txa1.setBounds(5, 300, 370, 80);
	   	p1.add(txa1);
		JScrollPane scr1 = new JScrollPane(txa1); // �إ߫������bscr
		scr1.setBorder(BorderFactory.createTitledBorder("�ۧڤ���"));
    	scr1.setBounds(5, 295, 375, 50);
    	cp.add(scr1);

		JButton btn = new JButton("�s ��");
		btn.setBounds(155, 360, 70, 30);
		cp.add(btn);

        frm.setSize(400, 450);
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}