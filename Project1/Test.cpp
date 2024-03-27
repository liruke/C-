//#include<stdio.h>
//#include<stdlib.h>
//int rand = 0;
//
////命名冲突
////我们和库，会产生冲突
////所以在C++中只能改名字，不能改库
//
//
//int main()
//{
//	printf("%d ", rand);
//	printf("hello world");
//}


namespace lyrics
{
	struct Node
	{
		struct Node* next;
		int val;
	};
	int b = 0;
	int Add(int a, int b)
	{
		return a + b;
	}
}

using lyrics::Add;
using lyrics::b;
using lyrics::Node;
int main()
{
	int i = Add(1, 8);
	b;
	struct Node nenwode;
}

//#include<stdio.h>
//#include<stdlib.h>
//
//namespace bit
//{
//	int rand = 0;
//}
//
//
//int main()
//{
//	printf("%d ", bit::rand);//默认不加命名空间会报警告，默认吊的是库函数指针
//	printf("hello world");
//}
//#include<stdio.h>
//namespace bit
//{
//	int rand = 0;
//}
//namespace bit1
//{
//	int rand = 1;
//}
//int rand = 2;
////::域作用限定符
////左边是空的话就是默认访问全局的
//int main()
//{
//	printf("%d ", ::rand);
//	printf("%d ", bit::rand);
//	printf("%d ", bit1::rand);
//	return 0;
//}

//命名空间本质是定义的域，定义的命名空间域
//要访问命名空间就要指定作用域

//编译器在走的时候有一个原则，每次它找的时候都要去找他的出处，找不到就会报错
//未声明的标识符


//如果没有指定的话，默认的查找顺序:先局部，后全局



//如果没找到是不会到命名空间中去找的，就会报错全局

//域有很多种，当前接触的只有命名空间域

//#include<stdio.h>
//namespace bit
//{
//	int rand = 0;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	struct Node
//	{
//		int val;
//	};
//}
//namespace Bit
//{
//	int rand = 0;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	struct Node
//	{
//		int val;
//	};
////}
//
//int main()
//{
//	printf("%d \n", Bit::Add(1, 0));
//	printf("%d \n", bit::Add(1, 2));
//	struct bit::Node newnode;
//	newnode.val = 0;
//}

//命名空间中可以定义变量、函数、结构体、还可以嵌套命名空间

//一个新的命名空间就相当于一个新的作用域


//使用命名空间

//#include<iostream>
//using namespace std;//在语法中的说法就是展开命名空间
//展开命名空间和展开头文件是两个东西，展开命名空间的意思是使用这个域，影响编译器的这个查找规则

//默认是在局部，然后就是查找，还有就是第三个就回到展开的命名空间中查找

//展开了之后产生的问题:


//如果没有的话，默认先到当前域去找，然后就去全局找，全局找了没有，就到声明了的命名空间中找
//没有指定先到全局去找，
//如果两个命名空间同时展开，但是两个命名空间都有相同的东西，这样会产生冲突的
namespace bit
{
	static int x = 0;
	static int y = 0;
}

//指定展开某一个

using bit::x;
//三种方式
//1.指定展开
//2.全展开
//3.指定某一个展开

#include<iostream>
//std是库的命名空间，是将库函数放在这个命名空间中
using std::cout;
using std::endl;
int main()
{
	//<<流插入
	int i = 0;
	std::cin >> i;
	double j = 1.11;
	//特点是自动识别类型
}

//printf和scanf会高效一点

//缺省参数
void Func(int a = 1)
{
	cout << a << endl;
}
//如果函数中传递了一个值，那这个函数输出该多少就是多少，但是如果这个函数不传值的话，就直接根据缺省参数进行初始化
//对于缺省参数来说不能跳跃的传

//缺省参数的用途

//缺省参数不能声明和定义同时给
//规定的是以声明为主