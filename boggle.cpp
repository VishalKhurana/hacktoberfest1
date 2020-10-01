#include<bits/stdc++.h>

using namespace std;
bool isSafe(int x,int y,int N,int M,vector<vector<bool>>&vis)
{
    if(x>=0&&x<N&&y>=0&&y<M&&!vis[x][y])
    {
        return true;
    }
    return false;
    
}
void dfs(int si,int sj,vector<vector<char>>&board,int N,int M,map<string,bool>&m,vector<string>&res,vector<vector<bool>>&vis,string &ans)
{
     
    //cout<<"hi"<<endl;
    vis[si][sj]=true;
    
    ans=ans+board[si][sj];

    if(m[ans]==true)
    {
        res.push_back(ans);
    }
    
    int row []={-1,-1,0,1,1,1,0,-1};
    int col []={0,1,1,1,0,-1,-1,-1};
    for(int i=0;i<8;i++)
    {
        if(isSafe(si+row[i],sj+col[i],N,M,vis))
        {
            dfs(si+row[i],sj+col[i],board,N,M,m,res,vis,ans);
        }
    }

    ans.erase(ans.length() - 1); 
    vis[si][sj]=false;
    
}
vector<string> boggle(vector<vector<char>>& board,vector<string>& dictionary) {
        map<string,bool>m;
        for(int i=0;i<dictionary.size();i++)
            {
                    m[dictionary[i]]=true;          
                          }
            vector<string>res;
            vector<vector<bool>>vis(board.size(),vector<bool>(board[0].size(),false));
            string ans="";
            for(int i=0;i<board.size();i++)
            {
                for(int j=0;j<board[0].size();j++)
                {
            dfs(i,j,board,board.size(),board[0].size(),m,res,vis,ans);
                }
            }
            cout<<res.size()<<endl;
            sort(res.begin(),res.end());
            return res;
            
    // Your code goes here
}
int main()
{
    int M=3;
    int N=3;
    vector<vector<char>> boggles = { { 'G', 'I', 'Z' }, 
                          { 'U', 'E', 'K' }, 
                          { 'Q', 'S', 'E' } }; 
        vector<string>dictionary = { "GEEKS", "FOR", "QUIZ", "GO" }; 
  
    cout << "Following words of dictionary are present\n"; 
    vector<string> ans=boggle(boggles,dictionary); 
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
