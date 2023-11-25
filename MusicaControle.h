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
    void buscar(std::string idMusica, std::string chaveUsuario); 
    void listarMusica(std::string chaveUsuario);
    void listarMusicaAutor(std::string chaveUsuario, std::string autor);
    void alterar(std::string idMusica, std::string chaveUsuario, std::string autor, std::string avaliacao);
    void remover(std::string idMusica, std::string chaveUsuario, std::string autor);
};

#endif