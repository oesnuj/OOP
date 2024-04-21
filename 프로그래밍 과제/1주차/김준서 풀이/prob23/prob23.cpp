#include <iostream>
using namespace std;

int main()
{
    int n, arr[100];
    int size = 0;

    while (1)
    {
        cin >> n;
        if (n == -1)
            return 0;

        int insertIndex = size;
        for(int i = size - 1; i >= 0 && arr[i] > n ; i--) //삽입 위치 찾기
            insertIndex--;

        if (insertIndex != 0 && arr[insertIndex - 1] == n) //삽입 위치 앞에 같은 정수가 있다면 duplicate
            cout << "duplicate";
        
        else //삽입 위치가 정확하다면
        {
            for (int i = size; i > insertIndex; i--) //삽입 위치 전까지 한칸씩 뒤로 밀기
            {
                arr[i] = arr[i - 1];
            }
            arr[insertIndex] = n; //삽입위치에 입력값 넣기
            size++;
            for (int i = 0; i < size; i++) //결과 배열 출력
                cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}