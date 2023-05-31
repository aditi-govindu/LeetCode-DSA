# Write your MySQL query statement below

# Q602. Description: Write an SQL query to report the movies with an odd-numbered ID and a description that is not "boring".
# Return the result table ordered by rating in descending order.
# The query result format is in the following example.

SELECT * FROM Cinema
WHERE description <> 'boring' AND id%2 != 0
ORDER BY rating DESC;
