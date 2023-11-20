#include "Usuario.h"

Usuario::Usuario() {
    this->email = this->senha = "";
}

Usuario::Usuario(std::string novoEmail, std::string novaSenha) {
    this->email = novoEmail;
    this->senha = novaSenha;
}

std::string Usuario::getEmail() {
    return this->email;
}

std::string Usuario::getSenha(){
    return this->senha;
}