package ufca.edu.repositorio;

import ufca.edu.negocio.ContaJogoAbstrata;

public class RepositorioContasVetor implements IRepositorioContas{
	// Define o tamanho máximo do repositorio e o declara na classe
		private ContaJogoAbstrata[] contas;
		private int size;
		private int MAX_SIZE;
		
		// Método para verificar o tamanho atual do repositório
		public int getSize() {
			return size;
		}
		
		// Método para alterar o tamanho atual do repositório
		public void setSize(int size) {
			this.size = size;
		}
		
		public int getMAX_SIZE() {
			return MAX_SIZE;
		}
		
		public void setMAX_SIZE(int MAX_SIZE) {
			this.MAX_SIZE = MAX_SIZE;
		}

		public ContaJogoAbstrata[] getContas() {
			return contas;
		}

		// Instancia o repositorio com o tamanho maximo
		public RepositorioContasVetor(int tam) {
			this.contas = new ContaJogoAbstrata[tam];
			this.MAX_SIZE = tam;
		}
		
		// Adiciona uma contas s no repositorio
		public void adicionar(ContaJogoAbstrata s) {
			this.contas[this.size] = s;
			this.size++;
		}
		
		// Verifica se uma conta está no repositorio e retorna o seu indice
		public int busca(ContaJogoAbstrata s) {
			int index = -1;
			for(int i = 0; i<this.getSize(); i++) {
				if(this.contas[i].equals(s)) {
					index = i;
					break;
				}
			}
			return index;
		}
		
		// Retorna A conta da posição i do vetor
		public ContaJogoAbstrata retornaConta(int i) {
			return this.contas[i];
		}
		
		// Aciona o método toString de todas as contas no repositorio
		public void imprimeRepositorio(){
			System.out.println("Contas no repositorio:\n");
			
			for(int i = 0; i<this.getSize(); i++) {
				System.out.println(this.contas[i].toString());;
			}
		}
		
		// Verifica se uma conta está no repositorio. Se sim, a remove.
		public void remover(ContaJogoAbstrata s) {
			int index = this.busca(s);
			for(int i = index; i<this.size-1; i++) {
				this.contas[i] = this.contas[i+1];
			}
			this.size--;
			System.out.println("A conta foi removida com sucesso.\n");
		}
		
}
