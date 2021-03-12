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
//    int start = 0;//�ظ�λ�õ���һ��λ��
//    for (int i = 0; i < arr.length; i++) {
//        if (map.containsKey(arr[i])) {
//            //�����ظ���ʱ����Ҫ����start��λ�ã����ܱȵ�ǰ�ظ���λ��ԶҲ���ܽ�
//            start = Math.max(start, map.get(arr[i]) + 1);
//        }
//        //ÿ����һ�� �͸���һ����ֵ
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
            //�ظ���
            start = Math.max(start, map.get(arr[end])+1);
            //ע�⣺����һ��Ҫȡ����start����Ȼ�ʹ�����
            //Ϊʲô�� ��Ϊ�ظ����ֵ������ܿ��ܱ�startС
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