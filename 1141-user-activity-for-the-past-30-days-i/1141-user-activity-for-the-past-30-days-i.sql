# Write your MySQL query statement below



select outter.activity_date as day ,count(distinct outter.user_id) as active_users 
from (select *
from Activity as a
where DATEDIFF('2019-07-27', a.activity_date) BETWEEN 0 AND 29) as outter
group by outter.activity_date