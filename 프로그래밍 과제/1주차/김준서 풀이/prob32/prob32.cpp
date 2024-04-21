#include <iostream>
using namespace std;

int main()
{
    //0이 나오는 인덱스를 배열에 하나씩 저장하고
    //이를 1로 바꾸면서 탐색
    int n, arr[100], zeroArr[100];
    int size = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
            zeroArr[size++] = i; //값이 0인 인덱스는 따로 저장
    }

    int maxCount = 0;
    for (int i = 0; i < size; i++)
    {
        arr[zeroArr[i]] = 1;
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == 1)
                count++;
            else
                count = 0;
            if (count > maxCount)
                maxCount = count;
        }
        arr[zeroArr[i]] = 0;
    }
    if (size == 0) //전부 1인 경우 n출력
        cout << n;
    else
        cout << maxCount;
    return 0;
}