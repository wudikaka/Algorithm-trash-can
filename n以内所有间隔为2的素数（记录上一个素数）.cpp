#include <iostream>
#include <string>
using namespace std;
bool sushu(int n)
{
	// 处理特殊情况
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    // 检查6k±1形式的因子
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
int main()
{
	int n,last=2;
	cin>>n;
	int last=2;//先定第一个
	for(int i=3;i<=n-2;i++)
	{
		if(sushu(i))
		{
			if(i-last==2)cout << last_prime << " " << i << endl;、//判断
		}
		last = i;//记录
	}
	if(last+2<=n&&sushu(last+2))cout << last<< " " << last + 2 << endl;
	return 0;
}
