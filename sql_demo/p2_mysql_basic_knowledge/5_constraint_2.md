# 外键约束

语法规则

constraint 约束名 foreign key (从表中的字段名或字段列表) references 主表(字段名或字段列表)

示例

将学生表student的class_no设置为外键，引用classes表中的class_no字段，可以在创建student表时添加如下SQL语句：

constraint student_class_fk foreign key(class_no) references classes(class_no)


外键的两个注意事项，

1. 外键必须和主表中的键类型相同

2. 主表中的键必须是主键或者唯一键， 一般是主键


插入时先插入主表，再插入从表。

创建时先创建主表，再创建从表

删除时先删除从表，再删除主表，因为主表中的数据被从表引用了


```shell
    create table classes(
        class_no int primary key,
        class_name varchar(20)
    );

    create table student(
        stu_no int primary key,
        stu_name varchar(10) not null,
        c_no int,
        constraint classes_student_fk foreign key(c_no) references classes(class_no)
    );

    insert into classes values(1, '2019 Electronic 01');
    insert into student values(1, 'ZhangSan', 1);
    # 错误，主表中没有c_no为2的班级
    insert into student values(2, 'Lisi', 2);
```