package ufca.edu.exceptions;

public class RepositorioCheioException extends Exception{
	
	public RepositorioCheioException() {
		super("Não é possível adicionar, pois o repositório está cheio.");
	}
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
}
