import java.util.Comparator;
import java.time.LocalDate;

public class ComparatorData implements Comparator<Viagem>{
    
    public int compare(Viagem v1, Viagem v2){
        LocalDate d1 = v1.getData();
        LocalDate d2 = v2.getData();
        if(d1.isBefore(d2)) return 1;
        if(d1.equals(d2)) return 0;
        if(d1.isAfter(d2)) return -1;
        return 0;
    }
        
}
