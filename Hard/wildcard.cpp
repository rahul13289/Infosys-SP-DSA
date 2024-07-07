class wildcard{

    public:
/*You are required to complete this method*/
    int wildCard(string pattern, string str) {
        
        int s = str.size();
        int p = pattern.size();
        
        
        vector<vector<bool>> dp(s + 1 , vector<bool>(p + 1 , false));
        
        
        dp[0][0] = true;
        
        
        for(int pat = 1; pat <= p; pat++){
            
            if(pattern[pat - 1] == '*'){
                
                dp[0][pat] = dp[0][pat - 1];
                
            }
        }
        
        
        for(int strg = 1; strg <= s; strg++)
        {
            for(int pat = 1; pat <= p; pat++)
            {
                if(pattern[pat - 1] == '?' || str[strg - 1] == pattern[pat - 1])
                {
                    dp[strg][pat] = dp[strg - 1][pat - 1];
                }
                 else if(pattern[pat - 1] == '*')
                 {
                     dp[strg][pat] = dp[strg][pat - 1] || dp[strg - 1][pat];
                 }
            }
        }
        
        return dp[s][p];
    }
};
