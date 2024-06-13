# Write your MySQL query statement below
-- WITH CTE AS
-- (SELECT num, lead(num) over(order by id) as after_num, lag(num) over(order by id) as before_num FROM Logs)

-- SELECT distinct num as ConsecutiveNums FROM CTE WHERE after_num = before_num and num=after_num; 

-- THE above solution would not work as in one of the test cases the Ids are not consecutive numbers. Consecutive appearing means the Id of the Num are next to each others. 

SELECT DISTINCT l1.num as ConsecutiveNums
FROM
    Logs l1,
    Logs l2,
    Logs l3
WHERE
    l1.Id = l2.Id - 1
    AND l2.Id = l3.Id - 1
    AND l1.Num = l2.Num
    AND l2.Num = l3.Num;