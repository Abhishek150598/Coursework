create table emp (
    EMP_CODE varchar(5) primary key,
    EMP_NAME varchar(20),
    DEPT_CODE	varchar(5),
    DESIG_CODE varchar(5),
    SEX varchar(1),
    ADDRESS varchar(25),
    CITY 	varchar(20),
    STATE varchar(20),
    PIN varchar(6),
    BASIC int,
    JN_DT date		
);

create table designation (
    DESIG_CODE varchar(5) primary key,
	DESIG_DESC varchar(20)
);

create table department (
    DEPT_CODE varchar(5) primary key,
    DEPT_NAME varchar(15)
);

/* Insert rows in department table */ 
insert into department values ('01PER', 'Personnel');
insert into department values ('02PRO', 'Production');
insert into department values ('03PUR', 'Purchase');
insert into department values ('04FIN', 'Finance');
insert into department values ('05RES', 'Research');

/* Insert rows in designation table */ 
insert into designation values ('01MAN', 'Manager');
insert into designation values ('02EXE', 'Executive');
insert into designation values ('03OFF', 'Officer');
insert into designation values ('04CLE', 'Clerk');
insert into designation values ('05HEL', 'Helper');

/* Insert rows in emp table */ 
insert into emp values ('00001', 'Amit', '01PER', '01MAN', 'M', 'Netajinagar', 'Kolkata', 'West Bengal', '700107', 12000, to_date('12-05-1996', 'dd-mm-yy'));
insert into emp values ('00002', 'Amrita', '03PUR', '01MAN', 'F', 'Batanagar', 'Kolkata', 'West Bengal', '700107', 18000, to_date('12-05-1990', 'dd-mm-yy'));

/* Insert rows in emp table without dept_code and basic */ 
insert into emp 
(EMP_CODE, EMP_NAME, DESIG_CODE, SEX, ADDRESS, CITY, STATE, PIN, JN_DT) 
values 
('00003', 'Amitansu', '02EXE', 'M', 'Ajoynagar', 'Kolkata', 'West Bengal', '700107', to_date('11-05-1992', 'dd-mm-yy'));
insert into emp 
(EMP_CODE, EMP_NAME, DESIG_CODE, SEX, ADDRESS, CITY, STATE, PIN, JN_DT) 
values 
('00004', 'Mary', '05HEL', 'F', 'Ramgarh', 'Kolkata', 'West Bengal', to_date('12-05-1990', 'dd-mm-yy'));

/* find rows with unassigned dept code */
select * from emp where DEPT_CODE is null;

/* find rows with basic zero */
select * from emp where BASIC = 0;

/* find rows with basic null */
select * from emp where BASIC is null;

/* find average basic */
select avg(basic) from emp;

/* replace basic with 0 for rows with unassigned basic */
update emp set basic = 0 where basic is null;

/* again find average basic */
select avg(basic) from emp;

/* delete employee records with unassigned employee code */
delete from emp where dept_code is null;

select emp_name, 1.9 * basic as net_pay from emp

select upper(emp_name) as emp_name, basic  from emp order by dept_code;

select * from emp where jn_dt > to_date('01-01-1990', 'dd-mm-yyyy');

select count(*) from emp where extract(month from jn_dt)=1;

select min(basic), max(basic) from emp;

select count(*) from emp where sex = 'F';

update emp set city = upper(city);

select count(city) from emp;

select * from emp order by dept_code, basic desc;