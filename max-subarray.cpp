/*Author : Manraj Singh */
#include <bits/stdc++.h>
using namespace std;


// Problem : 	
/* Solution : 	 */
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
        
    //     int i = 0;
    //     int j = 0;
    //     int maxv = INT_MIN;
    //     int sum = 0 , n = nums.size();
        
        
    //    while ( i < n && i <= j && j < n){
           
          
    //        if ( sum < 0 ){
               
              
    //            sum -= nums[i];
               
    //             i++;
              
    //        }
    //        else{
               
    //             sum += nums[j];
    //             maxv = max ( maxv  , sum);
               
    //            j++;
               
    //        }
           
    //        if ( i > j){
               
    //            j = i;
    //        }
    //    }
        
        
    //     return maxv;
        
    // }

    
// };
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int i = 0;
        int j = 0;
        int maxv = INT_MIN;
        int sum = 0 , n = nums.size();
        
        
       while ( i < n && i <= j && j < n){
           
          
            if (sum < 0){
                sum = 0;
            }
           
           sum += nums[j];
           maxv = max ( maxv , sum);
           j++;
           
       }
           
        
            return maxv;
        
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    

    return 0;
}
