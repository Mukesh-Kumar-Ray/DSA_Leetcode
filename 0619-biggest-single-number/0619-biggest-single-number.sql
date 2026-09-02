# Write your MySQL query statement below


select MAX(outter.num) as num
FROM(select *
from MyNumbers mynum
group by mynum.num
having count(mynum.num) = 1) AS outter