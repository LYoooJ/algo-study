-- 코드를 입력하세요
SELECT count(DISTINCT  a.NAME) as count
FROM ANIMAL_INS as a
WHERE a.NAME IS NOT NULL
 