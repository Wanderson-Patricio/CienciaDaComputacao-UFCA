package ufca.edu.negocio;

public abstract class Skin {
	// A identificação de uma skin é seu id
	private String id;
	
	// Instncia a skin
	public Skin(String id) {
		this.id = id;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}
	
	@Override
	public boolean equals(Object obj) {
		if(obj instanceof Skin) {
			Skin s = (Skin) obj;
			if(this.id.equals(s.getId())) {
				return true;
			}
		}
		return false;
	}
}
