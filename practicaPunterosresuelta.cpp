#include <iostream> // biblioteca para entrada y salida de datos
#include <cstdio> // biblioteca para printf
#include <cstdlib> // biblioteca para srand y rand
#include <ctime> // biblioteca para time

using namespace std; // para no tener que escribir std:: antes de cada cout o cin

void declararEInicializarPunteros() {
    double datoDouble = 2.2040;
    int datoInt = 3;
    char datoChar = 'a';

    double *punteroDouble = &datoDouble;
    int *punteroInt = &datoInt;
    char *punteroChar = &datoChar;

    // Imprimiremos los valores de: dirección, el valor y el tamaño de la memoria(en bytes) de cada una de las seis variables.

    // Valores de dirección de cada variable:
    printf("Dirección de datoDouble: 0x%p\n", (void*)&datoDouble);
    printf("Dirección de datoInt: 0x%p\n", (void*)&datoInt);
    printf("Dirección de datoChar: 0x%p\n", (void*)&datoChar);
    printf("Dirección de punteroDouble: 0x%p\n", (void*)&punteroDouble);
    printf("Dirección de punteroInt: 0x%p\n", (void*)&punteroInt);
    printf("Dirección de punteroChar: 0x%p\n", (void*)&punteroChar);

    // Valores almacenados de cada variable:
    printf("Valor almacenado de datoDouble: %f\n", datoDouble);
    printf("Valor almacenado de datoInt: %d\n", datoInt);
    printf("Valor almacenado de datoChar: %c\n", datoChar);
    printf("Valor almacenado de punteroDouble: 0x%p\n", (void*)punteroDouble);
    printf("Valor almacenado de punteroInt: 0x%p\n", (void*)punteroInt);
    printf("Valor almacenado de punteroChar: 0x%p\n", (void*)punteroChar);

    // Tamaño en bytes de cada variable:
    printf("Tamaño de datoDouble: %zu bytes\n", sizeof(datoDouble));
    printf("Tamaño de datoInt: %zu bytes\n", sizeof(datoInt));
    printf("Tamaño de datoChar: %zu bytes\n", sizeof(datoChar));
    printf("Tamaño de punteroDouble: %zu bytes\n", sizeof(punteroDouble));
    printf("Tamaño de punteroInt: %zu bytes\n", sizeof(punteroInt));
    printf("Tamaño de punteroChar: %zu bytes\n", sizeof(punteroChar));
}

void intercambioDePosicionMemoria(){
  //Inicializar la semilla del generador de números aleatorios
  srand(time(0));

  //crear e inicializar dos variables enteras con valores aleatorios
  int a = rand();
  int b = rand();

  //Creación de tres punteros:
  int *puntero1;
  int *puntero2;
  int *puntero3;

  //Obtener la posición de memoria de las variables a y b y asignarla a los punteros 1 y 2 respectivamente.
  puntero1 = &a;
  puntero2 = &b;

  //Imprimir los valores de todo antes de hacer el swap:
  //imprimir los valores para ver que tod esté bien:
  cout << "Antes de hacer el Swap: "  << endl;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "puntero1: " << puntero1 << endl;
  cout << "puntero2: " << puntero2 << endl;
  cout << "puntero3: " << puntero3 << endl;

  //intercambio de valor de puntero 1 y 2 utilizando el puntero 3, sin obtener nuevamente la posición de memoria de las variables enteras "a" y "b".
  puntero3 = puntero1;
  puntero1 = puntero2;
  puntero2 = puntero3;

  //imprimir los valores para ver que tod esté bien:
  cout << "\nDespués de hacer el Swap: "  << endl;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "puntero1: " << puntero1 << endl;
  cout << "puntero2: " << puntero2 << endl;
  cout << "puntero3: " << puntero3 << endl;

}

void investigarUnPunteroSinInicializar() {
  //Declarar un puntero sin inicializar
  int* puntero;
  cout << "El valor del puntero sin inicializar es:  " << puntero << endl;
  //El significado de este resultado "0x7ffff7cb738f" es que el puntero al no estar incializado
  //como  null o 0, se ha creado en un espacio ya existente que podría contener cualquier valor,
  //por lo que el valor que se imprime es el valor que se encuentra en esa dirección de memoria.
}

int main() {
  //Ejercicio 1
  //declararEInicializarPunteros();
  //Ejercicio 2
  //intercambioDePosicionMemoria();
  //Ejercicio 3
  investigarUnPunteroSinInicializar();

  return 0;
}