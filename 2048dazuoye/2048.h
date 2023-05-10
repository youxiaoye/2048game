#pragma once
#include<iostream>
#include<ctime>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include <conio.h>
#include <graphics.h>
#define SPACE 10	//分割线宽度
#define lengh1 120	//小方块边长
#define lengh2 550	//大方块边长
#define X 200
#define Y 100
//操控方向
enum Dirction { up = 'w', down = 's', left = 'a', right = 'd' };
//需要用到的颜色
enum Color {
    bk1 = RGB(230, 230, 250),
    bk2 = RGB(84, 255, 159),
    bk3 = RGB(58, 48, 37),
    col1 = RGB(50, 37, 23),
    col2 = RGB(63, 48, 21),
    col3 = RGB(255, 0, 255),
    col4 = RGB(0, 255, 0),
    col5 = RGB(139, 33, 8),
    col6 = RGB(255, 106, 106),
    col7 = RGB(139, 101, 8),
    col8 = RGB(255, 250, 205),
    col9 = RGB(93, 93, 22),
    col10 = RGB(15, 28, 24),
    col11 = RGB(130, 130, 101),
    font = RGB(171, 178, 191),
};