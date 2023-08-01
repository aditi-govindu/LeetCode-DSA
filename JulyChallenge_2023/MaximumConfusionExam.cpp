/*
Q2024. Description: A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).

You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:

Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.
*/

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) 
    {
        // Binary search to find middle of the list
        int n = answerKey.length();
        int left = k;
        int right = n;

        while(left < right)
        {
            // If mid is valid, continue searching
            int mid = (left + right + 1) / 2;
            if(isValid(answerKey, mid, k))
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }

    bool isValid(string answerKey, int size, int k)
    {
        int n = answerKey.length();
        unordered_map<char, int> counter;

        for(int i = 0; i < size; i++)
        {
            char c = answerKey[i];
            counter[c]++;
        }

        // No. of true, false less than k hence swaps can be made
        if(min(counter['T'], counter['F']) <= k)
            return true;
        
        for(int i = size; i < n; i++)
        {
            // Check if window size is valid by moving left and right boundaries
            char c1 = answerKey[i];
            counter[c1]++;
            char c2 = answerKey[i - size];
            counter[c2]--;

            if(min(counter['T'], counter['F']) <= k)
                return true;
        }

        return false;
    }
};