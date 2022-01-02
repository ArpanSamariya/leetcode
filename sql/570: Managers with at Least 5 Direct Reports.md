## 570: Managers with at Least 5 Direct Reports
Having is used for a dynamic col created from result of some aggregations
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
## Experiment

* Where is for column of table,
* while
* having for aggregate column.
* also where and having can be used together, only thing is where needs to be used before group by!
```
select a.name from Employee a
inner join
(
  select managerId, count(1) as cnt 
  from Employee
  where Department = 'B'
  group by managerId
  having cnt > 1
)b
on
a.id = b.managerId;
```
