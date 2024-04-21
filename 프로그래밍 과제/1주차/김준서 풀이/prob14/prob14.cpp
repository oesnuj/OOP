#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;   
}

int main()
{ 
    int count = 0;
    for (int i = 2; i <= 100; i++) {
        for (int j = i + 1; j <= 100; j++) {
            for (int k = j + 1; k <= 100; k++) {
                if (gcd(i, j) == 1 && gcd(j, k) == 1 && gcd(i, k) == 1)
                    count++;
            }
        }
    }
    cout << count;
    return 0;
}
