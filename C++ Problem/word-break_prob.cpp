#include<bits/stdc++.h>
using namespace std;
bool CanParseUtil(unordered_map<string, bool>mp, string word){

    int size = word.size();
    if(size == 0){
        return true;
    }
    string temp = "";
    for(int i = 0; i < word.length(); i++){
        temp += word[i];
        
        if(mp.find(temp) != mp.end() && CanParseUtil(mp, word.substr(i+1))){
            return true;
        }
    }
    return false;
}
string CanParse(vector<string>words, string word){
    int start = 0;
    
    unordered_map<string, bool>mp;
    for(auto it : words){
        mp[it] = true;
    }
    return CanParseUtil(mp,word ) == true ? "YES" : "NO";
}
 
 
int main() {
    vector<string>words{"mobile","samsung","sam","sung","man","mango","icecream","and","go","i","like","ice","cream"};
    string word = "samsungandmangok";
    cout << CanParse(words, word) << endl;
}