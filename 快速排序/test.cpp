#include<iostream>
using namespace std;

//开辟两个空间，一个a[],一个b[]
//a[i~r}

//第一种做法，比较暴力，就是开两个空间，然后将大于x放在第二个数组，将小于等于x放在第一个数组，如果将第一个数组和第二个数组分别顺序的
//的拷贝到原数组中







//第二种方法，用两个指针，一个指针指向头一个指针指向尾，分别向中间走

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
		while (a[right] >= a[key] && left < right)///注意left<right
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

//时间复杂度是ON
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