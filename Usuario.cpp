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

void Usuario::setEmail(std::string novoEmail) {
    this->email = novoEmail;
}

void Usuario::setSenha(std::string novaSenha) {
    this->senha = novaSenha;
}

void Usuario::setId(std::string novoId) {
    this->id = novoId;
}