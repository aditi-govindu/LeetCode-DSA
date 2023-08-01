'''
Q1125. Description: In a project, you have a list of required skills req_skills, and a list of people. The ith person people[i] contains a list of skills that the person has.

Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill. We can represent these teams by the index of each person.

For example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].
Return any sufficient team of the smallest possible size, represented by the index of each person. You may return the answer in any order.

It is guaranteed an answer exists.
'''

class Solution:
    def smallestSufficientTeam(self, req_skills: List[str], people: List[List[str]]) -> List[int]:
        n = len(people)
        m = len(req_skills)
        skill_id = {}

        for i, skill in enumerate(req_skills):
            skill_id[skill] = i
        # Represent set of people with needed skills
        skills_mask_of_person = [0] * n

        for i in range(n):
            for skill in people[i]:
                skills_mask_of_person[i] |= 1 << skill_id[skill]
        # Bit mask to store smallest team with all necessary skills
        dp = [(1 << n) - 1] * (1 << m)
        dp[0] = 0

        for skills_mask in range(1, 1 << m):
            for i in range(n):
                smaller_skills_mask = skills_mask & ~skills_mask_of_person[i]
                if smaller_skills_mask != skills_mask:
                    people_mask = dp[smaller_skills_mask] | (1 << i)
                    if people_mask.bit_count() < dp[skills_mask].bit_count():
                        dp[skills_mask] = people_mask
        
        answer_mask = dp[(1 << m) - 1]
        ans = []

        for i in range(n):
            if(answer_mask >> i) & 1:
                ans.append(i)
        return ans