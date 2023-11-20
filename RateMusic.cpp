#include <iostream>
#include "sqlite3.h"
#include "UsuarioControle.cpp"
#include <locale.h> 

using namespace std;

int main() {
   // sqlite3 *db;
    //int exit = 0;
    //exit = sqlite3_open("teste.db", &db);
    //sqlite3_close(db);
    setlocale(LC_ALL, "portuguese");
    UsuarioControle controleUsuario;
    try {
        string email, senha, id;
        cin >> email >> senha >> id;
        //controleUsuario.incluir(email, senha, id); funcionando
        //controleUsuario.remover(id); funcionando
        controleUsuario.alterar(email, senha, id);
    }
    catch (string &erro) {
        cout << erro << endl;
    }
    return 0;
}