    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        int N, K, X;

        vector<int> total_wage;
        vector<int> sum_from_begin;
        vector<int> sum_from_end;

        int first_check = 0; // 매일 일할 시 받는 wage.... yeoljeong pay!

        cin >> N >> K >> X;

        sum_from_end.resize(N);

        for(int i = 0; i < N; i++) {
            int a;
            cin >> a;
            total_wage.push_back(a);

            first_check += a * X;
        }

        sum_from_begin.push_back(total_wage[0]);
        sum_from_end[N-1] = total_wage[N -1];

        for(int i = 1; i < N; i++) {
            sum_from_begin.push_back(sum_from_begin[i - 1] + total_wage[i]);
            sum_from_end[N - 1 - i] = sum_from_end[N - i] + total_wage[N - 1 - i];
        }

        // 먼저 휴가를 아예 못 나가는 경우를 제외한다.
        if(first_check <= K) {
            cout << -1 << '\n';
            return 0;
        } 

        int n = 1; // p will be 1, 2, 4, 8, 16....
        int p = 0;
        bool success = false;

        while(!success) {
            int len_not_vac = n;

            if(len_not_vac > N) {
                break;
            }

            int earning = 0;

            int starting_index = n - 1;

            for(int i = 0; i < n + 1; i++) {

                if(i == 0) {
                    earning = X * sum_from_begin[starting_index];
                }

                else if(i == n) {
                    earning = sum_from_end[N - i];
                }

                else {
                    earning = X * sum_from_begin[starting_index - i] 
                                + sum_from_end[N - i];

                }

                if(earning >= K) {
                    success = true;
                    break;
                }
            }
            
            if(success) {
                break;
            }

            n *= 2;
            p++; // log(N), n의 지수
        }

        // 이제 최종적으로 나온 p가 있을거 아냐?

        int n_min;
        if(n / 2 == 0) {
            cout << N - n << '\n';
            return 0;
        }

        else {
            n_min = n / 2;
        }

        bool success_2 = false;

        while(!success_2) {
            int len_not_vac = n_min;

            int earning = 0;

            int starting_index = n_min - 1;

            for(int i = 0; i < n_min + 1; i++) {
                if(i == 0) {
                    earning = X * sum_from_begin[starting_index];
                }

                else if(i == n_min) {
                    earning = sum_from_end[N - i];
                }

                else {
                    earning = X* sum_from_begin[starting_index - i] 
                                + sum_from_end[N - i];

                }

                if(earning >= K) {
                    success_2 = true;
                    break;
                }
            }

            if(success_2) {
                break;
            }

            n_min ++; // 위와 다른점!
        }

        int vac = N - n_min;

        cout << vac << '\n';
        
        // // X*total_wage.front()이랑 total_wage.back()이랑 비교해서 큰 애를 pop해서 earning에 더함
        // total_wage를 deque으로 해본 버전

        // int vac;
        // int earning = 0;
        // bool success = false;

        // while(!success) {
            
        //     if(X * total_wage.front() >= total_wage.back()) {
        //         earning += X * total_wage.front();
        //         total_wage.pop_front();
        //     }

            
        //     else {
        //         earning += total_wage.back();
        //         total_wage.pop_back();                
        //     }

        //     if(earning >= K) {
        //         vac = total_wage.size();
                
        //     }
        // }

        return 0;
    }