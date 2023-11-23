#ifndef MUSICACONTROLE_H
#define MUSICACONTROLE_H
#include "Musica.cpp"
#include "MusicaDao.cpp"

class MusicaControle {
private:
    Musica * musica;
    MusicaDao * daoMusica;
    bool validaId(std::string id);
    bool validaNota(std::string nota);
public:
    MusicaControle();
    ~MusicaControle();
    void incluir(std::string idMusica, std::string chaveUsuario, std::string nome, std::string autor, std::string avaliacao);
    bool buscar(std::string idMusica, std::string chaveUsuario); 
    void alterar(std::string idMusica, std::string chaveUsuario, std::string avaliacao);
    void remover(std::string idMusica, std::string chaveUsuario, std::string autor);
};

#endif