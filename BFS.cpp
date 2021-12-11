/*��������������Թ������·���㷨*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>

char ditu[50][50];//��ͼ��#�����ϰ���.����ͨ��
int dis[50][50];//��¼����㵽��ͼ������ӵ������ƶ�����
int m, n;//��ͼ������
int dx[4] = {-1, 1, 0, 0};//�������������ĸ�����ı任
int dy[4] = {0, 0, -1, 1};

//������������㷨��x��y������꣬a��b�յ����꣬������㵽�յ�������ƶ�����
int BFS(int x, int y, int a, int b){
    queue<vector<int> > q;
    vector<int> tmp(2, 0);
    vector<int> cur(2, 0);
    tmp[0] = x;
    tmp[1] = y;
    q.push(tmp);
    for(int i=0;i<m;++i)//dis�����ʼ��Ϊ�������
        for(int j=0;j<n;++j)
            dis[i][j] = 0x7fffffff;
    dis[x][y] = 0;//��㵽�������Ϊ0
    while(q.size()){
        tmp = q.front();
        q.pop();
        int now_x = tmp[0], now_y = tmp[1];
        if(now_x==a&&now_y==b)//�����յ��˳�
            break;
        for(int i=0;i<4;++i){//�ĸ�����չ��������֮ǰû�߹���ͨ�и�����1
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
