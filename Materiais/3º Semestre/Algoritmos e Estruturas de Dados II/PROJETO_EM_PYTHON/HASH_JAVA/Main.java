public class Main {
    public static void main(String[] args) {
        Recurso[] rec = new Recurso[4];

        for(int i = 0; i<rec.length; i++){
            rec[i] = new Recurso("comida", -i);
        }

        Compartimento c = new Compartimento(rec);
        System.out.println(c.sort().toString());
        System.out.println(c.toString());
    }
}
