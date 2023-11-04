/*
 *
 *  Made by: Armando Arredondo Valle and Diego Efraín Antonion Pérez
 *  Date: 22/08/2023
 * */

#include <iostream>
#include <vector>

using namespace std;

void generateCombinations(vector<int> &elements, vector<int> &combination, int n, int k, int index) {
  // Si hemos generado k elementos, los imprimimos
  if (k == 0) {
    for (int i = 0; i < combination.size(); i++) {
      cout << combination[i] << " ";
    }
    cout << endl;
    return;
  }

  // Recorremos todos los elementos restantes
  for (int i = index; i < n; i++) {
    // Añadimos el elemento actual a la combinación
    combination.push_back(elements[i]);

    // Generamos las combinaciones restantes sin el elemento actual
    generateCombinations(elements, combination, n, k - 1, i + 1);

    // Eliminamos el elemento actual de la combinación
    combination.pop_back();
  }
}

int main() {
  // Creamos una lista de elementos
  vector<int> elements = {1, 2, 3, 4, 5};

  // Generamos todas las combinaciones de 3 elementos
  vector<int> combination;
  generateCombinations(elements, combination, elements.size(), 3, 0);

  return 0;
}
