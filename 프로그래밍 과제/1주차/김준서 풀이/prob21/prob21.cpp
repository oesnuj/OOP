#include <iostream>
using namespace std;

bool checkLeader(int* arr, int arrSize, int target)
{
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > target)
            return false;
    }
    return true;
}

int main()
{
    int n, inputArr[100], leaderArr[100], size = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> inputArr[i];

        if (checkLeader(inputArr, i, inputArr[i]))
            leaderArr[size++] = inputArr[i];
    }
    cout << size << ": ";
    for (int i = 0; i < size; i++)
        cout << leaderArr[i] << " ";
    return 0;
}