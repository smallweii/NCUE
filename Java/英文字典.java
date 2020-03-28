import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.print.attribute.standard.PrinterLocation;
import javax.swing.*;

public class S0454028 
{ 
  static JFrame frm = new JFrame("電子字典");
  static JLabel lab1 = new JLabel("電   子   字   典");
  static JLabel lab2 = new JLabel("英文單字：");
  static JTextField txt1 = new JTextField();
  static JButton btn1 = new JButton("查  詢");
  static JLabel lab3 = new JLabel("中        文：");
  static JLabel lab4 = new JLabel();
  static JLabel lab5 = new JLabel("例        句：");
  static JLabel lab6 = new JLabel();
	  
  public static void main(String[] args) 
  { 
	Container cp = frm.getContentPane(); // 取得視窗容器
    frm.setLayout(null);
    
    lab1.setBounds(230, 10, 80, 20);
    cp.add(lab1);
    
    lab2.setBounds(10, 40, 80, 20);
    cp.add(lab2);
    
    txt1.setBounds(90, 40, 185, 20);
    cp.add(txt1);
    
    btn1.setBounds(290, 40, 70, 20);
    cp.add(btn1);
    
    lab3.setBounds(10, 80, 80, 20);
    cp.add(lab3);
    
    lab4.setBounds(90, 80, 300, 20);
    cp.add(lab4);
    
    lab5.setBounds(10, 130, 80, 20);
    cp.add(lab5);
    
    lab6.setBounds(90, 130, 650, 20);
    cp.add(lab6);
    
    btn1.addActionListener(new ActLis());
    txt1.addActionListener(new ActLis());
    frm.addWindowListener(new WinLis());
    
    frm.setSize(750, 240);
    frm.setVisible(true);
    //frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  }
  
  static class ActLis implements ActionListener
  {
  	public void actionPerformed(ActionEvent e)
  	{
  	  if (e.getSource() == btn1)
  	  {
  		String no = "", id = "", pwd = "", name = "";
  		try
        { 
          Class.forName("net.ucanaccess.jdbc.UcanaccessDriver"); // Load the JDBC driver
          Connection con = DriverManager.getConnection("jdbc:ucanaccess://D:/java/dictionary.mdb"); // Connect to the databse
          //System.out.println("資料庫連線測試成功！"); 
      
          Statement stmt = con.createStatement(); 
          ResultSet rs = stmt.executeQuery("select * from dictionary");       
          while(rs.next())
          {
            no = rs.getString("識別碼");
            id = rs.getString("id");
            pwd = rs.getString("pwd");
            name = rs.getString("name");
            
            if (txt1.getText().compareTo(id) == 0) // =0兩字串相等
  	        {
              lab4.setText(pwd);
  	          lab4.setForeground(Color.blue);
  	          lab6.setText(name);
  	          lab6.setForeground(Color.blue);
  	        }
  	        else if (txt1.getText().compareTo(id) == 1) // =1後字串比較小
  	        {
  	          lab4.setText("查無此單字!");
    	      lab4.setForeground(Color.red);
    	      lab6.setText("");
  	        }
            //System.out.println(no+","+id+","+pwd+","+name); 
          }
          con.close(); 
        } 
        catch(ClassNotFoundException ioException)
        { 
          //System.out.println("找不到驅動程式類別"); 
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