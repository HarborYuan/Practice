package view;

import java.awt.Color;
import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JButton;

public class Block extends JButton{
	private int picNum;
	private int isShow;
	private int totNum;
	public int px;
	public int py;
	public int getPicNum() {
		return picNum;
	}
	public void setPicNum(int color) {
		this.picNum = color;
	}
	public int getIsShow() {
		return isShow;
	}
	public void setIsShow(int isShow) {
		this.isShow = isShow;
	}
	public int getTotNum() {
		return totNum;
	}
	public void setTotNum(int totNum) {
		this.totNum = totNum;
	}
	public Block(int picNum, int isShow, int totNum, int px, int py) {
		super();
		this.picNum = picNum;
		this.isShow = isShow;
		this.totNum = totNum;
		this.px = px;
		this.py = py;
		update();
	}
	
	public void update() {
		if (isShow==1) {
			this.setVisible(true);
			String fileName = this.getClass().getResource("/assets/photo"+picNum+".jpg").getFile();
			ImageIcon icon = new ImageIcon(fileName);
			icon.setImage(icon.getImage().getScaledInstance(500/(totNum+2), 500/(totNum+2), Image.SCALE_DEFAULT));
			this.setIcon(icon);
		}
		
		if (isShow==0) {
			this.setVisible(false);
		}
	}
}
