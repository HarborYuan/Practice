package puzzle.view;

import javax.swing.ImageIcon;
import javax.swing.JButton;

public class ImageButton extends JButton{
	
	private int row;
	private int col;
	private int num;
	private String preName;
	public int getRow() {
		return row;
	}
	public void setRow(int row) {
		this.row = row;
	}
	public int getCol() {
		return col;
	}
	public void setCol(int col) {
		this.col = col;
	}
	public int getNum() {
		return num;
	}
	public void setNum(int num) {
		this.num = num;
	}
	public String getPreName() {
		return preName;
	}
	public void setPreName(String preName) {
		this.preName = preName;
	}
	public ImageButton(int row, int col, int num, String preName) {
		super();
		this.row = row;
		this.col = col;
		this.num = num;
		this.preName = preName;
		
		updateImage(true);
	}
	
	public void updateImage(boolean isShow) {
		if (isShow) {
			String fileName = this.getClass().getResource("/images/subimage/"+preName+"_"+num+".jpg").getFile();
			ImageIcon icon = new ImageIcon(fileName);
			this.setIcon(icon);
		}else {
			this.setIcon(null);
		}
	}
}
