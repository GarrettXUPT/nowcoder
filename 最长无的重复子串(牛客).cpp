#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int maxLength(vector<int>& arr) {
    // write code here
    map<int, int> mp;
    int maxValue = 1;
    int start = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (mp.count(arr[i]) == 0) {
            mp.insert({ arr[i], i });
            if (i == arr.size() - 1) {
                maxValue = max(maxValue, i - start + 1);
            }
        }
        else {
            maxValue = max(maxValue, i - start);
            start = max(mp[arr[i]] + 1, start);
            mp[arr[i]] = i;
        }
    }
    return maxValue;
}


//public int maxLength(int[] arr) {
//    // write code here
//    if (arr == null) return 0;
//    Map<Integer, Integer> map = new HashMap<>();
//    int res = -1;
//    int start = 0;//重复位置的下一个位置
//    for (int i = 0; i < arr.length; i++) {
//        if (map.containsKey(arr[i])) {
//            //当有重复的时候，需要更新start的位置，可能比当前重复的位置远也可能近
//            start = Math.max(start, map.get(arr[i]) + 1);
//        }
//        //每遍历一次 就更新一次最值
//        res = Math.max(res, i - start + 1);
//        map.put(arr[i], i);
//    }
//    return res;
//}

/*
    public int maxLength (int[] arr) {
    HashMap<Integer,Integer> map = new HashMap<>();
    int max = 1;
    for(int start = 0, end = 0; end<arr.length ; end++){
        if(map.containsKey(arr[end])){
            //重复了
            start = Math.max(start, map.get(arr[end])+1);
            //注意：这里一定要取最大的start，不然就错误了
            //为什么？ 因为重复数字的索引很可能比start小
        }
        max = Math.max(max , end-start+1);
        map.put(arr[end],end);
    }
    return max;
}
*/

int main() {
    vector<int> vec{ 2,2,3,3,4,3,3 };
    cout << maxLength(vec) << endl;
    return 0;
}