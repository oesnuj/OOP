//202111602 김준서
//잘 작동합니다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;


struct pos 
{
	int x;
	int y;
	bool operator==(const pos& other) const {
		return x == other.x && y == other.y;
	}
};

bool check(vector<pos>& v, pos& a);
int main() {
	vector <pos> moveHistory; //지금까지 이동한 궤적을 기록하는 벡터
	const int dir[4][2] = { {0, 1}, //y좌표 증가
							{1, 0}, //x 좌표 증가
							{0, -1}, //y좌표 감소
							{-1, 0} }; //x좌표 감소
	pos current = {0, 0};

	while (true)
	{
		int way, distance;
		cin >> way;
		cin >> distance;
		if (way == -1 && distance == -1) //종료조건 way로 -1 입력시
			return 0;
		

		pos move = current; //move는 current로 초기화
		vector <pos> s;
		int i = 0;
		for(; i< distance; i++) //방향을 수행했을때 이게 벡터에 남아있는 좌표인지 확인 후, 없다면 넣고, 있다면 이동불가능
		{
			move.x += dir[way][0];
			move.y += dir[way][1];

			if (check(moveHistory, move))
				s.push_back(move);

			else
			{
				cout << "invalid move\n";
				break;
			}
		}
		if (i == distance) //입력받은 이동이 모두 잘 되었다면
		{
			for (pos point : s) {
				moveHistory.push_back(point);//s벡터의 내용을 move history에 추가한다.
				current = moveHistory.back(); //현재 위치를 이동의 마지막 지점으로 수정
			}
			cout << current.x << " " << current.y << "\n";
		}
			
	}
	return 0;
}


bool check(vector<pos> &v, pos &a)
{
	auto it = find(v.begin(), v.end(), a);
	if (it == v.end()) //안갔던 궤적이라면 true
		return true;
	else //갔던 궤적이라면 false
		return false;
}