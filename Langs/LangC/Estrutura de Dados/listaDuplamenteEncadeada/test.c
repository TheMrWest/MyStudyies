#include <stdio.h>
#include <stdlib.h>

void Panel() {
    char *textos[] = {
        "[0] - Sair",
        "[1] - Inserir no Inicio",
        "[2] - Inserir no fim",
        "[3] - Inserir ordenado",
        "[4] - Remover no Início",
        "[5] - Remover no fim",
        "[6] - Remover por valor",
        "[7] - Mostrar Lista",
        "[8] - Consultar se um elemento existe na linha"
    };

    int x = sizeof(textos) / sizeof(textos[0]);
    for (int i = 0; i < x; i++) {
        printf("%s\n", textos[i]);
    }
}

int main() {
    Panel();
    while (1) {
        int valor;
        scanf("%d", &valor);

        switch (valor) {
        case 1:
            break;
        
        default:
            break;
        }
    }
    

    return 0;
}
