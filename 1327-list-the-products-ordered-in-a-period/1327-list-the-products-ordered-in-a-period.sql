# Write your MySQL query statement below


select p.product_name ,sum(ld.unit) as unit
from (select * , DATE_FORMAT(o.order_date, '%Y-%m') as yrs_mon
from Orders o
where DATE_FORMAT(o.order_date, '%Y-%m') = '2020-02') ld left join
Products p
on ld.product_id = p.product_id
group by p.product_name 
having sum(ld.unit) >= 100