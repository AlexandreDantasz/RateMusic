#include "UsuarioDao.h"

UsuarioDao::UsuarioDao() {
    this->nomeBd = "RateMusic.db"; // será necessário usar a função c_str()
}

void UsuarioDao::incluir(Usuario * objeto) {
    sqlite3 *bancoDeDados;
    char* zErrMsg = 0;
    int rc;
    rc = sqlite3_open(nomeBd.c_str(), &bancoDeDados);
    if (rc != SQLITE_OK) throw std::string("Não foi possível abrir o banco de dados");
    // foi possível abrir o banco de dados
    std::string id = std::to_string(sqlite3_last_insert_rowid(bancoDeDados));
    std::string comando = "INSERT INTO Usuarios(idUsuario, email, senha) VALUES(" + id + ", '" + objeto->getEmail() + "', '" +
    objeto->getSenha() +"');";
    rc = sqlite3_exec(bancoDeDados, comando.c_str(), NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        throw std::string("Inserção deu erro");
        sqlite3_close(bancoDeDados);
    }
    sqlite3_close(bancoDeDados);
    std::cout << "Concluído com sucesso!\n";
}

Usuario * buscar(Usuario * objeto);
void alterar(Usuario * objeto);
void remover(Usuario * objeto);