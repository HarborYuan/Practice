package zoo;

public abstract class Animal {
	private int weight;
	private int height;
	private int power;
	private int skill;
	
	public Animal(int weight,int height,int power,int skill) {
		this.weight=weight;
		this.height=height;
		this.power=power;
		this.skill=skill;
	}
	
	public void walk() {
		this.skill++;
		this.weight--;
		System.out.println("It works!");
	}
	
	public abstract void bark();
	public abstract void fly();
	public abstract void eat();
	
	public int getWeight() {
		return weight;
	}
	
	public void setWeight(int weight) {
		this.weight = weight;
	}
	
	public int getHeight() {
		return height;
	}
	
	public void setHeight(int height) {
		this.height = height;
	}
	
	public int getPower() {
		return power;
	}
	
	public void setPower(int power) {
		this.power = power;
	}
	
	public int getSkill() {
		return skill;
	}
	
	public void setSkill(int skill) {
		this.skill = skill;
	}
}
