#include<iostream>
#include<vector>
#include<set>

using namespace std;


bool canPermutePalindrome(string s) {
	int ret = 0;
	set<char> checkSet;
	for (auto& ele : s) {
		if (checkSet.find(ele) == checkSet.end()) {
			checkSet.insert(ele);
			if (count(s.begin(), s.end(), ele) % 2 == 1) {
				ret += 1;
				if (ret > 1) {
					return false;
				}
			}
		}
	}
	return true;
}

