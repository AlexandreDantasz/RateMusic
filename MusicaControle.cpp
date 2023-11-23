#include "MusicaControle.h"

MusicaControle::MusicaControle() {
    musica = new Musica;
    daoMusica = new MusicaDao;
}

MusicaControle::~MusicaControle() {
    delete musica;
    delete daoMusica;
}

bool MusicaControle::validaId(std::string id) {
    int i, tam = id.length();
    for (i = 0; i < tam && (int) id[i] >= 48 && (int) id[i] <= 57; i++);
    return i == tam; // se chegar no final, o id contém apenas números
}

bool MusicaControle::validaNota(std::string nota) {
    if (nota.length() != 1) return false;
    if ((int) nota[0] >= 48 && (int) nota[0] <= 53) return true;
    return false;
}

void MusicaControle::incluir(std::string idMusica, std::string chaveUsuario, std::string nome, std::string autor, std::string avaliacao) {
    if(!validaId(idMusica)) throw std::string("Id da música é inválido");
    if (!validaId(chaveUsuario)) throw std::string("Id do usuário é inválido");
    if (!validaNota(avaliacao)) throw std::string("A avaliação está incorreta");
    musica->setIdMusica(idMusica);
    musica->setChaveUsuario(chaveUsuario);
    musica->setNomeMusica(nome);
    musica->setNomeAutor(autor);
    musica->setAvaliacao(avaliacao);
    daoMusica->incluir(musica);
}

bool MusicaControle::buscar(std::string idMusica, std::string chaveUsuario, std::string autor) {
    if(!validaId(idMusica)) throw std::string("Id da música é inválido");
    if (!validaId(chaveUsuario)) throw std::string("Id do usuário é inválido");
    musica->setIdMusica(idMusica);
    musica->setChaveUsuario(chaveUsuario);
    musica->setNomeAutor(autor);
    return daoMusica->buscar(musica);
}

void MusicaControle::alterar(std::string idMusica, std::string chaveUsuario, std::string autor, std::string avaliacao) {
    if(!validaId(idMusica)) throw std::string("Id da música é inválido");
    if (!validaId(chaveUsuario)) throw std::string("Id do usuário é inválido");
    if (!validaNota(avaliacao)) throw std::string("A avaliação está incorreta");
    musica->setIdMusica(idMusica);
    musica->setChaveUsuario(chaveUsuario);
    musica->setAvaliacao(avaliacao);
    musica->setNomeAutor(autor);
    daoMusica->alterar(musica);
}

void MusicaControle::remover(std::string idMusica, std::string chaveUsuario, std::string autor) {
    if(!validaId(idMusica)) throw std::string("Id da música é inválido");
    if (!validaId(chaveUsuario)) throw std::string("Id do usuário é inválido");
    musica->setIdMusica(idMusica);
    musica->setChaveUsuario(chaveUsuario);
    musica->setNomeAutor(autor);
    daoMusica->remover(musica);
}