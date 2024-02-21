package ufca.edu.interfaceUsuario;

import ufca.edu.negocio.Servidor;
import ufca.edu.negocio.Tela;


public class InterfaceUsuario {
	public static void main(String[] args) {
		
		int tamanho = 1000;
		Servidor server = new Servidor(tamanho);
		
		Tela tela = new Tela(server);
		tela.iniciar();
		
	}
}
