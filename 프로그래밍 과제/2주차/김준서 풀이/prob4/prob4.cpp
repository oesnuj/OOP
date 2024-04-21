#include <iostream>
#include <string>
using namespace std;

int main() {
    string terms;
    getline(cin, terms);
    int sum = 0, num = 0;
    char sign = '+';
    for (char& c : terms) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0'); // 숫자를 구성하는 문자를 실제 숫자로 변환
        }
        else if (c == '+' || c == '-') {
            if (sign == '+') {
                sum += num;
            }
            else {
                sum -= num;
            }
            sign = c; // 연산자 갱신
            num = 0; // 숫자 초기화
        }
    }
    // 마지막 숫자 처리
    if (sign == '+') {
        sum += num;
    }
    else {
        sum -= num;
    }

    cout << sum;
    return 0;
}
