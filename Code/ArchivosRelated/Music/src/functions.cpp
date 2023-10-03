#include "functions.h"

void log(std::string message) {
    std::cout << std::endl << "[ INFO ] " << message << std::endl;
}

std::string concatenate(std::vector <std::string> args) {
    std::ostringstream formattedMessage;
    for (auto &arg : args) { formattedMessage << arg << " "; }
    return formattedMessage.str();
}

bool directoryExists(const fs::path path, bool logMessage) {
    bool isValid = false;
    if (fs::exists(path) && fs::is_directory(path)) {
        if (logMessage) { log(concatenate({"Directory found:", path.string()})); };
        isValid = true;
    } else {
        if (logMessage) log(concatenate({"Directory not found:", path.string()}));
    } 
    return isValid;
}

bool fileExists(const fs::path path, const std::string filename) {
    bool fileExists = false;

    if (!directoryExists(path, false)) { return fileExists; }

    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.path().filename().string() == filename) {
            log(concatenate({"File found:", entry.path().string()}));
            fileExists = true;
            break;
        }
    }

    return fileExists;
}

void readFile(const fs::path folderPath, const std::string& filename, std::vector <fs::path>& data) {
    std::ifstream file(fs::absolute(folderPath / filename));

    if (!file.is_open()) { 
        log(concatenate({"Error during opening the file:", filename}));
        return;
    }

    std::string line;

    std::getline(file, line);
    while (std::getline(file, line)) {
        fs::path filePath(line);
        data.push_back(filePath);
    }

    file.close();
}

void readDirectory(const fs::path directory, std::vector <fs::path> &data) {
    for (const auto& file : fs::directory_iterator(directory)) {
        data.push_back(file.path());
    }
}

bool compareStrings(const std::string& str1, const std::string& str2) {
    std::locale loc;
    
    return std::use_facet<std::collate<char>>(loc).compare(
        str1.c_str(), str1.c_str() + str1.length(),
        str2.c_str(), str2.c_str() + str2.length()) == 0;
}

void removeDuplicates(std::vector<fs::path>& data, std::vector<fs::path>& musicData) {
    for (auto it = data.begin(); it != data.end(); ++it) {
        for (auto musicIt = musicData.begin(); musicIt != musicData.end(); ++musicIt) {
            // if (it -> string() == musicIt -> string()) {
            //     log(concatenate({"File removed from [ musicData ]:", it -> string()}));
            //     musicData.erase(musicIt);
            //     break;
            // }

            if (compareStrings(it -> string(), musicIt -> string())) {
                log(concatenate({"File removed from [ musicData ]:", it -> string()}));
                musicData.erase(musicIt);
                break;
            }
        }
    }
}

void writeToFile(const fs::path folderPath, const std::string& filename, fs::path item) {
    std::ofstream file(fs::absolute(folderPath / filename), std::ios::app);

    if (!file.is_open()) {
        log(concatenate({"Error during opening the file:", filename}));
        return;
    }

    std::string string = item.string();

    if (string.front() == '\"') string = string.substr(1, string.size() - 2);

    file << string << std::endl;

    file.close();
}

bool validateMsg(std::string msg) {
    std::vector <std::string> options = {"Si", "No", "si", "no", "SI", "NO", "S", "N", "s", "n", "y", "n", "Y", "N", "YES", "NO", "yes", "no", "Yes", "No"};
    bool flag = false;
    for (int i = 0; i < options.size(); i++) {
        if (msg == options[i]) {
            flag = true;
            if (i % 2 != 0){
                flag = false;
            }
        }
    }
    return flag;
}


