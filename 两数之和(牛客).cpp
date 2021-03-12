#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    // write code here
    
    map<int, int> checkMap;
    for (int i = 0; i < numbers.size(); ++i) {
        checkMap[i + 1] = numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    vector<int> check;
    for (int i = 0; i < numbers.size() - 1; ++i) {
        for (int j = i + 1; j < numbers.size(); ++j) {
            if (numbers[i] + numbers[j] == target) {
                check.push_back(numbers[i]);
                check.push_back(numbers[j]);
            }
            else if (numbers[i] + numbers[j] > target) {
                break;
            }
        }
    }
    int count = 0;
    vector<int> retVec;
    for (auto& ele : checkMap) {
        if (ele.second == check[0] || ele.second == check[1]) {
            retVec.push_back(ele.first);
        }
        else if (retVec.size() == 2) {
            break;
        }
    }
    return retVec;;
   
}