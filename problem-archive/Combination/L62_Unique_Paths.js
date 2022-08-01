function combination(m, n) {
    let acc = 1;
    for (let i = m; i > n; i--) {
        acc *= i;
    }
    for (let i = 2; i <= (m - n); i++) {
        acc /= i;
    }
    return acc;
}

/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
    return combination(m + n - 2, n - 1);
};

console.log(uniquePaths(3, 7));
console.log(uniquePaths(3, 2));
