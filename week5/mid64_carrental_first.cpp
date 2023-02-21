#include<bits/stdc++.h>
using namespace std;

int numCars(vector<int> box, int carMaxWeight){
    sort(box.begin(), box.end());
    int i = 0, j = box.size() - 1;
    int ans = 0;
    while (i <= j) {
        ans++;
        if (box[i] + box[j] <= carMaxWeight)
            i++;
        if (box[j] > carMaxWeight)
        {
            return 0;
        }
        j--;
    }
    return ans;

    // int countCar = 0, totalWeight = 0;
    // for (int i = 0 ; i < box.size(); i++)
    // {
    //     if (box[i] > carMaxWeight && totalWeight == 0)
    //         return 0;
    //     if (box[i] + totalWeight <= carMaxWeight){
    //         totalWeight += box[i];
    //         box.erase(box.begin() + i);
    //     }
    //     else {
    //         countCar++;
    //         totalWeight = 0;
    //         if (box[i] > carMaxWeight && totalWeight == 0)
    //             return 0;
    //         totalWeight += box[i];
    //         box.erase(box.begin() + i);
    //     }
    // }
    // if (totalWeight != 0)
    //     countCar++;
    // return countCar;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int K,N;
    cin >> K >> N;
    int contract[K][3];
    for (int i = 0 ; i<K; i++)
        cin >> contract[i][0] >> contract[i][1] >> contract[i][2];

    vector<int> w_package;
    for (int i = 0; i < N; i++){
        int a;
        cin >> a;
        w_package.push_back(a);
    }

    vector<int> ls_cost;
    for (int i = 0; i < K; i++){
        if (numCars(w_package, contract[i][2]) == 0)
            continue;
        ls_cost.push_back(contract[i][1] * numCars(w_package, contract[i][2]) + contract[i][0]);
        cout << i << " " << numCars(w_package, contract[i][2]) << " " << ls_cost[i] << endl;
    }
    cout << *min_element(ls_cost.begin(), ls_cost.end());


    return 0;
}