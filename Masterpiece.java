package hwJava;

public class Masterpiece extends Artifact{

	protected final String movement;
	
	protected String condition;
	
	Masterpiece(int index, String creator, int year, String movement, String condition){
		super(index,creator,year);
		this.movement=movement;
		this.condition=condition;
		System.out.println("Creating an instance of Masterpiece");
	}

	public String getInfo(){
		return super.getInfo()+", movement = "+movement+", condition = "+condition;
	}
	
	protected int getCondition(String condition){
		if(condition=="bad")
			return 0;
		else if(condition=="good")
			return 1;
		else if(condition=="excellent")
			return 2;
		return -1;
	}
}
