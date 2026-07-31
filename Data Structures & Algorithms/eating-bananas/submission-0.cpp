class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // notes
        // brute force
        // for range 1 to m (m being the maximum bananas in the array)
        // calculate hours it would take to finish total
        // to finish a given pile, it takes (piles[i] + k - 1) / k hours
        // repeat this until we have find an eating rate such that total_hours < h

        // where can we optimize?
        // can we restrict our choices of k?
        // we can binary search through options of k
        // pick k = piles.size() / 2
        // if k_h is greater than h, we can make it smaller
        int hours, k;
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        while (l <= r) {
            k = (l + r) / 2;

            hours = 0;
            for (int pile : piles) {
                hours += (pile + k - 1) / k;
            }
            if (hours > h) {
                l = k + 1;
            }
            else {
                res = k;
                r = k - 1;
            }
        }
        return res;
    }
};
