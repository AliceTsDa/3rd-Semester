Not really sure what's going on with the compilation and the package used. 
Using eclipse it worked just fine but on vscode I had certain issues. 

I ended up using these commands while being on ..../hwJava and it worked:
javac *.java
cd ..
java hwJava.Main 5 impressionism good

You may get 3 warnings, there's something going on with Integer() and Double().
No clue what's that about to be honest. 

I believe I fixed one of them by replacing: 
int N=new Integer(args[0]).intValue();
with: 
int N=Integer.parseInt(args[0]);

Hope it compiles because I did my best :) 