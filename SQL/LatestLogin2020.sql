# Write your MySQL query statement below
# Q1890. Description: Write an SQL query to report the latest login for all users in the year 2020. Do not include the users who did not login in 2020.
# Return the result table in any order.

SELECT user_id, MAX(time_stamp) As 'last_stamp'
FROM Logins
# WHERE (time_stamp <= '2020-12-31' AND time_stamp >= '2020-01-01')
WHERE time_stamp LIKE "%2020%"
GROUP BY user_id;