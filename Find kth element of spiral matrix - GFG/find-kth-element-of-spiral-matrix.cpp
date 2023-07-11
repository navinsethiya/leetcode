//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends

class Solution
{
    /*You are required to complete this method*/
    public:
    int findK(int A[MAX][MAX], int n, int m, int k)
    {
	// Your code here	
	int ans = solve(A,0,0,n,m,k);
	return ans;
	
    }

      int solve(int a[MAX][MAX], int i, int j,
                     int n, int m, int k)
    {
        if (n < 1 || m < 1)
            return -1;
 
        /*.....If element is in outermost ring ....*/
        /* Element is in first row */
        if (k <= m)
            return a[i + 0][j + k - 1];
 
        /* Element is in last column */
        if (k <= (m + n - 1))
            return a[i + (k - m)][j + m - 1];
 
        /* Element is in last row */
        if (k <= (m + n - 1 + m - 1))
            return a[i + n - 1][j + m - 1 - (k - (m + n - 1))];
 
        /* Element is in first column */
        if (k <= (m + n - 1 + m - 1 + n - 2))
            return a[i + n - 1 - (k - (m + n - 1 + m - 1))][j + 0];
 
        return solve(a, i + 1, j + 1, n - 2,
                     m - 2, k - (2 * n + 2 * m - 4));
    }
    
    
};



//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends