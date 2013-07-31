#ifndef STATION_H
#define STATION_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector <int> res;

class Station
{
    string mCall, mColor;
    int mFrequency;
    int pDelta, pK, pRes1, pRes2;
    int pTmp;

    public:
        Station(int pDelta, int pK, int mFrequency)
            {
                this->pDelta = pDelta;
                this->pK = pK;
                this->mFrequency = mFrequency;
            }
        int getPk()
        {
            return pK;
        }

        int getpDelta()
        {
            return pDelta;
        }

        int getFrequency()
        {
            return mFrequency;
        }

        void error()
        {

            res.push_back(mFrequency);

            for(int i = 1; i <= pK; ++i)
            {
                pTmp = pDelta * i;
                pRes1 = mFrequency + pTmp;
                res.push_back(pRes1);
                pRes2 = mFrequency - pTmp;
                res.push_back(pRes2);
            }
            sort(res.begin(), res.end());
        }

        void output()
        {
            for(int i = 0; i < res.size(); ++i)
            {
                cout << "[STATION 1]" << endl;
                cout << "call_sign = NNA_" << i << endl;
                cout << "color = r" << endl;
                cout << "frequency = " << res[i] << endl;
                cout << endl;
            }
        }
};


#endif // STATION_H
