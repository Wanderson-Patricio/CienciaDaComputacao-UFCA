package ufca.edu.classes;
import java.util.Random;

public class Campeonato {
	Clube[] clubes;
	
	Campeonato(Clube[] clubes){
		this.clubes = clubes;
	}
	
	Campeonato(){
		
	}
	
	
	// Código Para gerar as partidas com resultados aleatórios
	public void jogarPartida(Clube v, Clube m) {
		// Escolhe aleatoriamente quantos gols cada time fez. os gols variam de 0 a 5
		Random rand = new Random();
		int golsClubeV = rand.nextInt(6);
		int golsClubeM = rand.nextInt(6);
		
		// Define o saldo de gols do time naquela partida
		int saldoGolsV = golsClubeV - golsClubeM;
		int saldoGolsM = golsClubeM - golsClubeV;
		
		// Atualiza a quantidade de gols feitos e sofridos pelo time
		v.aumentaGolsFeitos(golsClubeV);
		v.aumentaGolsSofridos(golsClubeM);
		m.aumentaGolsFeitos(golsClubeM);
		m.aumentaGolsSofridos(golsClubeV);
		
		// Atualiza a pntuação do time dependendo do resultado da partida
		if(golsClubeV > golsClubeM) {
			v.ganhar(saldoGolsV);
			m.perder(saldoGolsM);
		}else if(golsClubeV < golsClubeM) {
			v.perder(saldoGolsV);
			m.ganhar(saldoGolsM);
		}else {
			v.empatar();
			m.empatar();
		}
		
		// Imprime o resultado da partida
		System.out.println(v.nome + " " + golsClubeV + " x " + golsClubeM + " " + m.nome);
	}
	
	
	// Código para gerar as partidas do campeonato
	public void jogarCampeonato() {
		for(int k=1; k<=2; k++) {
			String rodada = (k==1) ? "ida" : "Volta";
			System.out.println("Jogos de " + rodada + ":");
			System.out.println();
			for(int i=0; i<clubes.length-1; i++) {
				for(int j = i+1; j<clubes.length; j++) {
					this.jogarPartida(clubes[i], clubes[j]);
				}
			}
			System.out.println();
		}
	}
	
	
	// Código para rganizar os times pela pontuação
	public void getClassificaçao() {
		Clube temp = new Clube();
		int maior;
		for(int i = 0; i<this.clubes.length-1; i++) {
			maior = i;
			for(int j = i+1; j<this.clubes.length; j++) {
				if(this.clubes[j].pontos > this.clubes[maior].pontos) {
					maior = j;
				}else if(this.clubes[j].pontos == this.clubes[maior].pontos) {
					if(this.clubes[j].saldoGols > this.clubes[maior].saldoGols) {
						maior = j;
					}else if(this.clubes[j].saldoGols == this.clubes[maior].saldoGols) {
						if(this.clubes[j].qtdVitorias > this.clubes[maior].qtdVitorias) {
							maior = j;
						}else if(this.clubes[j].qtdVitorias == this.clubes[maior].qtdVitorias) {
							if(this.clubes[j].qtdEmpates > this.clubes[maior].qtdEmpates) {
								maior = j;
							}
						}
					}
				}
			}
			temp = this.clubes[i];
			this.clubes[i] = this.clubes[maior];
			this.clubes[maior] = temp;
		}
	}
	
	
	// Imprime quem foi o campeão do campeonato
	public void getCampeao() {
		System.out.println("O campeao do Campeonato foi o " + this.clubes[0].nome);
	}
	
	
	// Essa impressão da tabela sevirá especificamente para esses nomes de clubes, devido a tabulação específica
	public void imprimeTabela() {
		System.out.println("Nome do Time\tPontos\tVit\tEmp\tDer\tGols Feitos\tGols Sofridos \tSaldo de Gols");
		System.out.println();
		for(int i = 0; i<clubes.length; i++) {
			if(this.clubes[i].nome.equals("Bahia")) {
				System.out.println(this.clubes[i].nome + "   \t" + this.clubes[i].pontos + "\t" + this.clubes[i].qtdVitorias + "\t" + this.clubes[i].qtdEmpates + "\t" + this.clubes[i].qtdDerrotas + "\t" + this.clubes[i].golsFeitos + "\t\t" + this.clubes[i].golsSofridos + "\t\t " + this.clubes[i].saldoGols);
			}else if(this.clubes[i].nome.equals("Goias")){
				System.out.println(this.clubes[i].nome + "   \t" + this.clubes[i].pontos + "\t" + this.clubes[i].qtdVitorias + "\t" + this.clubes[i].qtdEmpates + "\t" + this.clubes[i].qtdDerrotas + "\t" + this.clubes[i].golsFeitos + "\t\t" + this.clubes[i].golsSofridos + "\t\t " + this.clubes[i].saldoGols);
			}else {
				System.out.println(this.clubes[i].nome + "  \t" + this.clubes[i].pontos + "\t" + this.clubes[i].qtdVitorias + "\t" + this.clubes[i].qtdEmpates + "\t" + this.clubes[i].qtdDerrotas + "\t" + this.clubes[i].golsFeitos + "\t\t" + this.clubes[i].golsSofridos + "\t\t " + this.clubes[i].saldoGols);
			}
			
		}
	}
	
}
