# Write your MySQL query statement below
# Write an SQL query to report the names of the customer that are not referred by the customer with id = 2.
# Note NULL values should also appear

SELECT name
FROM Customer
WHERE referee_id <> 2 OR referee_id IS NULL;