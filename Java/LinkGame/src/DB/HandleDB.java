package DB;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

import struct.TimeOrder;


public class HandleDB {
	
	private Connection conn = null;
	private PreparedStatement stat = null;
	private ResultSet rs = null;
	
	public ArrayList<TimeOrder> selectInfo(int grade) {
		ArrayList<TimeOrder> al = new ArrayList();
		
		String sql = "select * from link where grade="+grade+" order by time asc limit 5";
		
		conn = DBdriver.getConn();
		try {
			stat = conn.prepareStatement(sql);
			rs = stat.executeQuery();
			while (rs.next()) {
				int id = rs.getInt(1);
				String name = rs.getString(2);
				int time = rs.getInt(3);
				
				TimeOrder to =  new TimeOrder(id,name,time);
				al.add(to);
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return al;
	}
	
	public void insertInfo(String name,int time,int grade) {
		conn = DBdriver.getConn();
		try {
		String sql = "insert into link(name,time,grade) values('"+name+"',"+time+","+grade+")";
		stat = conn.prepareStatement(sql);
		stat.executeUpdate();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		
	}
}
