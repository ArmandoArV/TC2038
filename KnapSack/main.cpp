#include <iostream>
#include <vector>

using namespace std;

// Función para calcular el valor máximo de la mochila
int knapsack(int N, vector<int>& valores, vector<int>& pesos, int capacidad) {
    vector<vector<int>> dp(N + 1, vector<int>(capacidad + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int w = 1; w <= capacidad; ++w) {
            if (pesos[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - pesos[i - 1]] + valores[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[N][capacidad];
}

int main() {
    int N;
    cin >> N;

    vector<int> valores(N);
    vector<int> pesos(N);

    for (int i = 0; i < N; ++i) {
        cin >> valores[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> pesos[i];
    }

    int capacidad;
    cin >> capacidad;

    int resultado = knapsack(N, valores, pesos, capacidad);
    cout << "Ganancia óptima: " << resultado << endl;

    return 0;
}
