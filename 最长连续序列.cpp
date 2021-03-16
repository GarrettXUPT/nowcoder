#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) {
	unordered_set<int> checkSet;
	for (const auto& ele : nums) {
		checkSet.insert(ele);
	}
	int longest = 0;
	for (const auto& num : checkSet) {
		if (!checkSet.count(num - 1)) {
			int curNum = num;
			int curlongest = 1;
			/*
				评价连续序列
			*/
			while (checkSet.count(curNum + 1 )){
				curNum += 1;
				curlongest += 1;
			}
			longest = max(longest, curlongest);
		}
	}
	return longest;
}