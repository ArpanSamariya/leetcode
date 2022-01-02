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
