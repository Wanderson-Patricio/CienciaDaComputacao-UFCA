package aula003.ponto;

public class Ponto2D {
	double x;
    double y;

    Ponto2D(){

    }

    Ponto2D(double x, double y){
        this.x = x;
        this.y = y;
    }

    Ponto2D(double coordenada){
        this.x = coordenada;
        this.y = coordenada;
    }

    Ponto2D(Ponto2D ponto){
        this.x = -ponto.x;
        this.y = -ponto.y;
    }
}
