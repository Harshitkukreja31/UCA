import java.lang.*;

interface polygon{
    int sides=0;
    public int getNumberOfSides();
}

abstract class shape{
    abstract double calculateArea();
    abstract double calculatePerimeter();

}

class circle extends shape{
    private double radius;


    public circle(int rad){
        this.radius=rad;
    }

    public double calculatePerimeter(){
        return 2*3.14*radius;
    }
    public double calculateArea(){
        return 3.14*radius*radius;
    }
}

abstract class quadrilateral extends shape implements polygon{
    int sides=4;
    public int getNumberOfSides(){
        return sides;
    }
}
class rectangle extends quadrilateral{
    private double length;
    private double breadth;

    public rectangle(int l,int b){
        this.length=l;
        this.breadth=b;
    }
    public double calculateArea(){
        return length*breadth;
    }

    public double calculatePerimeter(){
        return 2*(length+breadth);
    }
}

class square extends quadrilateral{
    private double side;


    public square(int s){
        this.side=s;
    }
    public double calculateArea(){
        return side*side;
    }
    public double calculatePerimeter(){
        return 4*side;
    }
}


public class october21 {
    public static void main (String[] args) 
	{
		shape Circle =new circle(2);
		System.out.println(Circle.calculatePerimeter());
		shape Square=new square(4);
		System.out.println(Square.calculatePerimeter());
	}
}
