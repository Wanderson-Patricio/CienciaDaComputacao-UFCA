package ufca.edu.negocio;

public class SkinDiamonds extends Skin{
	// A skin Diamonds tem um preco em diamantes
	private int precoDiamonds;
	
	// Instancia a skin Diamonds
	public SkinDiamonds(String id, int precoDiamonds) {
		super(id);
		this.precoDiamonds = precoDiamonds;
	}

	public int getPrecoDiamonds() {
		return precoDiamonds;
	}

	public void setPrecoDiamonds(int precoDiamonds) {
		this.precoDiamonds = precoDiamonds;
	}
	
	@Override
	public String toString() {
		String frase = "Id da Skin: " + this.getId() + "\nValor da Skin: " + this.getPrecoDiamonds() + " diamantes\n";
		return frase;
	}
}
