#include <iostream>

#include <iostream>
#include <vector>

using namespace std;

// Función para leer la matriz de adyacencias
vector<vector<int>> leerMatriz(int n) {
  vector<vector<int>> matriz(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matriz[i][j];
    }
  }

  return matriz;
}

// Función para implementar el algoritmo de Dijkstra
void dijkstra(vector<vector<int>> matriz, int n, int origen) {
  // Inicializamos la matriz de distancias
  vector<vector<int>> distancias(n, vector<int>(n, INT_MAX));

  // Marcamos el nodo origen como visitado
  distancias[origen][origen] = 0;

  // Creamos una cola para almacenar los nodos no visitados
  queue<int> cola;
  cola.push(origen);

  // Mientras haya nodos no visitados
  while (!cola.empty()) {
    // Extraemos el nodo de la cabeza de la cola
    int actual = cola.front();
    cola.pop();

    // Actualizamos las distancias de los nodos adyacentes
    for (int i = 0; i < n; i++) {
      // Si el nodo adyacente no está visitado y la distancia actual es menor que la distancia anterior
      if (distancias[actual][i] < INT_MAX && distancias[origen][i] > distancias[actual][i] + matriz[actual][i]) {
        // Actualizamos la distancia del nodo adyacente
        distancias[origen][i] = distancias[actual][i] + matriz[actual][i];

        // Agregamos el nodo adyacente a la cola
        cola.push(i);
      }
    }
  }

  // Imprimimos las distancias
  for (int i = 0; i < n; i++) {
    cout << "node " << origen << " to node " << i << " : " << distancias[origen][i] << endl;
  }
}

// Función para implementar el algoritmo de Floyd-Warshall
void floyd_warshall(vector<vector<int>> matriz, int n) {
  // Inicializamos la matriz de distancias
  vector<vector<int>> distancias(n, vector<int>(n, INT_MAX));

  // Copiamos la matriz de adyacencias a la matriz de distancias
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      distancias[i][j] = matriz[i][j];
    }
  }

  // Realizamos n iteraciones
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        // Actualizamos la distancia entre i y j a través de k
        if (distancias[i][k] != INT_MAX && distancias[k][j] != INT_MAX && distancias[i][j] > distancias[i][k] + distancias[k][j]) {
          distancias[i][j] = distancias[i][k] + distancias[k][j];
        }
      }
    }
  }

  // Imprimimos la matriz de distancias
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << distancias[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  // Leemos el número de nodos
  int n;
  cout << "Ingrese el numero de nodos: ";
  cin >> n;

  // Leemos la matriz de adyacencias
  vector<vector<int>> matriz = leerMatriz(n);

  // Ejecutamos el algoritmo de Dijkstra
  dijkstra(matriz, n, 0);

  // Ejecutamos el algoritmo de Floyd-Warshall
  floyd_warshall(matriz, n);

  return 0;
