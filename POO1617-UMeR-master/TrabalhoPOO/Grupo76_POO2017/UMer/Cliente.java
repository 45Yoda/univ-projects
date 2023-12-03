import java.util.HashMap;
import java.util.Map;
import java.io.Serializable;

public class Cliente extends Utilizador implements Serializable{
   
   private Localizacao localizacao;
   
   //Construtores
   public Cliente(){
       super();
       localizacao = null;
   }
   
   public Cliente(String email,String nome, String pass, String morada, String data, Localizacao local, Historico viagem){
       super(email,nome,pass,morada,data);
       this.localizacao = local;
   }
   
   public Cliente(Cliente c){
       super(c);
       localizacao = c.getLocalizacao();
   }
   
   //gets
   
   public Localizacao getLocalizacao(){
       return (Localizacao) this.localizacao;
   }
   
   
   //sets
   public void setLocalizacao(Localizacao p){
       this.localizacao = p;
   }
   
   
   //Métodos
 
   
   
   
   //Método clone

   public Cliente clone(){
       return new Cliente(this);
   }
   
   //Método equals
   public boolean equals(Object o){
       if(this==o) return true;
       if((o==null) || o.getClass() != this.getClass()) return false;
       Cliente c = (Cliente) o;
       return super.equals(c) &&
              c.getLocalizacao().equals(localizacao);
   }

   //Método toString
   public String toString(){
       StringBuilder sb = new StringBuilder();
       sb.append("( ").append(localizacao.toString()).append(" )");
       
       return sb.toString();
   }
}