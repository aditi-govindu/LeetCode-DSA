# Write your MySQL query statement below
# Write an SQL query that reports the products that were only sold in the first quarter of 2019. That is, between 2019-01-01 and 2019-03-31 inclusive.
# Return the result table in any order.

SELECT Product.product_id, product_name
FROM Product INNER JOIN Sales USING(product_id)
GROUP BY Product.product_id
HAVING SUM(CASE WHEN sale_date BETWEEN '2019-01-01' AND '2019-03-31' 
           THEN 0 
           ELSE 1 
           END) = 0;