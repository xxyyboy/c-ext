# 基于c ，c ++ 封装php对象扩展

## @Lib
所有的扩展对象均以`Lib` 命名空间为开头
```php
namespace Lib;
```

## @`Lib/SharMem`
该扩展申请一块共享内存地址，提供php调用，用于多进程间共享数据
```php
//初始化传入内存大小 单位字节 bytes
$obj = new Lib\SharMem(8)

//模拟int 自增测试
$obj->get();
$obj->incr();
```
多进程共享内存测试,采用lib_fork 调用 原生fork操作
```php
$Obj = new Lib\SharMem(8);
if(lib_fork() == 0)
{
//子进程
    while(true)
    {
        sleep(1);
        $obj->incr();
        var_dump("this is clild process \n");
    }
}
//父进程
while(true)
{
    sleep(1);
    var_dump("this is parent process get value:".$obj->get());
}
```