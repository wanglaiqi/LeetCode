#include<iostream>
#include<stdio.h>
using namespace std;

class Solution
{
public:
	bool canWinNim(int n) {
		return n % 4 != 0;
	}
	Solution();
	~Solution();

private:

};

Solution::Solution()
{
}

Solution::~Solution()
{
}

/*
��Ϊÿ���˶�ȡ����4���������Լ����ߣ�Ҫ��֤ÿ���Լ��ͶԷ�ȡ�������ĺ���4��
��������ȷ��ÿ�������4�ı�����ʯͷ��ȡ�ߡ�����������������ߵĻ���
�Ȱ�n��4��������ʯͷ���ߣ�������������������󶼻���4���������Է�ȡ1�����ȡ3����
�Է�ȡ2�����ȡ2�����ͱ�Ӯ�ˡ�
*/