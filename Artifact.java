package hwJava;

public class Artifact {
	private final int index;
	
	private final String creator;
	
	private final int year;
	
	Artifact(int index, String creator, int year){
		this.index=index;
		this.creator=creator;
		this.year=year;
		System.out.println("Creating an instance of Artifact");
	}
	
	public String getInfo()
	{
		return "Creator = "+creator+", year = "+year;
	}
	
	public boolean evaluate(String movement, String condition){
		return true;
	}
	
	public String getIndex(){
		return new Integer(index).toString();
	}	
}
