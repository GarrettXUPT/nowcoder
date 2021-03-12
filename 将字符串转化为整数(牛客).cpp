#include<iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

int atoi(string str) {
	const char* str1 = str.c_str();
	if (str1 == nullptr) {
		return 0;
	}
	int flag = 2;  // 标志正负
	vector<int> intCheck;
	while (*str1 != '\0') {
		if (*str1 >= '0' && *str1 <= '9') {
			intCheck.push_back(*str1 - '0');
		}
		else if (*str1 == '-' && flag == 2) {
			flag = 0;
		}
		else if (*str1 == '+' && flag == 2) {
			flag = 1;
		}
		str1++;
	}
	long long ret = 0, pos = 0;
	auto rbegin = intCheck.rbegin();
	while (rbegin != intCheck.rend()) {
		ret += (*rbegin * static_cast<int>(pow(10, pos)));
		// 一定要注意越界问题
		if (ret < 0) {
			return (flag == 1 || flag == 2) ? INT_MAX : -(INT_MAX + 1);
		}
		rbegin++; pos++;
	}
	return (flag == 1 || flag == 2) ? ret : -ret;
}

int atoi(string str) {
	
}