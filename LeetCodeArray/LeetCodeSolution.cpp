#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class ArraySolution
{
public:
	ArraySolution();
	~ArraySolution();
	//01: remove the element
	int removeElement(vector<int>& nums, int val);
	//02: rotate the array
	void rotate(vector<int>& nums, int k);
	//03: the third max number
	int thirdMax(vector<int>& nums);
	//04: missing number
	int missingNumber(vector<int>& nums);
	//05: min path sum
	int minPathSum(vector<vector<int>>& grid);
	//06: find the peak element
	int findPeakElement(vector<int>& nums);
	//07: find the duplicate element
	int findDuplicate(vector<int>& nums);
	//08: the number of binary bits
	int NumberOf1(int n);
	//09:
	int f(int n, int m);
	int g(int n);
private:

};

ArraySolution::ArraySolution()
{
}

ArraySolution::~ArraySolution()
{
}

int ArraySolution::removeElement(vector<int>& nums, int val)
{
	vector<int>::iterator it;
	for (it = nums.begin(); it != nums.end();)
	{
		if (*it==val)
		{
			it = nums.erase(it);
		}
		else
		{
			++it;
		}
	}
	return nums.size();
}

void ArraySolution::rotate(vector<int>& nums, int k)
{
	int length = nums.size();
	if ((nums.size() == 0)|| (k %= nums.size())==0)
	{
		return;
	}
	for (int i = 0; i < length-k; i++)
	{
		nums.push_back(nums[0]);
		nums.erase(nums.begin());
	}
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}

int ArraySolution::thirdMax(vector<int>& nums)
{
	set<int> s;
	for (int i = 0; i < nums.size(); i++)
	{
		s.insert(nums[i]);
		if (s.size()>3)
		{
			s.erase(s.begin());
		}
	}
	return (s.size() == 3) ? *s.begin() : *s.rbegin();
}

int ArraySolution::missingNumber(vector<int>& nums)
{
	//method1
	int size = nums.size();
	int missing = 0;
	for (int i = 0; i < size; i++)
	{
		if ((nums[i + 1] - nums[i])!= 1)
		{
			missing = nums[i]+1;
			break;
		}
	}
	return missing;

	//method2
	int sum = 0;
	int n = nums.size();
	for (int i = 0; i < n; i++)
	{
		sum += nums[i];
	}
	return n*(n + 1) / 2 - sum;
}

//use the ¶¯Ì¬¹æ»® method
int ArraySolution::minPathSum(vector<vector<int>>& grid)
{
	if (grid.size() == 0)
	{
		return 0;
	}
	vector<vector<int>> res(grid);
	int i, j;
	for (j = 1; j < res[0].size(); j++)
	{
		res[0][j] += res[0][j-1];
	}
	for (j = 1; j < res.size(); j++)
	{
		res[j][0] += res[j-1][0];
	}
	for (i = 1; i < res.size(); i++)
	{
		for ( j = 1; j < res[0].size(); j++)
		{
			res[i][j] = ((res[i][j - 1]<res[i - 1][j]) ? res[i][j - 1] : res[i - 1][j]) + grid[i][j];
		}
	}
	return res[grid.size()-1][grid[0].size()-1];
}

int ArraySolution::findPeakElement(vector<int>& nums)
{
	vector<int>res(nums);
	if (nums.size() == 0)
	{
		return 0;
	}
	sort(res.begin(),res.end());
	int index;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == res.back())
		{
			index = i;
			break;
		}
	}
	return index;
}

int ArraySolution::findDuplicate(vector<int>& nums)
{ 
	int min = 0;
	int max = nums.size() - 1;
	while (min<=max)
	{
		int mid = (min + max) / 2;
		int cnt = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i]<=mid)
			{
				cnt++;
			}
		}
		if (cnt>mid)
		{
			max = mid - 1;
		}
		else
		{
			min = mid + 1;
		}
	}
	return min;
}

int ArraySolution::NumberOf1(int n)
{
	//method 1
	/*int count = 0;
	while (n)
	{
		if (n & 1)
		{
			count++;
		}
		n = n >> 1;
	}
	return count;*/

	//method 2
	int count = 0;
	while (n)
	{
		++count;
		n = n&(n - 1);
	}
	return count;
}

