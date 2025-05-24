package libcodificador;

public class CodificadorCesar {
    public native String codificar(String mensaje, int clave);
    public native String decodificar(String mensaje, int clave);

    public CodificadorCesar() {
        try {
            System.loadLibrary("cod");
            System.out.println("Biblioteca cargada exitosamente!");
        } catch (UnsatisfiedLinkError e) {
            System.err.println("Carga de la biblioteca fallida: " + e.getMessage());
        }
    }
}
