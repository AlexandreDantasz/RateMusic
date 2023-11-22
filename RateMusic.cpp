#include <iostream> // usada também em Menu.h
#include <conio.h> // função getch() usada em Menu.h
#include "Menu.h"
#include "sqlite3.h"
#include "UsuarioControle.cpp"
#include "MusicaControle.cpp"
#include <locale.h> 

using namespace std;

int hashingString(std::string str) {
    // essa função é responsável por criar o id dos usuários
    // a partir do email deles
    int tam = str.size(), hash = 0;
    for (int i = 0; i < tam; i++) { 
        hash += (int) str[i] * (i + 1);
    }
    return hash % 30;
}

int main() {
    string email, senha, id; // são variáveis que armazenam as informações
    // do usuário após validação de login e cadastro.
    int digito; // será usado para criar o efeito de senha asterisco na tela
    string loginEmail, loginSenha = ""; // são variáveis que armazenam informações
    // do usuário sem validação de login e cadastro.
    setlocale(LC_ALL, "portuguese");
    UsuarioControle controleUsuario;
    MusicaControle controleMusica;
    try {
        switch (telaInicial()) {
            case 0: // saída do programa 
                return 0;
            case 1: // login
                printf("Digite o seu email: ");
                cin >> loginEmail;
                printf("Digite a sua senha: ");
                lerSenha(&loginSenha);
                if (controleUsuario.login(loginEmail, loginSenha)) {
                    email = loginEmail;
                    senha = loginSenha;
                    id = to_string(hashingString(email));
                    puts("\nLogin realizado com sucesso!");
                }
                else puts("\nFalha ao efetuar o login!");
                break;
            case 2: // cadastro
                printf("Digite o seu email: ");
                cin >> loginEmail;
                printf("Digite a sua senha: ");
                lerSenha(&loginSenha);
                id = to_string(hashingString(loginEmail));
                controleUsuario.incluir(loginEmail, loginSenha, id);
                puts("Cadastro realizado com sucesso!");
                email = loginEmail;
                senha = loginSenha;
                break;
        }
        std::string nomeMusica, autor, idMusica, nota;
        switch (telaMusica()) {
            case 0: // saída do programa
                return 0;
            case 1: // adicionar música
                printf("Digite o nome da musica: ");
                cin.ignore();
                getline(cin, nomeMusica);
                printf("Digite o nome do autor: ");
                getline(cin, autor);
                printf("Digite a nota da música (0 - 5): ");
                cin >> nota;
                idMusica = to_string(hashingString(nomeMusica));
                controleMusica.incluir(idMusica, id, nomeMusica, autor, nota);
                puts("Musica adicionada na biblioteca!");
                break;
            case 2: // remover música
                break;
            case 3: // alterar música
                break;
            case 4: // busca música
                break;
        }
    }
    catch (string &erro) {
        cout << erro << endl;
    }
}