//202111602 김준서
//잘 작동합니다.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void sorted_merge(vector<string>& first, vector<string>& second) {
	vector<string>::iterator fit = first.begin();
	vector<string>::iterator sit = second.begin();
	//first it가 더 작으면 패스
	//second it가 더 작으면 insert 한 vector라도 끝에 도달하면 나머지 넣기
	while(fit != first.end() && sit != second.end())
	{
		if (*fit < *sit)
			fit++; 

		else if (*fit >= *sit)
		{
			fit = first.insert(fit, *sit) + 1; //v.insert는 새로 추가한 원소의 iterator을 반환하기 때문에 +1을 하여 원래대로 돌린다.
			sit++;
		}
	}
	//second가 남은경우라면 first에 채우기
	for (; sit != second.end(); sit++){
		first.push_back(*sit);
	}
}
int main() {
	int m, n;
	string str;
	vector<string> first, second;
	cin >> m;
	// m개의 영문자열이 사전식 순서로 정렬되어 입력된다.
	for (int i = 0; i < m; i++) {
		cin >> str;
		first.push_back(str);
	}
	cin >> n;
	// n개의 영문자열이 사전식 순서로 정렬되어 입력된다.
	for (int i = 0; i < n; i++) {
		cin >> str;
		second.push_back(str);
	}
	sorted_merge(first, second);
	// m+n개의 문자열이 사전식 순서로 정렬되어 출력되어야 한다.
	for (auto item : first)
		cout << item << " ";
	cout << endl;
	return 0;
}