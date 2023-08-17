class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>dis(m,vector<int>(n,0));
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(mat[i][j]==0) q.push({i,j});
                else mat[i][j]=-1;
            }
        }
        
        int dx[]={-1,0,0,1};
        int dy[]={0,1,-1,0};
        
        while(!q.empty()){
            
            auto top=q.front();q.pop();
            
            int r=top.first;
            int c=top.second;
                
            for(int i=0;i<4;i++){
                int vr=r+dx[i];
                int vc=c+dy[i];
                
                if(vr>=0 && vr<m && vc>=0 && vc<n && mat[vr][vc]==-1){
                    mat[vr][vc]=mat[r][c]+1;
                    q.push({vr,vc});
                }
            }
        }
        return mat;
    }
};