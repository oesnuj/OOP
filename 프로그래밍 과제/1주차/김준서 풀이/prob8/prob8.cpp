#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (b < c || d < a) //끝1 < 시작2 or 끝2 < 시작1
		cout << "NO";
	else
		cout << "YES";
	return 0;
}
