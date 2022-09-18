vector<vector<int> ans(vector<int> &A,bool b[])
{   vector<vector<int>> a;
    for(int i=0;i<A.size();i++)
    {
        if(!b[i])
        {
            b[i]=true;
            vector<vector<int>> x=ans(A,b);
           for(int j=0;j<x.size();j++)
           {
               x[j].push_back(A[i]);
               a.push_back(x[j]);
           } 
           b[i]=false;
        }
    } 
    vector<int> e;
    if(a.size()==0)
    a.push_back(e); 
    
    return a;

}
vector<vector<int> > Solution::permute(vector<int> &A) {
    bool b[A.size()];
    memset(b,false,sizeof(b));
    return q(A,b);
}
