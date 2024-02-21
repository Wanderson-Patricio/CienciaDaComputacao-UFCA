package ufca.edu.repositorio;

import ufca.edu.negocio.Skin;
import ufca.edu.negocio.SkinDiamonds;
import ufca.edu.negocio.SkinGold;

public class RepositorioSkinsVetor implements IRepositorioSkins{
	// Define o tamanho máximo do repositorio e o declara na classe
	private Skin[] skins;
	private int size;
	
	// Método para verificar o tamanho atual do repositório
	public int getSize() {
		return this.size;
	}
	
	// Método para alterar o tamanho atual do repositório
	public void setSize(int size) {
		this.size = size;
	}

	// Instancia o repositorio com o tamanho maximo
	public RepositorioSkinsVetor(int tam) {
		this.skins = new Skin[tam];
	}
	
	public Skin getSkin(int i) {
		return this.skins[i];
	}
	
	// Adiciona uma skin s no repositorio
	public void adicionar(Skin s) {
		this.skins[this.size] = s;
		this.size++;
	}
	
	// Verifica se uma skin está no repositorio e retorna o seu indice
	public int busca(Skin s) {
		int index = -1;
		for(int i = 0; i<this.getSize(); i++) {
			if(this.skins[i].equals(s)) {
				index = i;
				break;
			}
		}
		return index;
	}
	
	// Aciona o método toString de todas as skins no repositorio
	public void imprimeRepositorio(){
		System.out.println("Skins no repositorio:\n");
		
		for(int i = 0; i<this.getSize(); i++) {
			System.out.println(this.skins[i].toString());;
		}
	}
	
	// Verifica se uma skin está no repositorio. Se sim, a remove.
	public void remover(Skin s) {
		int index = this.busca(s);
		for(int i = index; i<this.size-1; i++) {
			this.skins[i] = this.skins[i+1];
		}
		this.size--;
		System.out.println("A skin foi removida com sucesso.\n");
	}
	
	// Método para ordenar as skins em função do seu id
	public void ordenaRepositorio() {
		Skin menor;
		int tam = this.skins.length;
		for(int i = 0; i<tam-1; i++) {
			menor = this.skins[i];
			for(int j = i+1; j<tam; j++) {
				if(Integer.valueOf(this.skins[j].getId()) < Integer.valueOf(menor.getId())) {
					Skin temp = this.skins[j];
					this.skins[j] = menor;
					menor = temp;
				}
			}
		}
	}
	
	// Método para criar um repositorio de skins aleatorias
	public RepositorioSkinsVetor criaRepositorio(int tam) {
		RepositorioSkinsVetor repSkinsJogo = new RepositorioSkinsVetor(tam);
		
		//Nessa parte do codigo criaremos skins aleatorias a partir da função Random
		int totalDeSkins = tam/10;
		Skin s;
		for(int i = 1; i<=totalDeSkins; i++) {
			String id;
			int preco;

			id = "" + i;
			
			preco = (i%10 + 1)*1100;
			
			// Se option=0 cria uma SkinGold, caso contrario uma SkinDiamonds
			int option = i%3;
			if(option == 0) {
				s = new SkinGold(id,preco);
			}else {
				s = new SkinDiamonds(id,preco);
			}
			repSkinsJogo.adicionar(s);
		}
		
		return repSkinsJogo;
	}
}
