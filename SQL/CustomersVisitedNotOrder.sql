# Write your MySQL query statement below

# Write an SQL query to find the IDs of the users who visited without making any transactions and the number of times they made these types of visits.

# Return the result table sorted in any
SELECT customer_id, COUNT(Visits.visit_id) AS 'count_no_trans'
FROM Visits
WHERE Visits.visit_id NOT IN(
SELECT Visits.visit_id
FROM Visits
JOIN Transactions
    ON Visits.visit_id = Transactions.visit_id
)
GROUP BY customer_id;