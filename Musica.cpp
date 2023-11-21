#include "Musica.h"

Musica::Musica() {
    nomeMusica = idMusica = chaveUsuario = nomeAutor = avaliacao = "";
}

void Musica::setNomeMusica(std::string newNomeMusica) {
    this->nomeMusica = newNomeMusica;
}

void Musica::setIdMusica(std::string newIdMusica) {
    this->idMusica = newIdMusica;
}

void Musica::setChaveUsuario(std::string newChaveUsuario) {
    this->chaveUsuario = newChaveUsuario;
}

void Musica::setNomeAutor(std::string newNomeAutor) {
    this->nomeAutor = newNomeAutor;
}

void Musica::setAvaliacao(std::string newAvaliacao) {
    this->avaliacao = newAvaliacao;
}

std::string Musica::getNomeMusica() {
    return this->nomeMusica;
}

std::string Musica::getIdMusica() {
    return this->idMusica;
}

std::string Musica::getChaveUsuario() {
    return this->chaveUsuario;
}

std::string Musica::getNomeAutor() {
    return nomeAutor;
}

std::string Musica::getAvaliacao() {
    return avaliacao;
}