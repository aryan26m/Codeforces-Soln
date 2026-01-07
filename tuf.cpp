class Solution {
public:
    int singleNumber(vector<int>& nums) {        
        //your code goes here 
        int n=nums.size();
        int ans[2];
        int x=0;
        for(int i=0;i<n;i++){
            x=x^nums[i];
        }
        int right=(x&(x-1))^x;
        int ans1=0;
        int ans2=0;
        for(int i=0;i<n;i++)
        {
            if((nums[i]&right)){
                ans1^=nums[i];
            }
            else{
                   ans2^=nums[i];
            }
        } 
    
        if(ans1<ans2){
            ans[0]=ans1;
            ans[1]=ans2;
        }else{
               ans[1]=ans1;
            ans[0]=ans2;
        }
        return ans;
    }
};