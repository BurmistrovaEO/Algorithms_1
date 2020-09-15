#include <iostream>
#include <vector>
#include <iterator>
#include <stdlib.h>
using namespace std;
void Merge(vector<int>& a, vector<int>::iterator s, vector<int>::iterator m, vector<int>::iterator m1, vector<int>::iterator e)
{	
	vector<int> tmp1;
	vector<int>::iterator i = s;
	vector<int>::iterator j = m1;
	vector<int>::iterator tmp,t;
	while (i < m1 || j < e+1)
	{
		if (j > e || *i < *j )
		{
			if (i >= m1)
			{
				tmp1.push_back(*j);
				j++;
			}
			else
				tmp1.push_back(*i);
			i++;
		}
		else if (i == m1 || *j <= *i)
		{
			tmp1.push_back(*j);
			j++;
		}
	}
	tmp = tmp1.begin();
	t = s;
	for (t; t <= e; t++,tmp++)
	{
		*t = *tmp;
	}
};
void Sort(vector<int>& a, vector<int>::iterator s, vector<int>::iterator e)
{
	vector<int>::iterator mm;
	vector<int>::iterator mm1;
	int tmp = 0,tmp2=0;
	int k=0;
	if (distance(s,e) <= 1)
	{
		if (*s > *e)
		{
			tmp = *e;
			tmp2 = *s;
			*s = tmp;
			*e = tmp2;
		}
		return;
	}
	else
	{
		k = (distance(s,e+1) / 2);
		mm = s + k - 1;
		mm1 = s + k;
		Sort(a, s, mm);
		Sort(a, mm1, e);
		Merge(a,s,mm,mm1,e);
	}
};

int main()
{
	int n,k;
	vector<int> nums;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		nums.push_back(k);
	}
	vector<int>::iterator iter = nums.begin(); 
	vector<int>::iterator iter2 = nums.end()-1;
	Sort(nums,iter,iter2);
	for (iter = nums.begin(); iter <= iter2; iter++)
	{
		cout << *iter << " ";
	}
	system("pause");
}