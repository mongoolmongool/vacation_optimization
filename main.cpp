#include <bits/stdc++.h>
using namespace std;

// v길이의 휴가가 가능한가?
bool possible(const vector<int>& wage, int k, int x, int v) { 

    int earning = 0;
    int not_vac = wage.size() - v;

    int starting_idx = not_vac - 1;

    for(int i = 0; i < not_vac; i++) {
        earning += x * wage[starting_idx - i];

        if(earning >= k) {
            return true;
        }
    }

    for(int j = 0; j < not_vac; j++) {
        earning -= x * wage[starting_idx - j];
        earning += wage[wage.size() - 1 - j];

        if(earning >= k) {
            return true;
        }
    }

    return false;
}

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
        
    int vac_high = N - 1;
    int vac_low = 1;

    int mid = (vac_high + vac_low) / 2;

    int ans;

    while(vac_low <= vac_high) {
        mid = (vac_high + vac_low) / 2;

        if(possible(total_wage, K, X, mid)) {
            ans = mid;
            vac_low = mid + 1;
        }

        else{
            vac_high = mid - 1;
        }
    }

    cout << ans << '\n';
        
    return 0;
}