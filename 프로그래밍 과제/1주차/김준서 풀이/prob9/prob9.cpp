#include <iostream>
using namespace std;

void print(int coef, int expo_x, int expo_y) {
    // 계수 0인 경우
    if (coef == 0) 
        return;

    // 계수가 -1인 경우, 음수 부호만 출력 (단, x와 y의 차수가 0일 때는 -1 그대로 출력)
    if (coef == -1) {
        if (expo_x > 0 || expo_x > 0) 
            cout << "-";
        else 
            cout << "-1";
    }
    // 계수가 1인 경우 제외 (단, x와 y의 차수가 0일 때는 1 그대로 출력)
    else if (coef != 1 || (expo_x == 0 && expo_y == 0)) 
    {
        cout << coef;
    }

    // x의 차수가 1보다 크면 x^를, 1이면 x를 출력
    if (expo_x > 1) 
        cout << "x^" << expo_x;
    else if (expo_x == 1) 
        cout << "x";

    // y의 차수가 1보다 크면 y^차수를, 1이면 y를 출력
    if (expo_y > 1) 
        cout << "y^" << expo_y;
    else if (expo_y == 1) 
        cout << "y";
}

int main() {


    int coef, expo_x, expo_y;
    cin >> coef >> expo_x >> expo_y;

    print(coef, expo_x, expo_y);

    return 0;
}
