#include<iostream>
#include<vector>
#include<map>

using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) {
	if (numbers.empty()) {
		return 0;
	}
	else if(numbers.size() == 1)
	{
		return numbers[0];
	}
	int len = numbers.size();
	map<int, int> checkMap;
	for (auto& ele : numbers) {
		if (checkMap.find(ele) != checkMap.end()) {
			checkMap[ele]++;
			if (checkMap[ele] > (len / 2)) {
				return ele;
			}
		}
		else
		{
			checkMap.insert({ ele, 1 });
		}
	}
	return 0;
}