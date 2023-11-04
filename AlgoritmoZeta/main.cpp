#include <iostream>
#include <string>
using namespace std;

void createZarray(const string& str, int Z[]) {
    int n = str.length();
    int L, R, k;
    L = R = 0;
    for (int i = 1; i < n; ++i) {
        if (i > R) {
            L = R = i;
            while (R < n && str[R - L] == str[R])
                R++;
            Z[i] = R - L;
            R--;
        } else {
            k = i - L;
            if (Z[k] < R - i + 1)
                Z[i] = Z[k];
            else {
                L = i;
                while (R < n && str[R - L] == str[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
}

void zAlgorithm(const string& text, const string& pattern) {
    string str = pattern + "$" + text;
    int len = str.length();
    int Z[len];
    createZarray(str, Z);
    for (int i = 0; i < len; ++i) {
        if (Z[i] == pattern.length())
            cout << (i - pattern.length() - 1) << "\t";
    }
}

int main() {
    string str = "Hello! Welcome To tutorials Point programming tutorial";
    string pattern = "tutorial";
    cout << "The pattern '" << pattern << "' is found in the string '" << str << "' at index:\t";
    zAlgorithm(str, pattern);
    return 0;
}
