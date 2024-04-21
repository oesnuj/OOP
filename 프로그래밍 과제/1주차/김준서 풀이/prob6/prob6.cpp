#include <iostream>
using namespace std;

int main()
{
	int n, minNum, maxNum;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (i == 0) //min, max 초기화
		{
			minNum = num;
			maxNum = num;
		}
		if (num < minNum)
			minNum = num;
		if (num > maxNum)
			maxNum = num;
		cout << maxNum - minNum << " ";
	}
	return 0;
}
