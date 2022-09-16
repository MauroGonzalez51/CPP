/**
 * @Grupo:
 *      - Mauro Gonzalez
 *      -
 *      -
 * @descripcion registroLibreria
 */

#include <iostream>

using namespace std;

int main() {
    
    int precioInventario = 0;
    int newUser = 1;
    do {
        int tipoLibro, numeroPaginas, precioLibro;
        // Pidiendo el tipo de libro
        cout << "Ingrese el tipo de libro: ";
        cin >> tipoLibro;

        // Pidiendo + validando la cantidad de paginas
        do {
            cout << "Ingrese el numero de paginas: ";
            cin >> numeroPaginas;
        } while (numeroPaginas < 1);

        // Asginando un precio al libro dependiendo del tipo de este
        switch(tipoLibro) {
            case 1: precioLibro = 10000 + (numeroPaginas * 50); break;
            case 2: precioLibro = 15000 + (numeroPaginas * 70); break;
            case 3: precioLibro = 20000 + (numeroPaginas * 90); break;
            default: precioLibro = 25000 + (numeroPaginas * 120); break;
        }
        precioInventario += precioLibro;

        // Mostrando los datos
        cout << endl;
        cout << "Tipo de Libro: " << tipoLibro << " | No. de Paginas: " << numeroPaginas << " | Precio: " << precioLibro << endl;
        cout << endl;

        // Verificando si el bucle se va a repetir de nuevo
        cout << "Continuar con el Inventario (0/1)? -> ";
        cin >> newUser;

    } while (newUser != 0); 
    cout << "Precio Total Inventario: " << precioInventario << endl;
    return 0;
}