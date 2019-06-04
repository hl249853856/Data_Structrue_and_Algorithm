#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool IsValid(string s)
{
	stack<char> nums;
	char ch;
	if (s.empty())
		return true;
	for (int i = 0; i != s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			nums.push(s[i]);
		
		if (s[i] == ')')
		{
			if (nums.empty())
				return false;
			if (nums.top() == '(')
				nums.pop();
			else
				return false;
		}
		if (s[i] == ']')
		{
			if (nums.empty())
				return false;
			if (nums.top() == '[')
				nums.pop();
			else
				return false;
		}
		if (s[i] == '}')
		{
			if (nums.empty())
				return false;
			if (nums.top() == '{')
				nums.pop();
			else
				return false;
		}
	}
	if (nums.empty())
		return true;
	else
		return false;
}

int main()
{
	string s("()");
	cout << IsValid(s) << endl;
	return 0;
}