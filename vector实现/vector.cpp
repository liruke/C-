#include"vector.h"
#include<vector>

namespace lyrics
{
	void test_vector()
	{
		vector<int> v1;
		vector<int> v2(2, 10);
		vector<int> v3(v2);
		v1.assign(5, 1);
		cout << v1[0] << endl;
		cout << v2[0] << endl;

		vector<int> v5;
		v5 = v2;
		cout << v5[0] << endl;
	}
	void testvector1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;
		vector<int>::iterator pos = std::find(v1.begin(), v1.end(), 2);
		pos = v1.insert(pos, 3);
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;
		vector<int>::iterator pos1 = std::find(v1.begin(), v1.end(), 3);
		pos1 = v1.erase(pos);
		for (auto e : v1)
		{
			cout << e << ' ';
		}
	}
	void testvector2()
	{
		vector<int> v1(2, 2);
	}
}
int main()
{
	lyrics::testvector2();
	return 0;
}