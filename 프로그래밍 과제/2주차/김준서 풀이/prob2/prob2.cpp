//잘 돌아감
#include <iostream>
#include <string>

using namespace std;

int main()
{
    while (1)
    {
        string str, fixed_str;
        getline(cin, str);
        if (str == "exit")
            return 0;
        int size = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (i == 0 && str[i] == ' ') //공백으로 시작하는 경우
                continue;
            
            if (str[i] != ' ') //1. 공백이 아닌경우 
                fixed_str += str[i];

            else if (str[i] == ' ' && str[i - 1] != ' ')//2. 공백이지만 이전 문자가 공백이 아닌경우 공백 저장
                fixed_str += str[i];
            
        }
        if (fixed_str.back() == ' ') //공백으로 끝나면 제거
            fixed_str.pop_back();

        cout << fixed_str << ":" << fixed_str.length() << '\n';
    }
}