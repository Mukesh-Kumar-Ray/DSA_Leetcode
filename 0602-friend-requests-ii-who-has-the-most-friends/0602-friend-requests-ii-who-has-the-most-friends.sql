# Write your MySQL query statement below
WITH mrg_data AS(select requester_id ,accepter_id 
from RequestAccepted 

union all

select accepter_id ,requester_id 
from RequestAccepted )

select mrgdata.requester_id as id ,count(mrgdata.requester_id) as num
from mrg_data mrgdata
group by mrgdata.requester_id 
order by num desc 
limit 1
