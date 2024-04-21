//잘 돌아감
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

struct MyStruct
{
	string word;
	int num;
};

void Sort(MyStruct * a, int k)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k - i - 1; j++)
		{
			if (a[j].num < a[j + 1].num)
				swap(a[j], a[j + 1]);
			else if (a[j].num == a[j + 1].num)
				if (a[j].word > a[j + 1].word)
					swap(a[j], a[j + 1]);
		}
	}

}

int main()
{
    ifstream inFile;
    inFile.open("input3.txt");
	if (inFile.is_open() == false) {
		cout << "Unable to openthe file" << endl;
		return -1;
	}
	
	string str;
	MyStruct pair[100];

	int k = 0;
	while (inFile >> str)
	{
		for (int j = 0; j < str.length(); j++){
			str[j] = tolower(str[j]);
		}
		int i = 0;
		for (i; i < k; i++)
		{
			if (pair[i].word == str)
				break;
		}
		if (i < k)
		{
			pair[i].num++;
		}
		else
		{
			pair[k].word = str;
			pair[k++].num = 1;
		}
	}

	Sort(pair, k);

	for (int i = 0; i < k; i++)
		cout << pair[i].word << ":" << pair[i].num << endl;


	inFile.close(); // 파일 닫기
	return 0;
}