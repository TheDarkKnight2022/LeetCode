#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

//�����ƽ����޷���ֵ
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

// ���ֲ��ң�Ѱ��target����߽�leftBorder��������target��
// ���leftBorderû�б���ֵ����target�����鷶Χ���ұߣ���������[3,3],targetΪ4����Ϊ�˴������һ
int Dichotomy_Left(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	int leftBorder = -2; // ��¼leftBorderû�б���ֵ�����
	while (left <= right) {
		int middle = (left + right) / 2;
		if (nums[middle] >= target) { // Ѱ����߽磬��Ҫ��nums[middle] == target��ʱ�����right
			right = middle - 1;
			leftBorder = right;
		}
		else {
			left = middle + 1;
		}
	}
	return leftBorder;
}

// ���ֲ��ң�Ѱ��target���ұ߽磨������target��
// ���rightBorderΪû�б���ֵ����target�����鷶Χ����ߣ���������[3,3]��targetΪ2����Ϊ�˴������һ
int Dichotomy_Right(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	int rightBorder = -2; // ��¼rightBorderû�б���ֵ�����
	while (left <= right) {
		int middle = (left + right) / 2;
		if (nums[middle] > target) {
			right = middle - 1; // target �������䣬����[left, middle - 1]
		}
		else { // ��nums[middle] == target��ʱ�򣬸���left���������ܵõ�target���ұ߽�
			left = middle + 1;
			rightBorder = left;
		}
	}
	return rightBorder;
}

//��Ȼһ�����ֲ��ܷ������飬Ϊʲô��������������Ѱ����߽���ұ߽��أ�
int main()
{
	int arr[] = { 5, 7, 7, 8, 8, 10 };
	int target = 8;
	vector<int> nums;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		nums.push_back(arr[i]);
	}

	//Solution_Violence(nums, target);//�������

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
					right = middle - 1; //flagΪ�棬��������
				else
					left = middle + 1; //flagΪ�٣���������
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