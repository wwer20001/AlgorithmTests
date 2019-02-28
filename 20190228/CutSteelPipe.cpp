#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string arrangement)
{
	int answer = 0;
	stack<char> brackets;

	for (unsigned int i = 0; i < arrangement.size(); i++)
	{
		if (arrangement[i] == '(')
		{
			brackets.push(arrangement[i]);
		}
		else if (arrangement[i] == ')')
		{
			brackets.pop();
			answer += arrangement[i - 1] == '(' ? brackets.size() : 1;
		}
	}

	return answer;
}

int main()
{
	cout << solution("()(((()())(())()))(())") << endl;
}