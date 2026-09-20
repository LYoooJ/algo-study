using namespace std;

long long solution(int price, int money, int count)
{
    long long total_price = ((long long)((count + 1) * count) / 2) * price;
    return money >= total_price ? 0 : total_price - money;
}
    