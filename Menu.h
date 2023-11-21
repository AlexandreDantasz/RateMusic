#ifndef MENU_H
#define MENU_H
#include <iostream>

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