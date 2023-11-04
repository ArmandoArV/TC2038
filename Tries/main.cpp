#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

void insertWord(TrieNode* root, const string& word) {
    TrieNode* current = root;
    for (char ch : word) {
        if (current->children.find(ch) == current->children.end()) {
            current->children[ch] = new TrieNode();
        }
        current = current->children[ch];
    }
    current->isEndOfWord = true;
}

bool searchWord(TrieNode* root, const string& word) {
    TrieNode* current = root;
    for (char ch : word) {
        if (current->children.find(ch) == current->children.end()) {
            return false;
        }
        current = current->children[ch];
    }
    return current->isEndOfWord;
}

void dfsTraversal(TrieNode* node, string& currentWord, vector<string>& result) {
    if (node->isEndOfWord) {
        result.push_back(currentWord);
    }
    for (const auto& [ch, child] : node->children) {
        currentWord.push_back(ch);
        dfsTraversal(child, currentWord, result);
        currentWord.pop_back();
    }
}

int main() {
    int N, M;
    cout << "Enter number of words to insert in the TRIE: ";
    cin >> N;

    TrieNode* root = new TrieNode();

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        insertWord(root, word);
    }

    cout << "Enter number of words to search in the TRIE: ";
    cin >> M;

    vector<string> wordsToSearch(M);
    vector<bool> searchResults(M);

    for (int i = 0; i < M; i++) {
        cin >> wordsToSearch[i];
        searchResults[i] = searchWord(root, wordsToSearch[i]);
    }

    string currentWord;
    vector<string> dfsResult;
    dfsTraversal(root, currentWord, dfsResult);

    cout << "DFS traversal of the TRIE:" << endl;
    for (const string& word : dfsResult) {
        cout << word << endl;
    }
    cout << "Search results:" << endl;
    for (bool result : searchResults) {
        cout << (result ? "Found" : "Not Found") << endl;
    }
    delete root;

    return 0;
}
