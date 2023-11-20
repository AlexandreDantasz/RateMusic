#include "Usuario.h"

Usuario::Usuario() {
    this->email = this->senha = this->id = "";
}

Usuario::Usuario(std::string novoEmail, std::string novaSenha, std::string novoId) {
    this->email = novoEmail;
    this->senha = novaSenha;
    this->id = novoId;
}

std::string Usuario::getEmail() {
    return this->email;
}

std::string Usuario::getSenha(){
    return this->senha;
}

std::string Usuario::getId() {
    return this->id;
}