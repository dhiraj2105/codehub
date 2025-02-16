#include <bits/stdc++.h>
using namespace std;

class RecentCounter
{
private:
    queue<int> requests; // stores the timestamps of the requests

public:
    RecentCounter() {}
    int ping(int t)
    {
        requests.push(t);
        while (requests.front() < t - 3000)
        {
            requests.pop();
        }
        return requests.size();
    }
};

int main()
{
    /*
    You have a RecentCounter class which counts the number of recent requests within a certain time frame.

    Implement the RecentCounter class:

    RecentCounter() Initializes the counter with zero recent requests.
    int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, and returns the number of requests that has happened in the past 3000 milliseconds (including the new request). Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].
    It is guaranteed that every call to ping uses a strictly larger value of t than the previous call.
    */

    // Initantiate recentcounter object
    RecentCounter *obj = new RecentCounter();

    // test case 1 : pint with times 1,100,3001,3002
    cout << "Ping(1) : " << obj->ping(1) << endl;       // returns 1
    cout << "Ping(100) : " << obj->ping(100) << endl;   // returns 2
    cout << "Ping(3001) : " << obj->ping(3001) << endl; // returns 3
    cout << "Ping(3002) : " << obj->ping(3002) << endl; // returns 3
    return 0;
}