#include <iostream>
using namespace std;

int main()
{
    int n, k, arr[100];
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int temp = arr[n - 1];
        for (int j = n - 1; 0 < j; j--)
            arr[j] = arr[j - 1]; 

        arr[0] = temp;
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}