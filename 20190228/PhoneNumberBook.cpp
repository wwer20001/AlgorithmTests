#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) 
{
	bool answer = true;

	sort(phone_book.begin(), phone_book.end());

	for (auto iter = phone_book.begin(); iter != phone_book.end(); iter++)
	{
		auto next = iter + 1;
		if (next != phone_book.end())
		{
			if (iter->size() > next->size()) continue;
			string str = next->substr(0, iter->length());
			if (str.compare(*iter) == 0)
			{
				answer = false;
				break;
			}
		}
	}

	return answer;
}

int main()
{
	cout << solution({ "119", "97674223", "1195524421" }) << endl;
	cout << solution({ "123","456","789" }) << endl;
	cout << solution({ "12","123","1235","567","88" }) << endl;
}