#include <iostream>
#include <vector>
#include <filesystem>
#include "functions.h"

namespace fs = std::filesystem;

const fs::path filesDir = fs::absolute(fs::current_path() / "files");
const std::string fileName = "data.csv";

const fs::path musicDir = "D:/Musik Related/Musik/";

std::vector <fs::path> data; // * data in files/data.csv
std::vector <fs::path> musicData; // * data in musicDir

// TODO

// Read whats in files/data.csv
// Store all of that inside a vector

// Read everything on the musicDir
// Store all of that inside a vector

// If an element thats in the files/data.csv vector is
// in the musicDir vector, then delete it from the musicDir vector

// The comparisson must be done by paths

// finally create a loop with the rest of elements of musicDir

void verifyDirectories() {
    if (!directoryExists(filesDir, true)) { exit(EXIT_FAILURE); }
    if (!directoryExists(musicDir, true)) { exit(EXIT_FAILURE); }
    if (!fileExists(filesDir, fileName)) { exit(EXIT_FAILURE); }
}

void loop() {
    for (auto it = musicData.begin(); it != musicData.end(); ++it) {
        std::string userInput;
        log(concatenate({"Actual:", it -> string()}));
        std::cout << std::endl << "Eliminar?" << std::endl;
        std::cout << "-> ";
        std::cin >> userInput;

        if (userInput.empty()) { exit(EXIT_FAILURE); }
        if (userInput == "clear") { exit(EXIT_SUCCESS); }

        if (!validateMsg(userInput)) {
            writeToFile(filesDir, fileName, *it);
            system("cls");
            log(concatenate({"Added to file:", it -> string()}));
            continue;
        };
        system("cls");

        fs::remove(*it);

        log(concatenate({"Deleted:", it -> string()}));
    }
}

void initialize() {
    readFile(filesDir, fileName, data);

    log(concatenate({"Current [ data ] size:", std::to_string(data.size())}));

    readDirectory(musicDir, musicData);
    log(concatenate({"Current [ musicData ] size:", std::to_string(musicData.size())}));

    removeDuplicates(data, musicData);

    log("Initialized [...]");

    loop();
}

int main() {
    verifyDirectories(); 
    initialize();
    return EXIT_SUCCESS;
}