package zoo;

public class Bird extends Animal{
	public Bird(int weight,int height,int power,int skill) {
		super(weight,height,power,skill);
	}
	public void bark() {
		System.out.println("tweet!");
	}
	public void fly() {
		System.out.println("It works!");
		super.setWeight(super.getWeight()-1);
		super.setSkill(super.getSkill()+1);
	}
	
	public void eat() {
		super.setWeight(super.getWeight()+1);
		System.out.println("I'm fatter!");
	}
	
	public void walk() {
		System.out.println("It works! But I don't like it!");
	}

}