int ArraySolution::f(int n, int m)
{
	if (m == 0 || m == n)
	{
		return 1;
	}
	else
	{
		return f(n - 1, m) + f(n - 1, m - 1);
	}
}

int ArraySolution::g(int n)
{
	if (n == 1 || n == 0)
	{
		return 1;
	}
	else
	{
		return n*g(n - 1);
	}
}

int main()
{
	/*ArraySolution arraySolutuon;
	vector<int> vec;
	int temp = 0;
	int number = 0;
	cout << "please input the numbet of data into vec" << endl;
	cin >> number;
	cout << "please input the data into vec" << endl;
	for (int i = 0; i < number; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}		
	int value = 0;
	cout << "please input the value" << endl;
	cin >> value;
	int newLength = arraySolutuon.removeElement(vec,value);
	cout << "the new array length is :" << newLength << endl;*/

	/*ArraySolution rotateSolutuon;
	vector<int> vec;
	int number = 0;
	int temp = 0;
	cout << "please input the numbet of data into vec" << endl;
	cin >> number;
	cout << "please input the data into vec" << endl;
	for (int i = 0; i < number; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}
	int k = 0;
	cout << "the step of k" << endl;
	cin >> k;
	rotateSolutuon.rotate(vec,k);*/

	/*ArraySolution thirdMaxSolutuon;
	vector<int> vec;
	int number = 0;
	int temp = 0;
	cout << "please input the numbet of data" << endl;
	cin >> number;
	cout << "please input the data into vec" << endl;
	for (int i = 0; i < number; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}
	int thirdMax = thirdMaxSolutuon.thirdMax(vec);
	cout << "the thirdMaxNUmber is: " << thirdMax << endl;*/

	/*ArraySolution missingSolution;
	vector<int> vec;
	int number = 0;
	int temp = 0;
	cout << "please input the numbet of data" << endl;
	cin >> number;
	cout << "please input the data into vec" << endl;
	for (int i = 0; i < number; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}
	int missing_number = missingSolution.missingNumber(vec);
	cout << "the missing number is: " << missing_number << endl;*/

	/*ArraySolution minPathSumSolution;
	vector<vector<int>> vec;
	int m, n;
	int temp = 0;
	cout << "please input the number of m and n" << endl;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		cout << "please input for " << i+1 << " line" << endl;
		vector<int> tempVec;
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			tempVec.push_back(temp);
		}
		vec.push_back(tempVec);
	}
	int minSum = minPathSumSolution.minPathSum(vec);
	cout << minSum << endl;;*/

	/*ArraySolution peakSolution;
	vector<int> vec;
	int number = 0;
	int temp = 0;
	cout << "please input the numbet of data" << endl;
	cin >> number;
	cout << "please input the data into vec" << endl;
	for (int i = 0; i < number; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}
	int peakNumberIndex = peakSolution.findPeakElement(vec);
	cout << "the peak number index is: " << peakNumberIndex << endl;*/
	
	/*ArraySolution duplicateSolution;
	vector<int> vec;
	int number = 0;
	int temp = 0;
	cout << "please input the numbet of data" << endl;
	cin >> number;
	cout << "please input the data into vec" << endl;
	for (int i = 0; i <=number; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}
	int duplicateNumber = duplicateSolution.findDuplicate(vec);
	cout << "the duplicate number is: " << duplicateNumber << endl;*/

	/*ArraySolution numberOfBits;
	int number;
	cout << "please input the number"<<endl;
	cin >> number;
	int theNumber = numberOfBits.NumberOf1(number);
	cout << "the number of 1 is: " << theNumber << endl;*/

	ArraySolution numberOfCom;
	int n, m;
	int result;
	cout << "please input the data of n && m" << endl;
	cin >> n >> m;
	while (n < m)
	{
		cout <<"please input data again"<< endl;
		cin >> n >> m;
	}
	result = (numberOfCom.f(n, m) * numberOfCom.g(m))/2;
	cout << "the combine number is:" << result << endl;
	system("pause");
	return 0;
}