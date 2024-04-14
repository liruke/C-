#include<stdio.h>
#include<math.h>

//int main()
//{
//	int money = 0;
//	int empty = 0;
//	int total = 0;
//	scanf("%d", &money);
//	empty = money;
//	total = money;
//	while (empty >= 2)
//	{
//		total += empty/2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d", total);
//	return 0;
//}
int main()
{
	int i = 0,right;
	char arr1[13] = "*************";
	int left = 0;
	right = strlen(arr1) - 1;
	//printf("\n"); //13
	while(left < right)
	{
		printf("%s", arr1);
		printf("\n");
		arr1[left] = '#';
		arr1[right] = '#';
		left++;
		right--;
		
	}
	return 0;
//}
//int main()
//{
//	int i = 0;
//	int arr1[] = "*************"
//	{
//
//	}
//	return 0;
}
//int main()
//{
//	int i = 0;
//	for (i = 1;i <= 100000;i++)
//	{
//		int a1,a2, a3, a4,a5,b = 0;
//		a1 = i / 10000;
//		a2 = i / 1000%10;
//		a3 = i / 100%10;
//		a4 = i / 10%10;
//		a5 = i % 10;
//		if (i==b)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}