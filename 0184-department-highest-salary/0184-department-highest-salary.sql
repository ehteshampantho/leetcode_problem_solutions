# Write your MySQL query statement below

SELECT dept.name AS Department, emp.name AS Employee, emp.salary AS Salary
FROM Employee AS emp
    JOIN Department AS dept
    ON emp.departmentId = dept.id
WHERE (departmentId,salary) IN (
                        SELECT departmentId,MAX(salary)
                        FROM Employee
                        GROUP BY departmentId
                        );


# SELECT MAX(salary)
# FROM Employee
# GROUP BY departmentId
   