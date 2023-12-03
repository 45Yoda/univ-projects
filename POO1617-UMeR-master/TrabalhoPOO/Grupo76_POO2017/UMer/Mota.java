import java.io.Serializable;

public class Mota extends Veiculo implements Serializable{

   
   public Mota(){
       super();
   }
   
   public Mota(int vMed, double preco, String matricula, Localizacao loc){
       super(vMed,preco,matricula,loc);
       
   }
   
   public Mota(Mota l){
       super(l);
   }
   
   public Mota clone(){
       return new Mota(this);
   }
   
   public boolean equals(Object o){
       if(o==this){
           return true;
       }
       if((o==null) || o.getClass() != this.getClass()){
           return false;
       }
       Mota l = (Mota) o;
       return super.equals(o);
   }
    
   public String toString(){
       StringBuilder sb = new StringBuilder();
       sb.append(super.toString());
     
       return sb.toString();
   }
}