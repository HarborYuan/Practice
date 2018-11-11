package use_interface;

public class Circle implements Shape{
	public double r;
	public Circle (double r){
		this.r=r;
	}
	
	public double Count() {
		return Math.PI*r*r;
	}

}
