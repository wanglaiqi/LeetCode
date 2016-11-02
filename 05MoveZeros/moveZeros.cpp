#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
	 Solution ();
	~ Solution ();

	void moveZeros(vector<int>& num);

private:

};

 Solution :: Solution ()
{
}

 Solution ::~ Solution ()
{
}

 void Solution::moveZeros(vector<int>& num) 
 {
	 cout << num.size() << endl;
	 for (int i = 0; i < num.size(); i++)
	 {
		 cout << num[i] << " ";
	 }
	 cout << endl;
	 int m = 0;
	 for (int j = 0; j < num.size(); j++)
	 {
		 if (num[j]!=0)
		 {
			 num[m++] = num[j];
		 }	
	 }

	 for (int j = m; j < num.size();j++)
	 {
		 num[j] = 0;
	 }

	 cout << "把零移动到最后的结果" << endl;

	 for (int i = 0; i < num.size(); i++)
	 {
		 cout << num[i] << " ";
	 }
	 cout << endl;
 }

 int main()
 {
	 Solution S;
	 int num[5] = {0,1,0,3,12};
	 vector<int> nums(num,num+5);
	 S.moveZeros(nums);
	 system("pause");
 }
