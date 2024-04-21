#include <iostream>
using namespace std;


void Sort(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Sort(arr, n);

    int size = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
            arr[size++] = arr[i];
    }
    cout << size << ": ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}