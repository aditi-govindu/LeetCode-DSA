// Q204. Description: Given an integer n, return the number of prime numbers that are strictly less than n.

class Solution {    
    public int countPrimes(int n) {
        boolean[] primes = new boolean[n];
        int count = 0;
        // Initialization
        for(int i = 2; i < n; i++)
            primes[i] = true; 
        for(int i = 2; i*i < n; i++)
        {
            if(!primes[i])
                continue;
            // if multiple of i found, set value to false
            for(int j = i*i; j < n; j += i)
            {
                primes[j] = false;
            }
        }
        // Count no. of true values in primes array
        for(int i = 2; i < n; i++)
        {
            if(primes[i])
                count++;
        }
        return count;
    }
}