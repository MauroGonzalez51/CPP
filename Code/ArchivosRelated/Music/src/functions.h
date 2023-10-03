#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
#include <initializer_list>

namespace fs = std::filesystem;

void log(std::string message);
std::string concatenate(std::vector <std::string> args);
bool directoryExists(const fs::path path, bool logMessage);
bool fileExists(const fs::path path, const std::string filename);
void readFile(const fs::path folderPath, const std::string& filename, std::vector <fs::path>& data);
void readDirectory(const fs::path directory, std::vector <fs::path> &data);
bool compareStrings(const std::string& str1, const std::string& str2);
void removeDuplicates(std::vector <fs::path> &data, std::vector <fs::path> &musicData);
void writeToFile(const fs::path folderPath, const std::string& filename, fs::path item);
bool validateMsg(std::string msg);

#endif