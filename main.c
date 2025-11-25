#include "inventario.h"

int main() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];
    int cantidad = 0;
    int opcion;

    printf("          BIENVENIDO    \n");
    printf("    Gestion de Inventario     \n");

    while (1) {
        mostrarMenu();
        
        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            printf("\nOpcion no valida. Intente de nuevo.\n");
        } else {
            // Validar que la opción esté entre 1 y 8
            while (opcion < 1 || opcion > 8) {
                printf("\n Opcion no valida. Debe ser un numero entre 1 y 8.\n");
                mostrarMenu();
                scanf("%d", &opcion);
            }
            switch (opcion) {

                case 1:
                    ingresarDatos(nombres, precios, &cantidad);
                    break;
                    
                case 2: {
                    if (cantidad == 0) {
                        printf("\n No hay productos ingresados.\n");
                    } else {
                        float total = calcularTotal(precios, cantidad);
                        printf("\n Precio total del inventario: $%.2f\n", total);
                    }
                    break;
                }
                    
                case 3:
                    encontrarMasCaro(nombres, precios, cantidad);
                    break;
                    
                case 4:
                    encontrarMasBarato(nombres, precios, cantidad);
                    break;
                    
                case 5: {
                    if (cantidad == 0) {
                        printf("\n No hay productos ingresados.\n");
                    } else {
                        float promedio = calcularPromedio(precios, cantidad);
                        printf("\n Precio promedio: $%.2f\n", promedio);
                    }
                    break;
                }
                    
                case 6:
                    buscarProducto(nombres, precios, cantidad);
                    break;
                    
                case 7: {
                    if (cantidad == 0) {
                        printf("\n No hay productos en el inventario.\n");
                    } else {
                        printf("\n Inventario Completo \n");
                        for (int i = 0; i < cantidad; i++) {
                            printf("%d. %s - $%.2f\n", i + 1, nombres[i], precios[i]);
                        }
                    }
                    break;
                }
                    
                case 8:
                    printf("Hasta luego, gracias por usar el Sistema.\n\n");
                    return 0;
            }
        }
    }
    return 0;
}