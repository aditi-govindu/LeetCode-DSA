'''
Q649. Description: In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.
Announce the victory: If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.
Given a string senate representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party. Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party. Predict which party will finally announce the victory and change the Dota2 game. The output should be "Radiant" or "Dire".
'''

class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        senate = list(senate)
        # Count no. of members of Radiant and Dire
        r_count = senate.count('R')
        d_count = len(senate) - r_count

        def ban(to_ban, start_at):
            loop_around = False
            pointer = start_at

            while True:
                # If at start of list, loop around is valid
                if pointer == 0:
                    loop_around = True
                # If pointer at opponent, remove them from voting
                if senate[pointer] == to_ban:
                    senate.pop(pointer)
                    break
                # Wrap the pointer around
                pointer = (pointer + 1) % len(senate)
            return loop_around
        
        turn = 0
        while r_count > 0 and d_count > 0:
            # Radiant will try to remove Dire
            if senate[turn] == 'R':
                ban_before = ban('D', (turn + 1) % len(senate))
                d_count -= 1
            else:
                # Dire will try to remove radiant
                ban_before = ban('R', (turn + 1) % len(senate))
                r_count -= 1
            if ban_before:
                turn -= 1
            # Wrap around the list
            turn = (turn + 1) % len(senate)
        return 'Radiant' if d_count == 0 else  'Dire'
