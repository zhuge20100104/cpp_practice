# 各种约束

## 主键约束

多个字段组合作主键

语法规则：

primary key(字段名1,字段名2)

例如，将(t1,t2)组合作test表的主键

```shell
    create table student(
        stu_no int primary key,
        stu_name varchar(10)
    );

    insert into student values(1, 'ZhangSan');
    # 错误，主键不能重复
    insert into student values(1, 'Lisi');
```

```shell
    # 复合主键
    create table student(
        stu_no int,
        gradle int,
        stu_name varchar(10),
        primary key(stu_no, gradle)
    );

    insert into student values(1, 1, 'ZhangSan');
    insert into student values(1, 2, 'Lisi');
    # 错误
    insert into student values(1, 1, 'WangWu');
```

## 非空约束

```shell
    create table student(
        stu_no int primary key,
        stu_name varchar(10) not null
    );

    insert into student values(1, 'ZhangSan');
    # 错误，非空列不能为 null
    insert into student values(2, null);
```

## 默认值约束

```shell
    create table student(
        stu_no int primary key,
        stu_name varchar(20) not null,
        class_name varchar(20) default '2019 Electronic 1'
    );

    insert into student values(1, 'ZhangSan', default);
    insert into student(stu_no, stu_name) values(2, 'Lisi');

    # 不使用默认值
    insert into student values(3, 'WangWu', '2019 Computer 01');
```

## 唯一约束

唯一约束可以有多个空值，MySQL数据库默认认为两个空值是不等的。

```shell
    create table student(
        stu_no int primary key,
        stu_name varchar(20) not null,
        stu_uid varchar(20) unique
    );

    insert into student values(1, 'ZhangSan', '123456789987654321');
    # 错误，违反唯一键约束
    insert into student values(2, 'Lisi', '123456789987654321');
    # ok
    insert into student values(3, 'WangWu', null);
    insert into student values(4, 'ZhaoLiu', null);
```