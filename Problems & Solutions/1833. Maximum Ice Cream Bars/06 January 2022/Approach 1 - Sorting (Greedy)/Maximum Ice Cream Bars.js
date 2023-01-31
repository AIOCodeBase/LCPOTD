var maxIceCream = function(costs, coins) {
    costs.sort((num1, num2) => num1 - num2);

    let n = costs.length;
    let icecream = 0;

    while (icecream < n && costs[icecream] <= coins) {
        coins -= costs[icecream];
        icecream += 1;
    }

    return icecream;
};