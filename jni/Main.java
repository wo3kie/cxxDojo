
public class Main
{
    private static int number = 7;
    private int id;

    public static void function(){
        System.out.println( "Hello World" );
    }
    
    public static int function2( int i ){
        return 2 * i;
    }

    public Main(){
        id = 2 * number;
    }

    public int getId(){
        return id;
    }
}

