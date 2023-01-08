# 数据类型

## Decimal类型
Decimal(length, precision)

Decimal(5, 2)  -999.99 --> 999.99

小数位数超出部分会四舍五入

```shell
    create table student(
        stu_no int,
        stu_name char(8),
        stu_fee decimal(6, 2)
    );

    insert into student values(1, '张三', 1000.2233);
    insert into student values(2, '李四', 1000.226);
```


## float和double类型

单精度浮点型 float  4字节

双精度浮点型 double 8字节

```shell
    create table employee(
        emp_id int,
        salary float unsigned
    );

    # 错误， unsigned不能为负
    insert into employee values(1, -123.00);
    # 正确
    insert into employee values(1, 12368.00);
```

## Datetime和date类型

3个字节

取值范围：'1000-01-01' ~'9999-12-31 '

格式： 'YYYY-MM-DD'


3个字节

取值范围：'1000-01-01' ~'9999-12-31 '

格式： 'YYYY-MM-DD'

```shell
    create table student(
        stu_no int,
        stu_name varchar(20),
        enter_date datetime
    );

    insert into student values(1, 'ZhangSan', '2022-01-03 09:00:00');
```


