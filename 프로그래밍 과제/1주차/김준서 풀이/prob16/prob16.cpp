#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int experiment(int trials, int n, int m) {
    int success = 0; //성공 횟수
    for (int i = 0; i < trials; ++i) {
        int count = 0; // 1이 나온 횟수
        for (int j = 0; j < n; ++j) {
            if (rand() % 6 + 1 == 1) 
                count++; // 주사위를 던져 1이 나오면 카운트
        }
        if (count >= m) 
            success++; // m번 이상 1이 나왔다면 성공
    }
    return success;
}

int main() {
    const int trials = 1000000;
    srand(time(0));

    // 6번 던져서 적어도 한 번 1 경우의 수
    int successCase1 = experiment(trials, 6, 1);
    // 12번 던져서 적어도 두 번 1 경우의 수
    int successCase2 = experiment(trials, 12, 2);

    cout << "6번 던져서 적어도 한 번 1이 나올 확률: " << (double)successCase1 / trials << endl;
    cout << "12번 던져서 적어도 두 번 1이 나올 확률: " << (double)successCase2 / trials<< endl;

    return 0;
}
