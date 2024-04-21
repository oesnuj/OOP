#include <iostream>
#include <cmath>
using namespace std;

double avr(int* arr, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum / n;
}

double var(int* arr, int n, double avr)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += (arr[i] - avr) * (arr[i] - avr);
    return sum / n;
}

int main()
{
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    double average = avr(arr, n);
    cout << average << " " << sqrt(var(arr, n, average));
    return 0;
}