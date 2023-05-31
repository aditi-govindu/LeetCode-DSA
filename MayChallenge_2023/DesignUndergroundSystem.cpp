/*
Q1396. Description: An underground railway system is keeping track of customer travel times between different stations. They are using this data to calculate the average time it takes to travel from one station to another.

Implement the UndergroundSystem class:

void checkIn(int id, string stationName, int t)
A customer with a card ID equal to id, checks in at the station stationName at time t.
A customer can only be checked into one place at a time.
void checkOut(int id, string stationName, int t)
A customer with a card ID equal to id, checks out from the station stationName at time t.
double getAverageTime(string startStation, string endStation)
Returns the average time it takes to travel from startStation to endStation.
The average time is computed from all the previous traveling times from startStation to endStation that happened directly, meaning a check in at startStation followed by a check out from endStation.
The time it takes to travel from startStation to endStation may be different from the time it takes to travel from endStation to startStation.
There will be at least one customer that has traveled from startStation to endStation before getAverageTime is called.
You may assume all calls to the checkIn and checkOut methods are consistent. If a customer checks in at time t1 then checks out at time t2, then t1 < t2. All events happen in chronological order.
*/

class UndergroundSystem {
public:
    // Unordered maps of customer id - station id
    // Map start, end station to total travel time
    unordered_map<string, pair<long long, int>> stationTimes;
    unordered_map<int, pair<string,int>> inTransit;
    
    UndergroundSystem() 
    {
        stationTimes.clear();
        inTransit.clear();
    }
    
    void checkIn(int id, string stationName, int t) 
    {
        // If station not found in map, return
        if(inTransit.find(id) != inTransit.end())
            return;
        // Store id of customer, station they boarded and time of boarding
        inTransit[id] = {stationName, t};
        
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        // Auto increment station travelled
        auto& info = inTransit[id];
        string startStation = info.first;
        int startTime = info.second;
        string key = startStation + ":" + stationName;
        // Calculate travel time
        int time = t - startTime;
        if(stationTimes.find(key) != stationTimes.end())
        {
            // If end station not in stations, add to list and update travel time
            auto& oldTimes = stationTimes[key];
            oldTimes.first += time;
            oldTimes.second++;
        }
        else
        {
            // Set station as visited
            stationTimes[key] = {time,1};
        }
        // Remove customer id from travelling list
        inTransit.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        // Calculate average travel time
        string key = startStation + ":" + endStation;
        auto& info = stationTimes[key];
        double avg = (double)info.first / (double)info.second;
        return avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */