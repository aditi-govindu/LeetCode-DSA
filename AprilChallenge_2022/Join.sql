# Q175. Description: Combine Person and Address tables on personId
# Person schema = personId, lastname, firstname
# Address schema = addressId, personId, city, state
# Write an SQL query to report the first name, last name, city, and state of each person in the Person table. If the address of a personId is not present in the Address table, report null instead.
# Return the result table in any order.


# Write your MySQL query statement below
SELECT firstname, lastname, city, state FROM 
Person p LEFT JOIN Address a
ON p.personId = a.personId;