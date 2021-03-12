#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	if (k > input.size()) {
		return {};
	}
	sort(input.begin(), input.end());
	vector<int> ret(input.begin(), input.begin() + k);
	return ret;
}