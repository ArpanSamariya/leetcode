## 570: Managers with at Least 5 Direct Reports
```
select a.name from Employee a
inner join (
  select ManagerId, count(*) as cnt
  from Employee
  group by ManagerId
  having cnt >= 5
) b
on a.id = b.ManagerId;
```

Solution blog
```
SELECT Name
FROM Employee
WHERE id IN
   (SELECT ManagerId
    FROM Employee
    GROUP BY ManagerId
    HAVING COUNT(DISTINCT Id) >= 5)
```
