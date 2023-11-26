#ifndef MENU_H
#define MENU_H
// usando iostream e conio.h de RateMusic.cpp

void lerSenha(std::string * senha) {
    int digito;
    std::string senhaEscrita;
    digito = getch();
    while (digito != 13) { //13 = carriage return (comando de iniciar nova linha)
        if (digito != 8) { // 8 = backspace 
            printf("*");
            senhaEscrita += (char) digito;
        }
        else {
            if (senhaEscrita.length()) {
                printf("\b \b"); // \b irá apagar qualquer caractere na linha
                // com espaço em branco
                senhaEscrita.resize(senhaEscrita.length() - 1);
            }
        }
        digito = getch();
    }
    *senha = senhaEscrita;
}

int telaInicial() {
    int resposta;
    system("cls");
    puts("\n----- [Rate Music] -----");
    puts("0 - Encerrar programa");
    puts("1 - Fazer Login");
    puts("2 - Cadastrar");
    do { // Loop para evitar opções inválidas
        printf("Digite a opcao que deseja: ");
        std::cin >> resposta;
        if (resposta != 0 && resposta != 1 && resposta != 2) {
            puts("A opcao desejada esta incorreta, digite novamente");
        }
    } while (resposta != 0 && resposta != 1 && resposta != 2);
    return resposta;
}

int telaMusica() {
    int resposta;
    puts("\n----- [Biblioteca] -----");
    puts("0 - Encerrar o programa");
    puts("1 - Adicionar musica");
    puts("2 - Remover musica");
    puts("3 - Alterar musica");
    puts("4 - Buscar musica");
    puts("5 - Listar musicas");
    puts("6 - Procurar usuarios");
    puts("7 - Sair da conta");
    do { // Loop para evitar opções inválidas
        printf("Digite a opcao que deseja: ");
        std::cin >> resposta;
        if (resposta < 0 || resposta > 7)
            puts("A opcao desejada esta incorreta, digite novamente");
    } while (resposta < 0 || resposta > 7);
    return resposta;
}

int telaListarMusicas() {
    int resposta;
    puts("\n------- [Listar musicas] -------");
    puts("0 - Encerrar o programa");
    puts("1 - Listar toda a biblioteca");
    puts("2 - Filtrar pelo autor");
    do {
        printf("Digite a opcao que deseja: ");
        std::cin >> resposta;
        if (resposta < 0 || resposta > 2) 
            puts("A opcao deseja esta incorreta, digite novamente");
    } while (resposta < 0 || resposta > 2);
    return resposta;
}

#endif