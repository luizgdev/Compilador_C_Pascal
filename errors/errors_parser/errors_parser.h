#ifndef COMPILADOR_C_PASCAL_ERRORS_PARSER_H
#define COMPILADOR_C_PASCAL_ERRORS_PARSER_H

#include <stdio.h>
#include <stdlib.h>

void error_1(); // program escrito errado ou faltando.

void error_2(); // nome do programa escrito errado.

void error_3(int); // faltando o ;

void error_4(); // faltando o var

void error_5(int); // nome de variavel errado

void error_6(int); // faltando o ":"

void error_7(int); // erro de tipo

void error_8(int); // Faltando begin

void error_9(int); // begin sem end

void error_10(int); // write escrito

void error_11(int); // faltando (

void error_12(int); // faltando )

void error_13(int); //

#endif //COMPILADOR_C_PASCAL_ERRORS_PARSER_H
