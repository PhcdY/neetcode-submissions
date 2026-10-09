class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<pair<int,float>> fleets;
        vector<pair<int,float>> cars(position.size());
        int answer=0;


        for (int i=0;i<position.size();i++){
            cars[i] = { position[i], (float)(target - position[i]) / speed[i] };
        }

        sort(cars.rbegin(),cars.rend());

        for(int i=0;i<cars.size();i++){
            if (fleets.empty()||cars[i].second > fleets.top().second){
                fleets.push(cars[i]);
                answer += 1;
            }
        }
    return answer;
    }
};
