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

