#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int checkDigit[10] = {0};
    int digit = n;
    while (digit > 0)
    {
        checkDigit[digit % 10]++;
        digit /= 10;
    }
    for (int i = 0; i < 9; i++)
        cout << checkDigit[i] << ", ";

    cout << checkDigit[9];
    return 0;
}