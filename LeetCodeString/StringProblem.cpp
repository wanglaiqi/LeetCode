#include <iostream>  
#include <vector>  
#include <string>
#include <list>
#include <set>
using namespace std;

typedef struct ListNode
{
	int key;
	ListNode *next;
}ListNode, *LinkList;

class OurSolution {
public:
	bool isValid(string s);
	string convert(string s, int numRows);
	string reverseVowels(string s);
	string countAndSay(int n);
	void reverseWords(string &s);
	bool isPalindrome(string s);
	bool canConstruct(string ransomNote, string magazine);
private:

};

//method1 whether string is valid
bool OurSolution::isValid(string s)
{
	list<char> lis;
	for (char c : s)
	{
		char expected = ' ';
		switch (c)
		{
		case ')': expected = '('; break;
		case ']': expected = '['; break;
		case '}': expected = '{'; break;
		}
		if (expected != ' ')
		{
			if (lis.empty() || lis.back() != expected)
			{
				return false;
			}
			else
			{
				lis.pop_back();//delete the last element
			}
		}
		else
		{
			lis.push_back(c);//add a element into the list end
		}
	}
	return lis.empty();//if list is null return true
}

//method2 transfer the ZigZag string
string OurSolution::convert(string s, int numRows)
{
	vector<string> nRow(numRows, "");
	int i = 0, j = 0;
	if (numRows == 1)
	{
		return s;
	}
	while (j < s.length())
	{
		while (j<s.length() && i<numRows - 1)
		{
			nRow[i++] += s[j++];
		}
		while (j<s.length() && i>0)
		{
			nRow[i--] += s[j++];
		}
	}

	string result = "";
	for (string st : nRow)
	{
		result += st;
	}
	return result;
}

//method3 reverse the vowels character
string OurSolution::reverseVowels(string s)
{
	if (s.length() == 0)
	{
		return "";
	}
	int left = 0, right = s.length() - 1;
	set<char> setStr = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
	while (left < right)
	{
		if (setStr.count(s[left]) == 0)
		{
			left++;
		}
		if (setStr.count(s[right]) == 0)
		{
			right--;
		}
		if (setStr.count(s[left]) != 0 && setStr.count(s[right]) != 0)
		{
			swap(s[left], s[right]);
			left++;
			right--;
		}
	}
	return s;
}

//method4 count and say
string OurSolution::countAndSay(int n)
{
	if (n == 0)
	{
		return NULL;
	}
	if (n == 1)
	{
		return "1";
	}
	string result1 = countAndSay(n - 1);
	string result2 = "";
	for (int i = 0; i < result1.size(); i++)
	{
		int count = 1;
		while ((result1[i] == result1[i + 1]) && (i + 1)<result1.size())
		{
			count++;
			i++;
		}
		result2 += to_string(count) + result1[i];
	}
	return result2;
}

//method5 reverse the words by words
void OurSolution::reverseWords(string &s)
{
	int l = 0, r = 0;
	string temp;
	while (true)
	{
		while (' ' != s[r] && r<s.length())
		{
			++r;
		}
		string word = s.substr(l, r - l);
		reverse(word.begin(), word.end());
		if (0 != word.length())
		{
			if (0 != temp.length())
			{
				temp.append(" ");
			}
			temp.append(word);
		}

		l = r = r + 1;
		if (r >= s.length())
		{
			break;
		}
	}
	s = temp;
	reverse(s.begin(), s.end());
	cout << s << endl;
}

//method6 the string is Palindrome
bool OurSolution::isPalindrome(string s)
{
	if (s.length() == 0)
	{
		return true;
	}
	int left = 0;
	int right = (int)s.length() - 1;
	while (left<right)
	{
		while (left<right && !(isalnum(s[left])))
		{
			++left;
		}
		while (right>left && !(isalnum(s[right])))
		{
			--right;
		}
		if (left<right && tolower(s[left++]) != tolower(s[right--]))
		{
			return false;
		}
	}
	return true;
}

//method7 canConstruct from magazine
bool OurSolution::canConstruct(string ransomNote, string magazine)
{
	if (ransomNote.length()>magazine.length())
	{
		return false;
	}
	int hash1[256] = { 0 };
	int hash2[256] = { 0 };
	for (int i = 0; i < ransomNote.length(); i++)
	{
		hash1[ransomNote[i]]++;
	}
	for (int i = 0; i < magazine.length(); i++)
	{
		hash2[magazine[i]]++;
	}
	for (int j = 0; j < 256; j++)
	{
		if (hash1[j]>hash2[j])
		{
			return false;
		}
	}
	return true;
}

//test myfile
int main()
{
	//method1
	OurSolution isvalid;
	string str1;
	cout << "please input an string:" << endl;
	cin >> str1;
	bool isValidValue = isvalid.isValid(str1);
	cout << "the reuslt is:" << isValidValue << endl;

	//method2
	/*OurSolution zigzag;
	string str2;
	int rowNumber;
	cout << "please input an string && row number" << endl;
	cin >> str2 >>rowNumber;
	string zigzagResult = zigzag.convert(str2,rowNumber);
	cout <<"the zigzagresult is:" <<zigzagResult<<endl;*/

	//method3
	/*OurSolution reverseVowels;
	string str3;
	cout << "please input an string:" << endl;
	cin >> str3;
	string reverseStr = reverseVowels.reverseVowels(str3);
	cout << "the reverseStr result is:" << reverseStr << endl;*/

	//method4
	/*OurSolution countAndSay;
	int n;
	cin >> n;
	string countAndSayResult = countAndSay.countAndSay(n);
	cout << countAndSayResult << endl;*/

	//method5
	/*OurSolution reverseWord;
	string reverseStr;
	getline(cin, reverseStr);
	reverseWord.reverseWords(reverseStr);*/

	//method6
	/*OurSolution isOrPalindrome;
	string str6;
	getline(cin,str6);
	bool boolValue = isOrPalindrome.isPalindrome(str6);
	cout << boolValue << endl;*/

	//method7
	/*OurSolution canconstruct;
	string ransomNote;
	string magazine;
	cin >> ransomNote >> magazine;
	bool canconResult = canconstruct.canConstruct(ransomNote,magazine);
	cout << canconResult << endl;*/

	system("pause");
	return 0;
}