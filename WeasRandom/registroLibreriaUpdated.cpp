#include <bits/stdc++.h>

using namespace std;


int main() {
    array <string, 12> options = {'Si', 'No', 's', 'n', 'S', 'n', 'y', 'n', 'Y', 'n', '0', '1'};
    int precioTotal = 0;
    do {
        array <int, 4> precioLibros = {10000, 15000, 20000, 25000};
        array <int, 4> precioPaginas = {50, 70, 90, 120};

        int tipoLibro, numeroPaginas, precioActual;
        cout << "Ingrese el Tipo de Libro: ";
        cin >> tipoLibro;

        do {
            cout << "Ingrese el numero de Paginas: ";
            cin >> numeroPaginas;
        } while (numeroPaginas < 1);

        if (tipoLibro == 1 || tipoLibro == 2 || tipoLibro == 3) {
            precioActual = precioLibros[tipoLibro - 1] + (precioPaginas[tipoLibro -1] * numeroPaginas);
            precioTotal += precioActual;
        } else {
            precioActual = precioLibros[precioLibros.size() - 1] + (precioPaginas[precioLibros.size() -1] * numeroPaginas);
            precioTotal += precioActual;
        }
        cout << "Tipo de Libro: " << tipoLibro << " | No. de Paginas: " << numeroPaginas << " | Precio: " << precioActual << endl;

        char opcion[2];
        cout << "Nuevo Registro? -> ";
        cin >> opcion;

        bool Flag = false;
        for (int i : options) {
            if (opcion == options[i]) {
                Flag = true;
                if (i % 2 != 0){
                    Flag = false;
                }
            }
        }
        if (Flag == false)
            break;
    } while (true);

    return 0;
}