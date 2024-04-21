#include <iostream>
using namespace std;

int main()
{
    int n, data[100];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> data[i];

    for (int i = n; 0 < i; i--)
    {
        int max_index = 0;
        for (int j = 1; j < i; j++) //0부터 i까지 최댓값구하기
        {
            if (data[j] > data[max_index])
                max_index = j;
        }
        swap(data[i-1], data[max_index]); //최댓값과 마지막 인덱스 교환
    }

    for (int i = 0; i < n; i++)
        cout << data[i] << " ";
    return 0;
}