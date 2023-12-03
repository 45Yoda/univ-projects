package Ficha7;


import static org.junit.Assert.*;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class TesteHoteisInc{
    
    public static void main(String[] args){
        Hotel h1 = new HotelStandard("h1","IbisB","Braga",3.4,45,true);
       Hotel h2 = new HotelStandard("h2","IbisP","Porto",3.4,55,true);
       HoteisInc hi = new HoteisInc();
       
       System.out.println("A Testar o Hotel");
       
       try{
           hi.adiciona(h1);
           hi.adiciona(h2);
           hi.adiciona(h1);
           hi.adiciona(h2);
        }
        catch (HotelExisteException e){
            System.out.println("Já existe este hotel");
        }
    }
}
