#include <iostream>
using namespace std;

int recursion(int n)
{
	if (n == 0 || n == 1)
		return 1;

	return recursion(n - 1) + recursion(n - 2);
}

int main()
{
	int n;
	cin >> n;
	// 풀이 1. recursion 사용 
	//cout << recursion(n) << endl;
	
	// 풀이 2. 반복문 사용
	int a = 0;
	int b = 1;
	int result = 1;
	while (n--)
	{
		result = a + b;
		a = b;
		b = result;
	}
	cout << result;
	return 0;
}