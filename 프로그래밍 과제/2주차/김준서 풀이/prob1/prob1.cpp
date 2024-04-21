//잘 돌아감
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 두 정수를 사전식 순서로 비교하는 함수
bool compareLexicographically(int x, int y) {
    std::vector<int> xDigits, yDigits;

    // 각 숫자를 자릿수 별로 분리하여 벡터에 저장
    while (x > 0) {
        xDigits.insert(xDigits.begin(), x % 10);
        x /= 10;
    }
    while (y > 0) {
        yDigits.insert(yDigits.begin(), y % 10);
        y /= 10;
    }

    // 더 짧은 숫자의 자릿수까지 비교
    int minLength = std::min(xDigits.size(), yDigits.size());
    for (int i = 0; i < minLength; i++) {
        if (xDigits[i] < yDigits[i]) return true;
        else if (xDigits[i] > yDigits[i]) return false;
    }

    // 자릿수가 더 긴 숫자가 사전식으로 뒤에 온다
    return xDigits.size() < yDigits.size();
}

int main() {
    int n;

    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
       cin >> numbers[i];
    }

    // compareLexicographically 함수를 사용하여 정렬
    sort(numbers.begin(), numbers.end(), compareLexicographically);

    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
