package ufca.edu.negocio;

public class SkinGold extends Skin{
	// A skin Gold tem o preco em Gold
	private int precoGold;
	
	// Instancia a skin Gold
	public SkinGold(String id, int precoGold) {
		super(id);
		this.precoGold = precoGold;
	}

	public int getPrecoGold() {
		return precoGold;
	}

	public void setPrecoGold(int precoGold) {
		this.precoGold = precoGold;
	}
	
	@Override
	public String toString() {
		String frase = "Id da Skin: " + this.getId() + "\nValor da Skin: " + this.getPrecoGold() + " ouros\n";
		return frase;
	}
}
