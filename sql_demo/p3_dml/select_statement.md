# Select Statement

## Query version No and the server time

```shell
    select version(), now();

    # Use the alias synatx
    select version() as version_number, now() as server_time;
```


Select all fields from a table

```shell
    # Select all the contents from student table
    # Typically we don't use select * since if the table is too wide, we can't see all
    # of the fields
    select * from student;

    # Select partitial fields from student
    select student_no, student_name, class_no from student;

    # Use alias for the fields
    select student_no 学号, student_name 姓名, class_no 班号 from student;

    # Use expressions demo
    select exam_score, regular_score, exam_score*0.8 + regular_score*0.2 total_score from exam;

``` 

Distinct demo,

```shell
    # Only one column for distinct
    select distinct table_schema from tables;

    # Multiple columns
    select distinct table_schema, table_type from tables;
```


Limit statement,

```shell
    
```