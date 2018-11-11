package puzzle.view;

import java.applet.Applet;
import java.applet.AudioClip;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.URL;
import java.util.Random;
import java.util.Timer;
import java.util.TimerTask;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.border.TitledBorder;

import puzzle.DB.HandleDB;
import puzzle.handle.HandleImage;

public class MainFrame extends JFrame implements ActionListener{

	private JPanel contentPane;
	JLabel lblShow = new JLabel("");
	JPanel imagePanel = new JPanel();
	private int nums =3;
	
	HandleDB hdb = new HandleDB();
	
	private Random rand = new Random();
	private int[] numArr = null;
	private int[] testArr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	
	private int blankR = 2;
	private int blankC = 2;
	
	ImageButton [][] btnArr = null;
	
	private JButton btnMusic = new JButton("\u5F00\u542F\u97F3\u4E50");
	private JButton btnShow = new JButton("\u6E38\u620F\u8BF4\u660E");
	private JButton btnStart = new JButton("\u91CD\u65B0\u5F00\u59CB");
	private JButton btnOrder = new JButton("\u6392\u884C\u699C");
	private JLabel lblNewLabel_1 = new JLabel("\u5269\u4F59\u65F6\u95F4\uFF1A");
	private JLabel lblLeftTime = new JLabel("1200");
	private String imageName = "0.jpg";
	String []strImage = {"选择图片","图片1","图片2","图片3","图片4"};
	String []strGrade = {"选择难度","3X3","4X4","5X5"};
	JComboBox cbImage = new JComboBox(strImage);
	JComboBox cdGrid = new JComboBox(strGrade);
	private int leftTime = 1200;
	Timer timer = null;
	private AudioClip sound = null;
	
