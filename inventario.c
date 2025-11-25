#include "inventario.h"

void ingresarDatos(char nombres[][MAX_NOMBRE], float precios[], int *cantidad) {
    printf("\n Registro de datos\n");
    
    int resultado;
    do {
        printf("Cuantos productos desea ingresar? (maximo %d): ", MAX_PRODUCTOS);
        resultado = scanf("%d", cantidad);
        
        if (resultado != 1) {
            while (getchar() != '\n');
            printf("Entrada no valida. Ingrese un numero entero.\n");
        } else if (*cantidad > MAX_PRODUCTOS || *cantidad <= 0) {
            printf("Cantidad invalida. Debe ser entre 1 y %d.\n", MAX_PRODUCTOS);
        }
    } while ((resultado != 1) || (*cantidad > MAX_PRODUCTOS || *cantidad <= 0));
    
    for (int i = 0; i < *cantidad; i++) {
        printf("\nProducto %d:\n", i + 1);
        
        printf("  Nombre: ");
        while (getchar() != '\n'); 

        fgets(nombres[i], MAX_NOMBRE, stdin);
        for (int j = 0; j < MAX_NOMBRE; j++) {
            if (nombres[i][j] == '\n') {
                nombres[i][j] = '\0';
                break;
            }
        }

        do {
            printf("  Precio: $");
            resultado = scanf("%f", &precios[i]);

            if (resultado != 1) {
                while (getchar() != '\n');
                printf("Entrada no valida. Ingrese un numero.\n");
            } else if (precios[i] < 0) {
                printf("El precio no puede ser negativo. Intente de nuevo.\n");
            }
        } while (resultado != 1 || precios[i] < 0);
    }
    
    printf("\n Datos ingresados exitosamente.\n");
}

float calcularTotal(float precios[], int cantidad) {
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += precios[i];
    }
    return total;
}

void encontrarMasCaro(char nombres[][MAX_NOMBRE], float precios[], int cantidad) {
    if (cantidad == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }
    
    int indice = 0;
    float maximo = precios[0];
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] > maximo) {
            maximo = precios[i];
            indice = i;
        }
    }
    
    printf("\n Producto mas costoso:\n");
    printf("  Nombre: %s\n", nombres[indice]);
    printf("  Precio: $%.2f\n", maximo);
}

void encontrarMasBarato(char nombres[][MAX_NOMBRE], float precios[], int cantidad) {
    if (cantidad == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }
    
    int indice = 0;
    float minimo = precios[0];
    
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] < minimo) {
            minimo = precios[i];
            indice = i;
        }
    }
    
    printf("\n Producto mas barato:\n");
    printf("  Nombre: %s\n", nombres[indice]);
    printf("  Precio: $%.2f\n", minimo);
}

float calcularPromedio(float precios[], int cantidad) {
    if (cantidad == 0) return 0;
    return calcularTotal(precios, cantidad) / cantidad;
}

void buscarProducto(char nombres[][MAX_NOMBRE], float precios[], int cantidad) {
    if (cantidad == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }

    char busqueda[MAX_NOMBRE];
    int encontrado = 0;

    do {
        printf("\n Busqueda de producto \n");
        printf("Ingrese el nombre del producto a buscar: ");
        scanf("%s", busqueda);

        encontrado = 0;
        for (int i = 0; i < cantidad; i++) {
            int j = 0;
            while (nombres[i][j] == busqueda[j] && nombres[i][j] != '\0') {
                j++;
            }
            
            if (nombres[i][j] == busqueda[j]) {
                printf("\n Producto encontrado:\n");
                printf("  Nombre: %s\n", nombres[i]);
                printf("  Precio: $%.2f\n", precios[i]);
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            printf("\n El producto '%s' no se encontro en el inventario.\n", busqueda);
            printf("Intente nuevamente.\n");
        }

    } while (!encontrado);
}

void mostrarMenu() {
    printf("     Sistema de Gestion   \n");
    printf(" 1. Ingresar productos                  \n");
    printf(" 2. Calcular precio total del inventario\n");
    printf(" 3. Encontrar producto mas caro         \n");
    printf(" 4. Encontrar producto mas barato       \n");
    printf(" 5. Calcular precio promedio            \n");
    printf(" 6. Buscar producto por nombre          \n");
    printf(" 7. Mostrar todos los productos         \n");
    printf(" 8. Salir                               \n");
    printf("Seleccione una opcion: ");
}
