#include<iostream>
#include<algorithm>
#include<cstdio>
#include <vector>
using namespace std;

/* 适用于LeetCode编码模式 */
int Solution(vector<int>& nums, int target) {
	//创建左右边界
	int left = 0;
	int right = nums.size() - 1;//此处nums.size()表示的是nums的长度，而nums.size()-1表示的是下标

	while (left <= right) { 
		int middle = (right + left) / 2;
		if (nums[middle] > target) {
			right = middle - 1; 
		}
		else if (nums[middle] < target) {
			left = middle + 1; 
		}
		else { 
			return middle; 
		}
	}
	return -1;
}

/* 
	二分法:
	使用的基本条件: 要操作容器中的元素应当是有序的 
*/
int main() {
	int target = 9;
	int arr[] = { -1,0,3,5,9,12 };
	int length = sizeof(arr) / sizeof(arr[0]);
	vector<int> nums;

	for (int i = 0; i < length; i++){
		nums.push_back(arr[i]);
	}
	cout<<Solution(nums,target)<<endl;
	return 0;
}