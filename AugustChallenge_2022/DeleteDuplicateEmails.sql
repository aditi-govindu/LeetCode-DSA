# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below

# Q196. Description: Write an SQL query to delete all the duplicate emails, keeping only 1 unique email with smallest id

DELETE p1 FROM Person p1, Person p2
WHERE p1.email = p2.email AND p1.id > p2.id;
