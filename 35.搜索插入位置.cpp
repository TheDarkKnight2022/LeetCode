#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

/* 做题目，大道至简，优先考虑暴力解法何尝不是一种选择？ */
int Violence(vector<int>& nums, int target) {
	for (int i = 0; i < nums.size(); i++) {
		if (target <= nums[i]) {
			return i;
		}
	}
	//return -1;//此处过于草率，没有判断若target要放在最后面的情况
	return nums.size();//这个才是正解
}
int Solution(vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;

	while (left <= right) {
		int middle = (left + right) / 2;
		if (nums[middle] < target) {
			left = middle + 1;
		}
		else if (nums[middle] > target) {
			right = middle - 1;
		}
		else if (nums[middle] == target) {
			return middle;
		}
	}

	// 目标值在数组所有元素之前  [0, -1]
	// 目标值等于数组中某一个元素  return middle;
	// 目标值插入数组中的位置 [left, right]，return  right + 1
	// 目标值在数组所有元素之后的情况 [left, right]， 因为是右闭区间，所以 return right + 1
	return right + 1;
}

int main() {
	int arr[] = { 1,3,5,6 };
	int target = 5;
	vector<int> nums;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		nums.push_back(arr[i]);
	}
	cout << Solution(nums, target);
	//Violence(nums, target);
	return 0;
}