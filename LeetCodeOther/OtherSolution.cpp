#include<iostream>
using namespace std;

class OtherSolution
{
public:
	OtherSolution();
	~OtherSolution();
	//no need the +-*% calcualte the sum of twonumber
	int AddOperate(int num1, int num2);

	int numberOfone(int num);

private:

};

OtherSolution::OtherSolution()
{
}

OtherSolution::~OtherSolution()
{
}

int OtherSolution::AddOperate(int num1, int num2)
{
	int sum, carray;
	do
	{
		sum = num1^num2;
		carray = (num1&num2) << 1;
		num1 = sum;
		num2 = carray;
	} while (num2!=0);
	return num1;
}

int OtherSolution::numberOfone(int num)
{
	int count=0;
	/*while (num)
	{
		count++;
		num = num&(num - 1);
	}*/

	while (num)
	{
		if (num & 1)
		{
			count++;
		}
		num = num >> 1;
	}
	return count;
}

int main()
{
	/*OtherSolution addSolution;
	int num1, num2;
	cout << "please input thr number" << endl;
	cin >> num1 >> num2;
	int addResult = addSolution.AddOperate(num1,num2);
	cout <<"the resukt is:"<< addResult << endl;*/

	OtherSolution oneNumberSolution;
	int number;
	cout << "please input thr number" << endl;
	cin >> number;
	int oneNumber = oneNumberSolution.numberOfone(number);
	cout << "the one number is:" << oneNumber << endl;
	system("pause");
	return 0;
}