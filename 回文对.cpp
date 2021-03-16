#include<iostream>
#include<set>
#include<vector>

using namespace std;


bool canPermutePalindrome(string s) {
	
	int len = s.length();
	int pos = len % 2 == 1 ? len / 2 + 1 : len / 2;
	auto begin = s.begin(); 
	auto rbegin = s.rbegin();
	for (int i = 0; i < pos; ++i) {
		if (*begin != *rbegin) {
			return false;
		}
	}
	return true;

}

vector<vector<int>> palindromePairs(vector<string>& words) {
	if (words.empty()) {
		return {};
	}
	vector<vector<int>> retVec;
	for (int i = 0; i < words.size(); ++i) {
		for (int j = 0; j < words.size(); ++j) {
			string tmpStr = words[i] + words[j];
			if (canPermutePalindrome(tmpStr) && i != j) {
				retVec.push_back({ i, j });
			}

		}
	}
	return retVec;
}