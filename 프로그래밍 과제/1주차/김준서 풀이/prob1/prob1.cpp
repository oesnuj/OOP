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
	// Ǯ�� 1. recursion ��� 
	//cout << recursion(n) << endl;
	
	// Ǯ�� 2. �ݺ��� ���
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