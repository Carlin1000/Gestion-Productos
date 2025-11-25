#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 50

// Función para ingresar datos del inventario
void ingresarDatos(char nombres[][MAX_NOMBRE], float precios[], int *cantidad);

// Función para calcular el precio total
float calcularTotal(float precios[], int cantidad);

// Función para encontrar el producto más caro
void encontrarMasCaro(char nombres[][MAX_NOMBRE], float precios[], int cantidad);

// Función para encontrar el producto más barato
void encontrarMasBarato(char nombres[][MAX_NOMBRE], float precios[], int cantidad);

// Función para calcular el precio promedio
float calcularPromedio(float precios[], int cantidad);

// Función para buscar un producto por nombre
void buscarProducto(char nombres[][MAX_NOMBRE], float precios[], int cantidad);

// Función para mostrar el menú
void mostrarMenu();