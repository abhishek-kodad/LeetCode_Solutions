class Solution {
public:
    int countPrimes(int n) {
        //Use sieve method to solve
        if (n<=2) return 0;
        
        int&& n_2=n>>1;
        vector<bool> oddPrime(n_2, 1);
        oddPrime[0]=0;
        int&& n_2sqrt=int(sqrt(n)/2);
        for(int&& i=1; i<=n_2sqrt; i++)
        {
            if (oddPrime[i])
            {
                int&& p=2*i+1;
                for(int j=p*p/2 ; j<n_2; j+=p)
                    oddPrime[j]=0;
            }
        }
        int result=0;
        for(bool b: oddPrime)
            if (b) result++;
        result++;
        return result;
    }
};