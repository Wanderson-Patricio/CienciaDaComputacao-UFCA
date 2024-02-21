package ufca.edu.exceptions;

public class CompraNaoPossivelException extends Exception{
	
	public CompraNaoPossivelException() {
		super("Somente maiores de Idade podem comprar diamantes.");
	}
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
}
