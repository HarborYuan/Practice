package view;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.Random;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.Color;

public class MyPanel extends JFrame{

	
	
	JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MyPanel frame = new MyPanel();
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
	public MyPanel() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBackground(Color.WHITE);
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		contentPane.addMouseMotionListener(new Deal(this));
	}

}


class Deal extends MouseAdapter {

	@Override
	public void mouseMoved(MouseEvent e) {
		// TODO Auto-generated method stub
		super.mouseMoved(e);
		Random random = new Random();
		int x = random.nextInt(256);
		int y = random.nextInt(256);
		int z = random.nextInt(256);
		this.pan.contentPane.setBackground(new Color(x,y,z));
	}
	
	
	private MyPanel pan = null;
	public Deal(MyPanel pan) {
		this.pan = pan;
	}
}