	/**
	 * Launch the application.
	 */
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

	
	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == btnMusic) {
			JButton btn =(JButton)e.getSource();
			if ("开启音乐".equals(btn.getText().trim())) {
				sound.loop();
				btn.setText("关闭音乐");
			}else {
				sound.stop();
				btn.setText("开启音乐");
			}
		} else if (e.getSource() == btnStart) {
			int n = JOptionPane.showConfirmDialog(this, "您真的要重新开始游戏吗？");
			if (n==0) {
				init();
			}
		} else if (e.getSource() == btnShow) {
			JOptionPane.showMessageDialog(this,"本游戏由武汉大学原昊博开发");
		}else if (e.getSource() == btnOrder) {
			new TimeOrderDialog(this,true); 
		}
		else {
			switchImage(e);
		}
	}
	
	public class MyTask extends TimerTask{
		public void run() {
			leftTime--;
			lblLeftTime.setText(""+leftTime);
			if (leftTime == 0) {
				lblLeftTime.setText("0");
				JOptionPane.showMessageDialog(null, "游戏时间到");
				this.cancel();
			}
		}
	}
	
	public void startThread() {
		if (timer!=null)
			timer.cancel();
		leftTime = 1200;
		timer = new Timer();
		timer.schedule(new MyTask(),1000,1000);
	}
	
	public void switchImage(ActionEvent e) {
		ImageButton btn = (ImageButton) e.getSource();
		int row = btn.getRow();
		int col = btn.getCol(); 
		
		if (Math.abs(row - blankR) + Math.abs(col -blankC) == 1) {
			int temp = btnArr[row][col].getNum();
			btnArr[row][col].setNum(btnArr[blankR][blankC].getNum());
			btnArr[blankR][blankC].setNum(temp);
			btnArr[row][col].updateImage(false);
			btnArr[blankR][blankC].updateImage(true);
			blankR = row;
			blankC = col;
			
			if (checkOrder()) {
				JOptionPane.showMessageDialog(this, "游戏成功！");
				
				int leftTime = Integer.parseInt(lblLeftTime.getText());
				int time = 1200 -leftTime;
				String name = JOptionPane.showInputDialog(this,"请输入姓名");
				if (name == null || "".equals(name.trim())) {
					name = "匿名";
				}
				hdb.insertInfo(name, time);
			}
		}
	}

	public void initNum() {
		numArr = new int [nums*nums];
		for (int i=0;i<nums*nums;i++) {
			numArr[i] = i+1;
		}
		
		for (int i=0;i<nums*nums-2;i++) {
			int n = rand.nextInt(nums*nums-i-1);
			int temp = numArr[i];
			numArr[i] = numArr[n+i+1];
			numArr[n+i+1] = temp;
		}
	}

	public void init() {
		initImage();
		initGrade();
		initNum();
		
		startThread();
		imagePanel.removeAll();
		imagePanel.setLayout(new GridLayout(nums,nums));
		btnArr = new ImageButton[nums][nums];
		
		HandleImage hi = new HandleImage();
		hi.deleteAll();
		
		long l = System.currentTimeMillis();
		String preName = String.valueOf(l);
		hi.cuttingImage(500/nums, nums, nums, preName, imageName);
		
		int k=0;
		for (int i=0;i<nums;i++) {
			for (int j=0;j<nums;j++) {
				ImageButton btn = new ImageButton(i,j,numArr[k],preName);
				k++;
				imagePanel.add(btn);
				btnArr[i][j] = btn;
				btnArr[i][j].addActionListener(this);
			}
		}
		blankR = nums-1;
		blankC = nums-1;
		btnArr[blankR][blankC].updateImage(false);
	}
	
	public boolean checkOrder() {
		int n = 1;
		for (int row=0;row<nums;row++)
			for (int col=0;col<nums;col++) {
				if (btnArr[row][col].getNum() !=n) {
					return false;
				}
				n++;
			}
		return true;
	}
	
	public void initImage() {
		int index = cbImage.getSelectedIndex();
		
		if (index == 0) {
			index = 0;
		}
		
		imageName = index+ ".jpg";
		
		URL url = this.getClass().getResource("/images/"+imageName);
		ImageIcon icon = new ImageIcon(url);
		icon.setImage(icon.getImage().getScaledInstance(200, 200, Image.SCALE_DEFAULT));
		lblShow.setIcon(icon);
	}
	
	public void initGrade() {
		int index = cdGrid.getSelectedIndex();
		
		if (index == 0 || index==1) {
			nums = 3;
		} else if (index == 2) {
			nums = 4;
		} else if (index == 3) {
			nums = 5;
		}
	}
	/**
	 * Create the frame.
	 */
	public MainFrame() {
		setTitle("\u62FC\u56FE\u6E38\u620F");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 770, 577);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		imagePanel.setBackground(Color.GRAY);
		imagePanel.setBounds(15, 15, 500, 500);
		contentPane.add(imagePanel);
		lblShow.setForeground(Color.GRAY);
		lblShow.setBackground(Color.MAGENTA);
		lblShow.setOpaque(true);
		
		lblShow.setBounds(535, 20, 210, 220);
		lblShow.setBorder(new TitledBorder(null,"样图"));
		contentPane.add(lblShow);
		
		btnMusic.setBounds(579, 408, 113, 27);
		contentPane.add(btnMusic);
		btnMusic.addActionListener(this);
		
		btnShow.setBounds(579, 448, 113, 27);
		contentPane.add(btnShow);
		btnShow.addActionListener(this);
		
		btnStart.setBounds(579, 488, 113, 27);
		contentPane.add(btnStart);
		lblNewLabel_1.setBounds(562, 250, 84, 27);
		
		contentPane.add(lblNewLabel_1);
		lblLeftTime.setForeground(Color.RED);
		lblLeftTime.setBounds(662, 250, 49, 27);
		
		contentPane.add(lblLeftTime);
		
		btnOrder.setBounds(579, 368, 113, 27);
		contentPane.add(btnOrder);
		
		cbImage.setBounds(579, 286, 113, 27);
		contentPane.add(cbImage);
		
		cdGrid.setBounds(579, 326, 113, 27);
		contentPane.add(cdGrid);
		btnOrder.addActionListener(this);
		
		btnStart.addActionListener(this);
		
		URL urlSound = this.getClass().getResource("/music/puzzle.wav"); 
		sound = Applet.newAudioClip(urlSound);
		init();
	}
}
