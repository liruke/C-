#include"list.h"


namespace lyrics
{
	void test()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		l.push_back(5);
		for (auto e : l)
		{
			cout << e << ' ';
		}
		l.pop_front();
		l.pop_front();
		l.pop_front();
		cout << endl;
		for (auto e : l)
		{
			cout << e << ' ';
		}
	}
}

int main()
{
	lyrics::test();
	return 0;
}