#include <bits/stdc++.h>

class Query {
    private:
        std::string expression;
        bool isDefined;
        std::vector <char> vectorQuery;
        int numbersBeforeX = 0;

        struct {
            std::vector <char> xCoefficientVector;
            std::vector <char> raisedToCoefficientVector;

            int xCoefficient, raisedToCoefficient;

            double xCoefficientPostIntegration, raisedToCoefficientPostIntegration;
        } resultInfo;
    
    public:
        void sintaxisSample() {
            std::cout << "Sintaxis Sample" << std::endl;
            std::cout << "nX^n" << std::endl;
            std::cout << "Siendo n: R" << std::endl;
        }

        void askQuery() {
            std::cout << "-> ";
            std::cin >> this -> expression;
        }

        void separateQuery() {
            for (int i = 0; i < expression.length(); i++) {
                char caracter = expression[i];
                vectorQuery.push_back(caracter);
            }
        }

        void separateCoefficients() {
            for (int i = 0; i < vectorQuery.size(); i++) {
                if ((vectorQuery.at(i) == 'X') || (vectorQuery.at(i) == 'x')) break;
                else this -> numbersBeforeX++;
            }
        }

        void separateCoefficientX() {
            for (int i = 0; i < this -> numbersBeforeX; i++) {
                this -> resultInfo.xCoefficientVector.push_back(vectorQuery.at(i));
            }
        }

        void concatenateCoefficientX() {
            std::string xCoefficientAux = "";
            for (auto &digit : this -> resultInfo.xCoefficientVector)
                xCoefficientAux += digit;
            
            this -> resultInfo.xCoefficient = std::stoi(xCoefficientAux);
        }

        void separateXRaisedTo() {
            int caracterIndex;
            for (int i = 0; i < vectorQuery.size(); i++) {
                if (vectorQuery.at(i) == '^') caracterIndex = i;
            }

            for (int i = caracterIndex + 1; i < vectorQuery.size(); i++)
                this -> resultInfo.raisedToCoefficientVector.push_back(vectorQuery.at(i));
        }

        void concatenateXRaisedTo() {
            std::string xRaisedToCoefficient = "";
            for (auto &digit : this -> resultInfo.raisedToCoefficientVector)
                xRaisedToCoefficient += digit;
            
            this -> resultInfo.raisedToCoefficient = std::stoi(xRaisedToCoefficient);
        }

        void integrateCoefficients() {
            this -> resultInfo.raisedToCoefficientPostIntegration = resultInfo.raisedToCoefficient + 1;
            this -> resultInfo.xCoefficientPostIntegration = resultInfo.xCoefficient / resultInfo.raisedToCoefficientPostIntegration;
        }

        void showIntegration() {
            std::cout << std::endl << "[RESULT]" << std::endl << std::endl;
            std::cout << resultInfo.xCoefficientPostIntegration << "X^" << resultInfo.raisedToCoefficientPostIntegration << std::endl; 
        }
};

int main(void) {
    Query* query = new Query();
    query -> sintaxisSample();
    query -> askQuery();
    query -> separateQuery();
    query -> separateCoefficients();
    query -> separateCoefficientX();
    query -> concatenateCoefficientX();
    query -> separateXRaisedTo();
    query -> concatenateXRaisedTo();
    query -> integrateCoefficients();
    query -> showIntegration();
    return EXIT_SUCCESS;
}