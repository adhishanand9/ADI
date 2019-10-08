import java.util.*;
import java.lang.*;
import java.io.*;

class Playlist implements Serializable{
    String name;
    static int id=0;
    static void setID(){
        id=id+1;
    }
    LinkedList<String> Songs = new LinkedList<String>();
    void setName(String name){
        this.name=name;
    }
    private static class Songs{
        int id;
        public void setID(int id){
            this.id=id;
        }

    }
    public void createSongs() throws NullPointerException{
        for(int i=0;i<10;i++)
        {
            Songs []s=new Songs[10] ;
            s[i].setID(i);

        }
    }
    public static void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }
    public void displayFirst()throws Exception{
        int value;
        Scanner sc=new Scanner(System.in);
        System.out.println("Welcome!");
        System.out.println("1.Create Playlist.");
        System.out.println("2.Exit");
        value=sc.nextInt();
        if(value==1){
            createPlaylist();
        }
        else if(value==2)
        {
            System.exit(0);
        }
    }
    public void createPlaylist() throws Exception{
        Playlist pl = new Playlist();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Name:");
        String name1=sc.nextLine();
        pl.setName(name1);
        savePlayList(pl,name1);
        clearScreen();
        displayMenu();

    }
    public void displayMenu ()throws Exception{
        Scanner sc=new Scanner(System.in);
        System.out.println("1.Add Song.");
        System.out.println("2.Delete Song.");
        System.out.println("3.Play Song");
        System.out.println("4.Set Mode");
        System.out.println("5.Back To Main Menu");
        int value=sc.nextInt();
        switch (value){
            case 1:addSong();
                break;
            case 2:deleteSong();
                break;
            case 3:playSong();
                break;
            case 4:setMode();
                break;
            case 5:display();
                break;
            default:System.exit(0);
                break;
        }


    }
    public void display ()throws Exception{
        Scanner sc=new Scanner(System.in);
        System.out.println("Welcome!");
        System.out.println("1.Create Playlist.");
        System.out.println("2.Goto Playlist.");
        System.out.println("3.Exit");
        int value=sc.nextInt();
        if(value==1){
            createPlaylist();
        }
        else if(value==2)
        {
            displayMenu();
        }
        else if(value==3)
        {
            System.exit(0);
        }
    }
    public void savePlayList(Playlist pl,String name1) throws Exception{
        FileOutputStream fs=new FileOutputStream(id+".txt");
        ObjectOutputStream oos=new ObjectOutputStream(fs);
        oos.writeObject(pl);
        oos.flush();
        oos.close();
        fs.close();
    }
    public void addSong(){

    }
    public void deleteSong(){

    }
    public void playSong(){

    }
    public void setMode(){

    }



}
public class Main {

    public static void main(String[] args) throws Exception
    {
        Playlist ply=new Playlist();
        //ply.createSongs();
        ply.setName("PlayX");
        FileOutputStream fs=new FileOutputStream("Playlist.txt");
        ObjectOutputStream oos=new ObjectOutputStream(fs);
        oos.writeObject(ply);
        oos.flush();
        oos.close();
        fs.close();
        ply.displayFirst();

    }
}
