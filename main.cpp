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



// 第4問(25点)
// 以下の関数をテンプレート化して、
// 様々な型で計算できるようにしてください。

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
        // ここにプログラムを記述
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
