package OODPackage;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class Interface extends JFrame {
	private static final long serialVersionUID = -7558524138358311369L;

	public Interface(){
		JPanel panel = new JPanel(new GridBagLayout());
		
		JButton btn1 = new JButton("Homework 1");
		btn1.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				HomeworkOne h1 = new HomeworkOne(40, 10);
				h1.setSize(600, 400);
				h1.setVisible(true);
				h1.setTitle("Homework one");
				h1.Solve();
			}
		});
		
		JButton btn2 = new JButton("Homework 2");
		btn2.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				JOptionPane.showMessageDialog(null, "Comming soon !", "InfoBox", JOptionPane.INFORMATION_MESSAGE);
			}
		});
		
		JLabel label = new JLabel("OOD Application - Vasile Sebastian Costinel");
		
		GridBagConstraints bagConstraints = new GridBagConstraints();
		
		bagConstraints.insets = new Insets(10,10,10,10);
		
		bagConstraints.gridx = 0;
		bagConstraints.gridy = 1;
		panel.add(label, bagConstraints);
		
		bagConstraints.gridx = 0;
		bagConstraints.gridy = 2;
		panel.add(btn1, bagConstraints);
		
		bagConstraints.gridx = 0;
		bagConstraints.gridy = 3;
		panel.add(btn2, bagConstraints);
		
		add(panel);
	}
}
