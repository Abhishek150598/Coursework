select dept_code, min(basic), max(basic), avg(basic) from emp group by dept_code;

select dept_code, count(emp_code) from emp where sex = 'F' group by dept_code;

select dept_code, city, count(*) from emp group by dept_code, city order by dept_code, city;

select desig_code, count(*) from emp where extract(year from jn_dt)=2000 group by desig_code order by count(*);

select * from (select dept_code, sum(basic) as basic_sum from emp where sex = 'M' group by dept_code) where basic_sum>50000  order by basic_sum desc;

select e.emp_name, d.desig_desc, e.basic from emp e join designation d on e.desig_code = d.desig_code;

select e.emp_name, d.desig_desc, dp.dept_name, e.basic from emp e join designation d on e.desig_code = d.desig_code join department dp on e.dept_code = dp.dept_code;

SELECT D.DEPT_CODE FROM DEPARTMENT D
EXCEPT
SELECT DISTINCT E.DEPT_CODE FROM EMP E;


SELECT DISTINCT D.DEPT_NAME FROM EMP E
LEFT JOIN DEPARTMENT D
ON D.DEPT_CODE = E.DEPT_CODE;

SELECT D.DEPT_NAME,COUNT(EMP_CODE) FROM EMP E
LEFT JOIN DEPARTMENT D
ON D.DEPT_CODE = E.DEPT_CODE
GROUP BY D.DEPT_NAME
HAVING COUNT(EMP_CODE)>=10;

SELECT DEPT_CODE FROM EMP
WHERE BASIC = (SELECT MAX(BASIC) FROM EMP);

SELECT D.DESIG_DESC FROM EMP E
LEFT JOIN DESIGNATION D
ON D.DESIG_CODE = E.DESIG_CODE
WHERE BASIC = (SELECT MAX(BASIC) FROM EMP);

SELECT DEPT_CODE,COUNT(EMP_CODE) AS "NUMBER OF MANAGERS"
FROM EMP
WHERE DESIG_CODE = 'DES01'
GROUP BY DEPT_CODE;

SELECT BASIC FROM EMP
ORDER BY BASIC DESC
LIMIT 1; 

SELECT BASIC FROM EMP
ORDER BY BASIC ASC
LIMIT 1; 

SELECT D.DEPT_NAME FROM EMP E
LEFT JOIN DEPARTMENT D
ON D.DEPT_CODE = E.DEPT_CODE
WHERE BASIC = (SELECT MAX(BASIC) FROM EMP);

SELECT D.DEPT_NAME FROM EMP E
LEFT JOIN DEPARTMENT D
ON D.DEPT_CODE = E.DEPT_CODE
GROUP BY D.DEPT_CODE
ORDER BY AVG(BASIC) DESC
LIMIT 1; 

SELECT D.DEPT_NAME FROM EMP E
LEFT JOIN DEPARTMENT D
ON D.DEPT_CODE = E.DEPT_CODE
GROUP BY D.DEPT_CODE
ORDER BY COUNT(E.EMP_CODE) DESC
LIMIT 1; 

INSERT INTO EMP(EMP_CODE,EMP_NAME,DEPT_CODE,SEX,ADDRESS,CITY,STATE,PIN,BASIC,JN_DT)
VALUES('EMP46','Dawasn','DPT01','F','turvxdzivuyjqryzdcmxc','CHENNAI','TAMIL NADU','600040',227000,'2003-5-12');
INSERT INTO EMP(EMP_CODE,EMP_NAME,DEPT_CODE,SEX,ADDRESS,CITY,STATE,PIN,BASIC,JN_DT)
VALUES('EMP47','Kayani','DPT02','F','riokcffcifmfbkordpsgr','AHMEDABAD','GUJARAT','380006',247000,'2019-8-14');
INSERT INTO EMP(EMP_CODE,EMP_NAME,DEPT_CODE,SEX,ADDRESS,CITY,STATE,PIN,BASIC,JN_DT)
VALUES('EMP48','Rajeevan','DPT03','M','trqmzexeleiujubleqejhxpy','KOLKATA','WEST BENGAL','700002',225000,'1998-3-12');

DELETE FROM EMP WHERE DESIG_CODE IS NULL;

SELECT EMP_NAME,DEPT_CODE FROM EMP E1 WHERE
BASIC > (SELECT AVG(BASIC) FROM EMP E2 WHERE E1.DEPT_CODE =  E2.DEPT_CODE) AND SEX = 'F'
ORDER BY DEPT_CODE;

SELECT COUNT(EMP_CODE) FROM EMP
WHERE DESIG_CODE = 'DES01' AND SEX = 'F';
