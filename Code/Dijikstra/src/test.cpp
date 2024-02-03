#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <limits>

/**
 * @brief This function takes a format string and a variable number of arguments and replaces each occurrence of '{}' in the format string with the corresponding argument value.
 *
 * @tparam Args The types of the arguments.
 * @param formatStr A constant reference to a string representing the format string.
 * @param args The variable number of arguments.
 * @return std::string The resulting string after replacing the placeholders with the argument values.
 */
template <typename ... Args>
std::string format(const std::string& formatStr, Args&&... args) {
    std::ostringstream result;
    size_t pos = 0;

    ((pos = formatStr.find("{}", pos)), ..., (
        result << formatStr.substr(pos, formatStr.find("{}", pos + 2) - pos) << std::forward<Args>(args),
        pos += 2
    ));

    result << formatStr.substr(pos);
    return result.str();
}

class Graph {
    private: 
        std::vector <std::vector <int>> adjacent;
        std::vector <std::vector <float>> weight;
        int NO_NODES; 

        template <typename T>
        size_t findMinValue(const std::vector <T> &vector) {
            if (vector.empty()) return static_cast <size_t> (-1);

            size_t minIndex = 0;

            for (size_t i = 0; i < vector.size(); ++i) {
                if (vector[i] < vector[minIndex]) minIndex = i;
            }

            return minIndex;
        }

    public:
        Graph(std::vector <std::vector <int>> adjacent, std::vector <std::vector <float>> weight) {
            this -> adjacent = std::move(adjacent);
            this -> weight = std::move(weight);
            this -> NO_NODES = this -> adjacent.size();
        }

        float findShortestDistance(int startNode, int endNode) {
            std::vector <bool> visited (NO_NODES, false);
            std::vector <float> tag (NO_NODES, std::numeric_limits <float>::infinity());

            tag[startNode] = 0;

            for (int count = 0; count < this -> NO_NODES - 1; count++) {
                int currentNode = static_cast <int> (findMinValue(tag));                
        
                std::cout << "Selected node: " << currentNode << std::endl;
        
                visited[currentNode] = true;

                for (int i = 0; i < this -> NO_NODES; i++) {
                    if (!visited[i] && this -> adjacent[currentNode][i]) {
                        if (tag[currentNode] + this -> weight[currentNode][i] < tag[i]) {
                            tag[i] = tag[currentNode] + this -> weight[currentNode][i];
                        }
                    }
                }
            }

            return (tag[endNode] == std::numeric_limits <float>::infinity()) ? std::numeric_limits<float>::infinity() : tag[endNode];
        }
};

int main(int argc, char **argv) {
    std::vector <std::vector <int>> adjacent = {
            {0, 1, 0, 0},
            {1, 0, 1, 1},
            {0, 1, 0, 1},
            {0, 1, 1, 0}
        };

    std::vector <std::vector <float>> weight = {
        {0, 3, 0, 0},
        {3, 0, 2, 4},
        {0, 2, 0, 8},
        {0, 4, 8, 0}
    };

    Graph *graph = new Graph(adjacent, weight);
    std::cout << graph -> findShortestDistance(0, 3) << std::endl;

    delete graph;


    return EXIT_SUCCESS;
}