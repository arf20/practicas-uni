import java.util.*;

public class TareaComparator implements Comparator<Tarea> {
    public int compare(Tarea a, Tarea b) {
        if (a.getPlazo() == null && b.getPlazo() == null) return 0;
        else if (a.getPlazo() == null) return 1;
        else if (b.getPlazo() == null) return -1;
        else return a.getPlazo().compareTo(b.getPlazo());
    }
}
