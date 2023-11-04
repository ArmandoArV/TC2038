#include <iostream>
#include <vector>

using namespace std;

vector<int> computeLPS(const string& pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);

    int len = 0;
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

vector<int> kmp(const string& text, const string& pattern) {
    int m = pattern.size();
    int n = text.size();

    vector<int> lps = computeLPS(pattern);
    vector<int> results;

    int i = 0;
    int j = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            results.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return results;
}

int main() {
    // string text = "AAAABAAAAABBBAAAAB";
    //string pattern = "AAAB";

    string text = "ababcababcabc";
    string pattern="abc";
    vector<int> results = kmp(text, pattern);

    for (int result : results) {
        cout << "Pattern found at index: " << result << endl;
    }

    return 0;
}
