-- 고양이와 개는 몇마리 있을까
SELECT ANIMAL_TYPE, count(*) AS count
  FROM ANIMAL_INS
GROUP BY ANIMAL_TYPE