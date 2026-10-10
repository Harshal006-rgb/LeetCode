# Write your MySQL query statement below
select DATE_FORMAT(t.trans_date, '%Y-%m') AS month
, t.country 
, count(*) as trans_count 
, sum(t.state = "approved") as approved_count
, sum(t.amount) as trans_total_amount 
, sum(case when t.state = "approved" then t.amount else 0 end ) as approved_total_amount
from Transactions as t
group by DATE_FORMAT(t.trans_date, '%Y-%m') , t.country