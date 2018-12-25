/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.lang.String;
/**
 *
 * @author User
 */
public class NSString extends NSObject {
    String str;
    
    
    public NSString init(String val){
        this.str = val;
        return this;
    }
    public NSString init(NSString val){
        this.str = val.str;
        return this;
    }
    
    public static NSString fromInt( int val){
        return new NSString().init( String.valueOf(val));
    }
    
    public static NSString fromFloat( float val){
        return new NSString().init( String.valueOf(val));
    }
    
    public static NSString fromBool( boolean val){
        return new NSString().init( String.valueOf(val));
    }
    
    public static NSString fromChar( char val){
        return new NSString().init( String.valueOf(val));
    }
    
    
    public static NSString fromChar( int val){
        return new NSString().init( String.valueOf((char)val));
    }
    
    public static NSString fromCharArray( char[] val){
        return new NSString().init( new String(val));
    }
    
    public NSString append( NSString otherStr){
        return new NSString().init(this.str + otherStr.str);
    }
}
