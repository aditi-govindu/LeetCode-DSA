'''
Q826. Description: You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:

difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
Every worker can be assigned at most one job, but one job can be completed multiple times.

For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
Return the maximum profit we can achieve after assigning the workers to the jobs.
'''

class Solution(object):
    def maxProfitAssignment(self, difficulty, profit, worker):
        # Map difficulty to profit for every job
        jobs = zip(difficulty, profit)
        jobs.sort()

        ans = 0
        i = 0
        best = 0

        worker.sort()

        # Process jobs in least to most skill order
        for skill in worker:
            # Find max profit to do a job with current skill
            while i < len(jobs) and skill >= jobs[i][0]:
                best = max(best, jobs[i][1])
                i += 1
            ans += best
        return ans