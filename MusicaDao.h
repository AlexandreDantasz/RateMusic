#include "dao.h"
#include "Musica.h"

#ifndef MUSICADAO_H
#define MUSICADAO_H

class MusicaDao : public Dao <Musica> {
public:
    //MusicaDao();
    static int callback(void * data, int argc, char ** argv, char ** azColName);
    void incluir(Musica * objeto);
    bool buscar(Musica * objeto);
    void buscarMusica(Musica * objeto);
    void alterar(Musica * objeto);
    void remover(Musica * objeto);
    void listaMusica(Musica * objeto);
    void listaMusicaAutor(Musica * objeto);
};

#endif



