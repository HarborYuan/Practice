package zoo;

public class Dog extends Animal {
	
	public Dog(int weight,int height,int power,int skill) {
		super(weight,height,power,skill);
	}
	public void bark() {
		System.out.println("Woof!");
	}
	public void fly() {
		System.out.println("Sorry, dogs can't fly!");
	}
	
	public void eat() {
		super.setWeight(super.getWeight()+1);
		System.out.println("I'm fatter");
	}
}
