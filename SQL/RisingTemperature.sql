# Write your MySQL query statement below

# Write an SQL query to find all dates' Id with higher temperatures compared to its previous dates (yesterday).

# Return the result table in any order.

SELECT w2.id AS 'Id'
FROM Weather w1
INNER JOIN
Weather w2 ON DATEDIFF(w2.recordDate, w1.recordDate) = 1
AND (w2.Temperature > w1.Temperature);