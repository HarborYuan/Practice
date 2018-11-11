package use_interface;

public class Rectangle implements Shape{
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
