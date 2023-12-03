import java.io.*;
import java.util.Map;
import java.util.TreeMap;
import java.util.List;
import java.util.ArrayList;
import java.io.Serializable;


public class UMeR implements Serializable{
   private Map<String,Utilizador> utilizadores; //Email
   private Map<String,Veiculo> veiculo; //Matricula;
   private Map<Veiculo,Motorista> motorista;
   private Map<String,Empresa> empresa;//nome da empresa
   private Utilizador user;
   private Fatores fator;
   
   public UMeR(){
       this.utilizadores = new TreeMap<String,Utilizador>();
       this.veiculo = new TreeMap<String,Veiculo>();
       this.empresa = new TreeMap<String,Empresa>();
       this.user = null;
   }
   
   public UMeR(TreeMap<String,Utilizador> uti, TreeMap<String,Veiculo> veic,TreeMap<String,Empresa> emp, Utilizador util){
       this.utilizadores = uti;
       this.veiculo = veic;
       this.empresa=emp;
       this.user = util;
   }
   
   public UMeR (UMeR um){
       this.utilizadores = um.getUtilizadores();
       this.veiculo = um.getVeiculo();
       this.empresa=um.getEmpresa();
       this.user = um.getUser();
   }
   
   //gets
   
   /*tipo de utilizador
    * 0 se n existir
    * 1-Cliente
    * 2-Motorista
    */
   public int getTipoUtilizador(){
       if(user instanceof Cliente){
           return 1;
       }
       if(user instanceof Motorista){
           Motorista m = (Motorista) user;
           if (m.getEmpresa()==null) return 2;
           else return 3;
       }
       
       return 0;
   }

   //obter email
   private String getMail(){
       if(user != null){
           return user.getEmail();
       }
       
       return "Não existe";
   }
   
   //utilizador com login
   public Utilizador getUser(){
       if(user instanceof Cliente){
           Cliente c = (Cliente) user;
           return c;
       }
       if(user instanceof Motorista){
           Motorista m = (Motorista) user;
           return m;
       }
       
       return null;
   }
   
   //Utilizadores do UMeR
   public Map<String,Empresa> getEmpresa(){
            
       return this.empresa;
   }
   
   //veiculos da UMeR
   public Map<String,Veiculo> getVeiculo(){
      
       return this.veiculo;
   }
   
   //utilizadores da umer
   public Map<String,Utilizador> getUtilizadores(){
       
       return this.utilizadores;
   }
   //sets
   
   //Utilizador com login
   public void setUtilizador(Utilizador util){
       if(util instanceof Cliente)
            user = new Cliente ((Cliente) util);
       if(util instanceof Motorista)
            user = new Motorista ((Motorista) util);
  }
   
   //Utilizadores
   public void setUtilizadores(Map<String,Utilizador> utilizadores){
       this.utilizadores = new TreeMap<String,Utilizador>();
       for(Map.Entry<String,Utilizador> entry: utilizadores.entrySet())
            this.utilizadores.put(entry.getKey(), entry.getValue());
   }
   
   //Veiculo da UMeR
   public void setVeiculo(Map<String,Veiculo> veiculo){
       this.veiculo = new TreeMap<String,Veiculo>();
       for(Map.Entry<String,Veiculo> entry: veiculo.entrySet())
            this.veiculo.put(entry.getKey(), entry.getValue());
   }
   
   //Empresa
    public void setEmpresa(Map<String,Empresa> empresa){
       this.empresa = new TreeMap<String,Empresa>();
       for(Map.Entry<String,Empresa> entry: empresa.entrySet())
            this.empresa.put(entry.getKey(), entry.getValue());
   }
   
   //Clone da UMeR
   public UMeR clone(){
       return new UMeR();
   }

   //Equals
   public boolean equals(Object o){
       if(o == this){
           return true;
       }
       if(o == null || o.getClass() != this.getClass()){
           return false;
       }
       UMeR u = (UMeR) o;
       return u.getUtilizadores().equals(utilizadores) &&
              u.getVeiculo().equals(veiculo) &&
              u.getUser().equals(user) &&
              u.getEmpresa().equals(empresa);
   }
   
   //Métodos
   
   /****Relativos ao inicio,registo e fecho de sessão****/
   
   //Registar utilizador
   public void registarUtilizador(Utilizador user) throws UtilizadorExisteException{
       String mail = user.getEmail();
       if(utilizadores.containsKey(mail)){ throw new UtilizadorExisteException("Utilizador já existente");}
       else {utilizadores.put(mail,user);System.out.println("Sucesso");}
   }
   
   //Iniciar a sessão
   public void iniciaSessao(String email, String password) throws SemAutorizacaoException{
       Utilizador u = utilizadores.get(email);
       if(u==null) {throw new SemAutorizacaoException("Utilizador não existente " + email);}
       if(u.getPass().equals(password)) this.user = u;
       else{ throw new SemAutorizacaoException("Password incorreta");}
    }
   
   //Fim da sessão
   public void fechaSessao(){
       this.user = null;
   }
   
   /**Abre os dados**/
   public static UMeR initApp() throws IOException, ClassNotFoundException{
       ObjectInputStream ois = new ObjectInputStream(new FileInputStream("dadosUMeR.data"));
       UMeR umer = (UMeR) ois.readObject();
       ois.close();
       return umer;
   }
   
   
   /****Gravar****/
   public void gravar() throws IOException{
       ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("dadosUMeR.data"));
       oos.writeObject(this);
       
       oos.flush();
       oos.close();
   }
   
   
   /****Relativos aos veiculos ****/
   
   //Criar e inserir veiculos
   public void insereVeiculo(Veiculo v) throws VeiculoExisteException, SemAutorizacaoException{
      if(this.veiculo.containsKey(v.getMat())) throw new VeiculoExisteException("Veiculo já existe\n");
      
      veiculo.put(v.getMat(),v);
   }
   
   //Associar o motorista ao veiculo
   public void associarMotVei(Motorista m, Veiculo v) throws SemAutorizacaoException{
       if(getTipoUtilizador() != 2) throw new SemAutorizacaoException("Cliente não pode aceder a área de Motorista");
       
       m.setVeiculo(v);
   }
   
   /****Preço*****/
   
   public double calculaTempo(double distancia, Veiculo veiculo){
       double tempEst = distancia / veiculo.getVMed();
       double tempFiab = tempEst + (tempEst*((100 - veiculo.getFiabilidade())/100));
       double tempReal = 0;
       int meteorologia = fator.getMeteo();
       int transito = fator.getTran();
       switch(meteorologia){
           case 1: tempReal = tempFiab;
                    break;
           case 2: tempReal = tempFiab * 1.20;
                    break;
           case 3: tempReal = tempFiab * 1.50;
                    break;
        }
       switch(transito){
           case 1: tempReal = tempReal;
                    break;
           case 2: tempReal *= 1.20;
                    break;
           case 3: tempReal *= 1.50;
                    break;
       }
        
       return tempReal;
    }
    
    public double calculaPreco(double distancia,double tempo,Veiculo v){
        double tempEst = distancia/v.getVMed();
        double custoCombinado = distancia * v.getPreco();
        double precoTotal;
        if(tempEst - tempo <= tempo*0.25){
            precoTotal = custoCombinado*(tempo/tempEst);
        }
        else{
            precoTotal = custoCombinado;
        }
        
        return precoTotal;
    }
    
   
   
}
   




