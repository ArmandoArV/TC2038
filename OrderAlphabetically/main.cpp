#include <iostream>
#include <vector>
#include <string>

using namespace std;

void merge(vector<std::string>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

   vector<std::string> leftArr(n1);
   vector<std::string> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<string>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    vector<string> nombres = {"Juan", "María", "Carlos", "Ana", "Luis"};

    int n = nombres.size();
    mergeSort(nombres, 0, n - 1);

    cout << "Nombres ordenados alfabéticamente: ";
    for (const string& nombre : nombres) {
        cout << nombre << " ";
    }
    cout << endl;

    return 0;
}
