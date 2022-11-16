#include <bits/stdc++.h>

// * To do list:
// * - Create the constructor of the "Book" class
// * - Create a loop to ask for the info
// * - Create a dashboard with all the functions

std::string folderPath = "BookManagement/files/";

struct {
    std::vector <int> bookID;
    std::vector <std::string> bookName;
    std::vector <float> bookPrice;
    std::vector <bool> bookStatus;
} allBooksInfo;

class Library {
    public:
        void writeLine(const std::string c, const int n) {
            std::cout << std::endl;
            for (int i = 0; i < n; i++) 
                std::cout << c;
            std::cout << std::endl;
        }

        void clearBookInfo() {
            allBooksInfo.bookID.clear();
            allBooksInfo.bookName.clear();
            allBooksInfo.bookPrice.clear();
            allBooksInfo.bookStatus.clear();
        }

        void showBooksStored() {
            for (int i = 0; i < allBooksInfo.bookName.size(); i++) {
                writeLine("-", 50);
                std::cout << "[Book ID: " << allBooksInfo.bookID.at(i) << "]" << std::endl;
                std::cout << "Name: " << allBooksInfo.bookName.at(i) << std::endl;
                std::cout << "Price: " << allBooksInfo.bookPrice.at(i) << std::endl;
                std::cout << "Book Status: ";
                    (allBooksInfo.bookStatus.at(i)) ? std::cout << "Avaliable" : "Reserved";
            }

        }

};

class Book : public Library {
    private:
        std::string bookName;
        float bookPrice;
        bool bookStatus;

    public:
        Book(const int bookCount) {
            
        }

        void writeBookInfoToStruct() {
            allBooksInfo.bookName.push_back(this -> bookName);
            allBooksInfo.bookPrice.push_back(this -> bookPrice);
            allBooksInfo.bookStatus.push_back(this -> bookStatus);
        }

        bool createBookFile() {
            bool success;
            std::ofstream bookFile (fodlerPath + this -> bookName + ".txt", std::ios::app);

            if (std::filesystem::exits (folderPath + this -> bookName + ".txt")) success = false;
            else {
                if (bookFile.is_open()) {
                    bookFile << std::to_string(allBooksInfo.bookName.size() + 1) << std::endl;
                    bookFile << this -> bookName << std::endl;
                    bookFile << this -> bookPrice << std::endl;
                    (this -> bookStatus) ? 
                        bookFile << "Avaliable" << std::endl : bookFile << "Reserved" << std::endl;
                }
            }
            
            return success,
        }
};


int main(void) {
    Book* book = new Book();




    return EXIT_SUCCESS;
}