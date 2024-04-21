//예제 모두 통과

//입력받은 문자열중엗 가장 짧은 거 하나를 고르고
//그 짧은 문자열 길이 만큼 전체탐색
//그 짧은 문자열의 [0]을 나머지 문자열과 비교
//하나라도 다르면 nothing -> return
//모두 같다면 해당 문자 prefix에 저장하고 다음 인덱스로
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<string> words;
	string shortest_word;
	string prefix;
	// 입력된 단어들을 벡터에 저장합니다.
	for (int i = 0; i < n; ++i) {
		string word;
		cin >> word;
		words.push_back(word);
		if (i == 0 || word.length() < shortest_word.length()) {
			shortest_word = word;
		}
	}
	for (int i = 0; i < shortest_word.length(); i++)
	{
		char current_char = shortest_word.at(i);
		for (int j = 0; j < n; j++)
		{
			if (current_char != words.at(j).at(i))
			{
				if (prefix == "")
				{
					cout << "nothing";
					return 0;
				}
				else
				{
					cout << prefix;
					return 0;
				}

			}
		}
		prefix += current_char;
	}
	cout << prefix;
	return 0;
}

