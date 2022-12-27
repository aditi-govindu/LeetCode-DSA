'''
Q299. Description: You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

* The number of "bulls", which are digits in the guess that are in the correct position.
* The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.

Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.
The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.
'''

class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        x = 0
        y = 0
        subs = 0
        bucket = [0]*10
        # Count no. of bulls matching correct digits
        for index, bull in enumerate(secret):
            if guess[index] == bull:
                x += 1
            else:
                # Increment mismatched digit count
                bucket[(int)(bull)] += 1
                bucket[(int)(guess[index])] -= 1
        for val in bucket:
            if(val > 0):
                subs += val
        y = len(secret)-x-subs
        return str(x)+"A"+str(y)+"B"