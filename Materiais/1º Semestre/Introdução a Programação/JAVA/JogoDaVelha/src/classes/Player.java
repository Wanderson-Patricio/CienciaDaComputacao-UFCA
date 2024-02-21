package classes;

public class Player {
	private String name;
	private char symbol;
	private int qtdVitorias;
	
	public Player(String name, char symbol) {
		this.symbol = symbol;
		this.name = name;
	}

	public char getSymbol() {
		return symbol;
	}

	public String getName() {
		return name;
	}

	public int getQtdVitorias() {
		return qtdVitorias;
	}
	
	public void ganhar() {
		this.qtdVitorias++;
	}
}
