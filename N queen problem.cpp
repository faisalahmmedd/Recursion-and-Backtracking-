#include<bits/stdc++.h>
#define long long ll
using namespace std;



void solution(int col,vector<string> &board,vector<vector<string>> &ans,int n,vector<int> &leftrow,vector<int> &upperdiag,vector<int> &lowerdiag)
{
    if(col==n)
    {
        ans.push_back(board);
        return;
    }

   for(int row=0; row<n; row++)
   {
       if(leftrow[row]==0 && upperdiag[row+col]==0 && lowerdiag[n-1+col-row]==0)
        {
        board[row][col]='Q';
       leftrow[row]=upperdiag[col+row]=lowerdiag[n-1+col-row]=1;
       solution(col+1,board,ans,n,leftrow,upperdiag,lowerdiag);
       board[row][col]='.';
      leftrow[row]=upperdiag[col+row]=lowerdiag[n-1+col-row]=0;
        }
   }
}

vector<vector<string>> solveNQueen(int n)
{
    vector<vector<string>>  ans;
    vector<string> board(n);

    string s(n,'.');
    for(int i=0; i<n; i++)
    {
        board[i]=s;
    }



    vector<int> leftrow(n,0);
    vector<int> upperdiag((2*n)-1,0);
    vector<int> lowerdiag((2*n)-1,0);

    solution(0,board,ans,n,leftrow,upperdiag,lowerdiag);

    return ans;
}

int main()
{
    int n;
    cin>>n;



    vector<vector<string>> ans=solveNQueen(n);
    cout<<ans.size()<<endl;

    for(auto ss:ans)
    {
        for(auto sss:ss)
        {
            cout<<sss<<endl;
        }
        cout<<endl;
    }



    return 0;
}
