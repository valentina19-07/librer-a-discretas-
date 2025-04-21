package libcodificador;

public class CodificadorCesar {
    public native String codificar(String mensaje, int clave);
    public native String decodificar(String mensaje, int clave);
}
