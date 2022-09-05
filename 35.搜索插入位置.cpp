#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

/* ����Ŀ������������ȿ��Ǳ����ⷨ�γ�����һ��ѡ�� */
int Violence(vector<int>& nums, int target) {
	for (int i = 0; i < nums.size(); i++) {
		if (target <= nums[i]) {
			return i;
		}
	}
	//return -1;//�˴����ڲ��ʣ�û���ж���targetҪ�������������
	return nums.size();//�����������
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

	// Ŀ��ֵ����������Ԫ��֮ǰ  [0, -1]
	// Ŀ��ֵ����������ĳһ��Ԫ��  return middle;
	// Ŀ��ֵ���������е�λ�� [left, right]��return  right + 1
	// Ŀ��ֵ����������Ԫ��֮������ [left, right]�� ��Ϊ���ұ����䣬���� return right + 1
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