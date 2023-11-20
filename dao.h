#ifndef DAO_H
#define DAO_H
#include "sqlite3.h"

template <class Tipo> class Dao {
private:
    int x;
public:
    //Dao();
    virtual void incluir(Tipo * objeto) = 0;
    virtual Tipo * buscar(Tipo * objeto) = 0;
    virtual void alterar(Tipo * objeto) = 0;
    virtual void remover(Tipo * objeto) = 0;
};

#endif