#include <bits/stdc++.h>

const std::string filePath = "Code/ArchivosRelated/.CSV/books.csv";

struct {
    std::vector<std::string> booksName;
    std::vector<std::string> booksPrice;
    std::vector<std::string> bookStatus;
} booksInfo;

void readData();
void showData();

void addBooks();

void reserveBook();

int mainMenu() {
    int choice;
    std::cout << std::endl;
    std::cout << "Main Menu" << std::endl;
    std::cout << "1. Show books stored" << std::endl;
    std::cout << "2. Add books" << std::endl;
    std::cout << "3. Reserve a book" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << std::endl
              << "-> ";
    std::cin >> choice;

    return choice;
}

int main() {
    do {
        switch (mainMenu()) {
            case 1: {
                readData();
                showData();
                break;
            }

            case 2: {
                addBooks();
                break;
            }

            case 3: {
                readData();
                showData();
                reserveBook();
                break;
            }

            default:
                exit(EXIT_SUCCESS);
            }
    } while (true);

    return EXIT_SUCCESS;
}

void readData() {
    std::ifstream file(filePath);
    std::string line;
    char delimiter = ',';

    booksInfo.booksName.clear();
    booksInfo.booksPrice.clear();
    booksInfo.bookStatus.clear();

    while (std::getline(file, line)) {
        if ((line[0] != '#') && (!line.empty())) {
            std::stringstream streamLine(line);
            std::array<std::string, 3> tempValues;

            std::getline(streamLine, tempValues[0], delimiter);
            std::getline(streamLine, tempValues[1], delimiter);
            std::getline(streamLine, tempValues[2], delimiter);

            booksInfo.booksName.push_back(tempValues[0]);
            booksInfo.booksPrice.push_back(tempValues[1]);
            booksInfo.bookStatus.push_back(tempValues[2]);
        }
        else
            continue;
    }

    file.close();
}

void showData() {
    for (int i = 0; i < 40; i++)
        std::cout << "-";
    std::cout << std::endl;

    for (int i = 0; i < booksInfo.booksName.size(); i++) {
        std::cout << "Book Identifier: " << i + 1 << std::endl;
        std::cout << "Name: " << booksInfo.booksName.at(i) << std::endl;
        std::cout << "Price: " << booksInfo.booksPrice.at(i) << std::endl;
        std::cout << "Status: ";
        (booksInfo.bookStatus.at(i) == "1") ? 
            std::cout << "Avaliable" : std::cout << "Reserved";

        std::cout << std::endl;
        for (int i = 0; i < 40; i++)
            std::cout << "-";
        std::cout << std::endl;
    }
}

void addBooks() {
    std::ofstream dataFile(filePath, std::ios::app);

    dataFile << std::endl;
    std::array <std::string, 3> infoToStore;

    std::cout << "Ingrese el nombre del libro: ";
    std::cin >> infoToStore.at(0);

    std::cout << "Ingrese el precio del libro: ";
    std::cin >> infoToStore.at(1);

    do {
        std::cout << "Ingrese la disponibilidad del libro (1/0): ";
        std::cin >> infoToStore.at(2);
    } while ((infoToStore.at(2) != "1") && (infoToStore.at(2) != "0"));

    std::string line;
    for (auto &info : infoToStore)
        line += "," + info;
    
    line.erase(line.begin());

    dataFile << line;

    dataFile.close();
}

void reserveBook() {
    std::cout << std::endl;

    int bookIdentifier;
    do {
        std::cout << "Enter the book Identifier: ";
        std::cin >> bookIdentifier;
    } while (bookIdentifier > booksInfo.booksName.size());

    if (booksInfo.bookStatus.at(bookIdentifier - 1) == "0") 
        std::cout << "Sorry, the book has been already reserved";
    else {
        std::cout << "The book has been reserverd";

        // Tengo que modificar el valor en el csv para despues leerlo :>
        booksInfo.bookStatus.at(bookIdentifier - 1) = "0";
    }
    
    std::cout << std::endl;
}