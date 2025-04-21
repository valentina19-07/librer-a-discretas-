#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* codificar(const char* mensaje, int clave);
char* decodificar(const char* mensaje, int clave);

int main(void) {
    int opc, clave;
    char* mensaje;
    char* str;
    do {
        printf("1. codificar\n2. decodificar\n3. salir\n");
        scanf("%d",&opc);
        fflush(stdin);
        switch(opc) {
            case 1:
                printf("Mensaje a codificar:\n");
                mensaje = calloc(100, sizeof(char));
                fgets(mensaje, 100, stdin);
                printf("Desplazamiento de los caracteres:\n");
                scanf("%d",&clave);
                str = codificar(mensaje, clave);
                printf("Mensaje codificado:\n");
                puts(str);
                free(str);
                free(mensaje);
                break;
            case 2:
                printf("Mensaje a decodificar:\n");
                mensaje = calloc(100, sizeof(char));
                fgets(mensaje, 100, stdin);
                printf("Desplazamiento de los caracteres:\n");
                scanf("%d",&clave);
                str = decodificar(mensaje, clave);
                printf("Mensaje codificado:\n");
                puts(str);
                free(str);
                free(mensaje);
                break;
            case 3:
                opc = 0;
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }
    }while (opc);
    return 0;
}

char* codificar(const char* mensaje, int clave) {
    char* mensajeCodificado;
    int strLen = strlen(mensaje) - 1;// aqui el -1 por que fgets captura el enter
    mensajeCodificado = calloc(strLen, sizeof(char));
    for(int i = 0; i < strLen; i++){
        int caracter = (mensaje[i] - 32 + clave) % 95 + 32;
        mensajeCodificado[i] = caracter;
    }
    return  mensajeCodificado;
}

char* decodificar(const char* mensaje, int clave) {
    char* mensajeCodificado;
    int strLen = strlen(mensaje) - 1;// aqui el -1 por que fgets captura el enter
    mensajeCodificado = calloc(strLen, sizeof(char));
    for(int i = 0; i < strLen; i++){
        int caracter = mensaje[i] - 32 - clave;
        if(caracter >= 0) {
            mensajeCodificado[i] = caracter % 95 + 32;
        }else {
            //modulo de un negativo
            int aux = caracter/95;
            if (caracter/95 != (float) caracter/95)
                aux--;
            aux *= 95;
            mensajeCodificado[i] = caracter - aux + 32;
        }
    }
    return  mensajeCodificado;
}