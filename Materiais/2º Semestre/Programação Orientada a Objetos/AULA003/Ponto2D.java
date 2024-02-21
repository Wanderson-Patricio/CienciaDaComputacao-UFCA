package AULA003;
import java.util.Scanner;

class Ponto2D{
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

class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Digite as coordenadas do ponto:");
        System.out.println("x: ");
        double x = scan.nextDouble();
        System.out.println("y: ");
        double y = scan.nextDouble();
        Ponto2D p1 = new Ponto2D();
        Ponto2D p2 = new Ponto2D(x,y);
        Ponto2D p3 = new Ponto2D(x);
        Ponto2D p4 = new Ponto2D(p2);
        System.out.println("p1: (" + p1.x + " , " + p1.y + ")");
        System.out.println("p2: (" + p2.x + " , " + p2.y + ")");
        System.out.println("p3: (" + p3.x + " , " + p3.y + ")");
        System.out.println("p4: (" + p4.x + " , " + p4.y + ")");
        scan.close();
    }
}