
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1];
             });

        int units = 0;

        for (int i = 0; i < boxTypes.size(); i++) {
            int boxes = min(boxTypes[i][0], truckSize);

            units += boxes * boxTypes[i][1];
            truckSize -= boxes;

            if (truckSize == 0) {
                break;
            }
        }

        return units;
    }
};
