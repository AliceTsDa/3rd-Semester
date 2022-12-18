package hwJava;

import java.util.Random;

public class Main{

	public static void auction(Artifact[] artifacts, String movement, String condition){
		System.out.println("Calling auction for: movement = "+movement+" and condition = "+condition);
		
		for (int i=0; i<artifacts.length; i++)
			System.out.println(artifacts[i].getIndex()+", "+artifacts[i].getInfo()+", "
					+ artifacts[i].evaluate(movement, condition));
	}
	
	public static void main(String[] args){
		if(args.length!=2&&args.length!=3){
			System.out.println("Give exactly 3 arguments (N movement [condition]).");
			return;
		}
		
		//int N=new Integer(args[0]).intValue(); this gave of a warning, instead use the bellow
		int N=Integer.parseInt(args[0]);
		String movement=args[1];
		String condition;
		
		if(args.length==3)
			condition=args[2];
		else
			condition=new String("good");
		
		Artifact artifacts[]=new Artifact[N];
		Random rand=new Random();
		
		for (int i=0; i<N; i++){
			int year=2010+rand.nextInt()%10;
			int mov=rand.nextInt()%3;
			String randMovement;
			
			if(mov==0)
				randMovement=new String("impressionism");
			else if(mov==1)
				randMovement=new String("expressionism");
			else
				randMovement=new String("naturalism");
			
			int con=rand.nextInt()%3;
			String randCondition;
			
			if(con==0)
				randCondition=new String("bad");
			else if(mov==1)
				randCondition=new String("good");
			else
				randCondition=new String("excellent");
			
			// Create a random artifact
			if(rand.nextInt()%2==0){
				int tech=rand.nextInt()%3;
				String randTechnique;
				
				if(tech==0)
					randTechnique=new String("oil");
				else if(tech==1)
					randTechnique=new String("aquarelle");
				else
					randTechnique=new String("tempera");
				artifacts[i]=new Painting(i, "Creator"+i, year, randMovement, randCondition, rand.nextDouble(), rand.nextDouble(), randTechnique);
			}
			else{
				int mat=rand.nextInt()%3;
				String randMaterial;
				
				if(mat==0)
					randMaterial=new String("iron");
				else if(mat==1)
					randMaterial=new String("stone");
				else
					randMaterial=new String("wood");
				artifacts[i]=new Sculpture(i, "Creator"+i, year, randMovement, randCondition, rand.nextDouble(), randMaterial);
			}
		}
				
		auction(artifacts, movement, condition);
	}

}
