//예제 모두 통과 완료
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ifstream inFile;
	inFile.open("harry.txt");
	if (inFile.is_open() == false) {
		cout << "Unable to open the file" << endl;
		return -1;
	}
	string str;
	vector <string> v;
	while (inFile >> str)
	{
		auto it = v.begin();
		while (it != v.end() && *it < str)
			it++;
		if (it == v.end())// words의 끝에 도달했다면 = str이 가장 사전식으로 먼 단어
			v.push_back(str);
		else if (*it == str)// 중복 단어라면
			continue;
		else //삽이되어야할 위치라면
			v.insert(it, str);
	}
	inFile.close();
	//--------------------중복제외하여 단어 정렬 완료-----------------------
	string prefix;
	cin >> prefix;
	int count = 0;
	vector<string>::iterator it = v.begin();
	while (it != v.end())
	{
		auto str = *it;
		if (str.find(prefix) == 0) //prefix가 포함되면 그냥 패스
			it++;
		else
			it = v.erase(it); //아니면 전부 제거
	}
	for (auto word : v)
	{
		cout << word << "\n";
	}
	cout << v.size();
	return 0;
}

