package use_class;

public class Test {

	public static void main(String[] args) {
		Shape[] a = new Shape[90];
		double total = 0;
		for (int i = 0; i < 30; i++) {
			a[i] = new Circle(20);
			total += a[i].Count();
 		}
		
		for (int i = 30; i < 60; i++) {
			a[i] = new Triangle(30,40,50);
			total += a[i].Count();
		}
		
		for (int i = 60; i < 90; i++) {
			a[i] = new Rectangle(30,40);
			total += a[i].Count();
		}
		System.out.println(total);

	}

}
