package puzzle.view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.border.EmptyBorder;

import puzzle.DB.HandleDB;
import puzzle.entity.TimeOrder;

public class TimeOrderDialog extends JDialog {

	private final JPanel contentPanel = new JPanel();

	/**
	 * Launch the application.
	 */
	
	
	/*public static void main(String[] args) {
		try {
			TimeOrderDialog dialog = new TimeOrderDialog();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	*/
	/**
	 * Create the dialog.
	 */
	public TimeOrderDialog(MainFrame parent, boolean notShow) {
		super(parent,notShow);
		this.setTitle("显示排行榜");
		setBounds(100, 100, 450, 300);
		this.setLocationRelativeTo(parent);
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		contentPanel.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("\u6392\u884C\u699C");
		lblNewLabel.setForeground(Color.RED);
		lblNewLabel.setFont(new Font("宋体", Font.PLAIN, 21));
		lblNewLabel.setBounds(177, 13, 70, 34);
		contentPanel.add(lblNewLabel);
		
		JTextArea taResult = new JTextArea();
		taResult.setBackground(Color.LIGHT_GRAY);
		taResult.setEditable(false);
		taResult.setBounds(14, 55, 404, 148);
		contentPanel.add(taResult);
		{
			JPanel buttonPane = new JPanel();
			buttonPane.setLayout(new FlowLayout(FlowLayout.RIGHT));
			getContentPane().add(buttonPane, BorderLayout.SOUTH);
			{
				JButton okButton = new JButton("OK");
				okButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent arg0) {
						dispose();
					}
				});
				okButton.setActionCommand("OK");
				buttonPane.add(okButton);
				getRootPane().setDefaultButton(okButton);
			}
			{
				JButton cancelButton = new JButton("Cancel");
				cancelButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						dispose();
					}
				});
				
				HandleDB hdb = new HandleDB();
				ArrayList<TimeOrder> al = hdb.selectInfo();
				if (al.size()==0) {
					taResult.setText("暂时没有游戏记录");
				} else {
					for (int i=0;i<al.size();i++) {
						TimeOrder to = al.get(i);
						taResult.append("第"+(i+1)+"名\t"+to.getName()+"\t"+to.getTime()+"\r\n");
					}
				}
				
				cancelButton.setActionCommand("Cancel");
				buttonPane.add(cancelButton);
			}
		}
		this.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
		this.setVisible(true);
	}
}
