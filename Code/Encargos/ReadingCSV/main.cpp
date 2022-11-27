// ! THIS IS THE MAIN FILE 

#include <bits/stdc++.h>
#include "dynamicSorting.h"
#include "readingFile.h"
#include "createBreakpoints.h"
#include "logFileManagement.h"
#include "analizeData.h"

const std::string folderPath = "ReadingCSV/files/";

// TODO: 
//   - Create the breakpoints :>

struct {
    std::vector <float> dataVector;
    std::vector <std::string> dataVectorParseString;
    std::vector <float> breakpoints;
} dataArrays;

// This function is to check is all the files with the info stored already exits, if then the program exits
bool filesExits() {
    const std::string categoriesFolderPath = folderPath + "categoryFiles/";
    for (int i = 0; i < dataArrays.breakpoints.size(); i++) {
        if (!std::filesystem::exists(categoriesFolderPath + std::to_string(dataArrays.breakpoints.at(i)) + ".txt"))
            return false;
    }
    return true;
}

void deletePreviousInfo() {
    const std::string categoriesFolderPath = folderPath + "categoryFiles/";
    for (int i = 0; i < dataArrays.breakpoints.size(); i++)
        std::filesystem::remove(categoriesFolderPath + std::to_string(dataArrays.breakpoints.at(i)) + ".txt");
}

void categoriesMain() {
    (readingFile(dataArrays.dataVector, dataArrays.dataVectorParseString, folderPath)) ?
        writeLog(folderPath, "Finished reading the file") : writeLog(folderPath, "Error during reading the file");
    dataArrays.dataVectorParseString.clear();

    createBreakpoints(dataArrays.dataVector, dataArrays.breakpoints);
    writeLog(folderPath, "Breakpoints created succesfully");

    if (!filesExits()) {
        deletePreviousInfo();
        writeLog(folderPath, "Categorizing Values ...");
        categorizePeople(dataArrays.dataVector, dataArrays.breakpoints, folderPath);
    } else {
        writeLog(folderPath, "Files already exits");
        writeLog(folderPath, "Proced to analize data ...");
    }
}

int main(void) {
    writeLog(folderPath);
    categoriesMain();
    analizeDataMain(dataArrays.breakpoints, folderPath);
    return EXIT_SUCCESS;
}