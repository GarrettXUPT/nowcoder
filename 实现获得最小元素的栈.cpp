#include<iostream>
#include<deque>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> getMinStack(vector<vector<int> >& op) {
    // write code here
    vector<int> minVec, retVc;
    deque<int> store;
    for (auto& ele : op) {
        if (ele[0] == 1) {
            store.push_back(ele[1]);
            minVec.push_back(ele[1]);
            sort(minVec.begin(), minVec.end());
        }
        else if (ele[0] == 2) {
            int tmp = store.back();
            minVec.erase(find(minVec.begin(), minVec.end(), tmp));
            store.pop_back();
        }
        else
        {
            retVc.push_back(minVec[0]);
        }
    }
    return retVc;
}