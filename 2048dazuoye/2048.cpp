#include<2048.h>
class game2048 {
private:
    void bk2() {//设置背景
        setfillcolor(Color::bk2);
        solidroundrect(X, Y, X + lengh2, Y + lengh2, 20, 20);
        int x, y;
        y = Y + SPACE;
        for (int i = 0; i < 4; i++)
        {
            x = X + SPACE;
            for (int j = 0; j < 4; j++)
            {
                setfillcolor(Color::bk3);
                solidroundrect(x, y, x + lengh1, y + lengh1, 7, 7);
                x += lengh1 + SPACE;
            }
            y += lengh1 + SPACE;
        }
    }
    void setFont() {
        LOGFONT f;
        gettextstyle(&f);
        f.lfHeight = 100;				  //字体高度
        _tcscpy_s(f.lfFaceName, TEXT("黑体"));//字体类型
        settextstyle(&f);
        outtextxy(X + SPACE + 150, 0, TEXT("2 0 4 8 game "));
        f.lfHeight = 20;
        settextstyle(&f);
        outtextxy(0, 0, TEXT("you are the winner!!!"));
    }

    int matrixsqrare[4][4];
    bool up() {
        bool key = false;
        for (int x = 0; x < 4; x++)  //逐列处理
        {
            for (int i = 0, j = 1; j < 4; j++) //从头开始查找是否能合并
            {
                if (matrixsqrare[j][x] != 0) {
                    if (matrixsqrare[j][x] == matrixsqrare[i][x])//相等
                    {
                        matrixsqrare[i][x] ++; key = true;
                        matrixsqrare[j][x] = 0;
                        i++;
                    }
                    else if (matrixsqrare[i][x] == 0) {  //移动
                        matrixsqrare[i][x] = matrixsqrare[j][x]; key = true;
                        matrixsqrare[j][x] = 0;
                    }
                    else {                          //碰撞
                        matrixsqrare[i + 1][x] = matrixsqrare[j][x];
                        if ((i + 1) != j)
                        {
                            matrixsqrare[j][x] = 0; key = true;
                        }
                        i++;
                    }
                }
            }
        }
        return key;
    }
    bool down() {
        bool key = false;
        for (int x = 0; x < 4; x++)  //逐列处理
        {
            for (int i = 3, j = 2; j >= 0; j--) //从头开始查找是否能合并
            {
                if (matrixsqrare[j][x] != 0) {
                    if (matrixsqrare[j][x] == matrixsqrare[i][x])//相等
                    {
                        matrixsqrare[i][x] ++; key = true;
                        matrixsqrare[j][x] = 0;
                        i--;
                    }
                    else if (matrixsqrare[i][x] == 0) {  //移动
                        matrixsqrare[i][x] = matrixsqrare[j][x]; key = true;
                        matrixsqrare[j][x] = 0;
                    }
                    else {                          //碰撞
                        matrixsqrare[i - 1][x] = matrixsqrare[j][x];
                        if ((i - 1) != j)
                        {
                            matrixsqrare[j][x] = 0; key = true;
                        }
                        i--;
                    }
                }
            }
        }
        return key;
    }
    bool left() {
        bool key = false;
        for (int y = 0; y < 4; y++)  //逐行处理
        {
            for (int i = 0, j = 1; j < 4; j++) //从头开始查找是否能合并
            {
                if (matrixsqrare[y][j] != 0) {
                    if (matrixsqrare[y][j] == matrixsqrare[y][i])//相等
                    {
                        matrixsqrare[y][i] ++; key = true;
                        matrixsqrare[y][j] = 0;
                        i++;
                    }
                    else if (matrixsqrare[y][i] == 0) {  //移动
                        matrixsqrare[y][i] = matrixsqrare[y][j]; key = true;
                        matrixsqrare[y][j] = 0;
                    }
                    else {                          //碰撞
                        matrixsqrare[y][i + 1] = matrixsqrare[y][j];
                        if ((i + 1) != j)
                        {
                            matrixsqrare[y][j] = 0; key = true;
                        }
                        i++;
                    }
                }
            }
        }
        return key;
    }
    bool right() {
        bool key = false;
        for (int y = 0; y < 4; y++)  //逐行处理
        {
            for (int i = 3, j = 2; j >= 0; j--) //从头开始查找是否能合并
            {
                if (matrixsqrare[y][j] != 0) {
                    if (matrixsqrare[y][j] == matrixsqrare[y][i])//相等
                    {
                        matrixsqrare[y][i] ++; key = true;
                        matrixsqrare[y][j] = 0;
                        i--;
                    }
                    else if (matrixsqrare[y][i] == 0) {  //移动
                        matrixsqrare[y][i] = matrixsqrare[y][j]; key = true;
                        matrixsqrare[y][j] = 0;
                    }
                    else {                          //碰撞
                        matrixsqrare[y][i - 1] = matrixsqrare[y][j];
                        if ((i - 1) != j)
                        {
                            matrixsqrare[y][j] = 0; key = true;
                        }
                        i--;
                    }
                }
            }
        }
        return key;
    }

 
public:
    
