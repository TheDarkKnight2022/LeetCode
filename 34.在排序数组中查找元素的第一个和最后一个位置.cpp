#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

//暴力破解且无返回值
void Solution_Violence(vector<int>& nums, int target) {
	int result[2];
	int t = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == target && t == 0) {
			t = 1;
			result[0] = i;
			continue;
		}
		if (t > 0 && nums[i] == target) {
			result[1] = i;
			t++;
		}
	}
	if (t == 1) {
		cout << result[0] << result[0] << endl;
	}
	else if (t == 0)
		cout << -1 << " " << -1 << endl;
	else {
		cout << result[0] << result[1] << endl;
	}
}

// 二分查找，寻找target的左边界leftBorder（不包括target）
// 如果leftBorder没有被赋值（即target在数组范围的右边，例如数组[3,3],target为4），为了处理情况一
int Dichotomy_Left(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	int leftBorder = -2; // 记录leftBorder没有被赋值的情况
	while (left <= right) {
		int middle = (left + right) / 2;
		if (nums[middle] >= target) { // 寻找左边界，就要在nums[middle] == target的时候更新right
			right = middle - 1;
			leftBorder = right;
		}
		else {
			left = middle + 1;
		}
	}
	return leftBorder;
}

// 二分查找，寻找target的右边界（不包括target）
// 如果rightBorder为没有被赋值（即target在数组范围的左边，例如数组[3,3]，target为2），为了处理情况一
int Dichotomy_Right(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	int rightBorder = -2; // 记录rightBorder没有被赋值的情况
	while (left <= right) {
		int middle = (left + right) / 2;
		if (nums[middle] > target) {
			right = middle - 1; // target 在左区间，所以[left, middle - 1]
		}
		else { // 当nums[middle] == target的时候，更新left，这样才能得到target的右边界
			left = middle + 1;
			rightBorder = left;
		}
	}
	return rightBorder;
}

//既然一个二分不能返回数组，为什么不用两个二分来寻找左边界和右边界呢？
int main()
{
	int arr[] = { 5, 7, 7, 8, 8, 10 };
	int target = 8;
	vector<int> nums;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		nums.push_back(arr[i]);
	}

	//Solution_Violence(nums, target);//暴力求解

	//cout << "Left_Border is: " << Dichotomy_Left(nums, target) << endl;
	//cout << "Right_Border is: " << Dichotomy_Right(nums, target) << endl;

	int leftBorder = Dichotomy_Left(nums, target);
	int rightBorder = Dichotomy_Right(nums, target);
	if (leftBorder == -2 || rightBorder == -2) {
		cout << -2 << " " << -2 << endl;
	}
	else if (rightBorder - leftBorder > -1) {
		cout << leftBorder + 1 << " " << rightBorder - 1 << endl;
	}
	else {
		cout << -1 << " " << -1 << endl;
	}

	return 0;
}


class Solution_1 {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int leftBorder = Dichotomy_Left(nums, target);
		int rightBorder = Dichotomy_Right(nums, target);
		if (leftBorder == -2 || rightBorder == -2) return { -1, -1 };
		if (rightBorder - leftBorder > 1) return { leftBorder + 1, rightBorder - 1 };
		return { -1, -1 };
	}
private:
	int Dichotomy_Right(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		int rightBorder = -2; 
		while (left <= right) {
			int middle = left + ((right - left) / 2);
			if (nums[middle] > target) {
				right = middle - 1;
			}
			else { 
				left = middle + 1;
				rightBorder = left;
			}
		}
		return rightBorder;
	}
	int Dichotomy_Left(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		int leftBorder = -2; 
		while (left <= right) {
			int middle = left + ((right - left) / 2);
			if (nums[middle] >= target) { 
				right = middle - 1;
				leftBorder = right;
			}
			else {
				left = middle + 1;
			}
		}
		return leftBorder;
	}
};

class Solution_2 {
	int Dichotomy(vector<int>& nums, int target, bool flag)
	{
		int left = 0, right = nums.size() - 1, middle, res = -1;
		while (left <= right)
		{
			middle = left + (right - left) / 2;
			// 'left + right' may cause the Integer Overflow, meaning that left+right > 2147483647
			// so we use 'left + (right - left) / 2'
			if (nums[middle] == target)
			{
				res = middle;
				if (flag)
					right = middle - 1; //flag为真，求左区间
				else
					left = middle + 1; //flag为假，求右区间
			}
			else if (nums[middle] < target)
				left = middle + 1;
			else
				right = middle - 1;
		}
		return res;
	}
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = Dichotomy(nums, target, true);
		int right = Dichotomy(nums, target, false);
		if (nums.empty() || (left == -1 && right == -1))
			return vector<int>{-1, -1};
		else if (left == -1)
			left = right;
		else if (right == -1)
			right = left;
		else
			;

		return vector<int>{left, right};
	}
};