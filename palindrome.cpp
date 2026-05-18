#include<iostream>
#include<algorithm>
using namespace std;
class Solution{
public:
bool isPalindrome(int x){
if(x<0){
return false;
}
int original=x;
long long rev=0;
while(x>0){
int digit=x%10;
rev=rev*10+digit;
x/=10;
}
return original==rev;
}
};
int main(){
int x;
cin>>x;
Solution s;
if(s.isPalindrome(x)){
cout<<"palindrome"<<endl;
}
else{
cout<<"not paindrome"<<endl;
}
return 0;
}




