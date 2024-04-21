#include <iostream>
using namespace std;

int main()
{
    int arr[100];
    int n = 0;
    while(1)
    {
        cin >> arr[n];
        if (arr[n] == -1)
            break;
        n++;
    }
    int buy = arr[0], sell = arr[0], total = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > sell) //판매값보다 크다면 판매가격 갱신
            sell = arr[i];
        else //구매가격이 더 싼경우
        {
            total += sell - buy;
            buy = arr[i]; 
            sell = arr[i];
        }
    }
    total += sell - buy;
    cout << total;
    return 0;
}

//for (int i = 1; i < n; i++)
//{
//    if (data[i] >= data[i - 1]) {
//        gain += (data[i] - data[i - 1]);
//    }
//    else {
//        total_gain += gain;
//        gain = 0;
//    }
//}
