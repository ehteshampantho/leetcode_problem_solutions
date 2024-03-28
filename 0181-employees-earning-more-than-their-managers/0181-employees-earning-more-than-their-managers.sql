# Write your MySQL query statement below

SELECT EMP.name AS Employee
FROM Employee AS EMP, Employee AS MGR
WHERE EMP.managerID = MGR.id AND EMP.salary > MGR.salary;