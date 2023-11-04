#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <limits>
#include <set>
#include <queue>
#include <map>

using namespace std;

class Graph {
public:
    Graph(int vertex, const vector<vector<int>> &matrix) {
        path = vector<int>();
        V = vertex;
        adjList = map<int, list<pair<int, int>>>();

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] != 0) {
                    adjList[i].push_back(make_pair(j, matrix[i][j]));
                }
            }
        }
    }

    vector<int> solution(int start) {
        path.push_back(start);

        for (int i = 0; i < V - 1; ++i) {
            vector<int> dist = dijkstra(path[i]);
            int smallest = -1;

            for (int j = 0; j < V; ++j) {
                if (dist[j] != 0 && dist[j] != numeric_limits<int>::max() &&
                    find(path.begin(), path.end(), j) == path.end()) {
                    if (smallest == -1 || dist[j] < dist[smallest]) {
                        smallest = j;
                    }
                }
            }

            if (smallest == -1) {
                path.push_back(distance(dist.begin(), find(dist.begin(), dist.end(), numeric_limits<int>::max())));
            } else {
                path.push_back(smallest);
            }
        }

        return path;
    }

    vector<int> dijkstra(int source) {
        vector<int> dist(V, numeric_limits<int>::max());
        set<int> seen;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

        dist[source] = 0;
        heap.push(make_pair(source, dist[source]));

        while (!heap.empty()) {
            int node = heap.top().first;
            int weight = heap.top().second;
            heap.pop();

            seen.insert(node);

            for (const auto &edge: adjList[node]) {
                int conn = edge.first;
                int w = edge.second;

                if (seen.find(conn) == seen.end()) {
                    int d = weight + w;

                    if (d < dist[conn]) {
                        dist[conn] = d;
                        heap.push(make_pair(conn, d));
                    }
                }
            }
        }

        return dist;
    }

private:
    vector<int> path;
    int V;
    map<int, list<pair<int, int>>> adjList;
};

pair<int, vector<vector<int>>>
readFile(const string &filename) {
    ifstream file(filename);
    int start;
    vector<vector<int>> matrix;

    if (file.is_open()) {
        file >> start;
        string line;
        while (getline(file, line)) {
            vector<int> row;
            size_t start = 0, found = 0;
            while (found != string::npos) {
                found = line.find(',', start);
                row.push_back(stoi(line.substr(start, found - start)));
                start = found + 1;
            }
            matrix.push_back(row);
        }
        file.close();
    }

    return make_pair(start, matrix);
}

int main() {
    // Txt format should be:
    // 1st line: Start node (int) If you want the first node to start at 0. Ends at newline
    // Next lines: Matrix of adjacency, each element in a row separated by a comma, and rows separated by a newline.
    // Example:
    // 0
    // 0, 16, 45, 32
    // 16, 0, 18, 21
    // 45, 18, 0,  7
    // 32, 21, 7,  0

    string filename = "input.txt";
    int start;
    vector<vector<int>> matrix;

    tie(start, matrix) = readFile(filename);

    Graph graph(matrix.size(), matrix);

    vector<int> solution = graph.solution(start);

    cout << "Forma de cablear las colonias con fibra: ( ";
    char abc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < solution.size(); ++i) {
        cout << abc[solution[i]] << ", ";
    }
    cout << ")" << endl;

    return 0;
}
