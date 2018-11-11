package use_interface;

public class Triangle implements Shape {
	public double a,b,c;
	public Triangle(double a, double b, double c) {
		this.a=a;
		this.b=b;
		this.c=c;
	}
	
	public double Count() {
		double p = (a+b+c)/2;
		return Math.sqrt(p*(p-this.a)*(p-this.b)*(p-this.c));
	}

}
