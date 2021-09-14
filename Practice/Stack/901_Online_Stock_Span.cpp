/*
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backward) for which the stock price was less than or equal to today's price.
*/
class StockSpanner {
public:
    StockSpanner() {}
    
    int next(int price) {
        int day = 1;
        while(s.size() && s.top().first <= price){
            day += s.top().second;
            s.pop();
        }
        s.push({price, day});
        return day;
    }
private:
    stack<pair<int,int>> s;
};