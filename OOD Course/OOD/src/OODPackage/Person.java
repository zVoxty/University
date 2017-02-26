package OODPackage;

public class Person {
	
	public Person(String name, int age) {
		super();
		this.name = name;
		this.age = age;
	}
	
	public String name;
	public int age;
	
	@Override
	public String toString() {
		return name + " age " + age;
	}
}
