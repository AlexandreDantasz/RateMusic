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
    " AND autor = '" + objeto->getNomeAutor() + "';";
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
    objeto->getChaveUsuario() + " AND autor = '" + objeto->getNomeAutor() + "';";
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
    if (sqlite3_exec(db, comando.c_str(), NULL, 0, &zErrMsg) != SQLITE_OK) 
    {
        sqlite3_close(db);
        throw std::string("Não foi possível deletar a música");
    }
    sqlite3_close(db);
}

int MusicaDao::callback(void * data, int argc, char ** argv, char ** azColName) {
    char trem = 205; // símbolo usado para separar as informações
    for (int i = 0; i < 50; i++) std::cout << trem;
    std::cout << '\n';
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << '\n';
    }
    for (int i = 0; i < 50; i++) std::cout << trem;
    std::cout << '\n';
    return 0;
}

void MusicaDao::listaMusica(Musica * objeto) {
    // essa função deve listar todas as músicas da
    // biblioteca de um usuário
    sqlite3 * db;
    char * zErrMsg; // mensagem de erro caso ocorra
    //abrindo o banco de dados
    if (sqlite3_open("RateMusic.db", &db) != SQLITE_OK)
        throw std::string("Não foi possível abrir o banco de dados");
    // a consulta sql deve ser baseada na chaveUsuario
    std::string comando = "SELECT nome, autor, avaliacao FROM Musica WHERE chaveUsuario = " + 
    objeto->getChaveUsuario() + ";";
    if (sqlite3_exec(db, comando.c_str(), callback, NULL, &zErrMsg) != SQLITE_OK) {
        sqlite3_close(db);
        throw std::string("Não foi possível listar as músicas");
    }
    // se chegar aqui, foi possível listar todas as músicas
    sqlite3_close(db);
}

void MusicaDao::listaMusicaAutor(Musica * objeto) {
    // essa função deve ser capaz de listar todas as
    // músicas da biblioteca do usuário, filtrando elas por um autor
    sqlite3 * db; 
    if (sqlite3_open("RateMusic.db", &db) != SQLITE_OK)
        throw std::string("Nao foi possivel abrir o banco de dados");
    std::string comando = "SELECT nome, avaliacao FROM Musica WHERE chaveUsuario = " +
    objeto->getChaveUsuario() + " AND autor = '" + objeto->getNomeAutor() + "';";
    if (sqlite3_exec(db, comando.c_str(), callback, NULL, NULL) != SQLITE_OK) {
        sqlite3_close(db);
        throw std::string("Nao foi possivel listar as musicas pelo autor");
    }
    // se chear aqui, foi possível listar todas as músicas
    sqlite3_close(db);
}