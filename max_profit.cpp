class solution{
public:
int maxprofit(vector<int>& prices){
int profit=0;
int mini=prices[0];
for(int i=0;i<prices.size();i++){
int diff=prices[i]-mini;
profit=max(diff,profit);
mini=min(mini,prices[i]);
}
return profit;
}
}
