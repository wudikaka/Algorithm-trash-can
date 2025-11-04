#include <iostream>
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
	int n;
	cin>>n;
	for(int i=2;i<=n-2;i++)
	{
		if(!sushu(i))continue;//若不是素数，跳过本次循环剩余代码
		if(sushu(i+2))cout << i << " " << i + 2 << endl;
	}
	return 0;
}

