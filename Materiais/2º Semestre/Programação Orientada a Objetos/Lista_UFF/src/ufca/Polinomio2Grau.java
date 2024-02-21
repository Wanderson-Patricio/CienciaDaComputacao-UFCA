package ufca;
import java.lang.Math;

public class Polinomio2Grau {
	double a;
	double b;
	double c;
	
	Polinomio2Grau(double a, double b, double c){
		this.a = a;
		this.b = b;
		this.c = c;
	}
	
	double Delta(){
		return b*b-4*a*c;
	}
	
	boolean temRaiz() {
		boolean result = true;
		if(this.Delta()<0) {
			result = false;
		}
		
		return result;
	}
	
	double raizPos() {
		double x = (-this.b + Math.sqrt(this.Delta()))/(2*this.a);
		return x;
	}
	
	double raizNeg() {
		double x = (-this.b - Math.sqrt(this.Delta()))/(2*this.a);
		return x;
	}
	
	void imprimeRaiz() {
		if(this.temRaiz()) {
			if(this.Delta() == 0) {
				System.out.println("As raiz e " + this.raizPos());
			}else {
				System.out.println("As raízes sao " + this.raizPos() + " e " + this.raizNeg());
			}
		}else {
			System.out.println("O polinomio nao tem raiz real.");
		}
	}
}
