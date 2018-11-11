package zoo;

public class Mouse extends Animal{
	public Mouse(int weight,int height,int power,int skill) {
		super(weight,height,power,skill);
	}
	public void bark() {
		System.out.println("Squeek!");
	}
	public void fly() {
		System.out.println("Sorry, mice can't fly!");
	}
	
	public void eat() {
		super.setWeight(super.getWeight()+1);
		System.out.println("I'm fatter!");
	}

}
