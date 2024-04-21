#include <iostream>
using namespace std;
int main()
{
    int num[1000];
    int size = 0, count = 0;
    while (1)
    {
        cin >> num[size++];
        if (num[size - 1] == -1)
        {
            size --; //-1이라면 입력종료
            break;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (i == 0 && num[i] <= num[i + 1])  //첫번째 정수
            count++;
        else if (i == size - 1 && num[i - 1] >= num[i]) // 마지막 정수
            count++;
        else if (num[i - 1] >= num[i] && num[i] <= num[i + 1]) // 그 외의 정수
            count++;
    }
    cout << count;
    return 0;
}