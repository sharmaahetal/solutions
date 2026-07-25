/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        //sort by start time
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){
            return a.start < b.start;
        });
        if(intervals.empty()){
            return 0;
        }
        //min heap --> ending time of ongoing meetings
        priority_queue<int, vector<int>, greater<int>> pq;
        //first meeting
        pq.push(intervals[0].end);

        for(int i=1; i<intervals.size(); i++){
            //if earliest ending meeting has finished --> reuse the room
            if(pq.top() <= intervals[i].start){
                pq.pop();
            }
            //allocate the curr meeting a room 
            pq.push(intervals[i].end);
        }
        //return rooms required
        return pq.size();
    }
};
