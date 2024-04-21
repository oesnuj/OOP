//202111602 김준서
//잘 작동합니다.
#include <iostream>
#include <vector>
using namespace std;
void compute_set(vector<int>& A, vector<int>& B) {
	auto ait = A.begin();
	auto bit = B.begin();
	//a == b가 같다면 ait erase하고 , bit +1씩
	//a > b 라면 bit 넣고 bit++
	//a < b 라면 ait++
	while (ait != A.end() && bit != B.end())
	{
		if (*ait == *bit)
		{
			ait = A.erase(ait); //erase 함수 반환시 삭제된 다음 iterator을 반환
			bit++; //같으면 넣지 않고 패스
		}
		else if (*ait > *bit) //ait이 더 크다면 b를 a에 넣어야함
		{
			ait = A.insert(ait, *bit) + 1;
			bit++;
		}
		else if (*ait < *bit) 
			ait++;
	}
	//second가 남은경우라면 first에 채우기
	for (; bit != B.end(); bit++) {
		A.push_back(*bit);
	}
}
int main() {
	int m, n, k;
	vector<int> first, second;
	cin >> m;
	// m개의 정수가 오름차순으로 정렬되어 입력된다.
	for (int i = 0; i < m; i++) {
		cin >> k;
		first.push_back(k);
	}
	cin >> n;
	// n개의 정수가 오름차순으로 정렬되어 입력된다.
	for (int i = 0; i < n; i++) {
		cin >> k;
		second.push_back(k);
	}
	compute_set(first, second);
	for (auto item : first)
		cout << item << " ";
	cout << endl;
	return 0;
}