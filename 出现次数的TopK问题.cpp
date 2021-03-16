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
    // 记录每个元素出现的次数
    unordered_map<string, int> hash;
    for (const auto& string : strings) {
        hash[string]++;
    }
    // 建立小根堆，按照出现次数排序，次数相同按照字典序
    auto cmp = [](const pair<string, int>& p1, const pair<string, int>& p2) {
        if (p1.second != p2.second)
            return p1.second > p2.second;
        return p1.first < p2.first;
    };
    // 将全部元素入堆，将出现次数较大的放在后面
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