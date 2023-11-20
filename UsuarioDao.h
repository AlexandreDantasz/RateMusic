#ifndef USUARIODAO_H
#define USUARIODAO_H
#include "Usuario.h"
#include "dao.h"

class UsuarioDao : public Dao <Usuario> {
private:
    std::string nomeBd; // nome do banco de dados
public:
    UsuarioDao();
    void incluir(Usuario * objeto);
    Usuario * buscar(Usuario * objeto);
    void alterar(Usuario * objeto);
    void remover(Usuario * objeto);
};

#endif