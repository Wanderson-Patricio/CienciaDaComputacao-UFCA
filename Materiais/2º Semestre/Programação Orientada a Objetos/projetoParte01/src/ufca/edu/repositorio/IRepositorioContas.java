package ufca.edu.repositorio;

import ufca.edu.negocio.ContaJogoAbstrata;

public interface IRepositorioContas {
	int getMAX_SIZE();
	int getSize();
	void adicionar(ContaJogoAbstrata conta);
	int busca(ContaJogoAbstrata conta);
	ContaJogoAbstrata retornaConta(int i);
	void imprimeRepositorio();
	void remover(ContaJogoAbstrata conta);
}
