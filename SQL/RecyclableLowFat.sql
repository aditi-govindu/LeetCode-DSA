# Write an SQL query to find the ids of products that are both low fat and recyclable.

# Return the result table in any order.
# low_fats is an ENUM of type ('Y', 'N') where 'Y' means this product is low fat and 'N' means it is not.
# recyclable is an ENUM of type ('Y', 'N') where 'Y' means this product is low fat and 'N' means it is not.

# Write your MySQL query statement below
SELECT product_id 
FROM Products
WHERE low_fats = 'Y' AND recyclable = 'Y';