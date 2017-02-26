package OODPackage;

import java.awt.BorderLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.util.ArrayList;
import java.util.Random;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class HomeworkOne extends JFrame {
	
	private static final long serialVersionUID = 1721343645594846834L;

	public HomeworkOne(int oldestThan, int numberOfPersons) {
		super();
		this.oldestThan = oldestThan;
		this.numberOfPersons = numberOfPersons;
		
		generatePersons();
	}
	
	private int oldestThan;
	private int numberOfPersons;
	
	Random randomGenerator = new Random();
	
	ArrayList<String> personNames = new ArrayList<String>();
	ArrayList<Person> persons = new ArrayList<Person>();
	ArrayList<Person> oldestThanNumber = new ArrayList<Person>();
	
	public void generatePersons(){
		personNames.add("John");
		personNames.add("Ken");
		personNames.add("Raphael");
		personNames.add("Alex");
		personNames.add("James");
		
		for (int i = 0; i < numberOfPersons; i++) {
			int indexPersonName = randomGenerator.nextInt(personNames.size());
			int ageGenerated = randomGenerator.nextInt(100);
			
			persons.add(new Person(personNames.get(indexPersonName), ageGenerated));
		}
	}
	
	public String solveFirstProblem(){
		Person oldestPerson = new Person("0", 0);
		
		for (Person person : persons) {
			if(person.age > oldestPerson.age){
				oldestPerson = person;
			}
		}
		
		return oldestPerson.toString();
	}
	
	public String solveSecondProblem(){
		String result = new String();
		
		for (Person person : persons) {
			if(person.age > oldestThan){
				oldestThanNumber.add(person);
				result += " " + person + ",";
			}
		}
		
		return result;
	}
	
	public void Solve(){
		JPanel panel = new JPanel(new GridBagLayout());
		
		GridBagConstraints g = new GridBagConstraints();
		g.insets = new Insets(10, 10, 10, 10);
		
		g.gridx = 0;
		g.gridy = 1;
		JLabel fProb = new JLabel(" << First Problem >> ");
		panel.add(fProb, g);
		
		g.gridx = 0;
		g.gridy = 2;
		String sPersons = new String();
		for (Person person : persons) {
			sPersons += " " + person + ",";
		}
		JLabel sPersonsLabel = new JLabel("Generated persons are : " + sPersons);
		panel.add(sPersonsLabel, g);
		
		g.gridx = 0;
		g.gridy = 3;
		JLabel result1  = new JLabel("Oldest person is : " + solveFirstProblem());
		panel.add(result1, g);
		
		g.gridx = 0;
		g.gridy = 4;
		JLabel sProb = new JLabel(" << Second Problem >> ");
		panel.add(sProb, g);
		
		g.gridx = 0;
		g.gridy = 5;
		JLabel result2  = new JLabel("Oldest persons than age " + oldestThan + " are : " + solveSecondProblem());
		panel.add(result2, g);
		
		add(panel, BorderLayout.NORTH);
	}
}
