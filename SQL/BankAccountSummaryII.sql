# Write your MySQL query statement below
# Q1587. Description: Write an SQL query to report the name and balance of users with a balance higher than 10000. The balance of an account is equal to the sum of the amounts of all transactions involving that account.

# Return the result table in any order.

SELECT Users.name, SUM(Transactions.amount) AS 'balance'
FROM Transactions
JOIN Users ON Users.account = Transactions.account
GROUP BY Transactions.account
HAVING SUM(Transactions.amount) > 10000;