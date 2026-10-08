class Solution {
public:
    bool isValid(string s) {
        stack<char> cur;

        if (s[0]==')'||s[0]=='}'||s[0]==']'){
            return false;
        }
        else{
            cur.push(s[0]);
        }
        


        for (int i=1;i<s.size();i++){
            if (!(s[i]==')'||s[i]=='}'||s[i]==']')){
                cur.push(s[i]);
            }
            else{
                if(cur.empty()){
                    return false;
                }
                else if (s[i]==']'&& cur.top()=='['){
                    cur.pop();
                    continue;
                }
                else if (s[i]==')'&& cur.top()=='('){
                    cur.pop();
                    continue;
                }
                else if (s[i]=='}'&& cur.top()=='{'){
                    cur.pop();
                    continue;
                }
                else{
                    return false;
                }
            }
        }

        if (cur.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
