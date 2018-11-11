package view;

import java.applet.Applet;
import java.applet.AudioClip;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.URL;
import java.util.Timer;
import java.util.TimerTask;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;

import DB.HandleDB;
import logic.Data;

public class MainFrame extends JFrame implements ActionListener{

	private JPanel contentPane;
	JPanel LinkPanel = new JPanel();
	JButton lists = new JButton("\u6392\u884C\u699C");
	JButton music = new JButton("\u5F00\u542F\u97F3\u4E50");
	JButton start = new JButton("\u91CD\u65B0\u5F00\u59CB");
	JLabel lblNewLabel = new JLabel("\u7528\u65F6\uFF1A");
	JLabel lblNewLabel_1 = new JLabel("0");
	
	String []strGrade = {"选择难度","4X4","6X6","8X8","10X10"};
	JComboBox comboBox = new JComboBox(strGrade);
	
	Block [][] blockArr = null;
	int nums = 4;
	Data my = null;
	int gameTime = 0;
	
	boolean clicked = false;
	Block pos = null;
	
	private AudioClip sound = null;
	Timer timer = null;
	HandleDB hdb = new HandleDB();
	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == music) {
			JButton btn =(JButton)e.getSource();
			if ("开启音乐".equals(btn.getText().trim())) {
				sound.loop();
				btn.setText("关闭音乐");
			}else {
				sound.stop();
				btn.setText("开启音乐");
			}
		}else if (e.getSource() == start) {
			int n = JOptionPane.showConfirmDialog(this, "您真的要重新开始游戏吗？");
			if (n==0) {
				init();
			}
		}else if (e.getSource() == lists) {
			new TimeOrderDialog(this,true,nums); 
		} else {
			link(e);
		}
	}
	
	public class MyTask extends TimerTask{
		public void run() {
			gameTime++;
			lblNewLabel_1.setText(""+gameTime);
			if (gameTime == 0) {
				lblNewLabel_1.setText("0");
				JOptionPane.showMessageDialog(null, "游戏时间到");
				this.cancel();
			}
		}
	}
	
	public void startThread() {
		if (timer!=null)
			timer.cancel();
		gameTime = 0;
		timer = new Timer();
		timer.schedule(new MyTask(),1000,1000);
	}
	
	public void link(ActionEvent e) {
		Block btn = (Block) e.getSource();
		if (!clicked) {
			pos = btn;
			clicked = true;
			return;
		}
		if (btn == pos) {
			return;
		}
		if ((btn.getPicNum() == pos.getPicNum()) && my.Judge(btn.px,btn.py,pos.px,pos.py)) {
			my.map[btn.px][btn.py] = 0;
			my.map[pos.px][pos.py] = 0;
			btn.setIsShow(0);
			btn.update();
			btn.setPicNum(0);
			pos.setPicNum(0);
			pos.setIsShow(0);
			pos.update();
			clicked = false;
			pos = null;
			if (my.JudgeStatus()) {
				JOptionPane.showMessageDialog(this, "游戏成功！");
				
				int time = Integer.parseInt(lblNewLabel_1.getText());
				timer.cancel();
				String name = JOptionPane.showInputDialog(this,"请输入姓名");
				if (name == null || "".equals(name.trim())) {
					name = "匿名";
				}
				hdb.insertInfo(name, time, nums);
			}
			this.fresh();
		} else {
			pos = btn;
		}
	}

	public void fresh() {
		for (int i=0;i<nums+2;i++) {
			for (int j=0;j<nums+2;j++) {
				blockArr[i][j].setIsShow((my.map[i][j]!=0)? 1 : 0);
				blockArr[i][j].setPicNum(my.map[i][j]);
				blockArr[i][j].update();
			}
		}
	}
	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MainFrame frame = new MainFrame();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	
	public void init() {
		int index = comboBox.getSelectedIndex();
		if (index == 0 || index==1) {
			nums = 4;
		} else if (index == 2) {
			nums = 6;
		} else if (index == 3) {
			nums = 8;
		} else if (index == 4) {
			nums = 10;
		}
		
		this.startThread();
		my = new Data(nums,nums);
		LinkPanel.setBorder(new LineBorder(Color.GREEN, 5));
		LinkPanel.removeAll();
		LinkPanel.setLayout(new GridLayout(nums+2,nums+2));
		
		blockArr = new Block[nums+2][nums+2];
		
		for (int i=0;i<nums+2;i++) {
			for (int j=0;j<nums+2;j++) {
				Block btn = new Block(my.map[i][j],(my.map[i][j]!=0)? 1 : 0 , nums , i , j);
				LinkPanel.add(btn);
				blockArr[i][j] = btn;
				blockArr[i][j].addActionListener(this);
			}
		}
		my.JudgeStatus();
		this.fresh();
		LinkPanel.setVisible(false);
		LinkPanel.setVisible(true);
	}
	
	public MainFrame() {
		this.setTitle("连连看");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 787, 572);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		LinkPanel.setBounds(14, 13, 500, 500);
		contentPane.add(LinkPanel);
		
		
		lists.setBounds(600, 292, 113, 27);
		contentPane.add(lists);
		lists.addActionListener(this);
		
		
		music.setBounds(600, 345, 113, 27);
		contentPane.add(music);
		music.addActionListener(this);
		
		
		start.setBounds(600, 399, 113, 27);
		contentPane.add(start);
		start.addActionListener(this);
		
		comboBox.setBounds(600, 238, 113, 27);
		contentPane.add(comboBox);
		
		
		lblNewLabel.setFont(new Font("宋体", Font.PLAIN, 25));
		lblNewLabel.setBounds(585, 171, 94, 58);
		contentPane.add(lblNewLabel);
		
		lblNewLabel_1.setFont(new Font("宋体", Font.PLAIN, 25));
		lblNewLabel_1.setForeground(Color.RED);
		lblNewLabel_1.setBounds(661, 187, 94, 27);
		contentPane.add(lblNewLabel_1);
		
		JLabel label = new JLabel("\u8FDE\u8FDE\u770B");
		label.setFont(new Font("宋体", Font.PLAIN, 30));
		label.setForeground(Color.GREEN);
		label.setBounds(600, 26, 94, 147);
		contentPane.add(label);
		
		URL urlSound = this.getClass().getResource("/assets/link.wav"); 
		sound = Applet.newAudioClip(urlSound);
		init();
	}
}
