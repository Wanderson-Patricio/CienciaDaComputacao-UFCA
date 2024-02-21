package ufca;

public class Main {
	public static void main(String[] args) {
		double a = 1;
		double b = 4;
		double c = 5;
		
		Polinomio2Grau p = new Polinomio2Grau(a,b,c);
		p.imprimeRaiz();
	}
}
