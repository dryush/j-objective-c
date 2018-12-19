
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Dryush
 */


public class NSScanner extends NSObject{
    Scanner in = new Scanner(System.in);
    
    public int scanInt(){
        return in.nextInt();
    }
    
    public NSString scanString(){
        return new NSString().init( in.next());
    }
    
    public float scanFloat(){
        return in.nextFloat();
    }
}
