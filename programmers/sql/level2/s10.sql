-- 중성화 여부 파악하기
SELECT ANIMAL_ID, NAME,
        CASE 
          WHEN SEX_UPON_INTAKE like '%Neutered%' OR SEX_UPON_INTAKE like '%Spayed%'
           THEN 'O'
          ELSE 'X'
        END AS 중성화
  FROM ANIMAL_INS
ORDER BY ANIMAL_ID