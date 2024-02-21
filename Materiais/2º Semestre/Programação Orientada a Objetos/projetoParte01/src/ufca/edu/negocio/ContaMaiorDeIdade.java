package ufca.edu.negocio;

public class ContaMaiorDeIdade extends ContaJogoAbstrata{
	
	public ContaMaiorDeIdade(String nome, String cpf, int idade, String nickname, String password, int tam) {
		super(nome, cpf, idade, nickname, password, tam);
	}
	
	// cada partida ganha aumenta 10 em XP do usuario
	public void aumentaXP() {
		this.setXP(getXP()+20);
	}
	
	// Para cada unidade monetária paga é retornado 50 diamantes para a conta
	public void comprarDiamantes(int valor) {
		this.aumentaDiamonds(50*valor);
		System.out.println("Compra realizada com sucesso.");
	}
}
