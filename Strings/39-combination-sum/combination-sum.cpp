class Solution {
public:
void solve(vector<int>& candidates, int target,int idx,vector<int>& curr,vector<vector<int>>& result){
     if(target<0){
        return;
     }
     if(target==0){
        result.push_back(curr);
        return;
     }
     for(int i=idx;i<candidates.size();i++){
        
     
     curr.push_back(candidates[i]);
     solve(candidates,target-candidates[i],i,curr,result);
     curr.pop_back();
}
}
     
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        solve(candidates,target,0,curr,result);
        return result;
    }
};