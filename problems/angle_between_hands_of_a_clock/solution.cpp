class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour == 12)
            hour = 0;
        // double k = minutes;
        double h = (hour + (minutes/60.00))*30;
        // h = h * 30.00;
        double m = minutes * 6;
        if(abs(h-m) > 180)
            return 360-abs(h-m);
        return abs(h-m);
        
    }
};