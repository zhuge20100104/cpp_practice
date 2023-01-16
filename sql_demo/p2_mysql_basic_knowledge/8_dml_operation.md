# DML Operation

## Insert data into the teachers table

```shell
    insert into teacher(teacher_no, teacher_name, teacher_contact) values('001', 'Mr Li', '11000000000');

    insert into teacher values('002', 'Mr Wang', '12000000000');

    insert into teacher values('003', 'Mrs Sun', '13000000000');
```


## Insert data into the classes table

```shell
    insert into classes values(null, '2018 Auto Grade 1', 'Mech Engineering'),
                        (null, '2018 Auto Grade 2', 'Mech Engineering'),
                        (null, '2018 Auto Grade 3', 'Mech Engineering');
```


## Insert data into the course table

```shell
    insert into course values(null, 'C', default, 'No', 'Approved', '001'),
                            (null, 'MySQL', 150, 'No', 'Approved', '002'),
                            (null, 'Java', 230, 'No', 'Approved', '003');
```


## Insert data into the student table

```shell
    insert into student values('2018001', 'ZhangSan', '15000000000', 1),
                              ('2018002', 'LiSi', '16000000000', 2),
                              ('2018003', 'WangWu', '17000000000', 3),
                              ('2018004', 'MaLiu', '18000000000', 2),
                              ('2018005', 'TianQi', '19000000000', 2);
```

## Insert Select statement

```shell
    use choose;
    create table stu1 like student;
    insert into stu1 select * from student;
    select * from stu1;
```

## Create table exam to demonstrate update

```shell
    create table exam(
        stu_no int primary key auto_increment,
        exam_score tinyint unsigned,
        regular_score tinyint unsigned 
    );

    insert into exam values(null, 80, 85),
                           (null, 99, 90),
                           (null, 65, 70),
                           (null, 52, null),
                           (null, 20, null);
```

The update statement,

```shell
    # No where sub clause (add each one's score by 5)
    update exam set exam_score=exam_score+5;
    # Have where clause will update the specific record
    update exam set exam_score=100 where exam_score>100;
    # Set the exam_score value to 60 if it falls into the region [55, 60)
    update exam set exam_score=60 where exam_score>=55 and exam_score<60;
```

Update multiple fields in a statement,

```shell
    update stu1 set student_name='LiXSi', class_no=3 where student_no='2018002';
```

Restricted keys can't be changed using update clause

```shell
    # Cuz there's a foreign key references to class_no on the classes table, this operation should be failed
    update classes set class_no=4 where class_no=3;
```

Can't use a key that's not exist in the referenced primary table

```shell
    update student set class_no=4 where student_no='2018001';
```


## Delete Clause

```shell
    # Delete the records from the exam table whose exam_score is less than 45
    delete from exam where exam_score<45;

    # No where conditions will delete all of the records in the current table
    delete from exam;

    # Can't delete records that are referenced by other tables
    delete from classes where class_no=1;
```

## The Truncate Clause

```shell
    # After truncate, the auto_increment keys will be re-generated from 1,
    # while by delete, it will start from the last maximum key.
    truncate table exam;
    insert into exam values(null, 80, 80);

    delete from exam;
    insert into exam values(null, 80, 80);


    # Can't truncate table with a foreign key contraint, but you can delete it
    # The below statement will execute failed
    truncate table student;
```