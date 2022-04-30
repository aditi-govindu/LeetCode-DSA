/*
Q535. Description: TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.

There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
*/

class Solution {
public:
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    long long mod = 56800235583;
    unordered_map<string, string> urlMap;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) 
    {
        long long random = rand() % mod;
        // Mod of index by 6^62 to get unique characters
        string tiny = convertToB62(random);
        // While URL found in mapping
        while(urlMap.find(tiny) != urlMap.end())
        {
            random = rand() % mod;
            tiny = convertToB62(random);
        }
        urlMap[tiny] = longUrl;
        return tiny;
    }
    
    string convertToB62(long long num)
    {
        // Find random index and append characters to ans string
        string ans = "";
        while(num)
        {
            int mod = num % 62;
            ans += characters[mod];
            num /= 62;
        }
        return ans;
    }
    
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) 
    {
        return urlMap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));