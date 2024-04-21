//잘 돌아감
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;


struct Line
{
	string text;
	int wordCount;
};
bool compareInfo(Line &a, Line &b)
{
	return a.wordCount > b.wordCount;
}

int main()
{
	ifstream inFile;
	inFile.open("sample_lines.txt");
	if (inFile.is_open() == false) {
		cout << "Unable to openthe file" << endl;
		return -1;
	}
	string str;
	Line lines[1000];
	int lineNum = 0;
	while (getline(inFile, str))
	{
		int count = 0;
		if (str.length() == 0)
			continue;

		for (int i = 0; i < str.length(); i++)
		{
			if (i == 0 && str[i] == ' ') //공백으로 시작하는 경우
				continue;

			if (str[i] != ' ') //1. 공백이 아닌경우 
				lines[lineNum].text += str[i];

			else if (str[i] == ' ' && str[i - 1] != ' ')//2. 공백이지만 이전 문자가 공백이 아닌경우 공백 저장
			{
				lines[lineNum].text += str[i];
				count++;
			}	

		}
		if (lines[lineNum].text.back() == ' ') //공백으로 끝나면 공백 제거
			lines[lineNum].text.pop_back();
		else //공백으로 끝나지 않으면 count가 안되었으니 count +1
			count++;

		lines[lineNum].wordCount = count; //lineNum++하면서 count도 저장
		lineNum++;
	}

	sort(lines, lines + lineNum, compareInfo);

	for (int i = 0; i < lineNum; i++)
	{
		cout << lines[i].text << ":" << lines[i].wordCount << endl;
	}
	return 0;
}

