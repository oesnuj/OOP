#include <iostream>
using namespace std;

int main()
{
	int n, min;
	cin >> n;
	int numArr[100];
	int size = 0;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (num >= 0)
		{
			numArr[size++] = num;
			if(size == 1)
				min = numArr[0];
			if (num < min)
				min = num;
		}
			
	}
	
	if (size == 0) //비어있는 배열
		cout << -1;
	else
		cout << min;

	return 0;
}
