#include <bits/stdc++.h>

using namespace std;

pair<int, int> tarotora[1000];
int aa[1000];
int bb[1000];
int n, k;

int hp(int i, int a, int b)
{
    int taro = tarotora[i].first;
    int tora = tarotora[i].second;
    int x, y;
    if (i == 0)
    {
        aa[i] = bb[i] = 1;
    }
    if(abs(a-b)>k){
        return 100000;
    }
    if (i + 1 < n)
    {
        x = taro + hp(i + 1, a+1,b);
        y = tora + hp(i + 1, a,b+1);
        return min(x, y);
    }
    return 0;
}

int main()
{
    int c;
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> n >> k;
        for (int j = 0; j < n; j++)
        {
            int a, b;
            cin >> a >> b;
            tarotora[j] = {a, b};
        }
        int HP = hp(0, 0, 0);
        cout << HP << "\n";
    }
}

/*
2
4 2
1 2
1 2
1 2
1 2
4 2
5 2
2 5
5 2
2 5
*/

/*
1
5 2
1 2
1 100
1 2
1 100
1 2
*/

/*
1
5 2
1 2
1 2
1 100
1 100
1 2
*/

/*
3163 5860
159 2633
2976 1560
2076 9322
9986 7209
66 2179
6640 7091
9132 5401
3033 7988
7367 1079
8012 9987
884 5884
700 1310
9237 7570
6764 8916
5119 5752
591 7488
6157 8260
9743 9805
4333 5806
6584 2641
6262 8473
4200 8083
6583 818
698 8731
8150 6550
759 160
6936 7966
9527 2997
3117 8854
9446 5493
9286 1886
448 3695
759 8240
560 4715
4491 6396
9457 2837
3257 8482
3181 8072
2702 1110
1453 5383
2179 7515
6773 1363
9540 6285
5682 2112
2101 5413
9435 6634
1151 2067
3385 2007
5946 1094
8719 7732
9966 9986
2468 6680
2949 471
3292 2028
3791 4768
2390 6267
2758 6184
4339 5212
9548 3045
1071 5041
4 4672
7363 4145
3226 9328
5419 6132
9962 40
3498 4107
334 31
4874 8288
1644 4793
3989 586
7857 6516
5305 7361
6189 7904
5028 6569
1173 1937
7016 9218
2818 7240
3532 1368
1248 4399
9177 9600
7115 3878
4543 7941
3870 7283
6132 779
6712 6646
2437 3386
80 3934
9009 5777
3620 6158
8879 7928
6761 885
897 9567
4762 5964
5081 4064
2062 7809
3985 2122
2611 8031
6659 5000
3167 7398
7522 2083
5743 8242
9137 7147
6674 6692
8087 2169
5073 21
6155 2950
889 9621
229 6044
7987 6391
4458 4363
7610 5676
6973 9105
6217 152
5390 7407
4219 5980
1626 4211
1447 1911
6429 4855
1185 482
2610 9892
9255 943
4479 8358
8711 1638
3275 6205
4911 7632
6491 7264
1594 6116
1341 7509
5458 3621
2013 9316
2601 5209
3038 4209
5176 52
1678 2803
7137 8484
1820 2064
756 1181
9176 4883
4726 365
1652 7968
8754 941
2880 669
7018 1916
8167 4628
6255 2801
4748 6158
5938 3196
3436 9446
6421 8444
8666 5644
926 1628
1152 361
6310 1551
2453 5939
6478 6212
5701 2340
1861 4226
6241 9738
5514 8190
803 4477
722 2668
8981 7896
2586 2911
8948 7231
8250 1170
7764 8901
2606 5819
8336 9076
1917 4477
8920 461
7017 1147
9749 3778
1178 5171
5691 7895
4411 7002
6059 2330
7786 3087
2747 3757
6364 9806
657 9494
9720 9346
1215 6260
7848 419
9480 7533
937 8356
1490 7332
8933 8774
2558 416
3090 5052
5764 1551
3847 173
6207 4721
7634 5431
3753 1073
7978 1847
7799 8012
798 3461
9614 2084
1125 1492
2512 2272
9595 7905
7541 9044
7128 9701
608 5090
7199 5126
3030 5846
4645 2780
891 28
2968 3401
500 6909
3711 9964
7226 9901
2928 4655
5955 6408
8949 1858*/