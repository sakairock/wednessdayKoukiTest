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
    ~Test()
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
void Calc(float a, float b, int type)
{
    float ans = 0;
    switch (type)
    {
    case 0:
        ans = a + b;
        break;
    case 1:
        ans = a - b;
        break;
    case 2:
        ans = a * b;
        break;
    case 3:
        ans = a / b;
        break;
    }
}

int main()
{
    Calc<int>(2, 5, 0);
    Calc<float>(10.0f, 2.5f, 3);
    Calc<char>(10, 4, 2);
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
        // �����Ƀv���O�������L�q
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
