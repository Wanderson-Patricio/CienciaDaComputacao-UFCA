package aula003.ponto;
import java.util.Scanner;


public class Main {
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
        Retangulo ret = new Retangulo(p1,p2);
        if(ret.isInside(p3)) {
        	System.out.println("Está Dentro");
        }else {
        	System.out.println("Está fora");
        }
        
        scan.close();
    }
}
