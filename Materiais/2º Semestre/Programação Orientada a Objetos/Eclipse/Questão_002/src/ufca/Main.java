package ufca;

public class Main {
	public static void main(String[] args) {
		Ponto3D p1 = new Ponto3D(1,2,3);
		Ponto3D p2 = new Ponto3D(3,2,1);
		Vetor vet = new Vetor(p1,p2);
		
		System.out.println(vet.modulo());
	}
}
