#include<iostream>
using namespace std;

int Size(int n)
{
	int size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return size;
}
int main()
{
	int N = 0;
	cin >> N;//范围
	int count = 0;
	for (int i = 1;i <= N;i++)//创造1~N的数字
	{
		//判断
		int size = Size(i);//判断每个数的位数
		bool sign = true;
		int tmp = i;
		int n = 1;
		while (n <= size)
		{
			int rmp = tmp % 10;
			if (n % 2 == 1)
			{
				if (rmp % 2 != 1)
				{
					sign = false;
				}
			}
			else if (n % 2 == 0)
			{
				if (rmp % 2 != 0)
				{
					sign = false;
				}
			}
			tmp /= 10;
			n++;
		}
		if (sign == true)
		{
			count++;
		}
	}
	cout << count;
	return 0;
}