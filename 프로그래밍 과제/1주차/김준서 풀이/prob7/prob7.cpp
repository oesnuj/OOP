#include <iostream>
using namespace std;

int main()
{
	int year1, month1, day1, year2, month2, day2;
	cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2;
	if (year1 > year2)
		cout << -1;
	else if (year1 < year2)
		cout << 1;
	else
	{
		if (month1 > month2)
			cout << -1;
		else if (month1 < month2)
			cout << 1;
		else
		{
			if (day1 > day2)
				cout << -1;
			else if (day1 < day2)
				cout << 1;
			else
				cout << 0;
		}
	}
	return 0;
}
