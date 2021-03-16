#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	int top = 0, botton = n - 1;
	int left = 0, right = n - 1;
	int value = 1;
	while (top < (n + 1) / 2 && left < (n + 1) / 2) {
		/*
			���� ������ 
		*/
		for (int i = left; i <= right; i++) {
			matrix[top][i] = value;
			value++;
		}
		/*
			���� ���ϵ���
		*/
		for (int i = top + 1; i <= botton; ++i) {
			matrix[i][right] = value;
			value++;
		}
		/*
			���� ���ҵ���
		*/
		for (int i = right - 1; i >= left && top != botton; --i) {
			matrix[botton][i] = value;
			value++;
		}
		/*
			��� ���µ���
		*/
		for (int i = botton - 1; i >= top + 1 && left != right; --i) {
			matrix[i][left] = value;
			value++;
		}
		left++; top++; botton--; right--;
	}
	return matrix;
}

int main() {
	generateMatrix(3);
	return 0;

}