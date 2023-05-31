# Q181. Description: Write an SQL query to find the employees who earn more than their managers.
# Return the result table in any order.

SELECT e1.name AS 'Employee'
FROM employee e1
JOIN employee e2 ON e1.managerId = e2.id
WHERE e1.salary > e2.salary;