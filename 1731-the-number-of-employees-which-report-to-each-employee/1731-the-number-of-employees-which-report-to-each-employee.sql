# Write your MySQL query statement below
SELECT
    e.employee_id,
    e.name,
    COUNT(*) AS reports_count,
    ROUND(AVG(m.age)) AS average_age
FROM Employees e
JOIN Employees m
    ON e.employee_id = m.reports_to
GROUP BY e.employee_id, e.name
ORDER BY e.employee_id;