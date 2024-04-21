//해결완
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	ifstream inFile;
	inFile.open("sample.txt");
	if (inFile.is_open() == false) {
		cout << "Unable to openthe file" << endl;
		return -1;
	}
	string str;
	string lines[500];
	int lineNum = 0;
	while (inFile >> str)
	{
		int s = 0, t = str.length() - 1;  //문자열 추출
		while (s < str.length() && !isalnum(str[s]))
			s++;
		while (t >= 0 && !isalnum(str[t]))
			t--;
		//소문자로 바꾸기
		if (s <= t)
		{
			string pure_word = str.substr(s, t - s + 1);

			for (int i = 0; i < pure_word.length(); i++) {
				pure_word[i] = tolower(pure_word[i]);
			}

			bool duplicate = false;
			for (int j = 0; j < lineNum; j++)
			{
				if (lines[j] == pure_word)
				{
					duplicate = true;
					break;
				}
			}
			if (!duplicate) { // 중복이 아닌 경우에만 추가
				lines[lineNum++] = pure_word;
			}
		}
	}
	inFile.close();
	//정렬
	sort(lines, lines + lineNum);
	for (int i = 0; i < lineNum; i++)
	{
		cout << lines[i] << '\n';
	}
	return 0;
}

