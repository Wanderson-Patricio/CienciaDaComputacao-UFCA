package ufca;
import java.lang.Math;

public class Vetor {
	Ponto3D p1;
	Ponto3D p2;
	
	Vetor(Ponto3D p1, Ponto3D p2){
		this.p1 = p1;
		this.p2 = p2;
	}
	
	double modulo() {
		double dist = Math.sqrt(Math.pow(p1.x-p2.x, 2)+Math.pow(p1.y-p2.y, 2)+Math.pow(p1.z-p2.z, 2));
		return dist;
	}
}