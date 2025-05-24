package aplicacion;

import libjni.libcodificador.CodificadorCesar;

public class Aplicacion {
	CodificadorCesar cc = null;

	static {
		System.loadLibrary("cod");
	}

	public Aplicacion(String mensaje, String opc, int clave){
		this.cc = new  CodificadorCesar();
		switch(opc){
			case "cod":
				System.out.println("\"" + mensaje + "\"" + " cifrado: \"" + cc.codificar(mensaje, clave) + "\"\n");
				break;
			case "decod":
				System.out.println("\"" +mensaje + "\"" + " descifrado: \"" + cc.decodificar(mensaje, clave) + "\"\n");
				break;
		}
	}

	public static void main(String[] args){
		new Aplicacion(args[0], args[1], Integer.parseInt(args[2]));
	}
}
