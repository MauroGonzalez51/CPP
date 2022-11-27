#include <bits/stdc++.h>
#include <ctype.h>

using namespace std;

struct {
    vector <string> nombreProductos;
    vector <float> precioUnitario;
} Inventario;

void escribirLinea(const string c) {
    cout << std::endl;
    for (int i = 0; i < 40; i++)
        cout << c;
    cout << std::endl;
}

void verInventario() {
    if (Inventario.nombreProductos.size() > 0) {
        for (int i = 0; i < Inventario.nombreProductos.size(); i++) {
            escribirLinea("*");
            cout << "Identificador: " << i + 1 << std::endl;
            cout << "Nombre del Producto: " << Inventario.nombreProductos.at(i) << std::endl;
            cout << "Precio Unitario: " << Inventario.precioUnitario.at(i) << std::endl;
        }
    } else 
        cout << std::endl << "No hay productos registrados en el inventario" << std::endl;
}

bool validarMensaje(const string mensajeIngresado) {
    bool esValido = false;
    vector <std::string> opcionesValidasTrue = {"Si", "si", "SI", "S", "s", "y", "Y", "YES", "yes", "Yes"};
    for (auto &opcion : opcionesValidasTrue) { if (mensajeIngresado == opcion) esValido = true; }
    return esValido;
}

void agregarProducto() {
    do {
        string nombreProducto;
        float precioUnitario;

        escribirLinea("/");
        cout << "Ingrese el nombre del producto: ";
        cin >> nombreProducto;

        cout << "Ingrese el precio Unitario del producto: ";
        cin >> precioUnitario;

        Inventario.nombreProductos.push_back(nombreProducto);
        Inventario.precioUnitario.push_back(precioUnitario);

        string mensajeSalida;
        cout << "Desea agregar otro producto?" << std::endl;
        cout << "-> ";
        cin >> mensajeSalida;

        if (!validarMensaje(mensajeSalida))
            break;

    } while (true);
}

bool crearOrden(string nombreCliente, int cantidadOrdenada, int identificadorProducto) {
    bool success = false;
    std::ofstream archivo ("SistemaInventario/pedidos/Recibo-" + nombreCliente + ".txt", std::ios::app);

    if (archivo.is_open()) {
        archivo << "Orden a nombre de: " << nombreCliente<< std::endl;
        try {
            archivo << "Producto ordenado: " << Inventario.nombreProductos.at(identificadorProducto - 1) << std::endl;
            archivo << "Cantidad Ordenada: " << std::to_string(cantidadOrdenada) << std::endl;
            archivo << "Total a pagar: " << std::to_string(cantidadOrdenada * Inventario.precioUnitario.at(identificadorProducto - 1)) << std::endl;
            success = true;
        } catch (...) {
            archivo << "NULL" << std::endl;
            cout << "Producto no encontrado" << std::endl;
        }
    }
    return success;
}

void hacerPedido() {
    verInventario();
    escribirLinea("/");

    if (Inventario.nombreProductos.size() != 0) {
        string nombreCliente;
        int cantidadOrdenada, identificadorProducto;

        cout << "Ingrese su nombre: ";
        cin >> nombreCliente;

        cout << "Ingrese el identificador del producto: ";
        cin >> identificadorProducto;

        cout << "Ingrese la cantidad deseada: ";
        cin >> cantidadOrdenada;

        (crearOrden(nombreCliente, cantidadOrdenada, identificadorProducto)) ? 
            cout << std::endl << "Orden realizada Correctamente" << std::endl :
                cout << std::endl << "Error al momento de realizar la orden" << std::endl;
    } else {
        cout << endl << "Procediendo a agregar productos primero" << endl;
        escribirLinea("*");
        agregarProducto();
    }
}

char mainMenuDashboard() {
    escribirLinea("-");
    char opcion;
    cout << "1. Ver Inventario" << std::endl;
    cout << "2. Agregar a Inventario" << std::endl;
    cout << "3. Hacer un Pedido" << std::endl;
    cout << "4. Salir" << std::endl;
    cout << "-> ";
    cin >> opcion;

    return opcion;
}

bool verificarOpcion(const char opcion) {
    return (isalpha(opcion)) ? true : false;
}

void mainMenu() {
    do {
        char opcion = mainMenuDashboard();
        if (verificarOpcion(opcion)) 
            cout << endl << "Ingrese una opcion valida" << endl;
        else {
            if (opcion == '1') verInventario(); 
            else if (opcion == '2') agregarProducto();
            else if (opcion == '3') hacerPedido();
            else exit(EXIT_FAILURE);
        }
    } while (true);
}

int main(void) {
    mainMenu();
    return EXIT_SUCCESS;
}