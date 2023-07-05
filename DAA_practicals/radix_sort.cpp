#include <bits/stdc++.h>
using namespace std;

class radix_sort
{

    void counting(vector<int> &arr, int itr)
    {
        vector<int> org = arr;
        map<int, int> mapy;

        for (auto x : arr)
        {    
            int temp=x;
            int ans=x;
            for (int i = 0; i < itr; i++){
                 ans=temp%10;
                 temp=temp/10;
            }

            mapy[ans] = mapy[ans] + 1;
        }

        arr.clear();

        vector<int>::iterator it = org.begin();
        for (auto ele : mapy)
        {
            for (int b = 0; b < ele.second; b++)
            {
                it = org.begin();
                for (int i = 0; i < org.size(); i++, it++)
                {
                    int ans = org[i];
                    int temp=org[i];
        
                    for (int k = 0; k < itr; k++)
                    {   
                        ans = temp % 10;
                        temp=temp/10;
                    }
                    if ( ans == ele.first)
                    {
                        arr.push_back(org[i]);
                        org.erase(it);
                        i--;
                        it--;
                    }
                }
            }
        }
    }

public:
    void sort(vector<int> &arr)
    {
        int maxi = *(max_element(arr.begin(), arr.end()));
        int count = 0;
        while (maxi != 0)
        {
            maxi = maxi/10;
            count++;
        }

        for (int i = 1; i <= count; i++)
        {
            counting(arr, i);
        }
    }
};

int main()
{
    vector<int> ans = {333, 45,2,3,1,4,5,77,2344};
    radix_sort x;
    x.sort(ans);
    for (auto y : ans)
    {
        cout << y << " ";
    }
    cout << endl;
    return 0;
}