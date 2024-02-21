package ufca.edu.negocio;

import ufca.edu.exceptions.SaldoInsuficienteException;
import ufca.edu.exceptions.SkinJaCompradaException;
import ufca.edu.repositorio.IRepositorioSkins;
import ufca.edu.repositorio.RepositorioSkinsVetor;
import java.util.Random;

public abstract class ContaJogoAbstrata {
	private String nome;
	private String cpf;
	private int idade;
	
	private String nickname;
	private String password;
	
	private int gold;
	private int diamonds;
	private int XP;
	private int level;
	
	private IRepositorioSkins skins;
	
	// Construtor
	public ContaJogoAbstrata(String nome, String cpf, int idade, String nickname, String password, int tam) {
		this.nome = nome;
		this.cpf = cpf;
		this.idade = idade;
		this.nickname = nickname;
		this.password = password;
		this.skins = new RepositorioSkinsVetor(tam);
		this.level = 1;
	}
	
	public IRepositorioSkins getSkins() {
		return skins;
	}




	// getters and setters
	public String getNome() {
		return nome;
	}


	public void setNome(String nome) {
		this.nome = nome;
	}


	public String getNickname() {
		return nickname;
	}


	public void setNickname(String nickname) {
		this.nickname = nickname;
	}


	public String getPassword() {
		return password;
	}


	public void setPassword(String password) {
		this.password = password;
	}


	public int getGold() {
		return gold;
	}


	public void setGold(int gold) {
		this.gold = gold;
	}


	public int getDiamonds() {
		return diamonds;
	}


	public void setDiamonds(int diamonds) {
		this.diamonds = diamonds;
	}


	public int getXP() {
		return XP;
	}


	public void setXP(int xP) {
		XP = xP;
	}


	public int getLevel() {
		return level;
	}


	public void setLevel(int level) {
		this.level = level;
	}


	public String getCpf() {
		return cpf;
	}


	public int getIdade() {
		return idade;
	}
	
	// *************** //////

	// Método para verificar se a senha digitada pelo usuário é igual a cadastrada na conta
	public boolean isPasswordCorrect(String str) {
		boolean result = false;
		if(str.equals(this.password)) {
			result = true;
		}
		return result;
	}


	// Métodos para aumentar e diminuir o gold e o diamond
	public void aumentaGold(int valor) {
		this.gold +=valor;
	}
	
	public void debitaGold(int valor) throws SaldoInsuficienteException{
		if(valor <= this.gold) {
			this.gold -= valor;
		}else {
			throw new SaldoInsuficienteException();
		}
	}

	
	public void aumentaDiamonds(int valor) {
		this.diamonds +=valor;
	}
	
	public void debitaDiamonds(int valor) throws SaldoInsuficienteException{
		if(valor <= this.diamonds) {
			this.diamonds -= valor;
		}else {
			throw new SaldoInsuficienteException();
		}
	}
	
	// Método para converter diamonds em Gold
	public void converteDiamondToGold(int valor) throws SaldoInsuficienteException{
		this.aumentaGold(10*valor);
		this.debitaDiamonds(valor);
	}
	
	
	// Método para aumentar o level da conta
	public void aumentaLevel() {
		if(this.getXP() >= this.getLevel()*100) {
			this.setXP(this.getXP() - this.getLevel()*100);
			this.setLevel(this.getLevel()+1);
			System.out.println("Você aumentou de nível.");
		}
	}
	
	// O método para aumentar o XP depende se a conta é VIP ou não
	public abstract void aumentaXP();
	
	// Método para jogar. Dependendo do resultado a pessoa ganha XP e uro de maneiras diferentes
	public void jogar() {
		Random rand = new Random();
		int result = rand.nextInt(2);
		if(result == 1) {
			this.aumentaXP();
			this.aumentaGold(10);
			System.out.println("Voce ganhou a partida.");
		}else {
			this.aumentaGold(5);
			System.out.println("Voce perdeu a partida.");
		}
	}
	
	public void compraSkin(Skin s) throws SaldoInsuficienteException, SkinJaCompradaException{
		
		if(this.skins.busca(s) != -1) {
			
			throw new SkinJaCompradaException();
			
		}else {
			int valorSkin;
			if(s instanceof SkinGold) {
				
				valorSkin = ((SkinGold) s).getPrecoGold();
				
				if(this.getGold() < valorSkin) {
					throw new SaldoInsuficienteException();
				}else {
					this.debitaGold(valorSkin);
					this.skins.adicionar(s);
				}
				
			}else if(s instanceof SkinDiamonds) {
				
				valorSkin = ((SkinDiamonds) s).getPrecoDiamonds();
				
				if(this.getDiamonds() < valorSkin) {
					throw new SaldoInsuficienteException();
				}else {
					this.debitaDiamonds(valorSkin);
					this.skins.adicionar(s);
				}
			}
			
		}
	}
	
	@Override
	public boolean equals(Object obj) {
		if(obj instanceof ContaJogoAbstrata) {
			ContaJogoAbstrata temp = (ContaJogoAbstrata) obj;
			if(temp.getCpf().equals(this.getCpf())) {
				return true;
			}
		}
		return false;
	}
	
	@Override
	public String toString() {
		String frase = "Nickname: " + this.nickname +
				"\nGold: " + this.gold + 
				"\nDiamantes: "+ this.diamonds +
				"\nXP: "+this.XP + 
				"\nLevel: "+this.level + "\n\n";
		return frase;
	}
}
