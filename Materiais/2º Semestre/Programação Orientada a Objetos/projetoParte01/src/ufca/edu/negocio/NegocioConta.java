package ufca.edu.negocio;

import ufca.edu.exceptions.ContaJaExistenteException;
import ufca.edu.exceptions.ContaNaoEncontradaException;
import ufca.edu.exceptions.RepositorioCheioException;
import ufca.edu.repositorio.IRepositorioContas;
import ufca.edu.repositorio.RepositorioContasVetor;

public class NegocioConta {
	private IRepositorioContas repositorio;
	
	public NegocioConta(int tam){
		this.repositorio = new RepositorioContasVetor(tam);
	}
	
	public IRepositorioContas getRepositorio() {
		return repositorio;
	}




	public int busca(ContaJogoAbstrata conta){
		int index = this.repositorio.busca(conta);
		return index;
	}
	
	
	
	public void adicionar(ContaJogoAbstrata conta) throws ContaJaExistenteException , 
														RepositorioCheioException{
		
		if(this.repositorio.getSize() >= this.repositorio.getMAX_SIZE()) {
			
			throw new RepositorioCheioException();
		
		}else {
			int index = this.busca(conta);
			
			if(index != -1) {
				
				throw new ContaJaExistenteException();
				
			}else {
				
				this.repositorio.adicionar(conta);
				
			}
			
		}
	}
	
	
	public void remover(ContaJogoAbstrata conta) throws ContaNaoEncontradaException{
		
		int index = this.repositorio.busca(conta);
		
		if(index == -1) {
			
			throw new ContaNaoEncontradaException();
			
		}else {
			
			this.repositorio.remover(conta);
		}
		
	}
	
	public void imprimeRepositorio() {
		
		this.repositorio.imprimeRepositorio();
		
	}
}
