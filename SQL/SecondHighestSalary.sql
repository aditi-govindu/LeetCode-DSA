# Write your MySQL query statement below
# Write an SQL query to report the second highest salary from the Employee table. If there is no second highest salary, the query should report null.

SELECT MAX(salary) AS 'SecondHighestSalary' 
FROM Employee 
WHERE salary NOT IN 
(SELECT MAX(salary) FROM Employee);