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
        // map<int,int> mp;
        // for(auto i : intervals){
        //     mp[i.start]++;
        //     mp[i.end]--;
        // }
        // int count=0,res=0;
        // for(auto i : mp){
        //   count+=i.second;
        // //   cout<<count<<" ";
        //   res=max(res,count);
        // }

        // return res;

        // priority_queue<int,vector<int>,greater<int>> minHeap;
        // sort(intervals.begin(),intervals.end(),[](Interval a, Interval b){
        //     return a.start<b.start;
        // });

        // for(auto i : intervals){
        //     if(!minHeap.size() || minHeap.top()>i.start){
        //         minHeap.push(i.end);
        //     }
        //     else{
        //         minHeap.pop();
        //         minHeap.push(i.end);
        //     }  
        // }

        // return minHeap.size();

        vector<int> start;
        vector<int> end;

        for(auto i : intervals){
            start.push_back(i.start);
            end.push_back(i.end);
        }

        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        int s=0,e=0;
        int n = start.size(),res=0,count=0;
        while(s<n && e<n){
            if(end[e]>start[s]){
              count++;
              s++;
            }
            else{
                count--;
                e++;
            }
            // cout<<count<<" ";
            res=max(count,res);
        }
        return res;
    }
};
