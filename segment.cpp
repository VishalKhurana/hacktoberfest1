#include<bits/stdc++.h>
using namespace std;
void build_tree(vector<int>&arr,vector<int>&seg,int low,int high,int pos)
{
    if(low==high)
    {
        seg[pos]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build_tree(arr,seg,low,mid,2*pos+1);
    build_tree(arr,seg,mid+1,high,2*pos+2);
    seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
    return;
}
int query(int qlow,int qhigh,int low,int high,vector<int>&seg,int pos)
{
    if(qlow<=low&&qhigh>=high)
    {
        //cout<<"hi"<<endl;
        return seg[pos];
    }
    if(qlow>high||qhigh<low)
    {
        return INT_MAX;
    }
    int mid=(low+high)/2;
    return min(query(qlow,qhigh,low,mid,seg,2*pos+1),query(qlow,qhigh,mid+1,high,seg,2*pos+2));
}
 int nextPowerOf2( int n)  
{  
    int count = 0;  
      
  
    if (n && !(n & (n - 1)))  
        return n;  
      
    while( n != 0)  
    {  
        n >>= 1;  
        count += 1;  
    }  
      
    return 1 << count;  
}  
int main()
{
    vector<int>arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        arr.push_back(val);
    }
    int pro=nextPowerOf2(n);
    //cout<<pro<<endl;
    int size=2*pro-1;
    
    vector<int>seg(size,INT_MAX);
    build_tree(arr,seg,0,size,0);
    int ans=query(0,n-1,0,size,seg,0);
    cout<<ans<<endl;
    return 0;
}
