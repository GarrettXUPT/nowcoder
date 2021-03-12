#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

/*
	在牛客的clang编译器里面 是不可以有死循环的
*/
vector<string> Permutation(string str) {
	if (str.empty()) {
		return {};
	}
	vector<string> retVec;
	sort(str.begin(), str.end());
	retVec.push_back(str);
	string pos = str;
	reverse(pos.begin(), pos.end());
	while (str != pos) {
		int len = str.size();
		int i = len - 1;
		while (i > 0 && str[i - 1] >= str[i]) {
			i--;
		}
		int j = len - 1;
		while (j > 0 && str[j] <= str[i - 1]) {
			j--;
		}
		swap(str[i - 1], str[j]);
		reverse(str.begin() + i, str.end());
		retVec.push_back(str);
	}
	return retVec;
}

int main() {
	auto res = Permutation("adsa");
	return 0;
}
