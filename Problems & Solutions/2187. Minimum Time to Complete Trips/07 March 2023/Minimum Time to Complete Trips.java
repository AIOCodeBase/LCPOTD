class Solution {
    public long minimumTime(int[] time, int totalTrips) {
    long lo = 1, hi = 100000000000000L;
    while (lo < hi) {
        long mid = lo + (hi - lo) / 2;
        if (!f(mid, totalTrips, time)) lo = mid + 1;
        else hi = mid;
    }
    return lo;
    }
    private boolean f(long x, int totalTrips, int[] time) {
        long sum = 0;
        for(int t: time) sum += x / t;
        return sum >= totalTrips;
    }
}