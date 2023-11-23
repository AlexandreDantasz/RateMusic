#include "MusicaDao.h"

void MusicaDao::incluir(Musica * objeto) {
    // essa função deve incluir uma música no banco de dados
    sqlite3 * db;
    char * zErrMsg = 0;
    sqlite3_stmt * stmt;
    // tentativa de abertura do banco de dados
    if (sqlite3_open("RateMusic.db", &db) != SQLITE_OK)
        throw std::string("Não foi possível conectar ao banco de dados");
    // verificando se o usuário está no banco de dados
    std::string comando = "SELECT * FROM Usuarios WHERE idUsuario = " +
    objeto->getChaveUsuario() + ";";
    if (sqlite3_prepare_v2(db, comando.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        sqlite3_close(db);
        throw std::string("Não foi possível verificar se o usuário existe");
    }
    if (sqlite3_step(stmt) != SQLITE_ROW) {
        // se entrar aqui, não há linhas de resultados
        // possíveis para a consulta
        sqlite3_close(db);
        sqlite3_finalize(stmt);
        throw std::string("Esse usuário não existe");
    } 
    // inserindo uma linha na tabela Musicas
    comando = "INSERT INTO Musica(idMusica, chaveUsuario, nome, autor, avaliacao) VALUES (" + objeto->getIdMusica() + ", " 
    + objeto->getChaveUsuario() + ", '" + objeto->getNomeMusica() + "', '" + objeto->getNomeAutor() +
    "', " + objeto->getAvaliacao() + ");";
    if (sqlite3_exec(db, comando.c_str(), NULL, 0, &zErrMsg) != SQLITE_OK) {
        sqlite3_close(db);
        throw std::string("Erro na inserção da música");
    }
    // se chegar aqui, a inclusão foi feita corretamente
    sqlite3_close(db);
}

bool MusicaDao::buscar(Musica * objeto) {
    // essa função deve ser capaz de dizer
    // se existe uma música no banco de dados ou não
    sqlite3 * db;
    sqlite3_stmt * stmt;
    if (sqlite3_open("RateMusic.db", &db) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        throw std::string("Não foi possível abrir o banco de dados");
    }
    // a busca será feita por idMusica e chaveUsuario
    std::string comando = "SELECT * FROM Musica WHERE idMusica = " +
    objeto->getIdMusica() + " AND chaveUsuario = " + objeto->getChaveUsuario() +
    ";";
    // preparando para a consulta
    if (sqlite3_prepare_v2(db, comando.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        throw std::string("Erro na busca da música");
    }
    if (sqlite3_step(stmt) == SQLITE_ROW) { // há uma linha de resultado possível
        // portanto, a música foi encontrada
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return true;   
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return false;
}

void MusicaDao::alterar(Musica * objeto) {
    // essa função deve ser capaz de atualizar
    // os dados de uma música no banco de dados
    sqlite3 * db;
    char * zErrMsg = 0;
    sqlite3_open("RateMusic.db", &db);
    // só será possível atualizar a avaliação de uma música 
    // a música deve ser encontrada por idMusica e chaveUsuario
    std::string comando = "UPDATE Musica SET avaliacao = " + objeto->getAvaliacao() +
    " WHERE idMusica = " + objeto->getIdMusica() + " AND chaveUsuario = " + 
    objeto->getChaveUsuario() + ";";
    if (sqlite3_exec(db, comando.c_str(), NULL, 0, &zErrMsg) != SQLITE_OK) {
        sqlite3_close(db);
        throw std::string("Erro na atualização da música");
    }
    sqlite3_close(db);
}

void MusicaDao::remover(Musica * objeto) {
    sqlite3 * db;
    char * zErrMsg;
    if (sqlite3_open("RateMusic.db", &db) != SQLITE_OK)
        throw std::string("Não foi possível abrir o banco de dados");
    // a remoção será filtrada por idMusica e por chaveUsuario
    std::string comando = "DELETE FROM Musica WHERE idMusica = " +
    objeto->getIdMusica() + " AND chaveUsuario = " + objeto->getChaveUsuario() + " AND " 
    + "autor = '" + objeto->getNomeAutor() + "';";
    std::cout << comando << '\n';
    if (sqlite3_exec(db, comando.c_str(), NULL, 0, &zErrMsg) != SQLITE_OK) 
    {
        sqlite3_close(db);
        throw std::string("Não foi possível deletar a música");
    }
    sqlite3_close(db);
}