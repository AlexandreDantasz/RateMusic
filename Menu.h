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
    puts("Rate Music");
    puts("0 - Encerrar programa");
    puts("1 - Fazer Login");
    puts("2 - Cadastrar");
    do { // Loop para evitar opções inválidas
        printf("Digite a opção que deseja: ");
        std::cin >> resposta;
        if (resposta != 0 && resposta != 1 && resposta != 2) {
            puts("A opção desejada está incorreta, digite novamente");
        }
    } while (resposta != 0 && resposta != 1 && resposta != 2);
    return resposta;
}

#endif