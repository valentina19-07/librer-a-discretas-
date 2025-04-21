package aplicacion;

import libcodificador.CodificadorCesar;

public class Aplicacion {
	CodificadorCesar cc = null;

	static {
		System.loadLibrary("cod");
	}

	public Aplicacion(){
		this.cc = new  CodificadorCesar();
		int clave = 10;
		String mensaje = "Hola mundo";
		String mensajeCodificado = cc.codificar(mensaje, clave);
		String mensajeDecodificado = cc.decodificar(mensajeCodificado, clave);
		System.out.println("\"" + mensaje + "\"" + " cifrado: \"" + mensajeCodificado + "\"\n");
		System.out.println("\"" + mensajeCodificado + "\"" + " descifrado: \"" + mensajeDecodificado + "\"\n");
	}

	public static void main(String[] args){
		new Aplicacion();
	}
}
