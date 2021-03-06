class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        if (nums.size() == 0)
            return res;
        
        vector<int> copy(nums);
        sort(copy.begin(), copy.end());
        int num1, num2;
        findIndex(copy, target, &num1, &num2);
        for (int i = 0; i < nums.size(); ++i) {
            if (num1 == nums[i])
                res[0] = i + 1;
            if (num2 == nums[i])
                res[1] = i + 1;
        }
        if (res[0] > res[1]) {
            res[0] = res[0] ^ res[1];
            res[1] = res[0] ^ res[1];
            res[0] = res[0] ^ res[1];
        }
        return res;
    }
    
    void findIndex(vector<int> &A, int target, int *num1, int *num2) {
        int left = 0, right = A.size() - 1, tmp_sum;
        while (left < right) {
            tmp_sum = A[left] + A[right]; 
            if (tmp_sum < target)
                left++;
            else if (tmp_sum > target)
                right--;
            else {
                *num1 = A[left];
                *num2 = A[right];
                return;
            }
        }
    }
    
};

