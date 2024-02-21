package main;
import classes.Tabuleiro;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Tabuleiro tab = new Tabuleiro("Wanderson", "Thayna");
		
		Scanner scan = new Scanner(System.in);
		
		while(tab.getJogada() < 1000) {
			tab.iniciarPartida(scan);
		}
		
		scan.close();
	}
}
