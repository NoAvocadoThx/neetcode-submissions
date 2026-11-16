class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;

        for(int i = 0 ;i<position.size();i++)
        {
            cars.push_back({position[i],speed[i]});
        }

        sort(cars.rbegin(), cars.rend());

        vector<double> fleet;
        for(auto& c : cars)
        {
            double time = (double)(target - c.first )/c.second;
            fleet.push_back(time);

            if(fleet.size() >= 2 && fleet.back() <= fleet[fleet.size() - 2]) // fleet back is the left most car fleet so far
            {
                fleet.pop_back();
            }
        }
        return fleet.size();
    }
};

// if the back of the fleet is takes longer than the fleet in front of it, we know those 2 will become a fleet



//[1,2,3,4,5,6,7,8,9,10]
// a     b
// 3     2
//         a   b
//               a b