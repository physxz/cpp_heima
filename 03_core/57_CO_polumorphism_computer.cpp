#include <iostream>
using namespace std;

// 3个抽象父类，6个子类，一个公共接口类computer，通过调用computer类调用6个子类

// *************** 抽象不同零件类 **************** //
// 抽象CPU类
class CPU
{
public:
    // 抽象的计算函数
    virtual void calculate() = 0;
};
// 抽象显卡类
class GPU
{
public:
    // 抽象的显示函数
    virtual void display() = 0;
};
// 抽象内存条类
class Memory
{
public:
    // 抽象的存储函数
    virtual void storage() = 0;
};

// *************** 电脑 ****************** //
class Computer
{
public:
    Computer(CPU * cpu, GPU * gpu, Memory * mem)
    {
        m_cpu = cpu;
        m_gpu = gpu;
        m_mem = mem;
    }
    void Work()
    {
        // 让零件工作起来，调用接口
        m_cpu->calculate();
        m_gpu->display();
        m_mem->storage();
    }
    ~Computer()
    {
        if (m_cpu != nullptr)
        {
            delete m_cpu;
            m_cpu = nullptr;
        }
        if (m_gpu != nullptr)
        {
            delete m_gpu;
            m_gpu = nullptr;
        }
        if (m_mem != nullptr)
        {
            delete m_mem;
            m_mem = nullptr;
        }
    }
private:
    CPU * m_cpu; // CPU零件指针
    GPU * m_gpu; // 显卡零件指针
    Memory * m_mem; // 内存条零件指针
};

// ************* 具体厂商 ************* //
// Intel厂商
class IntelCPU: public CPU
{
public:
    void calculate()
    {
        cout << "Intel的CPU开始计算了！" << endl;
    }
};
class IntelGPU: public GPU
{
public:
    void display()
    {
        cout << "Intel的GPU开始显示了！" << endl;
    }
};
class IntelMemory: public Memory
{
public:
    void storage()
    {
        cout << "Intel的内存开始存储了！" << endl;
    }
};
// 联想
class LenovoCPU: public CPU
{
public:
    void calculate()
    {
        cout << "Lenovo的CPU开始计算了！" << endl;
    }
};
class LenovoGPU: public GPU
{
public:
    void display()
    {
        cout << "Lenovo的GPU开始显示了！" << endl;
    }
};
class LenovoMemory: public Memory
{
public:
    void storage()
    {
        cout << "Lenovo的内存开始存储了！" << endl;
    }
};

void test01()
{
    cout << "第二台电脑开始工作" << endl;
    // 第一台电脑零件
    CPU * intelcpu = new IntelCPU;
    GPU * intelgpu = new IntelGPU;
    Memory * intelmem = new IntelMemory;
    // 创建第一台电脑
    Computer * cmp1 = new Computer(intelcpu, intelgpu, intelmem);
    cmp1->Work();
    delete cmp1;

    cout << "--------------------" << endl;
    cout << "第二台电脑开始工作" << endl;
    // 创建并组装第二台电脑
    Computer * cmp2 = new Computer(new LenovoCPU, new LenovoGPU, new LenovoMemory);
    cmp2->Work();
    delete cmp2;

    cout << "--------------------" << endl;
    cout << "第三台电脑开始工作" << endl;
    // 创建并组装第三台电脑
    Computer * cmp3 = new Computer(new LenovoCPU, new IntelGPU, new LenovoMemory);
    cmp3->Work();
    delete cmp3;
}

int main() {
    test01();
    return 0;
}