#include <iostream>
#include "sqlite3.h"
#include "Usuario.cpp"
#include "UsuarioDao.cpp"
#include <locale.h> 

using namespace std;

int main() {
   // sqlite3 *db;
    //int exit = 0;
    //exit = sqlite3_open("teste.db", &db);
    //sqlite3_close(db);
    setlocale(LC_ALL, "portuguese");
    Usuario * teste = new Usuario("teste@gmail", "9890", "14");
    try {
        UsuarioDao final;
        //final.incluir(teste);
    }
    catch (string &erro) {
        cout << erro << endl;
    }
    delete teste;
    return 0;
}