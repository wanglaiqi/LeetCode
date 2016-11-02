#include<stdio.h>
#include<iostream>
using namespace std;

/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
For example:
Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
*/
class Solution
{
public:
	int addDigits(int num);
	Solution();
	~Solution();

private:

};

int Solution::addDigits(int num)
{
	while (num/10>0)
	{
		int sum = 0;
		while (num!=0)
		{
			sum += num % 10;
			num = num / 10;
		}
		num = sum;
	}
	return num;
}

Solution::Solution()
{
}

Solution::~Solution()
{
}

int main()
{
	Solution s;
	int number;
	int result = 0;
	cout << "please input an non-negative number:" << endl;
	cin >> number;
	result = s.addDigits(number);
	cout << "return the result is :" << result << endl;
	system("pause");
	return 0;
}
/*
˼·һ�����ϵĽ����ֽ��в�����ֱ��ֻʣ��һλ��Ϊֹ
˼·����������ʹ�ù۲�ķ��������ҹ���
*/