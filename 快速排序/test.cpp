#include<iostream>
using namespace std;

//���������ռ䣬һ��a[],һ��b[]
//a[i~r}

//��һ���������Ƚϱ��������ǿ������ռ䣬Ȼ�󽫴���x���ڵڶ������飬��С�ڵ���x���ڵ�һ�����飬�������һ������͵ڶ�������ֱ�˳���
//�Ŀ�����ԭ������







//�ڶ��ַ�����������ָ�룬һ��ָ��ָ��ͷһ��ָ��ָ��β���ֱ����м���

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int begin = left;
	int end = right;
	int key = left;
	while (left < right)
	{
		while (a[right] >= a[key] && left < right)///ע��left<right
		{
			right--;
		}
		while (a[left] <= a[key] && left < right)
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[key]);
	key = right;
	QuickSort(a, begin, key - 1);
	QuickSort(a, key + 1, end);
}

//ʱ�临�Ӷ���ON
void QuickSelect(int* a, int k)
{
	int left = 0;

}

int main()
{
	int arr[10] = { 37, 88, 12, 63, 25, 50, 91, 18, 74, 42 };
	QuickSort(arr, 0, 9);
	for (int i = 0;i < 10;i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}