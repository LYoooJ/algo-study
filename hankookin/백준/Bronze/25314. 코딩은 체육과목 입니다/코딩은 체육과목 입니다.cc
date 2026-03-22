#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int count = N / 4;
    for (int i = 0; i < count; i++) {
        cout << "long ";
    }

    // 마지막에 "int"를 출력합니다.
    cout << "int" << endl;

    return 0;
}