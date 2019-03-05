#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) 
{
	int answer = 1;
	multimap<string, string> multiClothesMap;
	unordered_map<string, bool> calculatedClothesKind;
	for (int i = 0; i < clothes.size(); i++)
	{
		multiClothesMap.insert(multimap<string, string>::value_type(clothes[i][1], clothes[i][0]));
		if (calculatedClothesKind.find(clothes[i][1]) == calculatedClothesKind.end())
		{
			calculatedClothesKind.insert(unordered_map<string, bool>::value_type(clothes[i][1], false));
		}
	}

	for (auto iter = multiClothesMap.begin(); iter != multiClothesMap.end(); iter++)
	{
		auto finder = calculatedClothesKind.find(iter->first);
		if (finder != calculatedClothesKind.end() && !finder->second)
		{
			finder->second = true;
			answer *= multiClothesMap.count(iter->first) + 1;
		}
	}

	answer -= 1;

	return answer;
}

int main()
{
	cout << "Answer :: " << solution({ {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} }) << endl << endl;

	cout << "Answer :: " << solution({ {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"},{"1","1"} }) << endl << endl;

	cout << "Answer :: " << solution({ {"crow_mask", "face"},{"blue_sunglasses", "face"},{"smoky_makeup", "face"} }) << endl << endl;

	cout << "Answer :: " << solution({ {"1", "a"},{"2", "a"},{"3", "a"},{"1", "b"},{"2", "b"},{"1", "c"},{"1", "d"},{"2","d"} }) << endl << endl;

	cout << "Answer :: " << solution({ {"1", "a"},{"1", "b"},{"1", "c"},{"1", "d"} }) << endl << endl;

	cout << "Answer :: " << solution({ {"1", "a"} }) << endl << endl;

}