#include <bits/stdc++.h>

class Fibonacci {
    private:
        std::vector <int> sucesion = {1, 1};
    
    public:
        Fibonacci (const int cantidadValores) {
            for (int i = 0; i < cantidadValores; i++) 
                sucesion.push_back(sucesion[i] + sucesion[i + 1]);
        }

        void showData() {
            for (auto &numero : sucesion)
                std::cout << numero << " ";
        }
};

int main() {
    Fibonacci* fibonacci = new Fibonacci(44);

    fibonacci -> showData();

    return EXIT_SUCCESS;
}