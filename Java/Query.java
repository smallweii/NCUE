import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.print.attribute.standard.PrinterLocation;
import javax.swing.*;
import javax.swing.table.*;

public class S0454028 
{ 
  static JFrame frm = new JFrame("DB Query");
  static JLabel lab1 = new JLabel("SQL : ");
  static JTextField txt1 = new JTextField();
  static JButton btn1 = new JButton("Query");
  static DefaultTableModel tableModel = new DefaultTableModel();
  static JTable tab1 = new JTable();
  static String[] rowData = new String[4];
  static JScrollPane scr1 = new JScrollPane(tab1);
  
  public static void main(String[] args) 
  { 
	Container cp = frm.getContentPane(); // ���o�����e��
    frm.setLayout(null);  
    
    tab1.setModel(tableModel); 
    tableModel.addColumn("�Ǹ�");
    tableModel.addColumn("�m�W");
    tableModel.addColumn("�ʧO");
    tableModel.addColumn("�a�}");
    
    lab1.setBounds(10, 15, 80, 20);
    cp.add(lab1);
    txt1.setBounds(50, 10, 250, 30);
    cp.add(txt1);
    btn1.setBounds(295, 10, 75, 30);
    cp.add(btn1);
    //scr1.setBorder(BorderFactory.createTitledBorder(""));
	scr1.setBounds(40, 50, 300, 350);
    cp.add(scr1);
    
    btn1.addActionListener(new ActLis());
    txt1.addActionListener(new ActLis());
    frm.addWindowListener(new WinLis());
    
    frm.setSize(420, 460);
    frm.setVisible(true);
    //frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  }
  
  static class ActLis implements ActionListener
  {
  	public void actionPerformed(ActionEvent e)
  	{
  	
    if (e.getSource() == btn1)
  	{
      try
        { 
          Class.forName("net.ucanaccess.jdbc.UcanaccessDriver"); // Load the JDBC driver
          Connection con = DriverManager.getConnection("jdbc:ucanaccess://c:/db2.mdb"); // Connect to the databse
          //System.out.println("��Ʈw�s�u���զ��\�I"); 
      
          Statement stmt = con.createStatement(); 
          String str = txt1.getText();
          ResultSet rs = stmt.executeQuery(str);
          tableModel.setRowCount(0); // �M�ŦC
          while(rs.next())
          {
        	  rowData[0] = rs.getString(1);
              rowData[1] = rs.getString(2);
              rowData[2] = rs.getString(3);
              rowData[3] = rs.getString(4);
              tableModel.addRow(rowData);
          }
          con.close(); 
        } 
        catch(ClassNotFoundException ioException)
        { 
          //System.out.println("�䤣���X�ʵ{�����O"); 
          ioException.printStackTrace();
        } 
        catch(SQLException ioException) 
        { 
          ioException.printStackTrace();
        }
  	  }
  	}
  }
  
  static class WinLis extends WindowAdapter
  {
	public void windowClosing(WindowEvent e)
	{
	  frm.dispose();
	  System.exit(0);
	}
  }
}