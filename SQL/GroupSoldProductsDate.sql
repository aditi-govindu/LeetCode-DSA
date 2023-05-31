# Write your MySQL query statement below

# Write an SQL query to find for each date the number of different products sold and their names.

# The sold products names for each date should be sorted lexicographically.

# Return the result table ordered by sell_date.

SELECT sell_date, COUNT(sell_date) AS 'num_sold', 
GROUP_CONCAT(product ORDER BY product) AS 'products'
FROM (
    SELECT * 
    FROM Activities
    GROUP BY sell_date, product
    ) act
GROUP BY act.sell_date
ORDER BY act.sell_date;