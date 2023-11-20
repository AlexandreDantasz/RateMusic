#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>

class Usuario {
private:
    std::string email;
    std::string senha;
public:
    Usuario();
    Usuario(std::string novoEmail, std::string novaSenha);
    std::string getEmail();
    std::string getSenha();
};

#endif