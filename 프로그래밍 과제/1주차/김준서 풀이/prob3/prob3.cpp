#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	double result = 0;
	for (int i = n; 0 < i; i--)
	{
		int factorial = 1;
		for (int j = i; j > 0; j--)
			factorial *= j;

		result += 1.0 / factorial;
	}
	cout << result;
	return 0;
}
