package hwJava;

public class Sculpture extends Masterpiece{

	private final double volume;
	
	private final String material;
	
	Sculpture(int index, String creator, int year, String movement,
			String condition, double volume, String material){
		super(index, creator, year, movement, condition);
		this.volume=volume;
		this.material=material;
		System.out.println("Creating an instance of Sculpture");
	}

	public String getInfo(){
		return super.getInfo()+", volume = "+volume+", material = "+material;
	}
	
	public boolean evaluate(String movement, String condition){
		if(condition.isEmpty())
			condition="excellent";
		int givenCondition=getCondition(this.condition);
		int inputCondition=getCondition(condition);
		
		if(movement==this.movement&&givenCondition>=inputCondition)
			return true;
		return false;
	}
}
