#include <iostream>
using namespace std;

struct interval
{
    int start;
    int end;
};

void swap(interval& a, interval& b)
{
    interval temp = a;
    a = b;
    b = temp;
}

void Sort(interval* arr, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j].start > arr[j + 1].start)
                swap(arr[j], arr[j + 1]);

            else if(arr[j].start == arr[j + 1].start)
                if (arr[j].end > arr[j + 1].end)
                    swap(arr[j], arr[j + 1]);
        }
    }
}

int main()
{
    int n;
    interval arr[100];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].start >> arr[i].end;

    Sort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i].start << " " << arr[i].end << endl;
    return 0;
}

