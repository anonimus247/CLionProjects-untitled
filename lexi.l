%%
^[0-9]{10}$   { printf("Número de teléfono válido: %s\n", yytext); }
.             { printf("Número de teléfono inválido: %s\n", yytext); }
%%

int main() {
    yylex();
    return 0;
}
