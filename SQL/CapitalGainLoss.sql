# Write an SQL query to report the Capital gain/loss for each stock.

# The Capital gain/loss of a stock is the total gain or loss after buying and selling the stock one or many times.

# Return the result table in any order.

SELECT t1.stock_name AS stock_name, SUM(t1.price) AS capital_gain_loss FROM 
(SELECT stock_name,operation_day,
CASE
    WHEN operation = 'Buy' then -price
    ELSE price
END AS price
FROM Stocks) t1 
GROUP BY stock_name;