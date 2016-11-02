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
因为每个人都取不到4个，假设自己后走，要保证每轮自己和对方取得数量的和是4，
这样就能确保每轮完后都有4的倍数个石头被取走。这样，如果我们先走的话，
先把n除4的余数个石头拿走，这样不管怎样，到最后都会留4个下来，对方取1个你就取3个，
对方取2个你就取2个，就必赢了。
*/