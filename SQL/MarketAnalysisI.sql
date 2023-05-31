# Write your MySQL query statement below

# Write an SQL query to find for each user, the join date and the number of orders they made as a buyer in 2019.
# Return the result table in any order.
# The query result format is in the following example.

SELECT user_id AS 'buyer_id', join_date, 
SUM(IF(YEAR(order_date) = '2019', 1, 0)) AS 'orders_in_2019'
FROM Users
LEFT JOIN Orders
ON Users.user_id = Orders.buyer_id
GROUP BY Users.user_id;
