'''
Q956. Description: You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.

You are given a collection of rods that can be welded together. For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.

Return the largest possible height of your billboard installation. If you cannot support the billboard, return 0.
'''

class Solution(object):

    def tallestBillboard(self, rods):

        # Helper function to collect every combination `(left, right)`
        def helper(half_rods):
            states = set()
            states.add((0, 0))

            for r in half_rods:
                new_states = set()

                for left, right in states:
                    # For every rod, find its pair such that left + right = 0
                    new_states.add((left + r, right))
                    new_states.add((left, right + r))
                # Union of states and new_states before going to next rod
                states |= new_states

            dp = {}
            for left, right in states:
                # Hashmap to store maximum unique pair of left, right
                dp[left - right] = max(dp.get(left - right, 0), left)
            return dp

        n = len(rods)
        # Split rods into 2 parts to meet in the middle
        first_half = helper(rods[:n // 2])
        second_half = helper(rods[n // 2:])
        answer = 0

        for diff in first_half:
            if -diff in second_half:
                answer = max(answer, first_half[diff] + second_half[-diff])

        return answer