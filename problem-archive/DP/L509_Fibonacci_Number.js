/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    if (n < 1) {
        return 0;
    }

    let t0 = 0;
    let t1 = 1;
    let t2 = 0;
    for (let i = 1; i < n; i++) {
        t2 = t1;
        t1 += t0;
        t0 = t2;
    }

    return t1;
};

console.log(fib(2));
console.log(fib(3));
console.log(fib(4));
