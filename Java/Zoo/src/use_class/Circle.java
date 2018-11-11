package use_class;

public class Circle extends Shape{
	public double r;
	public Circle (double r){
		this.r=r;
	}
	
	public double Count() {
		return Math.PI*r*r;
	}

}
