#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000000007
long long get_Mod(long long N);
//对幂取模
long long get_Mod(long long N)
{
	long long result = 1;
	long long base = 2;
	while (N > 0)
	{
		if (N % 2 == 1)
		{
			result = (result * base) % MOD;
		}
		base = (base * base) % MOD;
		N/= 2;
	}

	return result;
}

int main()
{
	long long N;
	long long beautiful;
	cout << "Enter a number" << endl;
	cin >> N;
	while (N < 3)
	{
		cout << "Wrong!Enter again!" << endl;
		cin >> N;
	}
	vector<vector<long long>>dp(N + 1, vector<long long>(4, 0));
	
	//0代表-+，1代表++，2代表+-,3代表两个--。
	dp[1][0] =1 ;
	dp[1][2] =1 ;
	for (int i = 2; i < N+1 ; i++)
	{
		dp[i][0] = (dp[i - 1][2]+dp[i-1][3])%MOD;
		dp[i][1] = dp[i - 1][0]%MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1])%MOD;
		dp[i][3] = dp[i - 1][2]%MOD ;
	}
	beautiful = dp[N][0] + dp[N][1] + dp[N][2] + dp[N][3];
	long long total = get_Mod(N);
	long long ugly = total - beautiful % MOD;
		cout << ugly;

}