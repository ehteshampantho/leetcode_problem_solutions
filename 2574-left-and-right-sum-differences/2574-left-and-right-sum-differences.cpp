class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> leftSum(n);
        leftSum[0] = 0;
        for(int i=1;i<n;i++){
            leftSum[i] = nums[i-1] + leftSum[i-1];
        }
        
        vector<int> rightSum(n);
        rightSum[n-1] = 0;
        for(int i=n-2; i>=0 ;i--){
            rightSum[i] = nums[i+1] + rightSum[i+1];    
        }
        
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i] = abs(leftSum[i]-rightSum[i]);
        }
        return v;
    }
};