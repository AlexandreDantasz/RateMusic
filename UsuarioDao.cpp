#include "UsuarioDao.h"

UsuarioDao::UsuarioDao() {
    this->nomeBd = "RateMusic.db"; // será necessário usar a função c_str()
}

void UsuarioDao::incluir(Usuario * objeto) {
    //procedimento padrão para abrir o banco de dados
    sqlite3 *bancoDeDados;
    char* zErrMsg = 0; // mensagem de erro do sqlite3
    int rc; // variável usada para saber os comandos sql foram bem executados
    rc = sqlite3_open(nomeBd.c_str(), &bancoDeDados);
    if (rc != SQLITE_OK) throw std::string("Não foi possível abrir o banco de dados");
    // foi possível abrir o banco de dados
    std::string comando = "INSERT INTO Usuarios(idUsuario, email, senha) VALUES(" + objeto->getId() + ", '" + objeto->getEmail() + "', '" +
    objeto->getSenha() +"');";
    rc = sqlite3_exec(bancoDeDados, comando.c_str(), NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        throw std::string("Inserção deu erro");
        sqlite3_close(bancoDeDados);
    }
    sqlite3_close(bancoDeDados);
    std::cout << "Concluído com sucesso!\n";
}

bool UsuarioDao::buscar(Usuario * objeto) {
    sqlite3 * db;
    sqlite3_stmt * stmt; // ponteiro pra uma estrutura que representa uma consulta sql
    int rc;
    rc = sqlite3_open(nomeBd.c_str(), &db);
    if (rc != SQLITE_OK) throw std::string("Não foi possível conectar ao banco de dados");
    // foi possível conectar ao banco de dados
    std::string comando = "SELECT * FROM Usuarios WHERE idUsuario = " + objeto->getId() +
    ";";
    rc = sqlite3_prepare_v2(db, comando.c_str(), -1, &stmt, 0); // preparando a consulta
    if (rc != SQLITE_OK) {
        std::cout << "Erro na busca\n";
    }
    if (sqlite3_step(stmt) == SQLITE_ROW) { // há uma linha de resultado disponível
        // portanto, o usuário foi encontrado
        sqlite3_finalize(stmt); //finalizando o processo do stmt
        sqlite3_close(db);
        return true;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return false;
}

void UsuarioDao::alterar(Usuario * objeto) {
    sqlite3 * db;
    char * zErrMsg = 0;
    int rc;
    rc  = sqlite3_open(nomeBd.c_str(), &db);
    if (rc != SQLITE_OK) throw std::string("Não foi possível conectar ao banco de dados");
    // foi possível conectar ao banco de dados
    std::string comando = "UPDATE Usuarios SET email = '" + objeto->getEmail() + "', senha = '" +
    objeto->getSenha() + "' WHERE idUsuario = " + objeto->getId() + ";";
    rc = sqlite3_exec(db, comando.c_str(), NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        throw std::string("Não foi possível atualizar o usuário");
        sqlite3_close(db);
    }
    std::cout << "Usuário atualizado com sucesso!\n";
    sqlite3_close(db);
} 

void UsuarioDao::remover(Usuario * objeto) {
    sqlite3 * db;
    char * zErrMsg = 0;
    int rc;
    rc = sqlite3_open(nomeBd.c_str(), &db);
    if (rc != SQLITE_OK) throw std::string("Não foi possível conectar ao banco de dados");
    // foi possível conectar com o banco de dados
    std::string comando = "DELETE FROM Usuarios WHERE idUsuario = " + objeto->getId(); + ";";
    rc = sqlite3_exec(db, comando.c_str(), NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        sqlite3_close(db);
        throw std::string("Não foi possível deletar o usuário");
    }
    sqlite3_close(db);
    std::cout << "Usuário deletado com sucesso\n";
}