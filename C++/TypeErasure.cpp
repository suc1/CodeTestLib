/*
深入浅出C++类型擦除:  std::function 怎么实现多态的
https://zhuanlan.zhihu.com/p/351291649

本质：切割类型与其行为，使得不同的类型能用同一个接口提供功能
三类函数对象：函数指针、重载括号运算符的类、lambda

类型擦除是一种使得不同类型变量能够得到统一处理的技术。实现方式上可分为静态类型擦 & 动态类型擦除，
静态类型擦除通过模板或者宏实现，
动态类型擦除可通过继承虚函数或者void类型实现。
*/
#include <iostream>
#include <memory>

struct task_base {
   virtual ~task_base() {}
   #if 0
   virtual void operator()() const = 0;
   #else
   virtual void operator()() = 0;
   #endif
};

//子类写成类模板的具体用意是，对于用户提供的一个任意的类型F，F不需要知道task_base及其继承体系，而只进行语法上的duck typing检查
template <typename F>
struct task_model : public task_base {
    F functor_;

    template <typename U> // 构造函数是函数模板
    task_model(U&& f) :
      functor_(std::forward<U>(f)) {}

    #if 0       //编译错误
    void operator()() const override {
        functor_();
    }
    #else
    void operator()() override {
        functor_();
    }
    #endif
};

//自己定义的任务类
class my_task {
 std::unique_ptr<task_base> ptr_;

public:
    // 构造函数
    template <typename F>
    my_task(F&& f) {
        using model_type = task_model<F>;
        ptr_ = std::make_unique<model_type>(std::forward<F>(f));
    }

    // 移动构造函数
    my_task(my_task&& oth) noexcept : 
        ptr_(std::move(oth.ptr_))
    {}

    // 移动赋值函数
    my_task& operator=(my_task&& rhs) noexcept {
        ptr_ = std::move(rhs.ptr_);
        return *this;
    }

    // 析构函数
    ~my_task() = default;

    // 删除复制构造函数、复制赋值函数
    my_task(const my_task&) = delete;
    my_task& operator=(const my_task&) = delete;

public:
    void operator()() const {
        ptr_->operator()();
    } 

    // 其他部分略
};

////Test1
// 1. 普通函数
void foo() {
    std::cout << "type erasure 1";
}

// 2. 重载括号运算符的类
struct foo2 {
    void operator()() {
        std::cout << "type erasure 2";
    }
};

void Test1() {
    // 普通函数
    my_task t1{ &foo };
    t1(); // 输出"type erasure 1"

    #if 1
    // 重载括号运算符的类
    my_task t2{ foo2{} };
    t2(); // 输出"type erasure 2"
    #endif
    
    // 3. Lambda
    my_task t3{
        [](){ std::cout << "type erasure 3"; } 
    }; 
    t3(); // 输出"type erasure 3"
    
}

int main() {
    Test1();

    return 0;
}