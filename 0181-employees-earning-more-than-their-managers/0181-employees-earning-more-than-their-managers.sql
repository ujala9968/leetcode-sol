# Write your MySQL query statement below
select e.name as Employee
from Employee e 
LEFT join Employee x
On e.managerId = x.id
WHERE e.salary > x.salary