# Write your MySQL query statement below
select contest_id ,ROUND(Count(user_id) * 100 / (select count(*) from users) , 2) as  percentage
from Register 
group by contest_id
order by  percentage DESC,
contest_id;

