package ufca.edu.classes;

public class Clube {
	String nome;
	int pontos;
	int saldoGols;
	int golsFeitos;
	int golsSofridos;
	int qtdVitorias;
	int qtdEmpates;
	int qtdDerrotas;
	
	Clube(String nome){
		this.nome = nome;
		this.pontos = 0;
		this.saldoGols = 0;
		this.golsFeitos = 0;
		this.golsSofridos = 0;
		this.qtdVitorias = 0;
		this.qtdEmpates = 0;
		this.qtdDerrotas = 0;
	}
	
	Clube(){
		
	}
	
	public void ganhar(int saldoGols) {
		this.pontos += 3;
		this.saldoGols += saldoGols;
		this.qtdVitorias++;
	}
	
	public void empatar() {
		this.pontos += 1;
		this.qtdEmpates++;
	}
	
	public void perder(int saldoGols) {
		this.saldoGols += saldoGols;
		this.qtdDerrotas++;
	}
	
	public void aumentaGolsFeitos(int golsFeitos) {
		this.golsFeitos += golsFeitos;
	}
	
	public void aumentaGolsSofridos(int golsSofridos) {
		this.golsSofridos += golsSofridos;
	}
}