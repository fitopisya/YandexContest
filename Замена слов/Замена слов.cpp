#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

set<string> SplitIntoWords(const string& text) {
    set<string> words;
    string word;
    for (const char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.insert(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.insert(word);
    }
    return words;
}

vector<string> SplitIntoWordsVec(const string& text) {
    vector<string> words;
    string word;
    for (const char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}

int main()
{
    string str;
    getline(cin, str);
    set<string> short_words = SplitIntoWords(str);
    
    getline(cin, str);
    vector<string> words = SplitIntoWordsVec(str);
    
    if(words.empty()){
        return 0;
    }
    for (int i = 0; i < words.size(); ++i){
        string word;
        for (int j = 0; j < words[i].size(); ++j){
            word += words[i][j];
            if (short_words.contains(word)){
                cout << word << ' ';
                break;
            }
            if (j == words[i].size() - 1){
                cout << word << ' ';
            }
        }
    }
}
