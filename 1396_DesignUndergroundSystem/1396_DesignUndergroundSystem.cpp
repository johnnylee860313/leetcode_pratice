class UndergroundSystem {
public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        customer[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        int time = t - customer[id].second;
        string routesName = customer[id].first+"-"+stationName;
        routes[routesName].first += time;
        routes[routesName].second += 1;

        customer.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        string routesName = startStation+"-"+endStation;
        return (double) routes[routesName].first / routes[routesName].second; 
    }

private:
    /* customer[id] = {station,time} */
    /* routes["endStation-startStation"] = {totaltime, personCount}*/
    unordered_map<int, pair<string, int>> customer;
    unordered_map<string, pair<long, int>> routes;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */