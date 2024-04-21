#include <iostream>
using namespace std;

int main()
{
    int n, k, arr[100];
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;

    int maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0, count = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            count++;
            if (sum <= k && count > maxCount)
                maxCount = count;

        }
    }
    cout << maxCount;
    return 0;
}