#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
/****
	* 1. ����֮��
	* ��Ŀ������һ��target������nums���������������֮��Ϊtarget������Ԫ�ص�λ�ã�һ��Ԫ��ֻ��ʹ��һ�Σ�
	* ˼·��һ��ʼ���������ֵķ����룬�������ٽ��λ�á�
			�ı�˼·����������headָ���tailָ����б�������head+tail>target,��tail--,����head++�����Ӷ�O��nlogn)
	  Tips�����������Ԫ��λ�÷����ı䣬Ҫcopyһ��ԭ������ܷ���Ԫ����ԭ�����е�λ�á�
	  ��n������ˢ�ĵ�һ���㷨�⣬WA��3�Σ�д��һ��Сʱ���ң���Ȼ���ǲ���^-^��
	*
*/
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int>result, copy;
		copy = nums;
		sort(nums.begin(), nums.end());
		int head = 0;
		int tail = nums.size() - 1;
		while (head < tail) {
			if (nums[head] + nums[tail] == target) {
				break;
			}
			else if (nums[head] + nums[tail] < target) {
				head++;
			}
			else {
				tail--;
			}
		}
		auto iter = find(copy.begin(), copy.end(), nums[head]);
		int a = iter - copy.begin();
		iter = find(copy.begin(), copy.end(), nums[tail]);
		if (nums[head] == nums[tail]) {
			iter = find(iter+1, copy.end(), nums[tail]);
		}
		int b = iter - copy.begin();
		result.push_back(a);
		result.push_back(b);
		return result;
	}
};
int main()
{
	Solution solution;
	vector<int>nums, result;
	int x, target;
	for (int i = 0;i < 2;i++) {
		scanf("%d", &x);
		nums.push_back(x);
	}
	scanf("%d", &target);
	result = solution.twoSum(nums, target);
	for (const auto& value : result) {
		printf("%d ", value);
	}
	return 0;
}