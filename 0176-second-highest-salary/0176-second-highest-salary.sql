# Write your MySQL query statement below
SELECT (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1
) AS SecondHighestSalary;

-- SELECT MAX(salary) AS SecondHighestSalary
-- FROM Employee
-- WHERE salary < (SELECT MAX(salary) FROM Employee);

-- SELECT (
--     SELECT DISTINCT salary
--     FROM (
--         SELECT 
--             salary,
--             DENSE_RANK() OVER (ORDER BY salary DESC) as rnk
--         FROM Employee
--     ) AS RankedSalaries
--     WHERE rnk = 2
-- ) AS SecondHighestSalary;