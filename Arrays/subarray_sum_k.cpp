#better solution
#time complexity=o(n*2)
#space complexity=o(1)

----------#code---------


class solution{
public:
int subarray(vector<int>& nums,int k){
int n=nums.size();
int count=0;
for(int i=0;i<n;i++){
int sum=0;
for(j=i;j<n;j++){
sum+=nums[j];
if(sum==k){
count++;
}
}
}
return count;
}
};
