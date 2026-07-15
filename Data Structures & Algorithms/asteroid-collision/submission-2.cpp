class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> s;
        vector<int> res;
        for(int i=0;i<ast.size();i++){
            if(ast[i]>0){
                s.push(ast[i]);
            }
            else{
                bool equal=0;
                while(!s.empty() && abs(ast[i])>abs(s.top())){
                    s.pop();
                }
                if(!s.empty() && abs(ast[i])==abs(s.top()))
                 s.pop();
                else if(s.empty()){
                    res.push_back(ast[i]);
                } 
            }
        }
        int i = res.size();
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        
        reverse(res.begin()+i,res.end());
        return res;
    }
};