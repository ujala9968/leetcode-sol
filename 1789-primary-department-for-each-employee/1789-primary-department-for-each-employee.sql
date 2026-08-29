# Write your MySQL query statement below
select employee_id , department_id
from employee
where employee_id IN(
    select employee_id
    from employee
    group by employee_id
    having count(*) =1 
) or primary_flag = 'Y';