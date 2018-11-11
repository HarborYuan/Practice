package puzzle.DB;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

import puzzle.entity.TimeOrder;

public class HandleDB {
	
	private Connection conn = null;
	private PreparedStatement stat = null;
	private ResultSet rs = null;
	
	public ArrayList<TimeOrder> selectInfo() {
		ArrayList<TimeOrder> al = new ArrayList();
		
		String sql = "select * from puzzle order by time asc limit 5";
		
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
	
	public void insertInfo(String name,int time) {
		conn = DBdriver.getConn();
		
		String sql = "select count(*) from puzzle where time<="+time;
		try {
			stat = conn.prepareStatement(sql);
			rs = stat.executeQuery();
			if (rs.next()) {
				int n = rs.getInt(1);
				if (n<=4) {
					sql = "insert into puzzle(name,time) values('"+name+"',"+time+")";
					stat = conn.prepareStatement(sql);
					stat.executeUpdate();
				}
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		
	}

}
