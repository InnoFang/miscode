#include <stdio.h>
#include <conio.h>
#include <windows.h>
//贪吃蛇背景的宽度和高度
#define HEIGHT (30)
#define WIDTH HEIGHT
//背景的中心位置
int xCenter = HEIGHT%2==0 ? HEIGHT/2 : HEIGHT/2+1;
int yCenter = WIDTH%2==0 ? WIDTH/2 : WIDTH/2+1;
//贪吃蛇的长度
int snakesLen = 10;
//贪吃蛇的最大长度
int snakesMaxLen = (HEIGHT-2) * (WIDTH-2);
//一个供贪吃蛇移动的结构体数组
struct{
    int x;
    int y;
}snakes[(HEIGHT-2) * (WIDTH-2)];
//蛇头、蛇尾在snakes数组中的下标（索引）
int headerIndex, tailIndex;
HANDLE hConsole;  //控制台句柄
// 设置光标位置，x为行，y为列
void setPosition(int x, int y){
    COORD coord;
    coord.X = 2*y;
    coord.Y = x;
    SetConsoleCursorPosition(hConsole, coord);
}
// 设置颜色
void setColor(int color){
    SetConsoleTextAttribute(hConsole, color);
}
//初始化
void init(){
    int xCenter = HEIGHT%2==0 ? HEIGHT/2 : HEIGHT/2+1;
    int yCenter = WIDTH%2==0 ? WIDTH/2 : WIDTH/2+1;
    int x, y, i;
    int offset;
    CONSOLE_CURSOR_INFO cci;
   
    headerIndex = 0;
    tailIndex = snakesLen-1;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //隐藏光标
    GetConsoleCursorInfo(hConsole, &cci);
    cci.bVisible = 0;
    SetConsoleCursorInfo(hConsole, &cci);
   
    //设置窗口大小
    system("mode con: cols=64 lines=32");
    //打印背景，按行输出
    for(x=0; x<WIDTH; x++){
        for(y=0; y<HEIGHT; y++){
            if(y==0 || y==WIDTH-1 || x==0 || x==HEIGHT-1){  //输出边框
                setColor(4);
                printf("□");
            }else{  //贪吃蛇活动区域
                setColor(2);
                printf("■");
            }
        }
        printf("\n");
    }
    //输出贪吃蛇并初始化snake数组
    offset = snakesLen%2==0 ? snakesLen/2 : snakesLen/2-1;
    setPosition(xCenter, yCenter-offset);
    setColor(0xe);
   
    for(i=0; i<snakesLen; i++){
        printf("%s", "★");
        snakes[i].x = xCenter;
        snakes[i].y = yCenter-offset+i;
    }
}
// 蛇移动
void move(char direction){
    int headerX = snakes[headerIndex].x;
    int headerY = snakes[headerIndex].y;
    switch(direction){
        case 'w':
            headerX--;
            break;
        case 's':
            headerX++;
            break;
        case 'a':
            headerY--;
            break;
        case 'd':
            headerY++;
            break;
    }
    //输出新蛇头
    setPosition(headerX, headerY);
    setColor(0xe);
    printf("%s", "★");
    //删除蛇尾
    setPosition(snakes[tailIndex].x, snakes[tailIndex].y);
    setColor(2);
    printf("%s", "■");
   
    //设置headerIndex和tailIndex
    headerIndex = headerIndex==0 ? snakesMaxLen-1 : headerIndex-1;
    snakes[headerIndex].x = headerX;
    snakes[headerIndex].y = headerY;
    tailIndex = tailIndex==0 ? snakesMaxLen-1 : tailIndex-1;
}
//下次移动的方向
char nextDirection(char ch, char directionOld){
    int sum = ch+directionOld;
    ch = tolower(ch);
    if( (ch=='w' || ch=='a' || ch=='s' || ch=='d') && sum!=197 && sum!=234 ){
        return ch;
    }else{
        return directionOld;
    }
}
int main(){
    char charInput, direction = 'a';
    init();
   
    charInput = tolower(getch());
    direction = nextDirection(charInput, direction);
    //不停地移动贪吃蛇
    while(1){
        if(kbhit()){
            charInput = tolower(getch());
            direction = nextDirection(charInput, direction);
        }
        move(direction);
        Sleep(500);
    }
    return 0;
}
