#ifndef MUSICA_H
#define MUSICA_H
#include <iostream>

class Musica {
private:
    std::string nomeMusica;
    std::string idMusica;
    std::string chaveUsuario;
    std::string nomeAutor;
    std::string avaliacao;
public:
    Musica();
    void setNomeMusica(std::string newNomeMusica);
    void setIdMusica(std::string newIdMusica);
    void setChaveUsuario(std::string newChaveUsuario);
    void setNomeAutor(std::string newNomeAutor);
    void setAvaliacao(std::string newAvaliacao);
    std::string getNomeMusica();
    std::string getIdMusica();
    std::string getChaveUsuario();
    std::string getNomeAutor();
    std::string getAvaliacao();
};

#endif