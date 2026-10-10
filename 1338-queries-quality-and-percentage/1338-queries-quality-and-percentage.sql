# Write your MySQL query statement below
select q.query_name , round(sum(q.rating/q.position)/count(*),2) as quality
, round(avg(q.rating < 3)*100,2) as poor_query_percentage
from Queries as q 
group by query_name 