# Write your MySQL query statement below
# Write an SQL query to report the names of all the salespersons who did not have any orders related to the company with the name "RED".

SELECT sp.name
FROM SalesPerson sp
WHERE sp.sales_id 
NOT IN (
    SELECT o.sales_id 
    FROM Orders o, Company c
    WHERE c.com_id = o.com_id AND c.name LIKE 'RED');