#include <iostream>
#include <cmath> // for ceil and floor functions
using namespace std;
int main()
{
    int count = 0;
    /*for (int x = 0; x <= 100; x++)
    {
        for (int y = ceil(x / 3.0); y <= floor(2 * x / 3.0); y++)
        {
            if (x * x + y * y <= 10000)
            {
                cout << x << " " << y << endl;
                count++;
            }
        }
    }*/
    for (int x = 0; x <= 100; x++)
    {
        for (int y = 0; y <= 100; y++)
        {
            if (y <= 2 * x / 3.0 && y >= x / 3.0 && x * x + y * y <= 10000)
            {
                //cout << x << " " << y << endl;
                count++;
            }
        }
    }
    cout << count;
    return 0;
}
