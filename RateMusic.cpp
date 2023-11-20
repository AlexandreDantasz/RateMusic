#include <iostream>
#include "sqlite3.h"
#include "Usuario.h"
#include "UsuarioDao.h"

using namespace std;

int main() {
   // sqlite3 *db;
    //int exit = 0;
    //exit = sqlite3_open("teste.db", &db);
    //sqlite3_close(db);
    sqlite3 *bancoDeDados;
    char* zErrMsg = nullptr;
    int rc;
    rc = sqlite3_open("RateMusic.db", &bancoDeDados);
    
    return 0;
}