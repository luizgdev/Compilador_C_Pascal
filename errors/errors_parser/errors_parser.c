#include "errors_parser.h"

void error_1() {
    printf("Erro na linha 1. Faltando palavra \"program\".\n");
    exit(1);
}

void error_2() {
    printf("Erro na linha 1. Nome do programa escrito de forma incorreta.\n");
    exit(1);
}

void error_3(int linha) {
    printf("Erro na linha %d. Faltando o \";\".\n", linha);
    exit(1);
}

void error_4() {
    printf("Erro na linha 3. Faltando \"var\".\n");
    exit(1);
}

void error_5(int linha) {
    printf("Erro na linha %d. Nome de variável escrito errado.\n", linha);
    exit(1);
}

void error_6(int linha) {
    printf("Erro na linha %d. Faltando o \":\".\n", linha);
    exit(1);
}

void error_7(int linha) {
    printf("Erro na linha %d. Erro de tipo.\n", linha);
    exit(1);
}

void error_8(int linha) {
    printf("Erro na linha %d. Faltando \"begin\".\n", linha);
    exit(1);
}

void error_9(int linha) {
    printf("Erro na linha %d. Begin sem \"end\".\n", linha);
    exit(1);
}

void error_10(int linha) {
    printf("Erro na linha %d. \"write\" escrito errado.\n", linha);
    exit(1);
}

void error_11(int linha) {
    printf("Erro na linha %d. Faltando o \"(\".\n", linha);
    exit(1);
}

void error_12(int linha) {
    printf("Erro na linha %d. Faltando o \")\".\n", linha);
    exit(1);
}
