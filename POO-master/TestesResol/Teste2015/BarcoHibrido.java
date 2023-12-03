import java.io.Serializable;
import java.util.ArrayList;
import java.util.TreeSet;

public class BarcoHibrido extends Barco implements Serializable{
    
    private double capacidade;
    private double potencia;
    private double autonomiaEle;
    private double seguro;

    public BarcoHibrido(String id,double milhas,String categoria,double autonomia,Pessoa skipper, TreeSet<Pessoa> trip,ArrayList<RegistoEtapa> listaReg,double capacidade,double potencia,double autonomiaEle,double seguro){
        super(id,milhas,categoria,autonomia,skipper,trip,listaReg);
        this.capacidade=capacidade;
        this.potencia=potencia;
        this.autonomiaEle=autonomiaEle;
        this.seguro=seguro;
    }
    public BarcoHibrido(BarcoHibrido b){
        super(b);
        this.capacidade=b.getCapacidade();
        this.potencia=b.getPotencia();
        this.autonomiaEle=b.getAutonomiaEle();
        this.seguro=b.getSeguro();
    }

    public double getCapacidade(){return this.capacidade;}
    public double getPotencia(){return this.potencia;}
    public double getAutonomiaEle(){return this.autonomiaEle;}
    public double getSeguro(){
        return getMilhas()*0.02;
    }
    public double getAutonomia(){
        return this.getAutonomiaEle()+getAutonomia();
    }
    
    public String toString(){
        StringBuilder s = new StringBuilder();
        s.append("Capacidade:");
        s.append(getCapacidade());
        s.append(System.lineSeparator());
        s.append("Potência: ");
        s.append(getPotencia());
        s.append(System.lineSeparator());
        s.append("Autonomia: ");
        s.append(getAutonomiaEle());
        s.append(System.lineSeparator());
        return s.toString();
    } 
    
    @Override
    public BarcoHibrido clone(){
        return new BarcoHibrido(this);
    }
}
