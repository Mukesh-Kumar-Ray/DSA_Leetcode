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


-- with cte as (
--     (
--         select requester_id as id, count(requester_id) as partial_count
--         from RequestAccepted
--         group by requester_id
--     )
--     union all
--     (
--         select accepter_id as id, count(accepter_id) as partial_count
--         from RequestAccepted
--         group by accepter_id
--     )
-- )

-- select id, sum(partial_count) as num
-- from cte
-- group by id
-- order by num desc
-- limit 1;