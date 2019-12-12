#ifndef LIB_COROUTINE_H
#define LIB_COROUTINE_H
#define DEFAULT_PHP_STACK_PAGE_SIZE 8192
#include "php_lib.h"
#include "coroutine.h"
//协程传递参数
struct php_coro_args
{
    zend_fcall_info_cache *fci_cache; zval *argv;
    uint32_t argc;
};
//保存协程栈
struct php_coro_task
{
    //协程栈顶
    zval *vm_stack_top;
    //协程栈栈底
    zval *vm_stack_end;
    //协程栈指针
    zend_vm_stack vm_stack;
    //协程栈页大小
    size_t vm_stack_page_size;
    //协程栈的栈帧
    zend_execute_data *execute_data;
    Lib::Coroutine *co;

};

namespace Lib
{
    class PHPCoroutine
    {
    public:
        static long create(zend_fcall_info_cache *fci_cache,uint32_t argc,zval *argv);
    protected:
        //主协程成员
        static php_coro_task main_task;

        static void save_task(php_coro_task *task);
        //保存协程栈内容
        static void save_vm_stack(php_coro_task *task);
        //获取当前协程栈信息
        static php_coro_task* get_task();
        static void create_func(void *arg);
        //初始化一个php栈
        static void vm_stack_init(void);
    };
}


#endif // !1LIB_COROUTINE_#define LIB_COROUTINE_HH