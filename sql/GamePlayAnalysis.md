## 511
* select player_id, min(event_date) as first_login from Activity group by player_id;

## 512
inner join
```
select A.player_id, A.device_id from Activity as A
join 
(
select 
player_id,
min(event_date) as first_login 
from Activity group by player_id
) as B
on
A.player_id = B.player_id
and 
A.event_date = B.first_login;
```
Rank

* select player_id, event_date, device_id,
ROW_NUMBER() over (PARTITION BY player_id ORDER BY event_date) as r
from Activity;

* Use result of inner query:
```
SELECT player_id, device_id
FROM
(SELECT player_id, device_id, event_date,
ROW_NUMBER() OVER (PARTITION BY player_id ORDER BY event_date) AS r
FROM Activity) lookup
WHERE r = 1;
```


## 534
perform aggregation over some rows, these rows are based on the window..
sum...count..max..etc aggregations can be done over window

```
select player_id,
event_date,
sum(games_played) over (
partition by player_id order by event_date) as running_total
from Activity;
```

### 550
```
SELECT ROUND(COUNT(DISTINCT b.player_id)/COUNT(DISTINCT a.player_id),2) AS fraction
FROM
  (SELECT player_id, MIN(event_date) AS event_date FROM Activity
  GROUP BY player_id) a
  LEFT JOIN Activity b
  ON a.player_id = b.player_id AND a.event_date+1 = b.event_date;
```

### 580
* Remember where to put a table i.e left or right as per the ask of the problem,
* handel case when something
```
select d.dept_name, SUM(CASE WHEN student_id IS NULL THEN 0 ELSE 1 END) as student_number from 
department as d
left join 
student as s
on d.dept_id = s.dept_id
group by d.dept_name
order by student_number desc, d.dept_name
```

### 585
```
select sum(tiv_2016) from insurance as ins
inner join
(SELECT  lat, lon, count(1) as cnt from insurance group by lat, lon having cnt = 1) i
on
i.lat = ins.lat
and 
i.lon = ins.lon
inner join
(select tiv_2015, count(tiv_2015) as cnt from insurance group by tiv_2015 having cnt > 1) tiv
on 
tiv.tiv_2015 = ins.tiv_2015
```
lat and lon can also be concatenated to make a single entity!
```
SELECT SUM(TIV_2016) AS TIV_2016
FROM insurance
WHERE CONCAT(LAT, ',', LON)
    IN (SELECT CONCAT(LAT, ',', LON)
       FROM insurance
       GROUP BY LAT, LON
       HAVING COUNT(1) = 1)
AND TIV_2015 in
    (SELECT TIV_2015
    FROM insurance
    GROUP BY TIV_2015
    HAVING COUNT(1)>1)
```
* Use calculated values in having so as to remember concept and column selection in group by, having!

### 586
```
select customer_number from orders group by customer_number order by count(1) desc limit 1;
```
* order by can have calculated values

### 597
```
select IFNULL((round(q/p, 2)), 0.0) AS accept_rate
from
(select count(distinct sender_id, send_to_id) as p from friend_request) as t1,
(select count(distinct requester_id, accepter_id ) as q from request_accepted) as t2
```

### 601
Blog Sol
```
SELECT DISTINCT s1.*
FROM stadium s1 JOIN stadium s2 JOIN stadium s3
ON (s1.id = s2.id-1 AND s1.id = s3.id-2) OR
 (s1.id = s2.id+1 AND s1.id = s3.id-1) OR
 (s1.id = s2.id+1 AND s1.id = s3.id+2)
    WHERE s1.people >= 100 AND s2.people >= 100 AND s3.people>=100
  ORDER BY visit_date
```
My
```
SELECT distinct a.id, a.visit_date, a.people from
stadium a
inner join
(select id from stadium where people > 100) b
on
b.id = a.id + 1
inner join
(select id from stadium where people > 100) c
on
c.id = a.id + 2
where a.people > 100

union 

SELECT distinct a.id, a.visit_date, a.people from
stadium a
inner join
(select id from stadium where people > 100) b
on
b.id = a.id - 1
inner join
(select id from stadium where people > 100) c
on
c.id = a.id + 1
where a.people > 100

union

SELECT distinct a.id, a.visit_date, a.people from
stadium a
inner join
(select id from stadium where people > 100) b
on
b.id = a.id - 1
inner join
(select id from stadium where people > 100) c
on
c.id = a.id - 2
where a.people > 100
```
### 602
```

SELECT t.id, sum(t.num) AS num
FROM (
      (SELECT requester_id AS id, COUNT(1) AS num
       FROM request_accepted
       GROUP BY requester_id)
      union all
       (SELECT accepter_id AS id, COUNT(1) AS num
        FROM request_accepted
        GROUP BY accepter_id)) AS t
GROUP BY t.id
ORDER BY num DESC
LIMIT 1;

```
### 603
```
SELECT distinct t1.seat_id from 
cinema t1
left join
cinema t2
on 
t2.seat_id = t1.seat_id + 1
or
t2.seat_id = t1.seat_id - 1
where 
t1.free = 1 and 
t2.free = 1
order by t1.seat_id
```
blog sol
```

SELECT DISTINCT t1.seat_id
FROM cinema AS t1 JOIN cinema AS t2
ON abs(t1.seat_id-t2.seat_id)=1
WHERE t1.free='1' AND t2.free='1'
ORDER BY t1.seat_id

```
### 607
```
SELECT name from salesperson where sales_id not in (
select sales_id from  
orders 
where 
com_id not in (select com_id from company where name = 'RED')
);
```

### 608
```
select distinct sub.id,
case 
	when sub.root is null then 'Root'
    when sub.flag is not null then 'Inner'
    when sub.flag is null then 'Leaf'
END as type
from (
select a.id, a.p_id as root, b.p_id as flag
from tree a
left join
tree b
on
a.id = b.p_id
  ) sub
 order by sub.id;
```

### 612
```SELECT min(round(sqrt(pow((a.x - b.x),2) + pow((a.y - b.y) ,2)),2)) as dist FROM point_2d as a 
left join 
point_2d b
on
a.x != b.x
or
a.y != b.y
order by dist
limit 1;
```

### 613
```
select min(abs(a.x - b.x)) from point a 
left join 
point b
on
a.x != b.x
```

