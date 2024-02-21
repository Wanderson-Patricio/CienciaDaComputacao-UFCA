package ufca;

public class Produto {
	String nome;
	double preco;
	int quantidade;
	
	Produto(String nome, double preco, int quantidade){
		this.nome = nome;
		this.preco = preco;
		this.quantidade = quantidade;
	}
	
	double valorTotal() {
		double precoTotal;
		if(this.quantidade <= 10) {
			precoTotal = (this.preco)*(this.quantidade);
		}else if(this.quantidade <=20) {
			precoTotal = 0.9*(this.preco)*(this.quantidade);
		}else if(this.quantidade<=50) {
			precoTotal = 0.8*(this.preco)*(this.quantidade);
		}else {
			precoTotal = 0.75*(this.preco)*(this.quantidade);
		}
		
		return precoTotal;
	}
	
	void imprimeValor() {
		System.out.println(this.nome + ": R$ " + this.valorTotal());
	}
}