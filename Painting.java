package hwJava;

public class Painting extends Masterpiece{

	private final double length;
	
	private final double width;
	
	private String technique;
	
	Painting(int index, String creator, int year, String movement,
			String condition, double length, double width, String technique){
		super(index, creator, year, movement, condition);
		this.length=length;
		this.width=width;
		this.technique=technique;
		System.out.println("Creating an instance of Painting");
	}

	public String getInfo(){
		Double surface=new Double(length*width);
		return super.getInfo()+ ", length = "+length+", width = " 
				+width+", technique = "+technique 
				+", surface = "+surface.toString();
	}
	
	public boolean evaluate(String movement, String condition){
		if(condition.isEmpty())
			condition="good";
		int givenCondition=getCondition(this.condition);
		int inputCondition=getCondition(condition);
		
		if (movement==this.movement&&givenCondition>=inputCondition)
			return true;
		return false;
	}
}
