//202111602 김준서
//잘 작동합니다.
//출력하는데 시간이 좀 걸립니다.
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void makeDictionary(string file);
int makePuzzle(string file);
void findWordsInDirection(int i, int j, int size, int w);
bool isWordInDictionary(string word);

const int WAYS = 8;
const int WAY[8][2] = { { -1, 0 },
                        { 1, 0 },
                        { 0, -1 },
                        { 0, 1 },
                        { -1, 1 },
                        { -1, -1 },
                        { 1, -1 },
                        { 1, 1 } };


vector <string> dictonary;
vector <vector<char>> puzzle;
vector <string> result;
vector <string> possibleWords;

int main()
{
    makeDictionary("dictionary.txt");
    int puzzleSize = makePuzzle("puzzle.txt");

    for (int i = 0; i < puzzleSize; i++) {
        for (int j = 0; j < puzzleSize; j++) {
            for (int w = 0; w < WAYS; w++) {  //모든 방향에 대해서 탐색 실시
                findWordsInDirection(i, j, puzzleSize, w);
            }
        }
    }

    for (const auto& r : result)
    {
        cout << r << "\n";
    }
    return 0;
}


void makeDictionary(string file)
{
    ifstream d(file);
    string str;
    while (d >> str) {
        dictonary.push_back(str);
    }
    d.close();
    return;
}

int makePuzzle(string file)
{
    ifstream p(file);
    int size;
    p >> size;

    puzzle.resize(size, vector<char>(size));
    char c;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            p >> c;
            puzzle[i][j] = c;
        }
    }
    p.close();
    return size;
}

void findWordsInDirection(int i, int j, int size, int w) //특정 방향에 있는 단어 집합 확인
{
    int nx = i;
    int ny = j;
    string word;
    while (nx >= 0 && nx < size && ny >= 0 && ny < size) //puzzle을 넘어가지 않는 선에서 가능 한 단어 찾기
    {
        word += puzzle[nx][ny];
        if (isWordInDictionary(word))
        {
            auto it = find(result.begin(), result.end(), word);
            if (it == result.end()) // 이미 만든 단어가 아니라면 결과에 넣음
                result.push_back(word);
        }
        nx += WAY[w][0];
        ny += WAY[w][1];
    }
    return;
}

bool isWordInDictionary(string word)
{
    // 벡터를 정렬합니다.
    sort(dictonary.begin(), dictonary.end());

    // 이분 탐색을 이용하여 단어가 사전에 있는 지를 찾습니다.
    int left = 0;
    int right = dictonary.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (dictonary[mid] == word) {
            return true; // 단어를 찾았습니다.
        }
        else if (dictonary[mid] < word) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return false; // 단어를 찾지 못했습니다.
}