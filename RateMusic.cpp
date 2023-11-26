#include <iostream> // usada também em Menu.h
#include <conio.h> // função getch() usada em Menu.h
#include "Menu.h"
#include "sqlite3.h"
#include "UsuarioControle.cpp"
#include "MusicaControle.cpp"
#include <locale.h> // locale não está funcionando no vscode

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
    UsuarioControle controleUsuario;
    MusicaControle controleMusica;
    int flag = 0;
    try {
        do {
            switch (telaInicial()) {
                case 0: // saída do programa 
                    return 0;
                case 1: // login
                    printf("\n------ [Login] ------\n");
                    printf("Digite o seu email: ");
                    cin >> loginEmail;
                    printf("Digite a sua senha: ");
                    lerSenha(&loginSenha);
                    if (controleUsuario.login(loginEmail, loginSenha)) {
                        email = loginEmail;
                        senha = loginSenha;
                        id = to_string(hashingString(email));
                        puts("\nStatus: Login realizado com sucesso!");
                        flag++;
                    }
                    else puts("\nStatus: Falha ao efetuar o login!");
                    break;
                case 2: // cadastro
                    printf("\n------ [Cadastro] ------\n");
                    printf("Digite o seu email: ");
                    cin >> loginEmail;
                    printf("Digite a sua senha: ");
                    lerSenha(&loginSenha);
                    id = to_string(hashingString(loginEmail));
                    controleUsuario.incluir(loginEmail, loginSenha, id);
                    puts("\nStatus: Cadastro realizado com sucesso!");
                    email = loginEmail;
                    senha = loginSenha;
                    flag++;
                    break;
            }
        } while (!flag);
        std::string nomeMusica, autor, idMusica, nota, buscarUsuario;
        while (flag) {
            switch (telaMusica()) {
                case 0: // saída do programa
                    return 0;
                case 1: // adicionar música
                    system("cls");
                    printf("\n------ [Adicionar] ------\n");
                    printf("Digite o nome da musica: ");
                    cin.ignore();
                    getline(cin, nomeMusica);
                    printf("Digite o nome do autor: ");
                    getline(cin, autor);
                    printf("Digite a nota da musica (0 - 5): ");
                    cin >> nota;
                    idMusica = to_string(hashingString(nomeMusica));
                    controleMusica.incluir(idMusica, id, nomeMusica, autor, nota);
                    puts("Musica adicionada na biblioteca!");
                    break;
                case 2: // remover música
                    system("cls");
                    printf("\n------ [Remover] ------\n");
                    printf("Digite o nome da musica: ");
                    cin.ignore();
                    getline(cin, nomeMusica);
                    printf("Digite o nome do autor: ");
                    getline(cin, autor);
                    idMusica = to_string(hashingString(nomeMusica));
                    controleMusica.remover(idMusica, id, autor);
                    puts("Status: Musica removida com sucesso");
                    break;
                case 3: // alterar música
                    system("cls");
                    printf("\n------ [Alterar] ------\n");
                    printf("Digite o nome da musica: ");
                    cin.ignore();
                    getline(cin, nomeMusica);
                    printf("Digite o nome do autor: ");
                    getline(cin, autor);
                    printf("Digite a nova nota para essa musica: ");
                    cin >> nota;
                    idMusica = to_string(hashingString(nomeMusica));
                    controleMusica.alterar(idMusica, id, autor, nota);
                    puts("Musica atualizada com sucesso");
                    break;
                case 4: // buscar música
                    system("cls");
                    printf("Digite o nome da musica: ");
                    cin.ignore();
                    getline(cin, nomeMusica);
                    idMusica = to_string(hashingString(nomeMusica));
                    cout << "\n------ [" << nomeMusica << "] ------\n";
                    controleMusica.buscar(idMusica, id);
                    break;
                case 5: // listar música
                    system("cls");
                    switch (telaListarMusicas()) {
                        case 0: // encerrar o programa
                            return 0;
                        case 1: // listar toda biblioteca
                            system("cls");
                            printf("\n------ [Minha biblioteca] ------\n");
                            controleMusica.listarMusica(id);
                            break;
                        case 2: // listar músicas de um autor
                            cin.ignore();
                            system("cls");
                            printf("------- [Listar musicas] ------\n");
                            printf("Digite o nome do autor: ");
                            getline(cin, autor);
                            cout << "\n\n------ [" << autor << "] ------\n";
                            controleMusica.listarMusicaAutor(id, autor);
                            break;
                    }
                    break;
                case 6: // buscar biblioteca de outros usuários
                    system("cls");
                    system("cls");
                    puts("\n------ [Buscar usuarios] ------");
                    printf("Digite o email do usuario: ");
                    cin >> buscarUsuario;
                    system("cls");
                    cout << "\n------ [" << buscarUsuario << "] ------\n";
                    controleMusica.listarMusica(to_string(hashingString(buscarUsuario)));            
                    break;
                case 7: // sair da conta
                    flag--;
                    do {
                        switch (telaInicial()) {
                            case 0: // saída do programa 
                                return 0;
                            case 1: // login
                                printf("\n------ [Login] ------\n");
                                printf("Digite o seu email: ");
                                cin >> loginEmail;
                                printf("Digite a sua senha: ");
                                lerSenha(&loginSenha);
                                if (controleUsuario.login(loginEmail, loginSenha)) {
                                    email = loginEmail;
                                    senha = loginSenha;
                                    id = to_string(hashingString(email));
                                    puts("\nStatus: Login realizado com sucesso!");
                                    flag++;
                                }
                                else puts("\nStatus: Falha ao efetuar o login!");
                                break;
                            case 2: // cadastro
                                printf("\n------ [Cadastro] ------\n");
                                printf("Digite o seu email: ");
                                cin >> loginEmail;
                                printf("Digite a sua senha: ");
                                lerSenha(&loginSenha);
                                id = to_string(hashingString(loginEmail));
                                controleUsuario.incluir(loginEmail, loginSenha, id);
                                puts("\nStatus: Cadastro realizado com sucesso!");
                                email = loginEmail;
                                senha = loginSenha;
                                flag++;
                                break;
                        }
                    } while (!flag);
                    break;
            }
        }
    }
    catch (string &erro) {
        cout << erro << endl;
    }
}