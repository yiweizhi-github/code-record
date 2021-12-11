/*广度优先搜索走迷宫求最短路径算法*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>

char ditu[50][50];//地图，#代表障碍，.代表通行
int dis[50][50];//记录从起点到地图任意格子的最少移动次数
int m, n;//地图长、宽
int dx[4] = {-1, 1, 0, 0};//坐标上下左右四个方向的变换
int dy[4] = {0, 0, -1, 1};

//广度优先搜索算法，x、y起点坐标，a、b终点坐标，返回起点到终点的最少移动次数
int BFS(int x, int y, int a, int b){
    queue<vector<int> > q;
    vector<int> tmp(2, 0);
    vector<int> cur(2, 0);
    tmp[0] = x;
    tmp[1] = y;
    q.push(tmp);
    for(int i=0;i<m;++i)//dis数组初始化为最大整数
        for(int j=0;j<n;++j)
            dis[i][j] = 0x7fffffff;
    dis[x][y] = 0;//起点到本身距离为0
    while(q.size()){
        tmp = q.front();
        q.pop();
        int now_x = tmp[0], now_y = tmp[1];
        if(now_x==a&&now_y==b)//到达终点退出
            break;
        for(int i=0;i<4;++i){//四个方向展开搜索，之前没走过的通行格步数加1
            cur[0] = now_x+dx[i];
            cur[1] = now_y+dy[i];
            if(cur[0]>-1&&cur[0]<m&&cur[1]>-1&&cur[1]<n&&
            ditu[cur[0]][cur[1]]!='#'&&dis[cur[0]][cur[1]]==0x7fffffff){
                dis[cur[0]][cur[1]] = dis[now_x][now_y]+1;
                q.push(cur);
            }
        }
    }
    return dis[a][b];
}
