package zoo;

public class Test {

	public static void main(String[] args) {
		Dog lei = new Dog(100,50,24,10);
		Bird bo = new Bird(20,10,10,50);
		Cat han = new Cat(100,50,15,8);
		Mouse s = new Mouse(10,5,5,40);
		
		bo.bark();
		bo.eat();
		bo.fly();
		bo.walk();
		System.out.println();
		lei.bark();
		lei.eat();
		lei.fly();
		lei.walk();
		System.out.println();
		s.bark();
		s.eat();
		s.fly();
		s.walk();
		System.out.println();
		han.bark();
		han.eat();
		han.fly();
		han.walk();
	}

}
