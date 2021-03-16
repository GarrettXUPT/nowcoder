#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

vector<vector<string> > topKstrings(vector<string>& strings, int k) {
    // write code here
    vector<vector<string> > ans;
    if (strings.size() == 0 || strings.size() < k)
        return ans;
    // ��¼ÿ��Ԫ�س��ֵĴ���
    unordered_map<string, int> hash;
    for (const auto& string : strings) {
        hash[string]++;
    }
    // ����С���ѣ����ճ��ִ������򣬴�����ͬ�����ֵ���
    auto cmp = [](const pair<string, int>& p1, const pair<string, int>& p2) {
        if (p1.second != p2.second)
            return p1.second > p2.second;
        return p1.first < p2.first;
    };
    // ��ȫ��Ԫ����ѣ������ִ����ϴ�ķ��ں���
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> max_heap(cmp);

    auto p_iter = hash.begin();

    for (; p_iter != hash.end(); p_iter++) {
        max_heap.push(*p_iter);
        if (max_heap.size() > k)
            max_heap.pop();
    }

    while (!max_heap.empty()) {
        pair<string, int> p = max_heap.top();
        max_heap.pop();
        ans.insert(ans.begin(), vector<string>{p.first, to_string(p.second)});
    }

    return ans;
}

int main() {
    vector<string>str{ "1", "2", "3", "4" };
    topKstrings(str, 2);
    return 0;
}