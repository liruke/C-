#include<iostream>
#include<string>
using namespace std;


//int main()
//{
//	string a = "hello world";
//	string b = a;//拷贝构造
//	if (a.c_str() == b.c_str())//c_str找到底层的指针
//	{
//		cout << "true" << endl;//true
//	}
//	else cout << "false" << endl;
//	string c = b;
//	c = "";//强制类型转换，生成一个临时对象赋值拷贝给c
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;//false
//	a = "";
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;//false
//	return 0;
//}
//int main()
//{
//	string str("Hello Bit.");
//	str.reserve(111);//对capacity修改
//	str.resize(5);//对size进行修改，但是修改的值小于capacity，所以size不变
//	str.reserve(50);
//	cout << str.size() << ":" << str.capacity() << endl;
//	return 0;
//}
//int main()
//{
//	string strText = "How are you?";
//	string strSeparator = " ";
//	string strResult;
//	int size_pos = 0;
//	int size_prev_pos = 0;//前面的位置
//	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
//	{
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//		cout << strResult << " ";
//		//1.How
//		//2.are
//		//you?
//		size_prev_pos = ++size_pos;
//	}
//	if (size_prev_pos != strText.size())//如果最后的这个位置不等于size(),因为最后的位置是\0，所以size和prev_pos相等
//	{
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);//不相等继续打印
//		cout << strResult << " ";
//	}
//	cout << endl;
//	return 0;
//}
#include<cmath>
//bool CheckNo(char str)
//{
//    return (str >= '0' && str <= '9') || str == '-' || str == '+' || str == ' ';
//}
//bool CheckSpace(char str)
//{
//    return str == ' ';
//}
//int myAtoi(string str)
//{
//    int i = 0;
//    while (CheckSpace(str[i]))
//    {
//        i++;
//    }
//    if (!CheckNo(str[i]))
//    {
//        return 0;
//    }
//    while (CheckSpace(str[i]))
//    {
//        i++;
//    }
//    int flag = 1;
//    if ((str[i] == '-' || str[i] == '+') && (str[i + 1] != '-' || str[i + 1] != '+'))
//    {
//        if (str[i] == '-')
//        {
//            flag = -1;
//        }
//        i++;
//    }
//    int sum = 0, count = 10;
//    while (str[i] >= '0' && str[i] <= '9')
//    {
//        sum = (str[i] - '0') + sum * count;
//        i++;
//    }
//    if (sum <= -pow(2, 31))
//    {
//        return -pow(2, 31);
//    }
//    else if (sum >= pow(2, 31) - 1)
//    {
//        return pow(2, 31) - 1;
//    }
//    return sum;
////
////}
//int main()
//{
//    string s1 = "-91283472332";
//    int i = myAtoi(s1);
//    cout << i << endl;
//}
//int firstUniqChar(string s) {
//    int l = 0;
//    int count[26] = { 0 };
//    //统计计数
//    for (auto ch : s)
//    {
//        count[ch - 'a']++;
//    }
//    for (int i = 0;i < s.size();i++)
//    {
//        //s[i]--'a'对应的是字符的所在的位置，从开始开始遍历
//        if (count[s[i] - 'a'] == 1)
//        {
//            return i;
//        }
//    }
//    return -1;
//}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string multiplyStrings(string num1, string num2) 
{
    int len1 = num1.size();//num1的长度
    int len2 = num2.size();//num2的长度
    vector<int> result(len1 + len2, 0);//创建一个长度是两个相加的vector,并初始化为0
    //倒着遍历，从string的末尾开始遍历
    for (int i = len1 - 1; i >= 0; i--)
    {
        for (int j = len2 - 1; j >= 0; j--)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');//先从最末尾的开始乘
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + result[p2];
            result[p2] = sum % 10;
            result[p1] += sum / 10;
        }
    }
    // Convert result vector to string
    string resultStr = "";
    for (int digit : result)
    {
        if (!(resultStr.empty() && digit == 0))
        { // Skip leading zeros
            resultStr += to_string(digit);
        }
    }
    return resultStr.empty() ? "0" : resultStr;
}

int main() {
    string num1 = "123456789";
    string num2 = "987654321";
    cout << "Result: " << multiplyStrings(num1, num2) << endl;
    return 0;
}

