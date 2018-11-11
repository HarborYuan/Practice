package view;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.Color;
import javax.swing.JTextArea;
import javax.swing.JTextPane;
import javax.swing.JComboBox;
import javax.swing.JToggleButton;
import javax.swing.SwingConstants;

public class MyThirdFrame extends JFrame implements ActionListener{

	
	JFrame myFrame = new JFrame();
	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == button) {
			String s1 = textField.getText();
			String s2 = textField_1.getText();
			int num,tot;
			try {
				tot = Integer.parseInt(s1);
				num = Integer.parseInt(s2);
			}catch (Exception ee) {
				JOptionPane.showMessageDialog(myFrame,"输入错误请重新输入!");
				return;
			}
			
			if (tot < num) {
				JOptionPane.showMessageDialog(myFrame,"输入错误请重新输入!");
				return;
			}
			String tmp = "2016300030";
			boolean [] test = new boolean[tot];
			Random random = new Random();
			int j = num;
			while (j > 0) {
				int x = random.nextInt(tot);
				if (!test[x]) {
					j = j - 1;
					test[x] = true;
				}
			}
			lblNewLabel_2.setText("<html>");
			for (int i=0;i<tot;i++) {
				if (test[i]) {
					String ttt=new String();
					switch(String.valueOf(i).length()) {
					case 1: ttt = "00"; break;
					case 2: ttt = "0"; break;
					case 3: ttt = ""; break;
					}
					lblNewLabel_2.setText(lblNewLabel_2.getText()+tmp+ttt+i+"<br>");
				}
			}
			lblNewLabel_2.setText(lblNewLabel_2.getText()+"</html>");
		}
		if (e.getSource() == button_1) {
			lblNewLabel_2.setText("");
		}
	}

	JPanel contentPane;
	JTextField textField;
	JTextField textField_1;
	JButton button = new JButton("\u62BD\u67E5");
	JLabel lblNewLabel = new JLabel("\u73ED\u7EA7\u4EBA\u6570");
	JLabel lblNewLabel_1 = new JLabel("\u62BD\u67E5\u4EBA\u6570");
	JLabel lblNewLabel_2 = new JLabel("");
	JButton button_1 = new JButton("\u6E05\u9664");

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MyThirdFrame frame = new MyThirdFrame();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public MyThirdFrame() {
		setTitle("\u62BD\u67E5\u5C0F\u7A0B\u5E8F3");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 444, 722);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		button.setBounds(70, 619, 113, 27);
		contentPane.add(button);
		button.addActionListener(this);
		
		textField = new JTextField();
		textField.setBounds(244, 46, 86, 24);
		contentPane.add(textField);
		textField.setColumns(10);
		
		lblNewLabel.setBounds(70, 49, 72, 18);
		contentPane.add(lblNewLabel);
		
		lblNewLabel_1.setBounds(70, 113, 72, 18);
		contentPane.add(lblNewLabel_1);
		
		textField_1 = new JTextField();
		textField_1.setBounds(244, 110, 86, 24);
		contentPane.add(textField_1);
		textField_1.setColumns(10);
		
		lblNewLabel_2.setBackground(Color.WHITE);
		lblNewLabel_2.setOpaque(true);
		lblNewLabel_2.setVerticalAlignment(SwingConstants.TOP);
		lblNewLabel_2.setBounds(70, 190, 260, 400);
		contentPane.add(lblNewLabel_2);
		
		button_1.setBounds(217, 619, 113, 27);
		contentPane.add(button_1);
		button_1.addActionListener(this);
	}
}