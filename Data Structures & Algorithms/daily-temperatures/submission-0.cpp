class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(),0);
        stack<int> temps;

        for (int i=0;i<temperatures.size();i++){


            while(!temps.empty()){
                if(temperatures[i]>temperatures[temps.top()]){
                    result[temps.top()]=i-temps.top();
                    temps.pop();
                    continue;
                }
                else{
                    break;
                }
        
            }
            temps.push(i);

        }
        return result;

    }
};
