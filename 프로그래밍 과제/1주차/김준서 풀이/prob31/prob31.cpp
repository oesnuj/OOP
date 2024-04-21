#include <iostream>
using namespace std;

void Sort(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

bool checkStraight(int* arr, int n)
{
    int count = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] == arr[i] + 1)
            count++;

        else if ((arr[i + 1] == arr[i]))
            continue;

        else
            count = 1;

        if (count == 5)
            return 1;
    }
    return 0;
}

int main()
{
    const int n = 7;
    int arr[n];
    for (int i = 0; i < n; i++) //입력
        cin >> arr[i];

    Sort(arr, n); //정렬

    if (checkStraight(arr, n)) //스트레이트 확인
        cout << "YES";
    else
        cout << "NO";
    
    return 0;
}