package ufca.edu.negocio;

import java.util.Scanner;

import ufca.edu.exceptions.CompraNaoPossivelException;
import ufca.edu.exceptions.ContaJaExistenteException;
import ufca.edu.exceptions.ContaNaoEncontradaException;
import ufca.edu.exceptions.RepositorioCheioException;
import ufca.edu.exceptions.SaldoInsuficienteException;
import ufca.edu.exceptions.SenhaErradaException;
import ufca.edu.exceptions.SkinJaCompradaException;

public class Tela {
	private Servidor server;
	
	public Tela(Servidor server) {
		this.server = server;
	}
	
	public void iniciar() {
		Scanner  scan = new Scanner(System.in);
		int option;
		
		do {
			System.out.println("O que voce quer fazer?\n1 - Criar uma nova conta\n2 - Entrar na minha conta"
					+ "\n3 - Sair do jogo\n");
			option = scan.nextInt();
			scan.nextLine();
			
			switch(option){
				case 1: {
					try {
						this.server.criarConta(scan, this.server.getContas().getRepositorio().getMAX_SIZE());
					} catch (ContaJaExistenteException | RepositorioCheioException e) {
						System.out.println(e.getMessage());
					} 
				
					break;
				}
				
				case 2: try {
					this.server.acessarConta(scan);
				} catch (ContaNaoEncontradaException | SenhaErradaException | SkinJaCompradaException
						| SaldoInsuficienteException | CompraNaoPossivelException e) {
					
				} break;
				
				case 3: this.server.sair(); break;
			}
			
			
		}while(option != 3);
		
		scan.close();
	}
}
