package use_class;

public class Rectangle extends Shape{
	public double a;
	public double b;
	
	public Rectangle(double a,double b) {
		this.a = a;
		this.b = b;
	}
	
	public double Count() {
		return this.a*this.b;
	}
}
