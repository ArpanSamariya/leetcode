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
## Rank

//get rank of each row in table using 


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
