package rastreadores;

public class Rastreador {
    private ArrayList<Mensaje> mensajes;
    
    //implementacion
    private HashMap<String, LinkedList<Mensaje>> mapaAutores;

    public Rastreador() {
        this.mensajes = new ArrayList<Mensajes>();
        

    }

    public List<Mensajes> getMensajes() {
        return Collections.unmodifiableList(this.mensajes);
    }


    public List<Mensaje> getMensajesOrdenados() {
        // un metodo consulta no debe modificar
        var copia = new LinkedList<Mensaje>(this.mensajes);
        Collections.sort(copia); // orden natural (compareTo)
        return copia;
    }
    
    public List<Mensaje> getMensajesOrdenados(Comparator<Mensaje> comparador) {
        var copia = new LinkedList<Mensaje>(this.mensajes);
        Collections.sort(copia, comparador);
        return copia;
    }
    // funcionalidad
    

    public void registrar(String autor, String texto) {
        Mensaje mensaje = new Mensje(autor, texto);
        registrar(mensaje);
    }

    public void registrar(Mensaje mensaje) {
        this.mensajes.add(mensaje);
        if (!this.mapaAutores.containsKey(mensaje.getAutor())) {
            this.mapaAutores.put(autor, new LinkedList<Mensaje>());

        this.mapaAutores.get(autor).add(mensaje);
    }

    public List<Mensaje> getMensajesAutor(String autor) {
        return Collections.unmodifiableList(this.mapaAutores.get(autor));
    }

:q

}
