#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;
    int minNum = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (abs(k - arr[i]) < abs(k - minNum))
            minNum = arr[i];
    }
    cout << minNum;
    return 0;
}