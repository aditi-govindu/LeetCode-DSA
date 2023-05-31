# Write your MySQL query statement below
# Write an SQL query to find the daily active user count for a period of 30 days ending 2019-07-27 inclusively. A user was active on someday if they made at least one activity on that day.

SELECT activity_date AS 'day', COUNT(DISTINCT user_id) AS 'active_users'
FROM Activity
WHERE (activity_date > "2019-06-27" AND activity_date <= "2019-07-27")
GROUP BY activity_date;