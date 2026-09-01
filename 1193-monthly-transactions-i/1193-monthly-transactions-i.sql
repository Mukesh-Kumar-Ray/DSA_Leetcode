# Write your MySQL query statement below


select 
      outter.trns_date as month , 
      outter.country as country ,
      count(outter.trns_date) as trans_count ,
      SUM(CASE WHEN outter.state = 'approved' THEN 1 ELSE 0 END) AS approved_count,
      sum(outter.amount) as trans_total_amount,
      SUM(CASE WHEN outter.state = 'approved' THEN outter.amount ELSE 0 END) AS approved_total_amount
from(select *, DATE_FORMAT(t.trans_date,'%Y-%m' ) as trns_date
from Transactions  t) outter
group by outter.trns_date,outter.country