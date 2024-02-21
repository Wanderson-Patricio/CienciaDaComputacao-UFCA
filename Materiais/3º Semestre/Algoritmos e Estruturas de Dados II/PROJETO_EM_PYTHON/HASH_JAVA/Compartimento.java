public class Compartimento {
    private Recurso[] rec;

    public Compartimento(Recurso[] rec) {
        this.rec = rec;
    }

    @Override
    public String toString() {
        String result = "Recursos no compartimento: \n";
        for(Recurso r: this.rec){
            result += r.toString();
        }

        return result;
    }

    public Compartimento sort(){
        Compartimento novo = new Compartimento(null);

        Recurso aux;

        for(int i=0; i<this.rec.length-1; i++){
            for(int j =i+1; j<this.rec.length; j++){

                if(novo.rec[i].getId() > novo.rec[j].getId()){

                    aux = novo.rec[i];
                    novo.rec[i] = novo.rec[j];
                    novo.rec[j] = aux;

                }

            }
        }

        return novo;
    }

    

}
