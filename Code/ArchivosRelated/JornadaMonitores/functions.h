#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include "monitor.h"
#include "search_info.h"

namespace fs = std::filesystem;

void clearInputStreamBuffer();
bool directoryExists(const std::string& folderPath);
void readFile(const std::string& folderPath, std::vector <Monitor>& monitorList);
bool checkCase(Monitor monitor, SearchInfo searchInfo);
void convertToInt(const std::string& str, int& result);
void searchMonitor(std::vector <Monitor>& monitorList, SearchInfo searchInfo);

#endif 