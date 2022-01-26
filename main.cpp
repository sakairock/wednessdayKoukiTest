#include <stdio.h>
#include <list>
#include <vector>

// ��1��(10�_)
// �ȉ��̃N���X�ɃR���X�g���N�^�A�f�X�g���N�^��ǉ����Ă��������B
// �R���X�g���N�^�A�f�X�g���N�^�̏����̓��e�͂Ȃ�ł��\���܂���

class Point
{
public:
    //�R���X�g���N�^
    Point();
    //�f�X�g���N�^
    ~Point();
private:
    int x;
    int y;
};

Point::Point()
{

}
Point::~Point()
{

}



// ��2��(10�_)
// int�^�̕ϐ���new���g���m�ۂ��Ă��������B
// �܂��Achar�^�̔z���new���g���m�ۂ��Ă��������B
// �ǂ����delete���Ăяo���悤�ɂ��Ă��������B

int main()
{
    int* pNum = new int;
    char* pArray = new char[10];

    *pNum = 100;
    *pArray = { 'a' };

    delete pNum;
    delete[] pArray;
}



// ��3��(15�_)
// �ȉ��̌p����N���X�̃f�X�g���N�^���������Ăяo�����悤�ɁA
// �N���X���C�����Ă��������B

class Test
{
public:
    Test()
    {
        printf("Test\n");
    }
    virtual ~Test()
    {
        printf("~Test\n");
    }
};
class Test2 : public Test
{
public:
    Test2()
    {
        printf("Test2\n");
    }
    ~Test2()
    {
        printf("~Test2\n");
    }
};

int main()
{
    Test* t;
    t = new Test2();

    delete t;
    return 0;
}



// ��4��(25�_)
// �ȉ��̊֐����e���v���[�g�����āA
// �l�X�Ȍ^�Ōv�Z�ł���悤�ɂ��Ă��������B

template <typename T>
T Add(T a, T b)
{
    return a + b;
}
template <typename T>
T Sub(T a, T b)
{
    return a - b;
}
template <typename T>
T Mul(T a, T b)
{
    return a * b;
}
template <typename T>
T Div(T a, T b)
{
    return a / b;
}

int main()
{
    int ans1;
    float ans2;
    char ans3;

    ans1 = Add<int>(2, 5);
    ans2 = Div<float>(10.0f, 2.5f);
    ans3 = Mul<char>(10, 4);

    return 0;
}



// ��5��(25�_)
// ���̃v���O�������C�����A�ȉ��̂悤�ȕ\���ɂȂ�悤�Ƀv���O�������쐬���Ă��������B
// num = 50
// num = 40
// num = 30
// num = 20
// num = 10
// �܂��A���X�g�̃f�[�^��30�����Ȃ���Ԃɂ��Ă��������B���̍ە\���͈ȉ��̂ɂȂ�܂��B
// num = 30

int main()
{
    std::list<int> lst;
    for (int i = 100; i > 1; --i)
    {
        if (i % 10 == 0)
        {
            lst.push_front(i);
        }
    }

    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
    {
        printf("num = %d\n", *it);
    }

    // ���X�g���C������num=30�ƕ\�������悤�Ƀv���O�������L�q
}



// ��6��(25�_)
// ��5��Ɠ����\���ɂȂ�悤��std::vector���g���ăv���O�������L�q���Ă��������B

int main()
{
    std::vector<int> vec;

    for (int i = 100; i > 1; --i)
    {
        if (i % 10 == 0 && i <= 50)
        {
            vec.push_back(i);
        }
    }

    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        printf("num = %d\n", *it);
    }
}
