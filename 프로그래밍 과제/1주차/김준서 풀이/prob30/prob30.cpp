#include <iostream>
#include <algorithm>
using namespace std;

struct interval 
{
    int start;
    int end;
};

int Lap(interval& a, interval& b) //겹치는 구간 판단
{
    return min(a.end, b.end) - max(a.start, b.start);
}

int main()
{
    int n;
    cin >> n;
    interval arr[100];//입력받을 배열
    interval a, b; //최대로 겹치는 구간들을 저장하기 위한

    for (int i = 0; i < n; i++)
        cin >> arr[i].start >> arr[i].end;

    int maxlap = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int lap = Lap(arr[i], arr[j]); //겹치는 구간 구하기
            if (lap > maxlap)
            {
                maxlap = lap;
                a = arr[i];
                b = arr[j];
            }
        }
    }
    cout << "[" << a.start << ", " << a.end << "]\n";
    cout << "[" << b.start << ", " << b.end << "]";

    return 0;
}