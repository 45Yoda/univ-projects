import java.io.Serializable;

public abstract class Utilizador implements Serializable{
   private String email; //email do user
   private String nome; //nome do user
   private String pass; //password do user
   private String morada; //morada do user
   private String data; //data de nascimento do user
   private Historico historico; //histórico das viagens realizadas
   
   //Construtores
   public Utilizador() {
       this.email = " ";
       this.nome = " ";
       this.pass = " ";
       this.morada = " ";
       this.data = " ";
       this.historico= new Historico();
   }
   
   public Utilizador(String mail, String name, String passw, String moradas, String date){
       this.email = mail;
       this.nome = name;
       this.pass = passw;
       this.morada = moradas;
       this.data = date;
       this.historico=new Historico();
   }
    
   public Utilizador (Utilizador a){
       this.email = a.getEmail();
       this.nome = a.getNome();
       this.pass = a.getPass();
       this.morada = a.getMorada();
       this.data = a.getData();
       this.historico = a.getHistorico();
   }
   
   //gets
   
   
   public String getEmail(){
       return email;
   }
   
   public String getNome(){
       return nome;
   }
   
   public String getPass(){
       return pass;
   }
   
   public String getMorada(){
       return morada;
   }
   
   public String getData(){
       return data;
   }
   
   public Historico getHistorico(){
       return (Historico) this.historico;
   }
   
   public double getQuantia() {
       return this.historico.getViagens().
                   stream().mapToDouble(v->v.getPreco()).sum();
    }
   //sets
   
   public void setEmail(String email){
       this.email = email;
   }
   
   public void setNome(String nome){
       this.nome = nome;
   }
   
   public void setPass(String pass){
       this.pass = pass;
   }
   
   public void setMorada(String morada){
       this.morada = morada;
   }
   
   public void setData(String data){
       this.data = data;
   }
   
   public void setHistorico(Historico h){
       this.historico = h;
   }
   
   
   
   //Clone do Utilizador
   public abstract Utilizador clone();
   
   //Equals do Utilizador
   public boolean equal(Object o){
       if(o==this){
           return true;
       }
       if(o==null || o.getClass() != this.getClass()){
           return false;
       }
       Utilizador ut = (Utilizador) o;
       return ut.getEmail().equals(email)
              && ut.getNome().equals(nome)
              && ut.getPass().equals(pass)
              && ut.getMorada().equals(morada)
              && ut.getData().equals(data)
              && ut.getHistorico().equals(historico);
   }
   
   //toString do Utilizador
   public String toString(){
       StringBuilder sb = new StringBuilder();
       sb.append("Email").append(email).append("\n");
       sb.append("Nome").append(nome).append("\n");
       sb.append("Password").append(pass).append("\n");
       sb.append("Morada").append(morada).append("\n");
       sb.append("Data de Nascimento").append(data).append("\n");
       sb.append("historico ").append(historico.toString()).append(" )");
       return sb.toString();
   }
}
