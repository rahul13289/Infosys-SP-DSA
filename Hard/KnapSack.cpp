class KnapSack{
public:
     
     int knapSack(int W, int wt[], int val[], int n){ 
       
       vector<int> prev(W + 1, 0);
       
       // Step 1: Base cases
       for(int i = wt[0]; i <= W; i++) 
       
            prev[i] = val[0];
       
       // Step 2: Represent all the states
       
       for(int CI = 1; CI < n; CI++){
           
           for(int i = W; i >= 0; i--){
               
               // Step 3: Copy recursion
              
               int right = 0 + prev[i];
               int left = INT_MIN;
              
               if(wt[CI] <= i) 
               
                  left = val[CI] + prev[i - wt[CI]];
               
               prev[i] = max(left , right);
               
               
           }
       }
       
       
       return prev[W];
       
    }

};
