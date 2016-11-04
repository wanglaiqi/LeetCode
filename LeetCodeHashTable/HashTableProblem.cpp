#include<iostream>
#include<string>
using namespace std;

class HashTableSolution
{
public:
	HashTableSolution();
	~HashTableSolution();
	int cal(int x);
	int fun(int x, int y);

private:

};

HashTableSolution::HashTableSolution()
{
}

HashTableSolution::~HashTableSolution()
{
}

int HashTableSolution::cal(int x)
{
	if (x < 2)
	{
		return x;
	}
	return cal(x - 1) + cal(x - 2);
}

int HashTableSolution::fun(int x, int y)
{
	int z = x % y;
	if (z == 0)
	{
		return y;
	}
	else
	{
		return fun(y,z);
	}
}

int main()
{
	HashTableSolution solution;
	//int result = solution.cal(6);
	//cout << result << endl;
	int result = solution.fun(12,8);
	cout << result << endl;
	system("pause");
	return 0;
}