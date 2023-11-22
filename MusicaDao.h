#include "dao.h"
#include "Musica.h"

#ifndef MUSICADAO_H
#define MUSICADAO_H

class MusicaDao : public Dao <Musica> {
public:
    //MusicaDao();
    void incluir(Musica * objeto);
    bool buscar(Musica * objeto);
    void alterar(Musica * objeto);
    void remover(Musica * objeto);
};

#endif



