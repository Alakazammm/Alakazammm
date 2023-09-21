#include <iostream>
#include <map>
using namespace std;
//已知从青铜10到传说，共50个段位
//每个段位三颗星星
//设额外星数为i颗
double winningPercentage(int initialRanking, int extraStars) {
    //定义初始值 目前需要的星星和掉段保护次数
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
// 每个保护段可以输一次,调整总场次
    double totalGames = minWins + starsNeeded + lossProtected;
    double winRate = minWins / totalGames;
    return winRate;
}
//存放段位
map<string,int> rankMap ={
        {"钻石1", 1},
        {"钻石2", 2},
        {"钻石3", 3},
        {"钻石4", 4},
        {"钻石5", 5},
        {"钻石6", 6},
        {"钻石7", 7},
        {"钻石8", 8},
        {"钻石9", 9},
        {"钻石10", 10},
        {"白金1", 11},
        {"白金2", 12},
        {"白金3", 13},
        {"白金4", 14},
        {"白金5", 15},
        {"白金6", 16},
        {"白金7", 17},
        {"白金8", 18},
        {"白金9", 19},
        {"白金10", 20},
        {"黄金1", 21},
        {"黄金2", 22},
        {"黄金3", 23},
        {"黄金4", 24},
        {"黄金5", 25},
        {"黄金6", 26},
        {"黄金7", 27},
        {"黄金8", 28},
        {"黄金9", 29},
        {"黄金10", 30},
        {"白银1", 31},
        {"白银2", 32},
        {"白银3", 33},
        {"白银4", 34},
        {"白银5", 35},
        {"白银6", 36},
        {"白银7", 37},
        {"白银8", 38},
        {"白银9", 39},
        {"白银10", 40},
        {"青铜1", 41},
        {"青铜2", 42},
        {"青铜3", 43},
        {"青铜4", 44},
        {"青铜5", 45},
        {"青铜6", 46},
        {"青铜7", 47},
        {"青铜8", 48},
        {"青铜9", 49},
        {"青铜10", 50}
};

int main() {
    int extraStars,Stars,rankInt;
    string rankString;
    cout << "请输入当前段位(段位+数字): \t";
    cin >> rankString;
    cout << "\n请输入当前额外星星:\t ";
    rankInt= rankMap[rankString];
    cin>> extraStars;
    double winRate;
    winRate=winningPercentage(rankInt,extraStars);
    //如果给一个基础胜率 求接下来多少场中需要赢多少场
    //是一个独立同分布的概率论问题
    //然后你每局的基础胜率还会变化
    //脑子要炸了
    cout<<"在默认你到达掉段保护之后最多输一次的情况下，你到达传说的最小胜率为：\t"<<winRate<<endl;
    return 0;
}
