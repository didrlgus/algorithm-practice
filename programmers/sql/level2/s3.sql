-- 중복 제거하기
SELECT count(*) AS count
  FROM (
    SELECT *
      FROM ANIMAL_INS
     WHERE NAME IS NOT NULL
    GROUP BY NAME) AS A