#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>&v, int k)
{
    unordered_map<int,int>mp;
    int presum=0,cnt=0;
    mp[0]=1;
    for(int i=0;i<v.size();i++){
        presum+=v[i];
        int remov = presum-k;
        cnt+=mp[remov];
        mp[presum]+=1;
        cout<<mp[remov]<<" ";
    }
    cout<<endl;
    for(auto x : mp){
        cout<<x.first<<" "<<x.second<<endl;
    }
    return cnt;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int k;
    cin>>k;
    cout<<subarraySum(v,k)<<endl;
    return 0;
}
/**

10
1 2 3 -3 1 1 1 4 2 -3
3

*/
