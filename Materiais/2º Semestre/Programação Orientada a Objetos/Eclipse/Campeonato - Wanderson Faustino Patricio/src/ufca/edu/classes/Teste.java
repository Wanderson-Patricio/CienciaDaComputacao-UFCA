package ufca.edu.classes;


public class Teste {
	public static void main(String[] args) {
		
		// Inicializa todos os Times do Campeonato Brasileiro
		Clube c1 = new Clube("America-MG");
		Clube c2 = new Clube("Athletico-PR");
		Clube c3 = new Clube("Atletico-MG");
		Clube c4 = new Clube("Bahia");
		Clube c5 = new Clube("Botafogo");
		Clube c6 = new Clube("Corinthians");
		Clube c7 = new Clube("Coritiba");
		Clube c8 = new Clube("Cruzeiro");
		Clube c9 = new Clube("Cuiaba");
		Clube c10 = new Clube("Flamengo");
		Clube c11 = new Clube("Fluminense");
		Clube c12 = new Clube("Fortaleza");
		Clube c13 = new Clube("Goias");
		Clube c14 = new Clube("Gremio");
		Clube c15 = new Clube("Internacional");
		Clube c16 = new Clube("Palmeiras");
		Clube c17 = new Clube("Bragantino");
		Clube c18 = new Clube("Santos");
		Clube c19 = new Clube("Sao Paulo");
		Clube c20 = new Clube("Vasco da Gama");
		
		// Cria o campeonato Brasileiro com os times criados
		Clube clubes[] = {c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,c14,c15,c16,c17,c18,c19,c20};
		Campeonato Brasileirao = new Campeonato(clubes);
		
		// Faz a separação dos jogos e inicializa as partidas, exibindo os resultados
		System.out.println("Resultado das Partidas: \n");
		Brasileirao.jogarCampeonato();
		
		// Organiza a Tabela
		Brasileirao.getClassificaçao();
		
		// Imprime a Tabela
		System.out.println();
		Brasileirao.imprimeTabela();
		System.out.println();
		
		// Imprime quem foi o campeão
		Brasileirao.getCampeao();
	}
}
