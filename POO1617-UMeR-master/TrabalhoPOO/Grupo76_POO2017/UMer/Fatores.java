import java.util.Random;

public class Fatores{
    private int meteorologia;
    private int transito;
    
    public Fatores(){
        this.meteorologia = 0;
        this.transito = 0;
    }
    
    public Fatores(int meteo, int tran){
        this.meteorologia = meteo;
        this.transito = tran;
    }
    
    public Fatores(Fatores f){
        this.meteorologia = f.getMeteo();
        this.transito = f.getTran();
    }
    
    public int getMeteo(){
        return this.getMeteorologiaRandom();
    }
    
    public int getMeteorologiaRandom(){
        Random rand = new Random();
        int n = rand.nextInt(3) +1 ; // inteiro entre 1 e 3;
        setMeteo(n);
        return this.meteorologia;
    }
    
    public int getTran(){
        return this.getTranRandom();
    }
    
    public int getTranRandom(){
        Random rand = new Random();
        int n = rand.nextInt(3) +1; //inteiro entre 1 e 3;
        setTran(n);
        return this.transito;
    }
    
    public void setMeteo(int meteo){
        this.meteorologia = meteo;
    }
    
    public void setTran(int tran){
        this.transito = tran;
    }
    
    public boolean equals(Object o){
        if(o==this) return true;
        if(o == null || o.getClass() != this.getClass()) return false;
        Fatores f = (Fatores) o;
        
        return this.meteorologia == f.getMeteo() &&
               this.transito == f.getTran();
    }
    
    public String toString(){
        StringBuilder sb = new StringBuilder();
        String s=null,l=null;
        if(this.meteorologia == 1) s = "Céu Limpo";
        if(this.meteorologia == 2) s = "Chuva";
        if(this.meteorologia == 3) s = "Neve";
        sb.append("A meteorologia indica: ").append(s).append("\n");
        if(this.transito == 1) l = "Baixo";
        if(this.transito == 2) l = "Médio";
        if(this.transito == 3) l = "Alto";
        sb.append("O nível de trânsito é: ").append(l).append("\n");
        
        return sb.toString();
    }
}
