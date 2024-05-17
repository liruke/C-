#include"vector.h"


namespace lyrics
{
	void testvector1()
	{
		vector<int> v1(10, 1);
		vector<int> v2(v1.begin(), v1.end());
		vector<int> v3;
		v3 = v1;
		cout << v3[0] << endl;
		cout << v2[0] << endl;
		cout << v1[0] << endl;
		cout << v1.front() << endl;
		v3.push_back(3);
		cout << v3.back() << endl;
		vector<int>::iterator pos = std::find(v1.begin(), v1.end(), 1);
		pos = v1.insert(pos, 3);
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		pos = v1.erase(pos);
		cout << endl;
		for (auto e : v1)
		{
			cout << e << ' ';
		}
	}
}

int main()
{
	lyrics::testvector1();
}