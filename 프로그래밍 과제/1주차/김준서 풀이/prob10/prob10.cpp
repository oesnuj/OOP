#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int v = 1;
    while (v * 2 <= N)// N보다 작거나 같은 가장 큰 2의 거듭제곱수 v
        v *= 2;

    while (v > 0) 
    {
        if (N >= v)
        {
            N -= v;
            cout << 1;
        }
        else
            cout << 0;
        v /= 2;
        /* N ≥ v이면 N = N-v가되고 */
        /* 1을 출력한다. 그렇지 않으면 */
        /* 0을 출력한다. 두 경우 모두 */
        /* v는 1/2한다. */
    }
    return 0;
}