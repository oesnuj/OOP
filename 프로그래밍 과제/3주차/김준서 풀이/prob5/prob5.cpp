//202111602 김준서
//잘 작동합니다.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

struct HorizontalLine {
    Point start, end;
};

struct VerticalLine {
    Point start, end;
};

bool intersect(const HorizontalLine& horizontal, const VerticalLine& vertical) { //교점구하기
    int x = vertical.start.x;
    int y = horizontal.start.y;
    return horizontal.start.x <= x && x <= horizontal.end.x &&
        vertical.start.y <= y && y <= vertical.end.y;
}

bool comparePoints(const Point& a, const Point& b) {
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

int main() {
    int N;
    cin >> N;

    vector<HorizontalLine> horizontal_lines;
    vector<VerticalLine> vertical_lines;

    for (int i = 0; i < N; ++i) {
        int start_x, start_y, end_x, end_y;
        cin >> start_x >> start_y >> end_x >> end_y;

        if (start_y == end_y) {  // 수평 선분
            if (start_x < end_x)
                horizontal_lines.push_back({ {start_x, start_y}, {end_x, end_y} });
            else
                horizontal_lines.push_back({ {end_x, end_y}, {start_x, start_y} });
        }
        else {  // 수직 선분
            if (start_y < end_y)
                vertical_lines.push_back({ {start_x, start_y}, {end_x, end_y} });
            else
                vertical_lines.push_back({ {end_x, end_y}, {start_x, start_y} });
        }
    }

    vector<Point> intersections;
    for (const auto& h : horizontal_lines) {
        for (const auto& v : vertical_lines) {
            if (intersect(h, v))
                intersections.push_back({ v.start.x, h.start.y });
        }
    }

    sort(intersections.begin(), intersections.end(), comparePoints);

    for (const auto& intersection : intersections) {
        cout << "[" << intersection.x << ", " << intersection.y << "]" << endl;
    }

    return 0;
}
