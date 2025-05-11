https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1 

Hint :  Priority Queue 


double fractionalKnapsack(vector<int>& val, vector<int>& wt, int c) {
        vector<int>frac; 
        for(int i=0;i<val.size();i++) 
        {
            frac.push_back(val[i]/wt[i]); 
        }
         priority_queue<pair<double, pair<int, int>>> pq;

    for (int i = 0; i < val.size(); i++) 
    {
        double ratio = (double)val[i] / wt[i];
        pq.push({ratio, {val[i], wt[i]}});
    }

    double ans = 0; 

    while (!pq.empty() && c > 0)
    {
        auto top = pq.top(); 
        pq.pop();

        int value = top.second.first;
        int weight = top.second.second;
        double ratio = top.first;

        if (weight <= c) 
        {
            ans += value;
            c -= weight;
        } 
        else 
        {
            ans += c * ratio;
            c = 0;
        }
    }
    return ans; 
    }

