package teste;
import leituraEEscrita.Arquivo;

public class Main {
	public static void main(String args[]) {
		String caminho = "InformacoesCapitais.txt";
		String texto = Arquivo.read(caminho);
		
		String[] capitais = texto.split("\n");
		
		for(String capital: capitais) {
			String[] informacoes = capital.split(",");
			System.out.println("Nome: " + informacoes[0]);
			System.out.println("Temperatura: " + informacoes[1]);
			System.out.println("Populacao: " + informacoes[2]);
			System.out.println("Altitude: " + informacoes[3]);
		}
		
	}
}
