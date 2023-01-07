# MySQL Database basic knowledge

## 启动MySQL
```shell
    sudo service mysql start 
```

## 重启MySQL
```shell
    sudo service mysql restart
```

## 停止MySQL
``` shell
    sudo service mysql stop
```

## 登录MySQL
```shell
    mysql -h localhost -u root -p stu_db -P 3306
```

## 创建数据库
```shell
    create database choose;
```

## 查看所有数据库
```shell
    show databases;
```

## 查看选定数据库的结构
```shell
    show create database choose;
```

## 选择当前数据库
```shell
    use choose;
```

## 删除数据库
```shell
    drop database choose;
```
