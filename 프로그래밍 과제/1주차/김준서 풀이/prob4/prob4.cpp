#include <iostream>
using namespace std;

void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a > c)
		swap(a, c);
	if (b > c)
		swap(b, c);
	if (a > b)
		swap(a, b);
	cout << a << b << c << endl;
	return 0;
}
