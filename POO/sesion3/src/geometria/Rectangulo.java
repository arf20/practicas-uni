//import Point;

package geometria;

import geometria.Point;

public class Rectangulo {
    private Point verticeII, verticeSI, verticeSD, verticeID;
    private int ladoX, ladoY, perimetro;

    public Rectangulo(Point ii, int ladox, int ladoy) {
        verticeII = new Point(ii);
        ladoX = ladox;
        ladoY = ladoy;
        verticeSI = new Point(ii.x(), ii.y() + ladoy);
        verticeSD = new Point(ii.x() + ladox, ii.y() + ladoy);
        verticeSI = new Point(ii.x() + ladox, ii.y());
        perimetro = (2 * ladox) + (2 * ladoy);
    }
}
