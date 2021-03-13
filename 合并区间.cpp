#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;


 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
 

 /*
    官方解决方案 需要使用该方法解决类似问题
 */

vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.empty()) {
        return {};
    }
    sort(intervals.begin(), intervals.end(), [](Interval val1, Interval val2) {return val1.start < val2.start; });

    vector<Interval> retVec;
    for (int i = 0; i < intervals.size(); ++i) {
        int left = intervals[i].start, right = intervals[i].end;
        if (!retVec.size() || retVec.back().end < left) {
            Interval tmp;
            tmp.start = left; tmp.end = right;
            retVec.push_back(tmp);
        }
        else
        {
            retVec.back().end = max(retVec.back().end, right);
        }
    }
    return retVec;
}

/*
    官方思路 不超时 很好用
*/
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() == 0) {
        return {};
    }
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (int i = 0; i < intervals.size(); ++i) {
        int L = intervals[i][0], R = intervals[i][1];
        if (!merged.size() || merged.back()[1] < L) {
            merged.push_back({ L, R });
        }
        else {
            merged.back()[1] = max(merged.back()[1], R);
        }
    }
    return merged;
}
