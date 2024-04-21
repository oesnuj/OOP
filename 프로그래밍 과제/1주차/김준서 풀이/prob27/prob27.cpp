#include <iostream>
using namespace std;

int main()
{
    int n, arr[100];
    int count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                count++;
        }
    }
    cout << count;
    return 0;
}