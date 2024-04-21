#include <iostream>
using namespace std;

int main() 
//+ - 반복 로직 sign *= -1 사용
{
	int n;
	cin >> n;
	double sum = 0;
	for (int i = 1; i <= n; i++)
	{
		double x = 1.0; //초기값을 1로 설정
		for (int j = 0; j < i; j++)// i만큼 2의 제곱 수행
			x *= 0.5;

		if (i % 2 != 0 || i == 1) //홀수라면 음수로
			x *= -1;
		sum += x;
	}
	cout << 1 + sum;
	return 0;
}