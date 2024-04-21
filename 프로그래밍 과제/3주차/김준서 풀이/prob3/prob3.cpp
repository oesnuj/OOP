//202111602 김준서
//잘 작동합니다.
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

vector<string> words;
vector<vector<int>> lineNums;
vector<string> lines; //line을 저장하기위해

void makeIndex(string fileName);
void handle_find(string keyword);
void addWord(string word, int lineNum);
int findWord(string keyword);
string trim(string str);
void tolowercase(string& str);
vector<string> split_line(string line, char delimiter);


int main() {
    string command;
    while (true) {
        cout << "$ ";
        cin >> command;
        if (command == "read") {
            string fileName;
            cin >> fileName;
            makeIndex(fileName);
        }
        else if (command == "exit")
            break;
        else if (command == "find") {
            string keyword;
            cin >> keyword;
            handle_find(keyword);
        }
    }
    return 0;
}

void handle_find(string keyword) {
    tolowercase(keyword); //키워드를 소문자로 바꾼다.
    int index = findWord(keyword);
    if (index != -1) {
        cout << "The word " << keyword << " appears " <<
            lineNums[index].size() << " times in lines: \n";
        for (auto v : lineNums[index])
            cout << v << ": " << lines[v] << "\n"; //문장 위치와 실제 문장도 출력
        cout << endl;
    }
    else
        cout << "The word " << keyword << " doesn’t appear." << endl;
}

void makeIndex(string fileName) {
    ifstream theFile(fileName);
    int lineNum = 0;
    string line;
    while (getline(theFile, line)) {
        lines.push_back(line);
         //단어를 쪼개기전에 해당 문장을 저장한다.
        vector<string> tokens = split_line(line, ' ');
        for (auto s : tokens)
            if (s.length() > 3)  //길이가 3미만인 단어는 addWord로 가지 못한다.
                addWord(s, lineNum);
        lineNum++;
    }
    theFile.close();
}
void tolowercase(string& str) //소문자 변환 함수
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
}

string trim(string str) {
    int s = 0, t = str.length() - 1;;
    while (s < str.length() && !isalpha(str[s]))
        s++;
    while (t >= 0 && !isalpha(str[t]))
        t--;
    if (s <= t)
        return str.substr(s, t - s + 1);
    else
        return "";
}

vector<string> split_line(string line, char delimiter)
{
    vector <string> tokens;
    stringstream sstream(line);
    string str;
    
    while (getline(sstream, str, delimiter))
    {
        str = trim(str); //특수기호와 숫자 제거
        tolowercase(str); // 소문자로 변환
        //tokens에는 처음 나오는 단어만 저장해야함
        int i = 0;
        for (; i < tokens.size(); i++)
        {
            if (str == tokens[i])
                break;
        }
        if (i == tokens.size())
            tokens.push_back(str);
        
    }
    return tokens;
}


void addWord(string word, int lineNum) {
    int index = findWord(word);
    if (index > -1) //기존단어라면 해당위치에 라인번호만 넣어준다.
        lineNums[index].push_back(lineNum);
    else { //새로운 단어라면 삽입정렬 수행
        
        auto it = words.begin();
        while (it != words.end() && *it < word)
            it++;
        int wordIndex;
        if (it == words.end()) { // words의 끝에 도달했다면 = word가 사전적으로 가장 뒤에 있는 단어
            words.push_back(word);
            wordIndex = words.size() - 1; // 삽입된 단어의 인덱스
        }
        else { // 삽입되어야할 위치라면
            wordIndex = distance(words.begin(), it); // it이 현재 위치한 인덱스를 찾음
            words.insert(it, word);
        }
        vector<int> tmp = { lineNum };
        lineNums.insert(lineNums.begin() + wordIndex, tmp); // 새로운 단어의 인덱스에 맞게 lineNums에 새로운 라인 번호 추가 추가
        //lineNums.push_back(tmp);
    }
}


int findWord(string keyword) {
    for (int i = 0; i < words.size(); i++)
        if (words[i] == keyword)
            return i;
    return -1;
}
