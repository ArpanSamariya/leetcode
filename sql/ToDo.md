## All Qusetions : https://dsfaisal.com/articles/2020-11-06-leetcode-sql-problem-solving/
## Python Utility : https://github.com/jjjchens235/leetcode-sql-unlocked
## Qusetions
* ![Screenshot from 2022-01-02 23-12-39](https://user-images.githubusercontent.com/25519715/147884603-e33c7e31-e54c-4dfa-92be-2b438bea0ded.png)
* ![Screenshot from 2022-01-02 23-12-54](https://user-images.githubusercontent.com/25519715/147884608-ed628816-6a61-44b0-8c66-62b99b761c24.png)
* ![Screenshot from 2022-01-02 23-13-21](https://user-images.githubusercontent.com/25519715/147884613-2366e944-b508-4692-af02-91d83b365925.png)
* ![Screenshot from 2022-01-02 23-13-22](https://user-images.githubusercontent.com/25519715/147884616-804d14bc-04ba-4b7d-8254-5d0b30490ca6.png)
* ![Screenshot from 2022-01-02 23-15-20](https://user-images.githubusercontent.com/25519715/147884618-bda751ca-2ee4-439c-8c55-124efcf3ec05.png)


### Other IMP Git Repos:
    * https://github.com/mrinal1704/SQL-Leetcode-Challenge/
   

    
### 571: Find Median Given Frequency of Numbers
```

SELECT avg(t3.Number) as median
FROM Numbers as t3
JOIN
    (SELECT t1.Number,
        abs(SUM(CASE WHEN t1.Number>t2.Number THEN t2.Frequency ELSE 0 END) -
            SUM(CASE WHEN t1.Number<t2.Number THEN t2.Frequency ELSE 0 END)) AS count_diff
    FROM numbers AS t1, numbers AS t2
    GROUP BY t1.Number) AS t4
ON t3.Number = t4.Number
WHERE t3.Frequency>=t4.count_diff

```
