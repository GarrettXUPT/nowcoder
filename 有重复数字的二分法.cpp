#include<iostream>
#include<vector>

using namespace std;

/*
    不含重复数字的二分法
*/
int helper(vector<int> nums, int target, int begin, int end) {
    if (end < begin) {
        return -1;
    }
    if (nums[begin] == target) { return begin; }
    int mid = (begin + end) / 2;
    if (nums[mid] == target) return mid;
    if (target > nums[mid]) {
        return helper(nums, target, mid + 1, end);
    }
    else {
        return helper(nums, target, begin, mid - 1);
    }
}
int search(vector<int>& nums, int target) {
    // write code here
    return helper(nums, target, 0, nums.size() - 1);
}

/*
    method1
*/

int helper(vector<int> nums, int target, int begin, int end) {
    if (begin > end || nums[begin] > target || nums[end] < target) //边界检测
    {
        return -1;
    }
    if (nums[begin] == target) { return begin; }
    int mid = (begin + end) / 2;
    int l_i = helper(nums, target, begin, mid);
    if (l_i != -1) {
        return l_i;
    }
    return helper(nums, target, mid + 1, end);
}

/*
    method2
*/
int search(vector<int>& nums, int target) {
    // write code here
    return helper(nums, target, 0, nums.size() - 1);
}

int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (nums[mid] == target) {
            while (mid != 0 && (nums[mid - 1] == nums[mid])) {
                mid--;
            }
            return mid;
        }
        else if (nums[mid] > target) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}