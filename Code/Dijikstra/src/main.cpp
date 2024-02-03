/**
 *  @group 
 *      - Mauro Alonso Gonzalez Figueroa
 *      - Juan Jose Jimenez Guardo
 *      - Jorge Andres Herrera Monsalve
 *      - Daniel David Herrera Acevedo
 * 
 * 
*/

#include <iostream>
#include <vector>
#include <float.h>

class Graph {
    private:
        std::vector <std::vector <int>> adjacent;
        std::vector <std::vector <float>> weight;

    public:
        Graph(std::vector<std::vector<int>> &adjacent, std::vector <std::vector <float>> &weight) {
            this -> adjacent = std::move(adjacent);
            this -> weight = std::move(weight);
        }

        void dijikstra(int startNode, int endNode) {
            const int NO_NODES = this -> adjacent.size();

            std::vector <int> predecessor (NO_NODES);
            std::vector <int> visited (NO_NODES);
            std::vector <float> distance (NO_NODES, FLT_MAX);

            distance[startNode] = 0;
            int count = 0;

            while (count < NO_NODES - 1) {
                float minDistance = FLT_MAX;
                int nextNode;

                for (int i = 0; i < NO_NODES; i++) {
                    if (!visited[i] && distance[i] <= minDistance) {
                        minDistance = distance[i];
                        nextNode = i;
                    }
                }

                visited[nextNode] = 1;

                for (int i = 0; i < NO_NODES; i++) {
                    if (!visited[i] && this -> adjacent[nextNode][i] && distance[nextNode] != FLT_MAX
                        && distance[nextNode] + this -> weight[nextNode][i] < distance[i]) {
                        predecessor[i] = nextNode;
                        distance[i] = distance[nextNode] + this -> weight[nextNode][i];
                    }
                }

                count++;
            }

            std::cout << "Distance between " << startNode << " and " << endNode << " is " << distance[endNode] << std::endl;
            std::cout << "Route = " << endNode;

            int j = endNode;
            do {
                j = predecessor[j];
                std::cout << " <- " << j;
            } while (j != startNode);

            std::cout << std::endl;
        }
};

int main() {
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
    graph -> dijikstra(0, 3);

    delete graph;

    return EXIT_SUCCESS;
}