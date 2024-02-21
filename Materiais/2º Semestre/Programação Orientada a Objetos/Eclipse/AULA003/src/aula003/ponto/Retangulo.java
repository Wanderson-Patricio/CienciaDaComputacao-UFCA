package aula003.ponto;

public class Retangulo {
	Ponto2D p1;
	Ponto2D p2;
	
	Retangulo(Ponto2D p1, Ponto2D p2){
		this.p1 = p1;
		this.p2 = p2;
	}
	
	Retangulo(double x1,double y1,double x2,double y2){
		p1.x = x1;
		p1.y = y1;
		p2.x = x2;
		p2.y = y2;
	}
	
	double findXMax() {
		if(p1.x>p2.x) {
			return p1.x;
		}else {
			return p2.x;
		}
	}
	
	double findYMax() {
		if(p1.y>p2.y) {
			return p1.y;
		}else {
			return p2.y;
		}
	}
	
	double findXMin() {
		if(p1.x>p2.x) {
			return p2.x;
		}else {
			return p1.x;
		}
	}
	
	double findYMin() {
		if(p1.y>p2.y) {
			return p2.y;
		}else {
			return p1.y;
		}
	}
	
	boolean isInside(Ponto2D p) {
		if((p.x>this.findXMax())||(p.x<this.findXMin())) {
			return false;
		}
		if((p.y>this.findYMax())||(p.y<this.findYMin())) {
			return false;
		}
		return true;
	}
}
