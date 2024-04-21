#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("table.txt");
    if (fin.fail())
    {
        cout << "Unable to open the file";
        return 1;
    }

    int m, n; fin >> m >> n;
    fin.ignore(); // 줄바꿈 문자를 무시합니다.

    vector<vector<string>> table(m, vector<string>(n));
    string line;

    // 입력 처리
    for (int i = 0; i < m; i++)
    {
        getline(fin, line);
        stringstream ss(line);
        string buffer;

        for (int j = 0; j < n; j++)
        {
            getline(ss, buffer, '&');
            // 앞뒤 공백 제거
            buffer.erase(buffer.find_last_not_of(" \n\r\t") + 1);
            buffer.erase(0, buffer.find_first_not_of(" \n\r\t"));
            table[i][j] = buffer;
        }
    }

    fin.close();

    // 각 열의 최대 길이 계산
    vector<int> strlens(n, 0);
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            strlens[j] = max(strlens[j], (int)table[i][j].length());
        }
    }

    ofstream fout("output.txt");
    for (const auto& r : table)
    {
        for (int j = 0; j < n; j++)
        {
            fout << r[j];
            // 마지막 열을 제외하고 공백 추가
            if (j < n - 1) fout << string(strlens[j] - r[j].length() + 1, ' ');
        }
        fout << "\n"; // 각 행의 마지막에 줄바꿈
    }
    fout.close();

    return 0;
}