    game2048() :matrixsqrare{} {}
    //初始化游戏界面
    void init() {
        bk2();
        setFont();
    }
    //在空位产生2或者4
    void newNumber(bool judge) {
        if (judge)
        {
            srand((unsigned int)time(0));
            int x, y;
            int a = rand() % 100;
            //找到一个空位
            do {
                x = rand() % 4;
                y = rand() % 4;
            } while (matrixsqrare[x][y] != 0);
            matrixsqrare[x][y] = (a > 80) ? 2 : 1;
        }
    }
    //在对应的位置上画出小方块
    void drawSmallRect() {
        int x, y;
        y = Y + SPACE;
        for (int xj = 0; xj < 4; xj++)
        {
            x = X + SPACE;
            for (int yj = 0; yj < 4; yj++)
            {
                switch (matrixsqrare[xj][yj])//设置小方块颜色
                {
                case 1:
                    setfillcolor(Color::col1);
                    break;
                case 2:
                    setfillcolor(Color::col2);
                    break;
                case 3:
                    setfillcolor(Color::col3);
                    break;
                case 4:
                    setfillcolor(Color::col4);
                    break;
                case 5:
                    setfillcolor(Color::col5);
                    break;
                case 6:
                    setfillcolor(Color::col6);
                    break;
                case 7:
                    setfillcolor(Color::col7);
                    break;
                case 8:
                    setfillcolor(Color::col8);
                    break;
                case 9:
                    setfillcolor(Color::col9);
                    break;
                case 10:
                    setfillcolor(Color::col10);
                    break;
                case 11:
                    setfillcolor(Color::col11);
                    break;
                default:
                    setfillcolor(Color::bk3);
                    break;
                }//
                solidroundrect(x, y, x + lengh1, y + lengh1, 7, 7);
                LOGFONT f;
                gettextstyle(&f);
                _tcscpy_s(f.lfFaceName, TEXT("TimesNewRoman"));//字体类型
                setbkmode(TRANSPARENT);
                settextcolor(Color::font);

                if (matrixsqrare[xj][yj] < 4) {
                    f.lfHeight = 90;				  //字体高度
                    settextstyle(&f);
                    switch (matrixsqrare[xj][yj])
                    {
                    case 1:
                        outtextxy(x + 45, y + 20, TEXT("2"));
                        break;
                    case 2:
                        outtextxy(x + 45, y + 20, TEXT("4"));
                        break;
                    case 3:
                        outtextxy(x + 45, y + 20, TEXT("8"));
                        break;
                    }
                }
                else if (matrixsqrare[xj][yj] < 7) {
                    f.lfHeight = 90;				  //字体高度
                    settextstyle(&f);
                    switch (matrixsqrare[xj][yj])
                    {
                    case 4:
                        outtextxy(x + 25, y + 15, TEXT("16"));
                        break;
                    case 5:
                        outtextxy(x + 25, y + 15, TEXT("32"));
                        break;
                    case 6:
                        outtextxy(x + 25, y + 15, TEXT("64"));
                        break;
                    }
                }
                else if (matrixsqrare[xj][yj] < 10) {
                    f.lfHeight = 80;				  //字体高度
                    settextstyle(&f);
                    switch (matrixsqrare[xj][yj])
                    {
                    case 7:
                        outtextxy(x + 10, y + 20, TEXT("128"));
                        break;
                    case 8:
                        outtextxy(x + 10, y + 20, TEXT("256"));
                        break;
                    case 9:
                        outtextxy(x + 10, y + 20, TEXT("512"));
                        break;
                    }
                }
                else if (matrixsqrare[xj][yj] < 10) {
                    f.lfHeight = 90;				  //字体高度
                    settextstyle(&f);
                    switch (matrixsqrare[xj][yj])
                    {
                    case 10:
                        outtextxy(x, y, TEXT("1024"));
                        break;
                    case 11:
                        outtextxy(x, y, TEXT("2048"));
                        break;
                    }
                }
                x += lengh1 + SPACE;
            }
            y += lengh1 + SPACE;
        }
    }

