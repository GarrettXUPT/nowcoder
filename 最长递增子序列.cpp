#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/*
	����˵˵̰��+���ֵĽⷨ������˵������˼·����������arrΪ[2, 3, 1, 2, 3]��vec���������ŵ��������У�
	maxLen����������Ԫ��i��β�������������г��ȣ���ô��������arr��ִ�����¸��¹���:

	��ʼ����£�vecΪ[2]��maxLen[1]
	����������3������vec���һ��Ԫ��С��3��ֱ�Ӹ��£�vecΪ[2,3]��maxLen[1,2]
	����������1������vec����Ԫ�ش���1, ������vec�в��Ҵ��ڵ���1�ĵ�һ��Ԫ�ص��±꣬����1�滻֮����ʱvecΪ[1,3], maxLen[1,2,1]
	����������2������vec����Ԫ�ش���2��������vec�в��Ҵ��ڵ���2�ĵ�һ��Ԫ�ص��±꣬����2�滻֮����ʱvecΪ[1,2], maxLen[1,2,1,2]
	����������3������vec���һ��Ԫ��С��3��ֱ�Ӹ��£�vecΪ[1,2,3]��maxLenΪ[1,2,1,2,3]
	��ʱvec�Ĵ�С������������������������еĳ��ȣ�����vec��һ���Ǳ�������ս�

	���ڵڶ�������������ԭʼ������arr1���õ���maxLenΪ[1,2,3,1,3]������������Ϊres���ֵ�����С������������У���
	res�����һ��Ԫ����arr1��λ����ӹ������maxLen[i]==3��Ӧ���±꣬��ô������arr1[2]����arr1[4]�أ������arr1[2]��
	��ôarr1[2]<arr1[4]����maxLen[4]==4������֪������㣡��������Ӧ��ȡarr1[4]����res�����һ��λ��
*/

vector<int> LIS(vector<int>& arr) {
	// write code here
	if (arr.empty()) return {};
	vector<int> res;
	vector<int> maxLen;
	res.emplace_back(arr[0]);
	maxLen.emplace_back(1);
	for (int i = 1; i < arr.size(); ++i) {
		if (arr[i] > res.back()) {
			res.emplace_back(arr[i]);
			maxLen.emplace_back(res.size());
		}
		else
		{
			int pos = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
			res[pos] = arr[i];
			maxLen.emplace_back(pos + 1);
		}
	}
	/*
		��������������
	*/
	for (int i = arr.size() - 1, j = res.size(); j > 0; --i) {
		if (maxLen[i] == j) {
			res[--j] = arr[i];
		}
	}
	return res;
}