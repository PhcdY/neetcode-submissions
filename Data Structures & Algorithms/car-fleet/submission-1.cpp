class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, float>> cars(n);
        
        for (int i = 0; i < n; i++) {
            cars[i] = { position[i], (float)(target - position[i]) / speed[i] };
        }

        sort(cars.rbegin(), cars.rend());

        int answer = 0;
        float max_time = 0; // Đóng vai trò như fleets.top()

        for (int i = 0; i < n; i++) {
            // Nếu xe hiện tại tốn nhiều thời gian hơn "kỷ lục" hiện tại -> Nó tạo hạm đội mới
            if (cars[i].second > max_time) {
                max_time = cars[i].second; // Cập nhật kỷ lục thời gian mới
                answer += 1;
            }
        }
        
        return answer;
    }
};