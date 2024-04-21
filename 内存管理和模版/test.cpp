#include<iostream>
using namespace std;

//mallocÿ�ζ�Ҫ����һ�»᲻��ɹ�


//new�ĵײ���operator new+���캯��
//delete�ĵײ���operator delete+��������

//����һ��������operator new[];
//�ײ㻹��new[] -> operator new[] -> operator new -> malloc()


//new��new[]����delete��delete[]����ƥ��ʹ��
//���ۣ���Ҫȥ����ʹ�ã�һ��Ҫƥ��ʹ�ã��������ǲ�ȷ����
class A
{
public:
	A(int a=0)
		:_a(a)
	{
		cout << "A" << endl;
	}
	~A()
	{
		cout << "~A" << endl;
		_a = 0;
	}
private:
	int _a;
};

//int main()
//{
//	int* p1 = new int[10];
//	delete[] p1;
//	A* p2 = new A[10];//�����࿪�ĸ��ֽڣ���Ϊ�����ĸ��ֽڴ�Ŷ���ĸ���
//	//free(p2);
//	//�����࿪�ĸ��ֽڣ�����free��ʱ���ֻfree������ʮ��������û��free�棬����ֻ�ܵ���delete
//	delete[] p2;
//	//delete p2,Ҳ�ᱨ����Ϊdeleteƥ�����new����new����࿪�ֽڣ���Ӧ���ǵ�����������ֻ�����һ������
//	//�����õ�Ҳ��һ������
//	return 0;
//}


//������new��delete��ģ��
//int main()
//{
//	//�ȼ���new
//	//����д�ǲ���࿪�ĸ��ֽڣ���Ϊ�����������ֶ�д�ģ��������ǿ���ֱ�ӿ���
//	A* p1 = (A*)operator new(sizeof(A)*10);//������ʾ�ĵ���operator new��malloc���÷�
//	//һ����Ҳ������ʾ�ĵ�����������
//	
//	//�ṩһ���µķ�ʽ�Ƕ�λnewҲ��placement-new
//	//new+��ַ+���캯��
//	for(int i=0;i<10;i++)
//	new(p1+i)A;//��λnew�����ù��캯��
//
//	//�ȼ���delete
//	for(int i=0;i<10;i++)
//	(p1+i)->~A();//������������
//	operator delete[](p1);
//	return 0;
//}


void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}
void Swap(double& left, double& right)
{
	double temp = left;
	left = right;
	right = temp;
}
void Swap(char& left, char& right)
{
	char temp = left;
	left = right;
	right = temp;
}
//�кܶ�swap������Ҫд��




//ģ�棺


//��ģ��д�ı���Ϊ���ͱ��
template<typename T1>
void Swap(T1& left, T1& right)
{
	T1 temp = left;
	left = right;
	right = temp;
}
int main()
{
	//�����������õĲ���һ�������������ܲ���һ������
	//temp������һ�����ͣ��������ڲ��Ĳ�����һ������������ջ֡Ҳ��һ��
	int left = 0;
	int right = 1;
	Swap(left, right);
	cout << "left=" << left << " right=" << right << endl;

	double left1 = 0.1;
	double right1 = 0.2;
	Swap(left1, right1);
	cout << "left1=" << left1 << " right1=" << right1 << endl;
	return 0;
}