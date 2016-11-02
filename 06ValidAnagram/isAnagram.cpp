#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class Solution
{
public:
	Solution();
	~Solution();
	bool isAnagram(string s, string t);
private:

};

Solution::Solution()
{
}

Solution::~Solution()
{
}

bool Solution::isAnagram(string s,string t)
{
	bool b;
	cout << s << endl;
	cout << t << endl;
	//cout <<"×Ö·û´®µÄ³¤¶È£º"<< s.length() << endl;
	sort(s.begin(), s.end());
	sort(t.begin(),t.end());
	if (s == t)
	{
		b = true;
		cout << b << endl;
		return true;
	}
	else
	{
		b = false;
		cout << b << endl;
		return false;
	}

	cout << b << endl;
}

int main()
{
	Solution S;
	string s = "wang";
	string t = "lai";
	S.isAnagram(s,t);
	system("pause");
}