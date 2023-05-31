# Write an SQL query to report all customers who never order anything.

# Write your MySQL query statement below
SELECT name AS 'Customers'
FROM customers
WHERE customers.id NOT IN 
(
    SELECT customerId FROM orders
);