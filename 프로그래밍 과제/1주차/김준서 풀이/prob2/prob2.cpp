#include <iostream>
using namespace std;

int main() 
//+ - �ݺ� ���� sign *= -1 ���
{
	int n;
	cin >> n;
	double sum = 0;
	for (int i = 1; i <= n; i++)
	{
		double x = 1.0; //�ʱⰪ�� 1�� ����
		for (int j = 0; j < i; j++)// i��ŭ 2�� ���� ����
			x *= 0.5;

		if (i % 2 != 0 || i == 1) //Ȧ����� ������
			x *= -1;
		sum += x;
	}
	cout << 1 + sum;
	return 0;
}