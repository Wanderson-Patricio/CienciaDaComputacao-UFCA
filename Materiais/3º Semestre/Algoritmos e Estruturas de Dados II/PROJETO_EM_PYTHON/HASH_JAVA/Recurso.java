public class Recurso{

    private String nome;
    private int id;

    public Recurso(String nome, int id) {
        this.nome = nome;
        this.id = id;
    }
    
    public int getId() {
        return id;
    }

    public String toString(){
        return this.nome + " - " + this.id + "\n";
    }

    public boolean isEquals(Recurso r){
        return this.id == r.id;
    }
}