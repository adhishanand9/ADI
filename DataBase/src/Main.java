import java.util.*;
class QueryEngine{
    String query=new String();
    List<String> splits = new ArrayList<String>();
    ArrayList<String> firstWord= new ArrayList<String>(Arrays.asList("create","select","exit","load","insert","store","print"));
    void getInput()
    {
        Scanner sc=new Scanner(System.in);
        query=sc.nextLine();
        Collections.addAll(splits,query.split(" "));
        splits.removeAll(Arrays.asList("", null));
        matchFirstWord();

    }
    void display()
    {
        for(int i=0;i<splits.size();i++)
        {
            System.out.println(splits.get(i));
        }
    }
    void matchFirstWord(){
        if(!firstWord.contains(splits.get(0).toLowerCase())){
            System.out.println("Wrong Input");
            return ;
        }else{
            switch (splits.get(0).toUpperCase()){
                case "CREATE":{
                    System.out.println("create");
                    create();
                    break;
                }
                case "SELECT":{
                    System.out.println("create");
                    create();
                    break;
                }
                case "EXIT":{
                    System.out.println("create");
                    create();
                    break;
                }
                case "STORE":{
                    System.out.println("create");
                    create();
                    break;
                }
                case "PRINT":{
                    System.out.println("create");
                    create();
                    break;
                }
                case "LOAD":{
                    System.out.println("create");
                    create();
                    break;
                }
                case "INSERT":{
                    System.out.println("create");
                    create();
                    break;
                }

            }
        }

    }
    void create(){

    }
    void select(){

    }
}
public class Main {

    public static void main(String[] args) {
        QueryEngine qe=new QueryEngine();
        qe.getInput();
        //qe.display();

    }
}
