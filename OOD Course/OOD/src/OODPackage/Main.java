package OODPackage;

import javax.swing.JFrame;

public class Main{
	
	public static void main(String[] args) {
		
		Interface gui = new Interface();
		gui.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		gui.setSize(800, 600);
		gui.setVisible(true);
		gui.setTitle("OOD");

	}

}
