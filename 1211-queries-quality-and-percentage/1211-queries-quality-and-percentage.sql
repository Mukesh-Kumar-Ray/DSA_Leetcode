# Write your MySQL query statement below
select q.query_name ,ROUND(AVG((q.rating) / NULLIF(q.position, 0)), 2) as quality ,
round(count(( CASE WHEN q.rating < 3 THEN 1 END ))*100/count(q.query_name),2) as poor_query_percentage
from Queries q
group by q.query_name 






