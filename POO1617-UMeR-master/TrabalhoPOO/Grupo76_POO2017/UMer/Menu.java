
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.InputMismatchException;
import java.io.Serializable;

public class Menu implements Serializable{
    // variáveis de instância
    private List<String> opcoes;
    private int op;
    
    
    /**
     * Constructor for objects of class Menu
     */
    public Menu(String[] opcoes) {
        this.opcoes = new ArrayList<String>();
        for (String op : opcoes) 
            this.opcoes.add(op);
        this.op = 0;
    }
    
    /**
     * Método para apresentar o menu e ler uma opção.
     */
    public void executa(){
    
        do{
            showMenu();
            this.op = lerOpcao();
        } while(this.op == -1);
    }
    
    /**
     * Apresentar o menu
     */
    private void showMenu(){
        System.out.println("dddddddddddddddddddddddddddsooooooooooooooooooooooooooo");
        System.out.println("dddddddddddddddddddddddddddsooooooooooooooooooooooooooo");
        System.out.println("dddddddddddd+/hddddddddddddsoooooooooo/-/::+ooooooooooo");
        System.out.println("ddddddhddddd-.hddddhdddddddsooooooo/-`-/o+:..:+oooooooo");
        System.out.println("ddddds-.ystiflersy+:-oddddddsooooo-`-/ooooooo+:../ooooo");
        System.out.println("ddddddhy.:.:yh:.-+yhdddddddsoooo:.ooooooooooooo/.+ooooo");
        System.out.println("ddddddddyhyyodahhyhddddddddsoooo+`-ooooooooooo+`.oooooo");
        System.out.println("ddddds:.-sdstanhds:.:sddddddsooooo: /oooooooooo.`ooooooo");
        System.out.println("dddddhyhdddd-.hdddhyhddddddsoooooo-`ooooooooo: /ooooooo");
        System.out.println("dddddddddddd--hddddddddddddsoooooooo/--------+ooooooooo");
        System.out.println("dddddddddddddddddddddddddddsooooooooooooooooooooooooooo");
        System.out.println("dddddddddddddddddddddddddddsooooooooooooooooooooooooooo");

        
        System.out.println("\n ****** Menu ****** ");
        
        for(int i=0;i<this.opcoes.size();i++){
            System.out.print(i+1);
            System.out.print(" - ");
            System.out.println(this.opcoes.get(i));
        }
        System.out.println("0 - Sair");
    }
   
    /**
     * Ler uma opcão válida
     */
    private int lerOpcao(){
        int op;
        Scanner is = new Scanner(System.in);
        
        System.out.println("Opção: ");
        try{
            op = is.nextInt();
        }
        catch (InputMismatchException e){ //Não foi escrito um int
            op = -1;
        }
        if(op<0 || op > this.opcoes.size()){
            System.out.println("Opção Inválida!!!");
            op = -1;
        }
        return op;
    }
    
    /**
     * Método para obter a última opção lida
     */
    public int getOpcao(){
        return this.op;
    }
}
