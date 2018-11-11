package puzzle.DB;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class DBdriver {
	
	public static Connection conn = null;
	
	public static void myClose(Connection conn, Statement stat , ResultSet rs) {
		if (rs!=null) {
			try {
				rs.close();
				rs=null;
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		
		if (stat!=null) {
			try {
				stat.close();
				stat=null;
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		
		if (conn!=null) {
			try {
				conn.close();
				conn = null;
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
	}
	
	public static Connection getConn() {
		try {
			Class.forName("com.mysql.jdbc.Driver");
			String url = "jdbc:mysql://whuyhb.cn/JavaProject?characterEncoding=utf8&useSSL=true";
	        String user = "JavaProject";
	        String password = "javajava";
			conn =  DriverManager.getConnection(url,user,password);
			return conn;
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}
	
	public static void main() {
		 
	}

}
