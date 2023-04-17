/*
Q1201. Description: An ugly number is a positive integer that is divisible by a, b, or c.

Given four integers n, a, b, and c, return the nth ugly number.
*/

typedef long long ll;
#define BIG 2e9

class Solution {
public:
    ll GCD(ll a, ll b)
    {
        if(a == 0)
            return b;
        return GCD(b % a, a);
    }

    ll LCM(ll a, ll b)
    {
        return (a*b) / GCD(a, b);
    }

    int count(ll n, ll a, ll b, ll c)
    {
        return (int) ((n/a) + (n/b) + (n/c) - n/LCM(a,b) - n/LCM(b,c) - n/LCM(a,c) + n / (LCM(a, LCM(b, c))));
    }

    int nthUglyNumber(int n, int a, int b, int c) 
    {
        int low = 0;
        int high = BIG;
        int ans = 0;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(count(mid, a, b, c) >= n)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};