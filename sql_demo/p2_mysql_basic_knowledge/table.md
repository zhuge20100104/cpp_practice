# MySQL table basic knowledge

## 创建数据库表
```shell
    use choose;
    create table student(
        stu_no int,
        stu_name char(10)
    );
```

## 查看当前数据库中的所有表
```shell
    show tables;
```

## 查看指定表的表结构
```shell
    desc student;
```

## 查看指定表的详细信息
```shell
    show create table student;
```

## 删除表 30页 TODO: