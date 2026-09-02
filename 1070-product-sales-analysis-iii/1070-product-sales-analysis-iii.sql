# Write your MySQL query statement below



select outter.product_id , outter.year as first_year , outter.quantity , outter.price
 from (
    select * ,(MIN(sl.year) OVER ( PARTITION BY sl.product_id )) as rn
       from Sales as sl
    )as outter
where rn = outter.year 



