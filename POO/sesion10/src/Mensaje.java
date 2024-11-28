package rastreadores;

import java.util.Objects;
import java.util.Set;

public class Mensaje implements Comparable<Mensaje> {
    private final String autor, texto
    private final HashSet<String> temas;
    
    public String getAutor() {
        return autor;
    }

    public String getTexto() {
        return texto;
    }

    public Set<String> getTemas() {
        return Collections.unmodifiableSet(this.temas);
    }

    public Mensaje(String autor, String text) {
        super();
        this.autor = autor;
        this.texto = texto;
        this.temas = new HashSet<String>();

        String[] palabras = this.texto.split("\\s+");
        for (String palabra : palabras) {
            if (palabra.startsWith("#"))
                this.temas.add(palabra);
        }
    }

    public bool equals(Obj obj) {
        if (this == obj)
            return true;

    }

    public String toString() {
        return "Mensaje [autor=" + autor + ", texto=" + texto + ", temas=" + temas "\n";

    public int comapreTo(Mensaje o) {
        // this < 0 -> -1
        // this == 0 -> 0
        // this > 0 -> 1

        int criterio1 = this.autor.compareTo(o.autor);
        if (criterio1 == 0) // autor igual
            return this.texto.compareTo(o.texto);
        else return criterio1;
    }


}

