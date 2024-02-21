package ufca.edu.negocio;

public class ContaMenorDeIdade extends ContaJogoAbstrata{
	
	// O menor de Idade não pode fazer compras de diamantes no jogo
	
	public ContaMenorDeIdade(String nome, String cpf, int idade, String nickname, String password, int tam) {
		super(nome, cpf, idade, nickname, password, tam);
	}
	
	//// Para cada vitoria a contaMenorDeIdade aumenta em 10 o XP
	public void aumentaXP() {
		this.setXP(getXP()+10);
	}
}
