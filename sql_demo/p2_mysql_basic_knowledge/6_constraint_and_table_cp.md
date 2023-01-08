# 自增长字段
## 自增长字段
如果要求数据库表的某个字段依次递增，且不重复，则可以将该字段设置为自增型字段。

自增型字段的数据类型必须是整数。

自增型字段必须是主键


```shell
    create table classes(
        class_no int auto_increment primary key,
        class_name varchar(20) not null
    );

    insert into classes values(null, '2019 Electronic');

    insert into classes(class_name) values('2019 Computer');

    insert into classes values(3, '2019 Mechnical Des');
```


## 复制表结构

在create table语句的末尾添加like子句, 这种方法只复制表结构，不复制数据，没法复制外键约束，其他约束可以复制


create table 表名 select * from 源表, 这种方法拷贝数据，但是无法复制除非空约束以外的其他约束


```shell
    create table class1 like classes;

    desc class1;

    create table class2 select * from classes;

    desc class2;

    select * from class2;
```

