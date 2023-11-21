#ifndef USUARIOCONTROLE_H
#define USUARIOCONTROLE_H
#include "Usuario.cpp"
#include "UsuarioDao.cpp"

class UsuarioControle {
private:
    Usuario * usuario;
    UsuarioDao * daoUsuario;
    static bool validaEmail(std::string str);
    static bool validaSenha(std::string str);
    static bool validaId(std::string str);
public:
    UsuarioControle();
    ~UsuarioControle();
    void incluir(std::string email, std::string senha, std::string id);
    void remover(std::string id);
    bool buscar(std::string id);
    void alterar(std::string email, std::string senha, std::string id);
    bool login(std::string email, std::string senha);
    // void listarMusicas(std::string id); será feita apenas quando 
    // o módulo de música estiver pronto
};

#endif