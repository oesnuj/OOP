#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int dr[4] = { -1, 1, 0, 0 };
const int dc[4] = { 0, 0, -1, 1 };
int n;
int board[100][100];


int getRandomDirection(int r, int c) {
    int list[4];
    int len = 0;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (board[nr][nc]) //막힌 곳이라면 패스
            continue;
        list[len++] = i; //안 막힌 곳이면 갈 수 있는 방향기록 및 가능 경로수 + 1
    }

    if (!len) return -1; //길이 하나도 없다면 -1 return

    int randIdx = rand() % len; // 갈수 있는 방향 중에서 랜덤 방향 선택
    int dir = list[randIdx];
    return dir;
}


int simulation(int r,int c) //재귀 함수
{ 
    if (r == 0 || r == n - 1 || c == 0 || c == n - 1) //탈출구에 도착한다면 return
        return 1;

    board[r][c] = 1; //지나간 지점은 1로 만든다.

    int dir = getRandomDirection(r, c);
    if (dir == -1) //탈출 실패! return 0
        return 0;

    int nr = r + dr[dir]; //다음 방향 만들기
    int nc = c + dc[dir]; //다음 방향 만들기

    if (simulation(r + dr[dir], c + dc[dir]))
        return 1;

    return 0;
}

int startEscape() //보드판 초기화
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    return simulation(n / 2, n / 2); //재귀적 탐색 시작
}


int main()
{
    cin >> n;

    int successCount = 0;
    int T = 10000;
    while (T--){
        successCount += startEscape();
    }
    double prob = 1.0 * successCount / 10000;
    cout << prob;
    return 0;
}