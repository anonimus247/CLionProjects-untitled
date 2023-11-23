#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct NodoArbol {
    int dato;
    struct NodoArbol* izquierda;
    struct NodoArbol* derecha;
};

struct NodoArbol* crearNodo(int valor) {
    struct NodoArbol* nuevoNodo = (struct NodoArbol*)malloc(sizeof(struct NodoArbol));
    if (nuevoNodo == NULL) {
        printf("Error al asignar memoria para el nodo.\n");
        exit(EXIT_FAILURE);
    }
    nuevoNodo->dato = valor;
    nuevoNodo->izquierda = nuevoNodo->derecha = NULL;
    return nuevoNodo;
}

struct NodoArbol* insertar(struct NodoArbol* raiz, int valor) {
    if (raiz == NULL) {
        return crearNodo(valor);
    }

    printf("Desea insertar a la izquierda (1) o a la derecha (2) de %d: ", raiz->dato);
    int eleccion;
    scanf("%d", &eleccion);

    if (eleccion == 1) {
        raiz->izquierda = insertar(raiz->izquierda, valor);
    } else {
        raiz->derecha = insertar(raiz->derecha, valor);
    }

    return raiz;
}

void mostrar(struct NodoArbol* raiz) {
    if (raiz != NULL) {
        mostrar(raiz->izquierda);
        printf("%d ", raiz->dato);
        mostrar(raiz->derecha);
    }
}

int esArbolBinario(struct NodoArbol* raiz, int min, int max) {
    if (raiz == NULL) {
        return 1;  // Árbol vacío es un BST
    }

    if (raiz->dato < min || raiz->dato > max) {
        return 0;  // Fuera de rango, no es un BST
    }

    // Verificar recursivamente tanto el subárbol izquierdo como el derecho
    return esArbolBinario(raiz->izquierda, min, raiz->dato - 1) &&
           esArbolBinario(raiz->derecha, raiz->dato + 1, max);
}

int main() {
    // Inicializar la raíz con el valor 10
    struct NodoArbol* raiz = crearNodo(10);
    int eleccion, valor;

    do {
        printf("\nMenu:\n");
        printf("1. Insertar\n");
        printf("2. Mostrar\n");
        printf("3. Validar si es un arbol binario\n");
        printf("4. Salir\n");
        printf("Ingrese su eleccion: ");
        scanf("%d", &eleccion);

        switch (eleccion) {
            case 1:
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &valor);
                raiz = insertar(raiz, valor);
                break;
            case 2:
                printf("Datos en el arbol: ");
                mostrar(raiz);
                printf("\n");
                break;
            case 3:
                if (esArbolBinario(raiz, INT_MIN, INT_MAX)) {
                    printf("El arbol SI es un arbol binario.\n");
                } else {
                    printf("El arbol NO es un arbol binario.\n");
                }
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Intentelo de nuevo.\n");
        }
    } while (eleccion != 4);

    // Liberar la memoria antes de salir del programa

    return 0;
}