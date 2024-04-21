//성공 ㅋ
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector <string> words;
    string str;
    int size = 0;
    while (true)
    {
        cin >> str;
        if (str == "exit")
            return 0;
        auto it = words.begin();
        while (it != words.end() && *it < str)
            it++;
        if (it == words.end())// words의 끝에 도달했다면 = str이 가장 사전식으로 먼 단어
            words.push_back(str);
        else if (*it == str)// 중복 단어라면
        {
            cout << "duplicate" << '\n';
            continue;
        }
        else //삽이되어야할 위치라면
            words.insert(it, str);
        for (auto s : words)
            cout << s << " ";
        cout << '\n';
    }
    return 0;
}