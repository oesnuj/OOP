#include <iostream>
using namespace std;

int main()
{
    int n, arr[100];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int maxCount = 0, count = 1;
    //처음에는 배열안에서의 인덱스 시작으로 이중 for를 사용했지만
    // 한번의 탐색으로 풀이 할 수 있다는 것을 앎. O(n)으로 수정
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] <= arr[i + 1])
            count++;
        else
            count = 1;

        if (count > maxCount)
            maxCount = count;
    }
    cout << maxCount;
    return 0;
}