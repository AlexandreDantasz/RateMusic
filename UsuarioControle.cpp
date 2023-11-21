#include "UsuarioControle.h"

UsuarioControle::UsuarioControle() {
    this->usuario = new Usuario;
    this->daoUsuario = new UsuarioDao;
}

UsuarioControle::~UsuarioControle() {
    delete usuario;
    delete daoUsuario;
}

bool UsuarioControle::validaEmail(std::string str) {
    int tam = str.size(), i, caracNecessarios = 0;
    // realizando busca enquanto não houver caracteres diferentes
    // de letras maiúsculas, minúsculas, números, @ e . 
    for (i = 0; i < tam && ((int) str[i] == 46 || 
        ((int) str[i] >= 64 && (int) str[i] <= 90) || 
        ((int) str[i] >= 97 && (int) str[i] <= 122)) ||
        ((int) str[i] >= 48 && (int) str[i] <= 57) ; i++) {
        if (str[i] == '@') caracNecessarios++;
    }
    return caracNecessarios == 1 && i == tam; // valida o email
}

bool UsuarioControle::validaSenha(std::string str) {
    int tam = str.size(), i;
    // realizando busca enquanto não houver caracteres diferentes
    // de letras maiúsculas, minúsculas, números e !
    for (i = 0; i < tam && ((int) str[i] == 33 || 
        ((int) str[i] >= 65 && (int) str[i] <= 90) || 
        ((int) str[i] >= 97 && (int) str[i] <= 122) || 
        ((int) str[i] >= 48 && (int) str[i] <= 57)) ; i++);
    return i == tam; // se chegar no final, a senha está correta
}

bool UsuarioControle::validaId(std::string str) {
    int i, tam = str.size();
    for (i = 0; i < tam && (int) str[i] >= 48 && (int) str[i] <= 57; i++);
    return i == tam; // se chegar no final, o id contém apenas números
}

void UsuarioControle::incluir(std::string email, std::string senha, std::string id) {
    // será preciso uma validação para email, senha e id para evitar 
    // vulnerabilidade no sistema
    if (!validaEmail(email)) throw std::string("O email inserido está incorreto!");
    if (!validaSenha(senha)) throw std::string("A senha não pode conter caracteres especiais!");
    if (!validaId(id)) throw std::string("O id deve conter apenas números inteiros!");
    // os dados são válidos para inserção, podem ser passados para o objeto usuario
    this->usuario->setId(id);
    this->usuario->setEmail(email);
    this->usuario->setSenha(senha);
    // é preciso verificar se o id já está cadastrado
    if (this->daoUsuario->buscar(this->usuario)) throw std::string("Esse id já foi cadastrado!");
    // é possível realizar o cadastro
    this->daoUsuario->incluir(this->usuario);
}

void UsuarioControle::remover(std::string id) {
    if (!validaId(id)) throw std::string("O id deve conter apenas números inteiros!");
    this->usuario->setId(id);
    if (!this->daoUsuario->buscar(this->usuario)) throw std::string("Erro ao deletar usuário");
    this->daoUsuario->remover(this->usuario);
}

bool UsuarioControle::buscar(std::string id) {
    if (!validaId(id)) throw std::string("O id deve conter apenas números inteiros!");
    this->usuario->setId(id);
    return this->daoUsuario->buscar(this->usuario);
}
//void listarMusicas(std::string id); o módulo de música ainda não está pronto

void UsuarioControle::alterar(std::string email, std::string senha, std::string id) {
    // será preciso uma validação para email, senha e id para evitar 
    // vulnerabilidade no sistema
    if (!validaEmail(email)) throw std::string("O email inserido está incorreto!");
    if (!validaSenha(senha)) throw std::string("A senha não pode conter caracteres especiais!");
    if (!validaId(id)) throw std::string("O id deve conter apenas números inteiros!");
    // os dados são válidos para inserção, podem ser passados para o objeto usuario
    this->usuario->setId(id);
    this->usuario->setEmail(email);
    this->usuario->setSenha(senha);
    // é preciso verificar se o id já está cadastrado
    if (!this->daoUsuario->buscar(this->usuario)) throw std::string("Esse id não foi cadastrado!");
    // é possível realizar a atualização
    this->daoUsuario->alterar(this->usuario);
}

bool UsuarioControle::login(std::string email, std::string senha) {
    if (!validaEmail(email)) throw std::string("O email inserido está incorreto!");
    if (!validaSenha(senha)) throw std::string("A senha não pode conter caracteres especiais!");
    this->usuario->setEmail(email);
    if (!this->daoUsuario->validarCadastro(this->usuario)) return false;
    // se chegou aqui é porque existe esse cadastro
    this->usuario->setSenha(senha);
    return this->daoUsuario->validarLogin(this->usuario);
}