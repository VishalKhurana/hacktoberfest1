#include<bits/stdc++.h>
using namespace std;

int main()
{
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
        int n;
        cin>>n;
        int sum=0;
         int val;
        for(int i=0;i<n;i++)
        {
            int x=0;
            for(int j=0;j<n;j++)
            {
               
                cin>>val;
                if(i!=j)
                {
                x=x|val;
                }
            }
            sum=sum+x;

        }
        cout<<sum<<endl;
    }
