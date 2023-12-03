import java.util.HashMap;
import java.util.Map;
import static java.util.stream.Collectors.toMap;
import java.io.Serializable;

public class Motorista extends Utilizador implements Serializable{
   
   private int grauC; //grau de cumprimento de horário (0 a 100)
   private int classificacao; //classificação do motorista dada pelo cliente no final da viagem (0 a 100
   private double kmsTotal;
   private boolean disponibilidade;
   private Veiculo veiculo;
   private Empresa empresa;

   public Motorista(){
       super();
       this.grauC = 0;
       this.classificacao = 0;
       this.kmsTotal = 0;
       this.disponibilidade = true;
       this.veiculo=null;
       this.empresa=null;
   }
   
   public Motorista(String email,String nome, String pass, String morada, String data, int grau, int classif,double kmsT){
       super(email,nome,pass,morada,data);
       this.grauC = grau;
       this.classificacao = classif;
       this.kmsTotal = kmsT;
       this.disponibilidade = true;
       this.veiculo=null;
       this.empresa=null;
    }
   
   public Motorista(Motorista m){
       super(m);
       this.grauC = m.getGrau();
       this.classificacao = m.getClassif();
       this.kmsTotal = m.getKmsTot();
       this.disponibilidade = m.getDisp();
       this.veiculo=m.getVeiculo();
       this.empresa=m.getEmpresa();
   }
    
   //gets
   
   public int getGrau(){
       return this.grauC;
   }
   
   public int getClassif(){
       return this.classificacao;
   }
   
   public double getKmsTot(){
       return this.kmsTotal;
   }
   
   public boolean getDisp(){
       return this.disponibilidade;
    }
   
   public Veiculo getVeiculo() {
       return this.veiculo;
    }
    
    public Empresa getEmpresa() {
        return this.empresa;
    }
   //sets
   public void setGrau(int grauC){
       this.grauC = grauC;
   }
   
   public void setClass(int classificacao){
       this.classificacao = classificacao;
   }
   
   public void setKmsT(double kmsTotal){
       this.kmsTotal = kmsTotal;
   }
   
   public void setDisp(boolean disponibilidade){
       this.disponibilidade = disponibilidade;
   }
   
   public void setVeiculo(Veiculo v) {
       if (this.veiculo!=null) this.veiculo.setUso(false);
       this.veiculo=v;
       if (this.veiculo!=null) this.veiculo.setUso(true);
    }
    
   public void setEmpresa(Empresa e) {
       if (this.empresa!=null) this.empresa.getMotoristas().remove(this);
       this.empresa=e;
       if (this.empresa!=null) this.empresa.getMotoristas().add(this);
    }
   //Método clone
   public Motorista clone(){
       return new  Motorista(this);
   }
   
   public void classMotorista (int classificacao) {
       int t=this.getHistorico().quantViagens();
       int fin = (this.getClassif()*t+classificacao)/(t+1);
       this.setClass(fin);
    }
   
   //Método equals
   public boolean equals(Object o){
       if(this==o) return true;
       if((o==null) || o.getClass() != this.getClass()) return false;
       Motorista mot = (Motorista) o;
       return mot.getGrau() == grauC &&
              mot.getClassif() == classificacao &&
              mot.getKmsTot() == kmsTotal &&
              mot.getDisp() == disponibilidade;
   }
   
   //Método toString
   public String toString(){
       StringBuilder sb = new StringBuilder();
       sb.append("Grau de cumprimento: ").append(grauC).append("\n");
       sb.append("Classificação: ").append(classificacao).append("\n");
       sb.append("Kms percorridos(Total): ").append(kmsTotal).append("\n");
       sb.append("Disponibilidade: ").append(disponibilidade).append("\n");
       
       return sb.toString();
   }
}
