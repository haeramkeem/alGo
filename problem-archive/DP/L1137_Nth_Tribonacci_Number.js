/**
 * @param {number} n
 * @return {number}
 */
var tribonacci = function(n) {
    if (n < 1) {
        return 0;
    }

    let r0 = 0;
    let r1 = 1;
    let r2 = 1;
    let t0 = 0;
    let t1 = 0;
    for (let i = 2; i < n; i++) {
        t0 = r1;
        t1 = r2;
        r2 += r1 + r0;
        r0 = t0;
        r1 = t1;
    }
    return r2;
};

console.log(tribonacci(4));
console.log(tribonacci(25));
