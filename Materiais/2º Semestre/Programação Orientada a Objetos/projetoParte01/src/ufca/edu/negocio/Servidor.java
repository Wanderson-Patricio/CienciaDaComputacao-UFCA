package ufca.edu.negocio;

import java.util.Scanner;

import ufca.edu.exceptions.CompraNaoPossivelException;
import ufca.edu.exceptions.ContaJaExistenteException;
import ufca.edu.exceptions.ContaNaoEncontradaException;
import ufca.edu.exceptions.RepositorioCheioException;
import ufca.edu.exceptions.SaldoInsuficienteException;
import ufca.edu.exceptions.SenhaErradaException;
import ufca.edu.exceptions.SkinJaCompradaException;
import ufca.edu.repositorio.IRepositorioSkins;
import ufca.edu.repositorio.RepositorioSkinsVetor;

public class Servidor {
	private NegocioConta contas;
	private IRepositorioSkins skinsJogo;

	public Servidor(int tam){
		this.contas = new NegocioConta(tam);
		
		//**************Criação de contas de Teste**********************//
		
		try {
			
			ContaJogoAbstrata contaPaola = new ContaMaiorDeIdade("Paola Rodrigues de Godoy Accioly", "0000", 20, "Paola001@UFCA.EDU", "paola@ufca", tam);
			ContaJogoAbstrata contaWanderson = new ContaMaiorDeIdade("Wanderson Faustino Patricio", "0001", 12, "Wanderson002@UFCA.EDU", "wanderson@ufca", tam);
			
			contaPaola.setXP(300);
			contaPaola.setLevel(15);
			
			contaWanderson.setXP(500);
			contaWanderson.setLevel(20);
			
			contaPaola.aumentaDiamonds(30000);
			contaWanderson.aumentaGold(30000);
			
			
			contas.adicionar(contaPaola);
			contas.adicionar(contaWanderson);
			
			
		} catch (ContaJaExistenteException | RepositorioCheioException e) {
			
		}
		
		
		//**************************************************************//
		
		this.skinsJogo = new RepositorioSkinsVetor(tam);
		skinsJogo = skinsJogo.criaRepositorio(tam);
	}
	
	public NegocioConta getContas() {
		return contas;
	}

	public IRepositorioSkins getSkinsJogo() {
		return skinsJogo;
	}
	
