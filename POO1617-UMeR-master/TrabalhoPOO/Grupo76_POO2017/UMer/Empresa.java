import java.util.List;
import java.util.ArrayList;
import java.io.Serializable;

public class Empresa implements Serializable{
    private String nomeEmpresa;
    private List<Veiculo> taxis;
    private int nveiculos; //numero veiculos na empresa
    private List<Motorista> motoristas;
    private int nmotoristas; //numero motoristas na empresa
    private int motocap; //capacidade de motoristas da empresa
    private int capacidade;//capacidade da empresa (em número de veículos)
    
    
    //Construtores
    public Empresa(){
        this.nomeEmpresa = " ";
        this.taxis = new ArrayList<Veiculo>(capacidade);
        this.capacidade = 0;
        this.motocap=0;
        this.nveiculos = 0;
        this.nmotoristas=0;
        this.motoristas = new ArrayList<Motorista>(motocap);
    }
    
    public Empresa(String nome, int capacidade,int motocap){
        this.nomeEmpresa = nome;
        this.taxis = new ArrayList<Veiculo>(capacidade);
        this.nveiculos = 0;
        this.motocap=motocap;
        this.capacidade = capacidade;
        this.nmotoristas=0;
        this.motoristas = new ArrayList<Motorista>(motocap);
    }
    
    public Empresa(Empresa emp){
        this.nomeEmpresa = emp.getNomeEmpresa();
        this.taxis = emp.getTaxis();
        this.nveiculos = emp.getNVeiculos();
        this.capacidade = emp.getCapacidade();
        this.nmotoristas=emp.getNMotoristas();
        this.motocap=emp.getMotocap();
        this.motoristas=emp.getMotoristas();
    }
    
    //gets
    public String getNomeEmpresa(){
        return this.nomeEmpresa;
    }
    
    public List<Veiculo> getTaxis(){
        List<Veiculo> aux = new ArrayList<Veiculo>(this.capacidade);
        for(Veiculo v: this.taxis)
            aux.add(v);
                
        return aux;
    }
    
    public List<Motorista> getMotoristas(){
        List<Motorista> aux = new ArrayList<Motorista>(this.motocap);
        for(Motorista m: this.motoristas)
            aux.add(m);
        
        return aux;
    }
    
    public int getNVeiculos(){
        return this.nveiculos;
    }
    
    public int getNMotoristas(){
        return this.nmotoristas;
    }
    
    public int getCapacidade(){
        return this.capacidade;
    }
    
    public int getMotocap(){
        return this.motocap;
    }
    
    
    //sets
    
    
    public void setNomeEmpresa(String nomeEmpresa){
        this.nomeEmpresa = nomeEmpresa;
    }
    
    
    public void setTaxis(List<Veiculo> taxis){
        for(Veiculo v: taxis)
            this.taxis.add(v);
    }
    
    public void setMotoristas(List<Motorista> motoristas) {
         for(Motorista m: motoristas)
            this.motoristas.add(m);
    }
    
    public void setNVeiculos(int nveiculos){
        this.nveiculos = nveiculos;
    }
    
    public void setNMotoristas(int nmotoristas) {
        this.nmotoristas=nmotoristas;
    }
    
    public void setCapacidade(int capacidade){
        this.capacidade = capacidade;
    }
    
    public void setMotocap(int motocap){
        this.motocap=motocap;
    }
    
    //Métodos auxiliares
    public void insereVeiculo(Veiculo v){
        if(!this.taxis.contains(v) && this.nveiculos < this.capacidade){
            this.taxis.add(v);
            this.nveiculos++;
        }
    }
    
    public void insereMotorista(Motorista m) {
        if(!this.motoristas.contains(m) && this.nmotoristas<this.motocap) { 
            this.motoristas.add(m);
            this.nmotoristas++;
        }
    }
    
    
    //Método equals
    public boolean equals(Object o){
        if(this==o) return true;
        if((o==null) || this.getClass() != o.getClass()) return false;
        Empresa emp = (Empresa) o;
        return emp.getNomeEmpresa().equals(nomeEmpresa) &&
               emp.getTaxis().equals(taxis) &&
               emp.getNVeiculos() == nveiculos &&
               emp.getCapacidade() == capacidade &&
               emp.getMotocap()==motocap &&
               emp.getNMotoristas()==nmotoristas &&
               emp.getMotoristas().equals(motoristas);
    }
    
    //Método toString
    public String toString(){
        int i;
        StringBuilder sb = new StringBuilder();
        sb.append("Nome Empresa: ").append(nomeEmpresa).append("\n");
        sb.append("Número de veiculos: ").append(nveiculos).append("\n");
        sb.append("Capacidade: ").append(capacidade).append("\n");
        sb.append("Número de motoristas: ").append(nmotoristas).append("\n");
        sb.append("Capacidade de motoristas: ").append(motocap).append("\n");
        
        for(i=0;i<nveiculos;i++){
            sb.append("Táxis: ").append(taxis.get(i)).append("\n");
        }
        
        for(i=0;i<nmotoristas;i++){
            sb.append("Motoristas: ").append(motoristas.get(i)).append("\n");
        }
        
        return sb.toString();
    }
    
    //Método clone
    public Empresa clone(){
        return new Empresa(this);
    }
}
