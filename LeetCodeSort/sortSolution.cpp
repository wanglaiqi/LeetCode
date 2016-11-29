#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class SortSolution
{
public:
	SortSolution();
	~SortSolution();
	//01£»intersection of two array
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2);
	//02:intersection of two array II
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2);
	//03:quick sort
	void  quick_sort(int vec[], int left, int right);

private:

};

SortSolution::SortSolution()
{

}

SortSolution::~SortSolution()
{

}

vector<int> SortSolution::intersection(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> result;
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	vector<int>::iterator iter1;
	vector<int>::iterator iter2;
	iter1 = unique(nums1.begin(), nums1.end());
	iter2 = unique(nums2.begin(), nums2.end());
	if (iter1!=nums1.end())
	{
		nums1.erase(iter1,nums1.end());
	}
	if (iter2 != nums2.end())
	{
		nums2.erase(iter2, nums2.end());
	}
	vector<int>::iterator iter0;
	for (int i = 0; i < nums1.size(); i++)
	{
		/*for (int j = 0; j < nums2.size(); j++)
		{
			if (nums1[i] == nums2[j])
			{
				result.push_back(nums1[i]);
				break;
			}
		}*/
		iter0 = find(nums2.begin(),nums2.end(),nums1[i]);
		if (iter0 != nums2.end())
		{
			result.push_back(nums1[i]);
		}
	}
	return result;
}

vector<int> SortSolution::intersect(vector<int>& nums1, vector<int>& nums2)
{
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	vector<int> result;
	for (int i = 0,j=0; i < nums1.size() && j<nums2.size();)
	{
		if (nums1[i] < nums2[j])
		{
			i++;
		}
		else if (nums1[i]>nums2[j])
		{
			j++;
		}
		else
		{
			result.push_back(nums1[i]);
			i++;
			j++;
		}
	}
	return result;
}

void SortSolution::quick_sort(int vec[], int left, int right)
{
	if (left < right)
	{
		int i = left;
		int j = right;
		int x = vec[i];
		while (i<j)
		{
			while (i<j&&vec[j]>=x)
			{
				j--;
			}
			if (i < j)
			{
				vec[i] = vec[j];
				i++;
			}
			while (i<j&&vec[i]<x)
			{
				i++;
			}
			if (i < j)
			{
				vec[j] = vec[i];
				j--;
			}
		}
		vec[i] = x;
		quick_sort(vec, left, i-1);
		quick_sort(vec, i+1, right);
	}
}

int main()
{
	/*SortSolution intersectionSolution;
	vector<int> vec1 = {1,2,2,1,3,5};
	vector<int> vec2 = {2,2,3};
	vector<int> result = intersectionSolution.intersection(vec1, vec2);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;*/

	/*SortSolution intersectionSolutionII;
	vector<int> vec1 = {1,2,2,1,3,5};
	vector<int> vec2 = {2,2,3};
	vector<int> result = intersectionSolutionII.intersect(vec1, vec2);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;*/

	SortSolution quickSolution;
	int vect[] = { 5, 6, 2, 1, 3, 9,4,10 };
	quickSolution.quick_sort(vect,0,7);
	cout <<"after sort the vect"<< endl;
	for (int i = 0; i < 8; i++)
	{
		cout << vect[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}