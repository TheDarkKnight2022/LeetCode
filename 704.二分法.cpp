#include<iostream>
#include<algorithm>
#include<cstdio>
#include <vector>
using namespace std;

/* ������LeetCode����ģʽ */
int Solution(vector<int>& nums, int target) {
	//�������ұ߽�
	int left = 0;
	int right = nums.size() - 1;//�˴�nums.size()��ʾ����nums�ĳ��ȣ���nums.size()-1��ʾ�����±�

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
	���ַ�:
	ʹ�õĻ�������: Ҫ���������е�Ԫ��Ӧ��������� 
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