#include <iostream>
#include <map>
using namespace std;
//��֪����ͭ10����˵����50����λ
//ÿ����λ��������
//���������Ϊi��
double winningPercentage(int initialRanking, int extraStars) {
    //�����ʼֵ Ŀǰ��Ҫ�����Ǻ͵��α�������
    int starsNeeded = 0;
    int lossProtected = 0;
    if(initialRanking >= 50) {
        starsNeeded += (50 - initialRanking) * 3;
    }
    if(initialRanking % 5 == 0) {
        lossProtected++;
    }
    if(initialRanking >= 40) {
        starsNeeded += 20;
        if(initialRanking >= 45) {
            lossProtected++;
        }
    }
    if(initialRanking >= 30) {
        starsNeeded += 20;
        if(initialRanking >= 35) {
            lossProtected++;
        }
    }
    if(initialRanking >= 20) {
        starsNeeded += 20;
        if(initialRanking >= 25) {
            lossProtected++;
        }
    }
    if(initialRanking >= 10) {
        starsNeeded += 20;
        if(initialRanking >= 15) {
            lossProtected++;
        }
    }
    starsNeeded += 20;
    starsNeeded -= extraStars;
    double minWins = starsNeeded / 2.0;
// ÿ�������ο�����һ��,�����ܳ���
    double totalGames = minWins + starsNeeded + lossProtected;
    double winRate = minWins / totalGames;
    return winRate;
}
//��Ŷ�λ
map<string,int> rankMap ={
        {"��ʯ1", 1},
        {"��ʯ2", 2},
        {"��ʯ3", 3},
        {"��ʯ4", 4},
        {"��ʯ5", 5},
        {"��ʯ6", 6},
        {"��ʯ7", 7},
        {"��ʯ8", 8},
        {"��ʯ9", 9},
        {"��ʯ10", 10},
        {"�׽�1", 11},
        {"�׽�2", 12},
        {"�׽�3", 13},
        {"�׽�4", 14},
        {"�׽�5", 15},
        {"�׽�6", 16},
        {"�׽�7", 17},
        {"�׽�8", 18},
        {"�׽�9", 19},
        {"�׽�10", 20},
        {"�ƽ�1", 21},
        {"�ƽ�2", 22},
        {"�ƽ�3", 23},
        {"�ƽ�4", 24},
        {"�ƽ�5", 25},
        {"�ƽ�6", 26},
        {"�ƽ�7", 27},
        {"�ƽ�8", 28},
        {"�ƽ�9", 29},
        {"�ƽ�10", 30},
        {"����1", 31},
        {"����2", 32},
        {"����3", 33},
        {"����4", 34},
        {"����5", 35},
        {"����6", 36},
        {"����7", 37},
        {"����8", 38},
        {"����9", 39},
        {"����10", 40},
        {"��ͭ1", 41},
        {"��ͭ2", 42},
        {"��ͭ3", 43},
        {"��ͭ4", 44},
        {"��ͭ5", 45},
        {"��ͭ6", 46},
        {"��ͭ7", 47},
        {"��ͭ8", 48},
        {"��ͭ9", 49},
        {"��ͭ10", 50}
};

int main() {
    int extraStars,Stars,rankInt;
    string rankString;
    cout << "�����뵱ǰ��λ(��λ+����): \t";
    cin >> rankString;
    cout << "\n�����뵱ǰ��������:\t ";
    rankInt= rankMap[rankString];
    cin>> extraStars;
    double winRate;
    winRate=winningPercentage(rankInt,extraStars);
    //�����һ������ʤ�� ����������ٳ�����ҪӮ���ٳ�
    //��һ������ͬ�ֲ��ĸ���������
    //Ȼ����ÿ�ֵĻ���ʤ�ʻ���仯
    //����Ҫը��
    cout<<"��Ĭ���㵽����α���֮�������һ�ε�����£��㵽�ﴫ˵����Сʤ��Ϊ��\t"<<winRate<<endl;
    return 0;
}
