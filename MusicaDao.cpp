#include "MusicaDao.h"

void MusicaDao::incluir(Musica * objeto) {
    sqlite3 * db;
    char * zErrMsg = 0;
    // tentativa de abertura do banco de dados
    if (sqlite3_open("RateMusic.db", &db) != SQLITE_OK)
        throw std::string("Não foi possível conectar ao banco de dados");
    // inserindo uma linha na tabela Musicas
    std::string comando = "INSERT INTO Musicas(idMusica, chaveUsuario, nome, autor, avaliacao) VALUES (" + objeto->getIdMusica() + ", " 
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

}

void MusicaDao::alterar(Musica * objeto) {

}

void MusicaDao::remover(Musica * objeto) {
    
}