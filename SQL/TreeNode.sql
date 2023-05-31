# Write your MySQL query statement below
# Each node in the tree can be one of three types:

# "Leaf": if the node is a leaf node.
# "Root": if the node is the root of the tree.
# "Inner": If the node is neither a leaf node nor a root node.
# Write an SQL query to report the type of each node in the tree.

# Return the result table ordered by id in ascending order.

SELECT id, 
    IF(p_id IS null, 
       "Root",
       IF(id IN (SELECT p_id FROM Tree), 'Inner', 'Leaf'))
       AS 'type'
    FROM Tree
ORDER BY Tree.id;