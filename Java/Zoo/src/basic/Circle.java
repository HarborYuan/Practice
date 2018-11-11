package basic;

public class Circle {
	public double r;
	public Circle (double r){
		this.r=r;
	}
	
	public double Count() {
		return Math.PI*r*r;
	}

}
