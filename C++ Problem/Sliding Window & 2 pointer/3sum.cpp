/*Author : Manraj Singh */
#include <bits/stdc++.h>
using namespace std;


// Problem : 	15. 3Sum
/* Solution : 	 Two pointer modified*/
class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
    {

        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int i = 0;
        int j = i + 1;
        int k = n - 1;

        while (i < n)
        {
            j = i + 1;
            k = n - 1;
            while (j < k)
            {

                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    printf("%d %d %d\n", nums[i], nums[j], nums[k]);

                    while (j + 1 < k && nums[j] == nums[j + 1])
                    {

                        j++;
                    }
                    j++;
                }
                else if (sum < 0)
                {

                    j++;
                }
                else
                {

                    k--;
                }
            }

            while (i + 1 < n && nums[i] == nums[i + 1])
            {

                i++;
            }
            

            i++;
        }

        return ans;
    }
};


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    

    return 0;
}
