/*
    name: karankulx
    date: 07/03/2023
    Qlink: https://leetcode.com/problems/minimum-time-to-complete-trips/description/
    Companies: Microsoft, Amazon, Meta, Quant
    
    Time Complexity --|--->  m --> totalTrips
                      |      k --> time taken by each trip 
                      |--->  every time we search for half range --> log(mk) and n lenght of time --> n*O(log(mk))
*/

class Solution {
public:
    bool timeEnough(vector<int>& time, long long givenTime, int totalTrips) {
        long long actualTrips = 0;
        for(auto t : time) {
            actualTrips += givenTime / t;
        }
        return actualTrips >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1;
        long long right = 1LL**max_element(time.begin(), time.end()) * totalTrips;

        while(left < right) {
            long long mid = (left + right) / 2;
            if(timeEnough(time, mid, totalTrips)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};