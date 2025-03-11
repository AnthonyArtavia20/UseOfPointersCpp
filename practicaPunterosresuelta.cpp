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

void mallocList() { // Declarar lista de 25 elementos con malloc, luego otorgarle numeros aleatorios acada uno y finalmente imprimir

  srand(time(0)); //Inicializar el generador de números aleatorios:

  int *lista = (int*)malloc(25*sizeof(int));

  for (int i = 0; i < 25; i++) {
    lista[i] = rand();
  }
  //imprimir cada elemento para confirmar los números randoms
  for (int i = 0; i < 25; i++) {
    cout << "Elemento con número random: " << lista[i] << endl;
  }
  free(lista);
}

void listaConAritmeticaPunterosInt() { //Utilizaré aritmética de punteros para recorrer una lista.
  srand(time(0));

  int *lista = (int*)malloc(25*sizeof(int));
  for (int i = 0; i < 25; i++) {
    *(lista + i) = rand();
  }

  for (int i = 0; i < 25; i++) {
    cout << "Elemento printeado con aritmética de punteros: " << *(lista + i) << endl;
  }

  free(lista);
}

void listaConAritmeticaPunterosDouble() {
  srand(time(0));

  double *lista = (double*)malloc(25*sizeof(double));
  for (int i = 0; i < 25; i++ ) {
    *(lista + 1) = rand();
  }
  for(int i = 0; i  < 25; i++) {
    cout << "Elemento double printeado con aritmética de punteros: " << *(lista + i) << endl;
  }

  free(lista);
}

void explicacionDelContadorEnEjercicio6y7(){
  /*
    En los ejercicios 6 y 7  pasados, se realizó la creación de dos listas, una enteros y otra de doubles
    estas a pesar de ser tipos de datos distintos, se pueden iterar simplemente haciendo puntero++, pues
    el contador de punteros se encarga de incrementar la cantidad de bytes necesarios para llegar al siguiente
    elemento de la lista, por lo que no importa si la lista es de enteros, doubles, chars, etc, el puntero
    se encargará de incrementar la cantidad de bytes necesarios para llegar al siguiente elemento de la lista.

    resumen: Lo hace automático según el tipo de datos.
  */
}

bool cambiarPorNumeroAleatorioUsandoUnPuntero(int* punteroAlNumero) {
  srand(time(0)); //Inicializar el generador de números aleatorios

  if (punteroAlNumero == NULL) { // comprobar que el puntero venga vacío
    return false;
  }

  *punteroAlNumero = rand(); // Desreferenciamos  el puntero para acceder al valor que almacena.
  cout << "El número random es: " << *punteroAlNumero << endl;

  return true;
}

//----------------------------------------Ejercicio 9(start) --------------------------------------------------------------
struct mallocStruct { //definición de la estructura  a operar
  int a;
  unsigned int b;
  double c;
};

void cambioDeLosDatosParte2(mallocStruct* punteroALaEstructura) { // encargada de recibir el puntero a la estructura, acceder a ella y cambiar los datos por otros aleatorios
  if (punteroALaEstructura == nullptr) { // Comprobar si el puntero es NULL
      cerr << "Error: puntero a la estructura es NULL.\n";
      return;
  }

  cout << "Valores originales de la estructura:" << endl;
  cout << "a: " << punteroALaEstructura->a << endl;
  cout << "b: " << punteroALaEstructura->b << endl;
  cout << "c: " << punteroALaEstructura->c << endl;

  // Asignar nuevos valores aleatorios
  punteroALaEstructura->a = rand();
  punteroALaEstructura->b = rand();
  punteroALaEstructura->c = (double)rand() / RAND_MAX; // Número aleatorio entre 0 y 1

  cout << "Nuevos valores de la estructura:" << endl;
  cout << "a: " << punteroALaEstructura->a << endl;
  cout << "b: " << punteroALaEstructura->b << endl;
  cout << "c: " << punteroALaEstructura->c << endl;
}

void creacionDeStructurasParte1() {
  srand(time(0)); // Inicializar el generador de números aleatorios

  // Reservar memoria para la estructura
  mallocStruct* estructura = (mallocStruct*)malloc(sizeof(mallocStruct));

  if (estructura == nullptr) { // Comprobar si malloc falló
      cerr << "Error: No se pudo asignar memoria para la estructura.\n";
      return;
  }

  // Asignar valores aleatorios
  estructura->a = rand();
  estructura->b = rand();
  estructura->c = (double)rand() / RAND_MAX; // Número aleatorio entre 0 y 1

  cout << "Valores de la estructura inicial:" << endl;
  cout << "a: " << estructura->a << endl;
  cout << "b: " << estructura->b << endl;
  cout << "c: " << estructura->c << endl;

  cout << "Cambio de los datos a nuevos aleatorios..." << endl;
  cambioDeLosDatosParte2(estructura);

  // Liberar memoria
  free(estructura);
}
//----------------------------------------Ejercicio 9(end) --------------------------------------------------------------

//----------------------------------------Ejercicio 10(start) --------------------------------------------------------------
struct structForLists {
  int *listaEnteros;
  double *listaDobles;
};

void inicializarListas(structForLists* estructura){ //Recibe un puntero a la estructura y se encarga de inicializar las listas con valores aleatorios
  srand((time(0))); //Inicializar el generador de números aleatorios

  //Reservar memoria para las listas:
  estructura->listaEnteros = (int*)malloc(25*sizeof(int));
  estructura->listaDobles = (double*)malloc(25*sizeof(double));

  if (estructura->listaEnteros == nullptr || estructura->listaDobles == nullptr) { // Comprobar si malloc falló
      cerr << "Error: No se pudo asignar memoria para las listas.\n";
      return;
  }

  // Asignar valores aleatorios a las listas:
  for (int i = 0; i < 25; i++) {
    *(estructura->listaEnteros + i) = rand();
    *(estructura->listaDobles + i) = (double)rand();
  }

  //Imprimir los valores en las listas;
  cout << "Valores de la lista de enteros:" << endl;
  for (int i = 0; i < 25; i++) {
    cout << *(estructura->listaEnteros + i) << " ";
  }
  cout << endl;

  cout << "Valores de la lista de doubles:" << endl;
  for (int i = 0; i < 25; i++) {
    cout << *(estructura->listaDobles + i) << " ";
  }
  cout << endl;

  free(estructura->listaEnteros);
  free(estructura->listaDobles);
}
//----------------------------------------Ejercicio 10(End) --------------------------------------------------------------

int main() {
    //Ejercicio 1
  //declararEInicializarPunteros();
    //Ejercicio 2
  //intercambioDePosicionMemoria();
    //Ejercicio 3
  //investigarUnPunteroSinInicializar();
    //Ejercicio 4
  //mallocList();

    //Ejercicio 5
  //listaConAritmeticaPunterosInt();
    //Ejercicio 6
  //listaConAritmeticaPunterosDouble();
    //Ejercicio 7
  //explicacionDelContadorEnEjercicio6y7();
    //Ejercicio 8
  //int a = 8;
  //int *puntero = &a;
  //cambiarPorNumeroAleatorioUsandoUnPuntero(puntero);
    //Ejercicio 9
  //creacionDeStructurasParte1();
    //Ejercicio 10
  structForLists estructura;
  inicializarListas(&estructura);

  return 0;
}