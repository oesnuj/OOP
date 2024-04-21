//잘 작동함
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct WordDefinition {
    string word;
    string definition;
};

bool compareInfo(const WordDefinition& a, const WordDefinition& b) {
    return a.word < b.word;
}

int main() {
    ifstream inFile;
    inFile.open("shuffled_dict.txt");
    if (!inFile.is_open()) {
        cout << "Unable to open the file" << endl;
        return -1;
    }

    string line;
    vector<WordDefinition> words;
    while (getline(inFile, line)) {
        int cutIndex = line.find('\t');
        string word = line.substr(0, cutIndex);
        string definition = line.substr(cutIndex + 1);
        words.push_back({ word, definition });
    }
    inFile.close();

    sort(words.begin(), words.end(), compareInfo);

    string inputWord;
    cin >> inputWord;

    bool found = false;
    for (const auto& wd : words) {
        if (wd.word == inputWord) {
            cout << wd.word << ": " << wd.definition << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Not found" << endl;

        vector<WordDefinition>::iterator it = words.begin();
        for (; it != words.end(); ++it) {
            if (it->word >= inputWord) {
                break;
            }
        }

        if (it != words.end()) {
            if (it != words.begin()) {
                auto prevIt = prev(it);
                cout << "- " << prevIt->word << ": " << prevIt->definition << endl;
            }
            if (it != words.end()) {
                cout << "+ " << it->word << ": " << it->definition << endl;
            }
        }
    }
    cout << "\nResults of prefix search:" << endl;
    for (const auto& wd : words) {
        if (wd.word.substr(0, inputWord.size()) == inputWord) {
            cout << wd.word << ": " << wd.definition << endl;
        }
    }

    return 0;
}
