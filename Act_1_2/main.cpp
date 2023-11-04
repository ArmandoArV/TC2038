#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> cambioDinamico(vector<int>& denominaciones, int precio, int pago) {
    int n = denominaciones.size();
    vector<vector<int>> dp(n + 1, vector<int>(pago + 1, 0));

    for (int i = 0; i <= n; ++i)
        dp[i][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= pago; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= denominaciones[i - 1])
                dp[i][j] = max(dp[i][j], dp[i][j - denominaciones[i - 1]] + 1);
        }
    }

    vector<int> cambio(n, 0);
    int j = pago;
    for (int i = n; i >= 1; --i) {
        while (j >= denominaciones[i - 1] && dp[i][j] == dp[i][j - denominaciones[i - 1]] + 1) {
            cambio[i - 1]++;
            j -= denominaciones[i - 1];
        }
    }

    return cambio;
}

vector<int> cambioAvaro(vector<int>& denominaciones, int precio, int pago) {
    vector<int> cambio(denominaciones.size(), 0);

    int diferencia = pago - precio;
    int i = 0;

    while (diferencia > 0 && i < denominaciones.size()) {
        if (denominaciones[i] <= diferencia) {
            cambio[i]++;
            diferencia -= denominaciones[i];
            } else {
            i++;
        }
    }

    return cambio;
}

int main() {
    int N;
    cin >> N;

    vector<int> denominaciones(N);
    for (int i = 0; i < N; ++i) {
        cin >> denominaciones[i];
    }

    int P, Q;
    cin >> P >> Q;

    vector<int> cambioDp = cambioDinamico(denominaciones, P, Q);
    vector<int> cambioA = cambioAvaro(denominaciones, P, Q);
    for (int i = N - 1; i >= 0; --i) {
        cout << cambioDp[i] << endl;
    }

    cout << "---" << endl;
    for (int i = N - 1; i >= 0; --i) {
        cout << cambioA[i] << endl;
    }

    return 0;
}
