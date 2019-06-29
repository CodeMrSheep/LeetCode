#include <iostream>
#include <vector>
using namespace std;
// coins = [1, 2, 5], amount = 11 Output: 3; 用最少的纸币，使其面值之和为目标值
class solution_coin {
public:
    int coinChange(vector<int>& coins, int amount);
    int coinChange2(int amount, vector<int>& coins); 
};
int solution_coin::coinChange(vector<int>& coins, int amount){
        vector<int> comb(amount+1,0);
        int flag = amount+1;
        for(int i = 1;i<amount+1;i++){
            for(int coin:coins){
                if(i - coin >= 0){
                    flag = min(flag,comb[i-coin]+1);
                }
            }            comb[i] = flag;
            flag = amount+1;
        }
        return comb[amount] < amount+1 ? comb[amount]:-1;
    }
int solution_coin::coinChange2(int amount, vector<int>& coins){
        vector<int> res(amount+1,0);
        res[0] = 1;
        for (int coin:coins){ //注意这里循环顺序和coin change 1 的差别
            for(int i = 1;i<amount+1;i++){
                if(i >= coin){
                  res[i] += res[i - coin];
            }
        }
      }
        return res[amount];
    }

int main()
{
    solution_coin s1;
    vector<int> coins;
    int num = 0;
    int target = 0;
    cout<<"please input the coins(vector):"<<endl;
    while(cin>>num){
        if(num == -1){
            break;
        }
        coins.push_back(num);
    }
    cout<<"please input the target(integer):"<<endl;
    cin>> target;
    cout<<"the min number of coins that sum to target is:"<<s1.coinChange(coins,target)<<endl;
    cout<<"the number of coins'combinations is:"<<s1.coinChange2(target,coins)<<endl;
    system("pause");
    return 0;
}
 