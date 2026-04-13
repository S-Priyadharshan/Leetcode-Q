class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res=new ArrayList<>();
        combinations(res,0,0,n,"");
        return res;
    }
    public void combinations(List<String>res,int left,int right,int n,String curr){
        if(curr.length()==2*n){
            res.add(new String(curr));
            return;
        }
        if(left<n){
            combinations(res,left+1,right,n,curr+"(");
        }
        if(right<left){
            combinations(res,left,right+1,n,curr+")");
        }
    }
}