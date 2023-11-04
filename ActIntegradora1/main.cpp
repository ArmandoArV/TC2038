#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string readFile(const string &fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening file " << fileName << endl;
        exit(1);
    }

    string content;
    char ch;
    while (file.get(ch)) {
        if (ch != ' ') {
            content += tolower(ch);
        }
    }

    file.close();
    return content;
}

bool searchSequence(const string &sequence, const string &content) {
    string lowerSequence = sequence;
    transform(lowerSequence.begin(), lowerSequence.end(), lowerSequence.begin(), ::tolower);
    return content.find(lowerSequence) != string::npos;
}

pair<bool, pair<int, int>> findMirrorPalindrome(const string &file) {
    string lowerFile = file;
    transform(lowerFile.begin(), lowerFile.end(), lowerFile.begin(), ::tolower);

    int start = 0;
    int end = 0;
    int longestLength = 0;

    for (int i = 0; i < lowerFile.length(); i++) {
        for (int j = i; j < lowerFile.length(); j++) {
            bool isPalindrome = true;
            for (int k = 0; i + k < j - k; k++) {
                if (lowerFile[i + k] != lowerFile[j - k]) {
                    isPalindrome = false;
                    break;
                }
            }

            if (isPalindrome) {
                int length = j - i + 1;
                if (length > longestLength) {
                    longestLength = length;
                    start = i;
                    end = j;
                }
            }
        }
    }

    return make_pair(longestLength > 0, make_pair(start, end));
}

pair<int, int> findCommonSubstring(const string &file1, const string &file2) {
    string lowerFile1 = file1;
    transform(lowerFile1.begin(), lowerFile1.end(), lowerFile1.begin(), ::tolower);
    string lowerFile2 = file2;
    transform(lowerFile2.begin(), lowerFile2.end(), lowerFile2.begin(), ::tolower);

    int start = 0;
    int end = 0;
    int longestLength = 0;

    for (int i = 0; i < lowerFile1.length(); i++) {
        for (int j = 0; j < lowerFile2.length(); j++) {
            int length = 0;
            while (i + length < lowerFile1.length() && j + length < lowerFile2.length() &&
                   lowerFile1[i + length] == lowerFile2[j + length]) {
                length++;
            }

            if (length > longestLength) {
                longestLength = length;
                start = i;
                end = i + length - 1;
            }
        }
    }

    return make_pair(start, end);
}

int main() {
    string transmission1 = readFile("transmission1.txt");
    string transmission2 = readFile("transmission2.txt");
    string mcode1 = readFile("mcode1.txt");
    string mcode2 = readFile("mcode2.txt");
    string mcode3 = readFile("mcode3.txt");

    cout << boolalpha;

    // Parte 1
    cout << "transmission1.txt contiene mcode1.txt: " << searchSequence(mcode1, transmission1) << endl;
    cout << "transmission1.txt contiene mcode2.txt: " << searchSequence(mcode2, transmission1) << endl;
    cout << "transmission1.txt contiene mcode3.txt: " << searchSequence(mcode3, transmission1) << endl;
    cout << "transmission2.txt contiene mcode1.txt: " << searchSequence(mcode1, transmission2) << endl;
    cout << "transmission2.txt contiene mcode2.txt: " << searchSequence(mcode2, transmission2) << endl;
    cout << "transmission2.txt contiene mcode3.txt: " << searchSequence(mcode3, transmission2) << endl;

    // Parte 2
    pair<bool, pair<int, int>> palindrome1 = findMirrorPalindrome(transmission1);
    pair<bool, pair<int, int>> palindrome2 = findMirrorPalindrome(transmission2);

    if (palindrome1.first) {
        cout << "Position inicial y final del palindrome en transmission1.txt: " << palindrome1.second.first + 1 << " " << palindrome1.second.second + 1 << endl;
    } else {
        cout << "No se encontró palíndromo en transmission1.txt" << endl;
    }

    if (palindrome2.first) {
        cout << "Posición inicial y final del palindrome en transmission2.txt: " << palindrome2.second.first + 1 << " " << palindrome2.second.second + 1 << endl;
    } else {
        cout << "No se encontró palíndromo en transmission2.txt" << endl;
    }

    // Parte 3
    pair<int, int> commonSubstring = findCommonSubstring(transmission1, transmission2);
    cout << "Position inicial y final del substring common más largo entre transmission1.txt y transmission2.txt: " << commonSubstring.first + 1 << " " << commonSubstring.second + 1 << endl;

    return 0;
}
