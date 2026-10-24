
class Solution {
public:
    int convert(string date) {
        int m[] = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        for (int i = 0; i < month - 1; i++) {
            day += m[i];
        }

        return day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int sAlice = convert(arriveAlice);
        int eAlice = convert(leaveAlice);

        int sBob = convert(arriveBob);
        int eBob = convert(leaveBob);

        int start = max(sAlice, sBob);
        int end = min(eAlice, eBob);

        if (start > end) {
            return 0;
        }
        return end - start+1;
    }
};