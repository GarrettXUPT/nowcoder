#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
	ʹ������ָ�룬һ��ָ���һ��Ԫ�أ�һ��ָ�����һ��Ԫ��,����Ԫ��֮���γɵ�����������min(first, last) * (last - first - 1)
	ǰ������Ԫ�أ��ĸ�Ԫ��ֵ��С�����ƶ���Ԫ���ϵ�ָ�뼴��
*/
int maxArea(vector<int>& height) {
	auto begin = height.begin();
	auto rbegin = height.end() - 1;
	int len = height.size() - 1;
	vector<int> resVec;
	/*
		�˴�Ҫע����ǣ����������Ҳ�������͵ģ����Բ�ͬ����֮��ʱ�������Ƚϵ�
	*/
	while (begin != rbegin) {
		int hg = min(*begin, *rbegin);
		resVec.push_back(len * hg);  // ��¼��ǰ������
		if (hg == *begin) {
			begin++;
		}
		else {
			rbegin--;
		}
		len--;
	}
	return *max_element(resVec.begin(), resVec.end());  // ѡ����������
}
