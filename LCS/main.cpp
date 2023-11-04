#include <iostream>
#include <string>

using namespace std;

string longestCommonSubstring(const string &X, const string &Y) {
    int m = X.length();
    int n = Y.length();

    int longest[m + 1][n + 1];
    int len = 0;
    int row = 0, col = 0;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                longest[i][j] = 0;
            else if (X[i - 1] == Y[j - 1]) {
                longest[i][j] = longest[i - 1][j - 1] + 1;
                if (len < longest[i][j]) {
                    len = longest[i][j];
                    row = i;
                    col = j;
                }
            } else
                longest[i][j] = 0;
        }
    }

    if (len == 0) {
        return "There exists no common substring";
    }

    string final_str;
    final_str.reserve(len);

    while (longest[row][col] != 0) {
        final_str = X[row - 1] + final_str;
        row--;
        col--;
    }

    return final_str;
}

int main() {
    string X = "helloworld";
    string Y = "worldbook";
    string result = longestCommonSubstring(X, Y);

    cout << result << endl;

    return 0;
}
