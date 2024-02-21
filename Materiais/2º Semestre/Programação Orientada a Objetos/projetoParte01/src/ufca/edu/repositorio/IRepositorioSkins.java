package ufca.edu.repositorio;

import ufca.edu.negocio.Skin;

public interface IRepositorioSkins {
	Skin getSkin(int i);
	void adicionar(Skin s);
	int busca(Skin s);
	void imprimeRepositorio();
	void remover(Skin s);
	void ordenaRepositorio();
	IRepositorioSkins criaRepositorio(int tam);
}
