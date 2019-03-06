#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
	map<string, int> genresCount;
	for (int i = 0; i < genres.size(); i++)
	{
		auto finder = genresCount.find(genres[i]);
		if (finder != genresCount.end())
		{
			finder->second += plays[i];
		}
		else
		{
			genresCount.insert(map<string, int>::value_type(genres[i], plays[i]));
		}
	}

	map<int, string, greater<int>> genresOrder;
	for (auto iter = genresCount.begin(); iter != genresCount.end(); iter++)
	{
		genresOrder.insert(map<int, string, greater<int>>::value_type(iter->second, iter->first));
	}

	map<string, multimap<int, int, greater<int>>> genresMap;
	for (int i = 0; i < genres.size(); i++)
	{
		auto finder = genresMap.find(genres[i]);
		if (finder != genresMap.end())
		{
			finder->second.insert(multimap<int, int, greater<int>>::value_type(plays[i], i));
		}
		else
		{
			multimap<int, int, greater<int>>* pMap = new multimap<int, int, greater<int>>();
			pMap->insert(multimap<int, int, greater<int>>::value_type(plays[i], i));
			genresMap.insert(map<string, multimap<int, int, greater<int>>>::value_type(genres[i], *pMap));
		}
	}

	vector<int> answer;
	for (auto iter = genresOrder.begin(); iter != genresOrder.end(); iter++)
	{
		auto finder = genresMap.find(iter->second);
		if (finder != genresMap.end())
		{
			int genCount = 0;
			for (auto iter2 = finder->second.begin(); iter2 != finder->second.end() && genCount < 2; genCount++, iter2++)
			{
				answer.insert(answer.end(), iter2->second);
			}
		}
	}

	return answer;
}

int main()
{
	auto result = solution({ "classic","pop","classic","pop","classic","classic" }, { 400,600,150,2500,500,500 });
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
}