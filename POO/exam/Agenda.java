import java.util.*;
import java.time.LocalDate;

public class Agenda {
    private LinkedList<Tarea> todas;
    private LinkedList<Tarea> completas;
    private TreeMap<LocalDate, HashSet<Tarea>> porPlazo
        = new TreeMap<LocalDate, HashSet<Tarea>>();

    public Agenda() {
        todas = new LinkedList<Tarea>();
        completas = new LinkedList<Tarea>();
    }

    public List<Tarea> getTodas() {
        return Collections.unmodifiableList(todas);
    }

    public List<Tarea> getPendientes() {
        LinkedList<Tarea> pendientes = new LinkedList<Tarea>();
        for (Tarea t : todas) {
            if (!t.isVencida() && !completas.contains(t))
                pendientes.add(t);
        }
        return pendientes;
    }

    public List<Tarea> getPendientes(Comparator<Tarea> cmp) {
        List<Tarea> pendientes = getPendientes();
        Collections.sort(pendientes, cmp);
        return pendientes;
    }

    public Set<LocalDate> getPlazos() {
        HashSet<LocalDate> plazos = new HashSet<LocalDate>();
        for (Tarea t : todas)
            plazos.add(t.getPlazo());
        return plazos;
    }

    protected void eleminar(Tarea t) {
        todas.remove(t);
    }

    public boolean addTarea(Tarea t) {
        if (!todas.contains(t)) {
            todas.add(t);
            
            if (porPlazo.containsKey(t.plazo())) {
                porPlazo.get(t.plazo()).add(t);
            } else {
                HashSet<Tarea> ns = new HashSet<Tarea>();
                ns.add(t);
                porPlazo.put(t.plazo(), ns);
            }

            return true;
        }
        return false;
    }

    public List<Tarea> addTareas(Tarea... ts) {
        LinkedList<Tarea> tsi = new LinkedList<Tarea>();
        for (Tarea t : ts) {
            if (addTarea(t))
                tsi.add(t);
        }
        return tsi;
    }

    public Set<Tarea> getTareas(LocalDate date) {
        if (!porPlazo.containsKey(date)) return new HashSet<Tarea>();
        return porPlazo.get(date);
    }


}
