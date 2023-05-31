# Write your MySQL query statement below

# Write an SQL query to report the distance traveled by each user.

# Return the result table ordered by travelled_distance in descending order, if two or more users traveled the same distance, order them by their name in ascending order.
# The query result format is in the following example.

SELECT Users.name, 
IF(SUM(Rides.distance)>0, SUM(Rides.distance), 0) AS travelled_distance
FROM Users
LEFT JOIN Rides 
ON Users.id = Rides.user_id
GROUP BY user_id
ORDER BY SUM(distance) DESC, name ASC;