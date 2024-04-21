#include <iostream>
using namespace std;
int main()
{
    int count = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int num = i;
        while (num)
        {
            if (num % 10 == 0)
                count++;
            num /= 10;
        }
    }
    cout << count;
    return 0;
}
