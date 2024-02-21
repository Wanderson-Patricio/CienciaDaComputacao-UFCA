package classes;

import java.util.Scanner;

public class Tabuleiro {
	private Player playerX;
	private Player playerO;
	private char[][] tabuleiro;
	private int partida;
	private int jogada;
	
	public Tabuleiro(String nameX, String nameO) {
		this.playerX = new Player(nameX, 'X');
		this.playerO = new Player(nameO, 'O');
		this.partida = 1;
		this.tabuleiro = new char[3][3];
		
		for(int i=0; i<3; i++) {
			for(int j = 0; j<3; j++) {
				this.tabuleiro[i][j] = ' ';
			}
		}
		
	}
	
	
	
	public Player getPlayerX() {
		return playerX;
	}



	public void setPlayerX(Player playerX) {
		this.playerX = playerX;
	}



	public Player getPlayerO() {
		return playerO;
	}



	public void setPlayerO(Player playerO) {
		this.playerO = playerO;
	}



	public char[][] getTabuleiro() {
		return tabuleiro;
	}



	public void setTabuleiro(char[][] tabuleiro) {
		this.tabuleiro = tabuleiro;
	}



	public int getPartida() {
		return partida;
	}



	public void setPartida(int partida) {
		this.partida = partida;
	}

	

	public int getJogada() {
		return jogada;
	}



	public void setJogada(int jogada) {
		this.jogada = jogada;
	}



	private void imprimeTab() {
		
		String name = (this.jogada%2 == 0) ? this.playerX.getName() : this.playerO.getName();
		System.out.println("Esta rodada e de " + name);
		
		System.out.println("");
		
		String linha;
		for(int i=0; i<3; i++) {
			
			linha = "";
					
			for(int j = 0; j<3; j++) {
				linha += "[" + this.tabuleiro[i][j] + "]";
			}
			
			System.out.println("\t" + linha);
		}
	}
	
	
	private boolean isVitoria() {
		// Verificando a linha
		for(int i = 0; i<3; i++) {
			if(this.tabuleiro[i][0] == this.tabuleiro[i][1] && this.tabuleiro[i][0] == this.tabuleiro[i][2] && this.tabuleiro[i][0] != ' ') {
				return true;
			}
		}
		
		// Verificando a coluna
		for(int j = 0; j<3; j++) {
			if(this.tabuleiro[0][j] == this.tabuleiro[1][j] && this.tabuleiro[0][j] == this.tabuleiro[2][j] && this.tabuleiro[0][j] != ' ') {
				return true;
			}
		}
		
		// Verificando a diagonal principal
		if(this.tabuleiro[0][0] == this.tabuleiro[1][1] && this.tabuleiro[0][0] == this.tabuleiro[2][2] && this.tabuleiro[0][0] != ' ') {
			return true;
		}
		
		// Verificando a diagonal secundária
		if(this.tabuleiro[2][0] == this.tabuleiro[1][1] && this.tabuleiro[1][1] == this.tabuleiro[0][2] && this.tabuleiro[2][0] != ' ') {
			return true;
		}
		
		
		return false;
	}
	
	
	private void aumentaVitorias() {
		if(this.jogada%2 == 1) {
			this.playerX.ganhar();
		}else {
			this.playerO.ganhar();
		}
	}
	
	
	private void preencheUltimaLinha() {
		for(int linha=0; linha<3; linha++) {
			for(int coluna=0; coluna<3; coluna++) {
				if(this.tabuleiro[linha][coluna] == ' ') {
					this.setCelula(linha, coluna);
				}
			}
		}
	}
	
	
	
	private void setCelula(int linha, int coluna) {
		this.tabuleiro[linha][coluna] = (this.jogada%2 == 0) ? this.playerX.getSymbol() : this.playerO.getSymbol();
	}
	
	private boolean isCelulaOcupada(int linha, int coluna) {
		return (this.tabuleiro[linha][coluna] != ' ');
	}
	
	private boolean indexOutOfRange(int linha, int coluna) {
		return (linha < 1 || linha > 3 || coluna < 1 || coluna > 3);
	}
	
	
	public void iniciarPartida(Scanner scan) {
		this.jogada = 0;
		int linha = 1, coluna = 1;
		
		for(int i=0; i<3; i++) {
			for(int j = 0; j<3; j++) {
				this.tabuleiro[i][j] = ' ';
			}
		}
		
		System.out.println("Partida: " + this.partida);
		System.out.println("Jogador 1: "+ this.playerX.getName() + "(" + this.playerX.getSymbol() + ")" + "\t - "  + this.playerX.getQtdVitorias() + " vitorias");
		System.out.println("Jogador 2: "+ this.playerO.getName() + "(" + this.playerO.getSymbol() + ")" + "\t - "  + this.playerO.getQtdVitorias() + " vitorias \n");
		
		while(this.jogada < 8 && !isVitoria()) {
			this.imprimeTab();
			
			do {
				
				System.out.println("Escolha a linha:");
				linha = scan.nextInt();
				scan.nextLine();
				
				System.out.println("Escolha a coluna:");
				coluna = scan.nextInt();
				scan.nextLine();
			}while(indexOutOfRange(linha, coluna) || isCelulaOcupada(linha-1, coluna-1));
			
			this.setCelula(linha-1, coluna-1);
			this.jogada++;
			
		}
		
		this.partida++;
		
		if(this.jogada == 8) {
			
			this.preencheUltimaLinha();
			
			if(isVitoria()) {
				this.aumentaVitorias();
			}else {
				System.out.println("Deu empate.");
			}
			
		}else {
			
			this.aumentaVitorias();
			
		}
		
		this.imprimeTab();
		
	}
}
