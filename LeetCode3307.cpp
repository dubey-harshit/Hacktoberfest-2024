class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        char ans = 'a';
        long long p = k-1; //k-1 for indexing purposes
        vector<int> s; //contains the binary vector of k-1
        while(p > 0){ //creating the binary vector
            s.push_back(p%2);
            p = p/2;
        }
        // for(auto elem : s)cout << elem << " ";;
        // cout << endl;
        for(long long x = 0 ; x < s.size() ; x++){ //if you observe the character being updated, you can observe that for the required position if the binary digit is 1 then the operation happens else it doesn't
            if(s[x] == 1){
                if(operations[x] == 1)ans = (ans-'a'+1)%26 + 'a';
            }
        }
        return ans;
    }
};