	public void criarConta(Scanner scan, int tam) throws ContaJaExistenteException , RepositorioCheioException{
		System.out.println("Nome:");
		String nome = scan.nextLine();
		
		System.out.println("CPF:");
		String CPF = scan.nextLine();
		
		System.out.println("Idade:");
		int idade = scan.nextInt();
		scan.nextLine();
		
		System.out.println("Nickname:");
		String nickname = scan.nextLine();
		
		System.out.println("Qual sera a sua senha de acesso?");
		String password = scan.nextLine();
		
		ContaJogoAbstrata conta;
		
		if(idade < 18) {
			
			conta = new ContaMenorDeIdade(nome, CPF, idade, nickname, password, tam);
			
		}else {
			
			conta = new ContaMenorDeIdade(nome, CPF, idade, nickname, password, tam);
			
		}
		
		if(this.contas.busca(conta) != -1) {
			throw new ContaJaExistenteException();
		}else {

			try {
				contas.adicionar(conta);
				System.out.println("Conta criada com sucesso!");
			} catch (ContaJaExistenteException | RepositorioCheioException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
		
	}

	public void sair() {
		System.out.println("Obrigado por jogar o nosso jogo :):):)");
	}
	
	//****************Ajeitar Depois********************//
	
	public ContaJogoAbstrata solicitaDados(Scanner scan) throws ContaNaoEncontradaException{
		System.out.println("Digite seu CPF:");
		String CPF = scan.nextLine();
		ContaJogoAbstrata contaTemp = new ContaMenorDeIdade("", CPF, 0, "", "", 1);
		
		int index = contas.busca(contaTemp);
		
		if(index == -1) {
		
			throw new ContaNaoEncontradaException();
			
		}else {
			
			contaTemp = contas.getRepositorio().retornaConta(index);
			return contaTemp;
		}
	}
	
	public boolean verificaCredenciaisDaConta(Scanner scan, ContaJogoAbstrata conta) throws ContaNaoEncontradaException, 
																							SenhaErradaException{
		
		boolean result = false;;
		
		if(this.contas.busca(conta) == -1) {
			
			throw new ContaNaoEncontradaException();
			
		}else{
			
			String senha = "";
			int tentativas = 1;
			
			while(!conta.isPasswordCorrect(senha) && tentativas < 6) {
				
				System.out.println("Digite sua senha:");
				senha = scan.nextLine();
				tentativas ++;
				
			}
			
			if(tentativas == 6) {
				
				throw new SenhaErradaException();
				
			}else {
				
				result = true;
				
			}
		}
		
		
		return result;
	}
	
	public void jogar(ContaJogoAbstrata conta) {
		conta.jogar();
		conta.aumentaLevel();
	}
	
	public void abrirArmarioDeSkins(ContaJogoAbstrata conta) {
		conta.getSkins().imprimeRepositorio();
	}
	
	public void comprarSkins(Scanner scan, ContaJogoAbstrata conta) throws SkinJaCompradaException, SaldoInsuficienteException{
		this.skinsJogo.imprimeRepositorio();
		
		skinsJogo.imprimeRepositorio();
		System.out.println("Digite o id da Skin que deseja comprar.");
		String id = scan.nextLine();
		
		Skin s = new SkinGold(id, 0);
		s = this.skinsJogo.getSkin(this.skinsJogo.busca(s));
		
		conta.compraSkin(s);
	}
	
	public void comprarDiamantes(Scanner scan, ContaJogoAbstrata conta) throws CompraNaoPossivelException{
		if(conta.getIdade() < 18) {
			
			throw new CompraNaoPossivelException();
			
		}else {
			
			System.out.println("Quanto voce quer comprar?");
			int valor = scan.nextInt();
			scan.nextLine();
			conta.aumentaDiamonds(valor);
			
		}
	}
	
	public void converterDiamanteParaOuro(Scanner scan, ContaJogoAbstrata conta) throws SaldoInsuficienteException{
		
		System.out.println("Quantos diamantes você deseja converter?");
		int valor = scan.nextInt();
		scan.nextLine();
		conta.converteDiamondToGold(valor);
		
	}
	
	public void atualizarDadosDaConta(Scanner scan, ContaJogoAbstrata conta) throws ContaNaoEncontradaException, SenhaErradaException{
		
		System.out.println("Qual o novo nome nickname deseja?");
		String novo = scan.nextLine();
		conta.setNickname(novo);
		
		boolean result = this.verificaCredenciaisDaConta(scan, conta);
		
		if(result) {
			
			System.out.println("Qual a senha nova?");
			String senhaNova1;
			String senhaNova2;
			senhaNova1 = scan.nextLine();
			System.out.println("Digite a nova senha novamente.");
			senhaNova2 = scan.nextLine();
			
			while(!senhaNova1.equals(senhaNova2)) {
				System.out.println("Confirme a senha novamente.");
				senhaNova2 = scan.nextLine();
			}
			
			conta.setPassword(senhaNova1);
			System.out.println("Senha atualizada com sucesso.");
			
		}
		
	}
	
	public void excluirConta(Scanner scan, ContaJogoAbstrata conta) throws ContaNaoEncontradaException{
		
		System.out.println("Voce realmente deseja excluir a sua conta? (Digite sim ou nao)");
		String excluir = scan.nextLine();
		
		if(excluir.equals("sim")) {
		
			this.contas.remover(conta);
			
			System.out.println("Sua conta foi excluida com sucesso.");
			
		}
		
	}
	
	public void acessarConta(Scanner scan) throws ContaNaoEncontradaException, SenhaErradaException, SkinJaCompradaException, SaldoInsuficienteException, CompraNaoPossivelException{
		
		ContaJogoAbstrata conta = this.solicitaDados(scan);
		
		if(this.contas.busca(conta) == -1) {
			throw new ContaNaoEncontradaException();
		}
		
		boolean result = this.verificaCredenciaisDaConta(scan, conta);
		
		if(result) {
			
			boolean continuar = true;
			int option;
			
			while(continuar) {
				
				System.out.println(conta.toString());
				
				System.out.println("O que deseja fazer?\n1 - Jogar\n2 - Abrir armario de Skins\n3 - "
						+ "Comprar Skins\n4 - Comprar Diamantes\n5 - Converter Diamantes para ouro\n"
						+ "6 - Atualizar Dados da Conta\n7 - Excluir minha conta\n8 - Sair da conta");
				
				option = scan.nextInt();
				scan.nextLine();
				
				try {
					
					switch(option) {
					
					case 1: this.jogar(conta); break;
					case 2: this.abrirArmarioDeSkins(conta); break;
					case 3: this.comprarSkins(scan, conta); break;
					case 4:	this.comprarDiamantes(scan, conta); break;
					case 5: this.converterDiamanteParaOuro(scan, conta); break;
					case 6: this.atualizarDadosDaConta(scan, conta); break;
					case 7: this.excluirConta(scan, conta); break;
					case 8: continuar = false; break;
					
					}
					
				}catch(ContaNaoEncontradaException | SenhaErradaException | SkinJaCompradaException
						| SaldoInsuficienteException | CompraNaoPossivelException e) {
					
					System.out.println(e.getMessage());
					
				}
				
			}
			
		}
		
		
		
	}
	//**************************************************//
}
