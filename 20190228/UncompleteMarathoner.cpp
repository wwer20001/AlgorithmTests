#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct ParticipantData
{
	string name;
	int count;

	ParticipantData() : name(""), count(0) { }
	ParticipantData(string name, int count) : name(name), count(count) { }
};

string solution(vector<string> participant, vector<string> completion)
{
	unordered_map<string, ParticipantData> completionMap;
	for (auto name : completion)
	{
		auto finder = completionMap.find(name);
		if (finder == completionMap.end())
		{
			ParticipantData data(name, 1);
			completionMap.insert(unordered_map<string, ParticipantData>::value_type(name, data));
		}
		else
		{
			finder->second.count++;
		}

	}

	string answer = "";
	for (auto name : participant)
	{
		auto finder = completionMap.find(name);
		if (finder == completionMap.end())
		{
			answer = name;
			break;
		}
		else
		{
			if (finder->second.count != 0)
			{
				finder->second.count--;
			}
			else
			{
				answer = name;
				break;
			}
		}
	}

	return answer;
}

int main()
{
	cout << solution({ "leo", "kiki", "eden" }, { "eden", "kiki" }) << endl;
	cout << solution({ "marina", "josipa", "nikola", "vinko", "filipa" }, { "josipa", "filipa", "marina", "nikola" }) << endl;
	cout << solution({ "mislav", "stanko", "mislav", "ana" }, { "stanko", "ana", "mislav" }) << endl;
	cout << solution({ "mark", "may", "snake", "dean", "may" }, { "mark", "may", "dean", "may" }) << endl;
	//cout << solution("()(((()())(())()))(())") << endl;
}