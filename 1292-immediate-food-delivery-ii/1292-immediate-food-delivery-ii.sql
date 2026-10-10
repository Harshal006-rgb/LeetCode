# Write your MySQL query statement below
select round(avg( d.order_date = d.customer_pref_delivery_date)*100,2) as immediate_percentage
from Delivery as d
where (d.customer_id , d.order_date) in
( select customer_id , min(order_date)
  from Delivery
  group by customer_id
)