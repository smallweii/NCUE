import java.sql.*;

public class S0454028 
{ 
  public static void main(String[] args) 
  { 
    try
    { 
      Class.forName("net.ucanaccess.jdbc.UcanaccessDriver"); // Load the JDBC driver
      Connection con = DriverManager.getConnection("jdbc:ucanaccess://c:/java/db2.mdb");//Connect to the databse
      System.out.println("��Ʈw�s�u���զ��\�I"); 
      
      Statement stmt=con.createStatement(); 
      ResultSet rs=stmt.executeQuery("select * from students where stud_addr = '����' and stud_sex = 'M'");       
      while(rs.next())
      {
        String stud_no=rs.getString(1);
        String stud_name=rs.getString(2);
        String stud_sex=rs.getString("stud_sex");
        String stud_addr=rs.getString("stud_addr");
        System.out.println(stud_no+","+stud_name+","+stud_sex+","+stud_addr); 
      }
      con.close(); 
    } 
    catch(ClassNotFoundException e) 
    { 
      System.out.println("�䤣���X�ʵ{�����O"); 
      e.printStackTrace(); 
    } 
    catch(SQLException e) 
    { 
      e.printStackTrace(); 
    } 
  } 
}