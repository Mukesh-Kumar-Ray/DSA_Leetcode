# Write your MySQL query statement below
-- select dup.employee_id ,dup.department_id 
-- from () as dup
-- group by dup.employee_id 
-- order by dup.pr_num  desc



-- select dup.employee_id ,dup.department_id ,
-- (ROW_NUMBER() over (partition by dup.employee_id order by dup.primary_flag asc)) as order_num
-- from (
-- select *,
--     CASE 
--         WHEN e.primary_flag = 'Y' THEN 1
--         ELSE 0
--     END AS pr_num
-- from Employee  e) as dup
-- where dup.order_num = 1

SELECT employee_id, department_id
FROM (
    SELECT
        dup.employee_id,
        dup.department_id,
        ROW_NUMBER() OVER (
            PARTITION BY dup.employee_id
            ORDER BY dup.pr_num DESC
        ) AS order_num
    FROM (
        SELECT *,
            CASE
                WHEN primary_flag = 'Y' THEN 1
                ELSE 0
            END AS pr_num
        FROM Employee
    ) AS dup
) AS result
WHERE order_num = 1;