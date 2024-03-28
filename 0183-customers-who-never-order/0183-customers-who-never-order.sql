# Write your MySQL query statement below

SELECT Cus.name AS Customers
FROM CUSTOMERS AS Cus
    LEFT JOIN Orders AS Ord
    ON Cus.id = Ord.customerId
WHERE Ord.id IS NULL;     