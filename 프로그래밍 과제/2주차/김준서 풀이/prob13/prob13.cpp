//잘 돌아감
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareInfo(string a, string b)
{
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}
int main()
{
	vector <string> v;
	int n;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), compareInfo);
	for (string c : v)
		cout << c << endl;
	return 0;
}

