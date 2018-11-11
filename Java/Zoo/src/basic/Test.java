package basic;

public class Test {

	public static void main(String[] args) {
		Rectangle[] a = new Rectangle[30];
		Triangle[] b = new Triangle[30];
		Circle[] c = new Circle[30];
		double total = 0;
		for(int i = 0; i < 30 ; i ++) {
			a[i] = new Rectangle(30,40);
			total += a[i].Count();
		}
		
		for(int i = 0; i < 30 ; i ++) {
			b[i] = new Triangle(30,40,50);
			total += b[i].Count();
		}
		
		for(int i = 0; i < 30 ; i ++) {
			c[i] = new Circle(30);
			total += c[i].Count();
		}
		System.out.println(total);

	}

}
