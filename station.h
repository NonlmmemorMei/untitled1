#ifndef STATION_H
#define STATION_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <QDebug>

using namespace std;

vector <int> res;

class Station
{
    string mCall, mColor;
    double mFrequency;
    double pDelta, pRes1, pRes2;
    int pK;
    double pTmp;

    public:
        Station(double pDelta, int pK, string mCall, string mColor, double mFrequency)
            {
                this->pDelta = pDelta;
                this->pK = pK;
                this->mColor = mColor;
                this->mCall= mCall;
                this->mFrequency = mFrequency;
            }

        double getpDelta()
        {
            return pDelta;
        }

        int getPk()
        {
            return pK;
        }

        string getCall()
        {
            return mCall;
        }

        string getColor()
        {
            return mColor;
        }

        double getFrequency()
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
                cout << "[STATION_]"<< i << endl;
                cout << "call_sign = "<< mCall << i << endl;
                cout << "color = " << mColor << endl;
                cout << "frequency = " << res[i] << endl;
                cout << endl;
            }
        }
};
#endif // STATION_H
