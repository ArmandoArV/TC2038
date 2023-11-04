#include <iostream>
#include <vector>

using namespace std;

int M, N;

bool isSafe(vector<vector<int>>& maze, int x, int y) {
    return (x >= 0 && x < M && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMazeBacktracking(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& solution) {
    if (x == M - 1 && y == N - 1) {
        solution[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y)) {
        solution[x][y] = 1;

        if (solveMazeBacktracking(maze, x, y + 1, solution))
            return true;

        if (solveMazeBacktracking(maze, x + 1, y, solution))
            return true;

        solution[x][y] = 0;
        return false;
    }

    return false;
}

bool solveMazeBranchAndBound(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& solution) {
    if (x == M - 1 && y == N - 1) {
        solution[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y)) {
        solution[x][y] = 1;

        if (solveMazeBranchAndBound(maze, x, y + 1, solution))
            return true;

        if (solveMazeBranchAndBound(maze, x + 1, y, solution))
            return true;

        solution[x][y] = 0;
        return false;
    }

    return false;
}

int main() {
    cin >> M >> N;
    vector<vector<int>> maze(M, vector<int>(N));
    vector<vector<int>> solution(M, vector<int>(N, 0));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
        }
    }

    solveMazeBacktracking(maze, 0, 0, solution);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            solution[i][j] = 0;
        }
    }

    solveMazeBranchAndBound(maze, 0, 0, solution);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
