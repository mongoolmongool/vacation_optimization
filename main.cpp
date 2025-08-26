    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        int N, K, X;

        vector<int> total_wage;

        int first_check = 0; // 매일 일할 시 받는 wage.... yeoljeong pay!

        cin >> N >> K >> X;

        for(int i = 0; i < N; i++) {
            int a;
            cin >> a;
            total_wage.push_back(a);

            first_check += a * X;
        }

        // 먼저 휴가를 아예 못 나가는 경우를 제외한다.
        if(first_check <= K) {
            cout << -1 << '\n';
            return 0;
        }

        // i가 휴가의 길이
        for(int i = N - 1; i > 0; i--) {
            vector<int> adj_wage = total_wage;
            int earning = 0;

            for(int j = N - i - 1; j >= 0; j--) {
                earning += total_wage[j] * X;
                if(earning >= K) {
                    cout << i << '\n';
                    return 0;
                }
            }

            // d가 휴가 시작 idx
            for(int k = N - i - 1; k >= 0; k--) {
                earning -= total_wage[k] * X;
                earning += total_wage[k + i]; // 끝에 것을 더해줌;
                if(earning >= K) {
                    cout << i << '\n';
                    return 0;
                }              
            }
        }

        // 여기서 더 최적화를 하라고???????????

        return 0;
    }