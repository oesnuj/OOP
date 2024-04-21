//잘 만듦
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector <int> v;
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	cout << v.size()<<": ";
	for (int k : v)
		cout << k << " ";
	return 0;
}

