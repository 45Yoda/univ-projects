import java.io.Serializable;

public class Carrinha extends Veiculo implements Serializable{

   
   public Carrinha(){
       super();
   }
   
   public Carrinha(int vMed, double preco, String matricula, Localizacao loc){
       super(vMed,preco,matricula,loc);
       
   }
   
   public Carrinha(Carrinha l){
       super(l);
   }
   
   public Carrinha clone(){
       return new Carrinha(this);
   }
   
   public boolean equals(Object o){
       if(o==this){
           return true;
       }
       if((o==null) || o.getClass() != this.getClass()){
           return false;
       }
       Carrinha l = (Carrinha) o;
       return super.equals(o);
   }
    
   public String toString(){
       StringBuilder sb = new StringBuilder();
       sb.append(super.toString());
     
       return sb.toString();
   }
}

