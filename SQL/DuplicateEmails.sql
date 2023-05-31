# Q182. Description: Write an SQL query to report all duplicate email ids

# Write your MySQL query statement below
SELECT email FROM Person 
GROUP BY email HAVING COUNT(*) > 1;
