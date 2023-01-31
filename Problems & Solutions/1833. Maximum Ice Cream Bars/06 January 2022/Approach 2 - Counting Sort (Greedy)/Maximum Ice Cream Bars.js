var maxIceCream = function(costs, coins) {
    let n = costs.length;
    let icecreams = 0;
    let m = Math.max(...costs);

    let costsFrequency = Array(m + 1).fill(0);
    for (let cost of costs) {
        costsFrequency[cost] += 1;
    }

    for (let cost = 1; cost <= m; ++cost) {
        if (!costsFrequency[cost]) {
            continue;
        }
        if (coins < cost) {
            break;
        }
        
        let count = Math.min(costsFrequency[cost], Math.floor(coins / cost));
        coins -= cost * count;
        icecreams += count;
    }

    return icecreams;
};