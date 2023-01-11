# 选课系统数据库

## Create database choose

```shell
    create database choose;
```

## Select the database "choose"

```shell
    use choose;
```

## Create tables

```shell

    # Create the class table
    create table classes(
        class_no int auto_increment primary key,
        class_name varchar(20) not null unique, # class name should not be null and should be unique
        department_name varchar(20) not null # department name should not be null
    );

    # Create the teacher table
    create table teacher(
        teacher_no varchar(10) primary key,
        teacher_name varchar(10) not null, # teacher name should not be null
        teacher_contact varchar(20) not null # teacher contact should not be null
    );

    # Create the student table
    create table student(
        student_no varchar(11) primary key,  # student no should not be duplicated
        student_name varchar(10) not null, # student name should not be null
        student_contact varchar(20) not null, # student contact should not be null
        class_no int,  # student's class no can be null
        constraint student_class_fk foreign key(class_no) references classes(class_no) 
    );


    # Create the course table
    create table course(
        course_no int auto_increment primary key,
        course_name varchar(10) not null, # course name can be duplicated
        up_limit int default 60, # up limit default value 60
        description varchar(100) not null, # description can not be null
        status varchar(30) default 'not approved', # course status default value "not approved"
        teacher_no varchar(10) not null unique, # unique constraint to implement 1 to 1 relations between teacher and course
        constraint course_teacher_fk foreign key(teacher_no) references teacher(teacher_no)
    );

    # Create the choose table
    create table choose(
        choose_no int auto_increment primary key,
        student_no varchar(11) not null,
        course_no int not null,
        score tinyint unsigned,
        choose_time datetime not null, # course choose time, can be generated automatically by the now function
        constraint choose_student_fk foreign key(student_no) references student(student_no),
        constraint choose_course_fk foreign key(course_no) references course(course_no)
    );
```