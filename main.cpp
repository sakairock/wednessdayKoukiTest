#include <stdio.h>
#include <list>
#include <vector>

// 第1問(10点)
// 以下のクラスにコンストラクタ、デストラクタを追加してください。
// コンストラクタ、デストラクタの処理の内容はなんでも構いません

class Point
{
public:
    //コンストラクタ
    Point();
    //デストラクタ
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



// 第2問(10点)
// int型の変数をnewを使い確保してください。
// また、char型の配列をnewを使い確保してください。
// どちらもdeleteを呼び出すようにしてください。

int main()
{
    int* pNum = new int;
    char* pArray = new char[10];

    *pNum = 100;
    *pArray = { 'a' };

    delete pNum;
    delete[] pArray;
}



// 第3問(15点)
// 以下の継承先クラスのデストラクタが正しく呼び出されるように、
// クラスを修正してください。

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



// 第4問(25点)
// 以下の関数をテンプレート化して、
// 様々な型で計算できるようにしてください。

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



// 第5問(25点)
// 次のプログラムを修正し、以下のような表示になるようにプログラムを作成してください。
// num = 50
// num = 40
// num = 30
// num = 20
// num = 10
// また、リストのデータが30しかない状態にしてください。その際表示は以下のになります。
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

    // リストを修正してnum=30と表示されるようにプログラムを記述
}



// 第6問(25点)
// 第5問と同じ表示になるようにstd::vectorを使ってプログラムを記述してください。

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
