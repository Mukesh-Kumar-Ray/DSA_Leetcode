# Write your MySQL query statement below


select round(count(distinct ac.player_id)/(select count(distinct player_id) from Activity),2) as fraction
from Activity ac
where (ac.player_id ,DATE_SUB(ac.event_date , INTERVAL 1 DAY) )
IN (SELECT a.player_id , MIN(a.event_date) as first_login
FROM Activity a
group by a.player_id)