    bool move(int di) {//移动方块到指定位置
        bool isMove = false;
        switch (di)
        {
        case Dirction::up:
            isMove = up();
            break;
        case Dirction::down:
            isMove = down();
            break;
        case Dirction::left:
            isMove = left();
            break;
        case Dirction::right:
            isMove = right();
            break;
        }
        return isMove;
    }
    bool isWon() {//chenggong
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (matrixsqrare[i][j] == 2048)
                {
                    return true;
                }
            }
        }//到2048就成功
        return false;
    }
    bool isFail() {//shibai
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 3; j++) {
                // 横向和纵向比较挨着的两个元素是否相等，若有相等则游戏不结束 
                if (matrixsqrare[i][j] == matrixsqrare[i][j + 1] || matrixsqrare[j][i] == matrixsqrare[j + 1][i])
                    return false;
            }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (matrixsqrare[i][j] == 0)
                    return false;
            }
        }
        return true;
    }
    char overPict() {
        LOGFONT f;
        gettextstyle(&f); 
        f.lfHeight = 100;				  
        _tcscpy_s(f.lfFaceName, TEXT("微软雅黑"));
        settextstyle(&f);
        Sleep(200);
        cleardevice();
        outtextxy(X + SPACE + lengh1 + 50, 200, TEXT("DEFEAT!"));
        f.lfHeight = 60;
        settextstyle(&f);
        outtextxy(X + SPACE + lengh1 + 50, 300, TEXT("PRESS e TO START AGAIN"));
        return (char)_getch();//失败显示的界面
    }
};

int main()
{
    initgraph(640, 480); // 初始化画布大小

    // 开始界面
    setbkcolor(col4); // 设置背景颜色为白色
    cleardevice(); // 清空画布
    settextcolor(col10); // 设置文本颜色为黑色
    settextstyle(30, 0, _T("微软雅黑")); // 设置文本字体大小和样式
    outtextxy(250, 200, _T("heiheihei 2048 game")); // 在画布上输出文本

    // 按钮
    setfillcolor(RGB(128, 128, 128)); // 设置填充颜色为灰色
    setlinecolor(RGB(0, 0, 0)); // 设置边框颜色为黑色
    fillrectangle(300, 300, 360, 340); 
    rectangle(300, 300, 360, 340); // 绘制矩形边框
    settextcolor(col5); // 设置文本颜色
    settextstyle(20, 0, _T("TimesNewRoman")); // 设置文本字体大小和样式
    outtextxy(305, 310, _T("START!")); // 在画布上输出文本

    //点击开始按钮
    while (true) {
        // 获取鼠标当前位置和点击状态
        int x = -1, y = -1;
        bool clicked = false;
        if (MouseHit()) {
            MOUSEMSG msg = GetMouseMsg();
            x = msg.x;
            y = msg.y;
            clicked = msg.mkLButton;
        }

        // 判断是否点击了开始按钮
        if (clicked && x >= 280 && x <= 360 && y >= 300 && y <= 340) {
            break;
        }
    }

    // 进入游戏:
   
    // 初始化图形窗口
    initgraph(1000, 800);
    setbkcolor(Color::col10);
    cleardevice();
    //画出游戏主界面
A:
    game2048 a;
    a.init();
    //游戏循环
    a.newNumber(true);
    a.newNumber(true);
    a.drawSmallRect();
    bool judge;
    int congr;
    while ((congr = _getch()) == Dirction::up || congr == Dirction::down
        || congr == Dirction::left || congr == Dirction::right)
    {
        judge = a.move(congr);
        a.drawSmallRect();
        Sleep(150);
        a.newNumber(judge);
        a.drawSmallRect();
        if (a.isWon()) {
            Sleep(3000);
            break;
        }
        if (a.isFail()) {
            Sleep(2000);
            char e = a.overPict();
            if (e == 'e')
            {
                goto A;
            }
            else {
                cleardevice();
                outtextxy(X + SPACE + lengh1 + 50, 200, TEXT("rubbish！哈哈哈哈哈哈哈"));
                Sleep(2000);
                break;
            }
        }
       
    }
    closegraph();
    return 0;
}

