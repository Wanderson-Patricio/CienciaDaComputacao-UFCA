package ufca.edu.exceptions;

public class SaldoInsuficienteException extends Exception{

	public SaldoInsuficienteException() {
		super("Você não pode realizar a compra, pois seu saldo é insuficiente.");
	}
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	
	
}
