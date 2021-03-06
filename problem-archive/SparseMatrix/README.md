# Binary Lifting

## Step 1. Making Tree Structure
* To initiate binary lifting, we need to prepare child-parent relationship and depth information for all nodes.
* So make them while traverse all the nodes.
- - - -
## Step 2. Making Exponent-Parent Array
### What is it?
* _Exponent-Parent Array_ is the two-dimension array that `expParent[i][j]` holds `node i`’s `2^j`-th parent.
* So, when given tree looks like this :
```
0 -- 1 -- 2 -- 3 -- 4
  |- 5 -- 6
  |- 7
```
* We can make _Exponent-Parent Array_ like this :
```
ij|	0	1	2	3
--+-----------------
0 |	-1	-1	-1	-1
1 |	0	-1	-1 	-1
2 |	1	0	-1	-1
3 |	2	1	-1	-1
4 |	3	2	0	-1
5 |	0	-1	-1	-1
6 |	5	0	-1	-1
7 |	0	-1	-1	-1
```
* In the example above, non-existent nodes are filled with -1.
### How to make it?
* First thing we have to do is making `N X (log2(N) + 1)` array.
* When N is number of nodes, Beware of the size of row is (of course) N, but **Size of column** must be bigger than or equal to `log2(N) + 1`.
* It’s because leaf nodes can be lifted maximum `log2(n) + 1` (when all nodes are linked linearly)
* And then you can fill all the elements of array by :
```
exp[i][j] = exp[exp[i][j - 1]][j - 1];
```
* It’s because **n-th parent’s n-th parent is 2n-th parent** - _4th parent’s 4th parent is 8th parent._
* So, to calculate `exp[i][j]`, we need to get `exp[i][j - 1]` first. It means `node i`’s `2^(j - 1)`-th parent.
* When value of `exp[i][j - 1]` is valid (not -1), next thing we have to do is getting `exp[exp[i][j - 1]][j - 1]`. It means `node i`’s `2^(j - 1)`-th parent’s `2^(j - 1)`-th parent.
* In the example above, when calculating `exp[4][2]`,  `exp[4][1]`is 2 and `exp[2][1]`is 0. So, `exp[4][2]` is 0.
- - - -
## Step 3. Make both nodes the same height
* The basic principle of this algorithm is to make both nodes the same height and lift both nodes directly below the LCA(Lowest Common Ancestor).
* So, we have to flatten the height of two nodes first. It can be done with binary operation.
* For example, when difference between height of two nodes is 5, lifting lower node 1 and 4 step up will make both nodes the same height.
* So swapping `node i`with `exp[i][0]`and then swapping again with `exp[i][2]` will make this happen.
- - - -
## Step 4. Lift both nodes directly below the LCA
* Lifting both nodes directly below the LCA is similar with step 3, but the difference is that we don’t know how much to lift.
* So, we might try the largest lift first, then the next largest lifts sequentially:
```
for(int liftIdx = log2N; listIdx >= 0; liftIdx--) {

	// Check if value is valid.
	if(exp[node1][liftIdx] != -1) {

		// Check if two lifted value is not equal.		
		if(exp[node1][liftIdx] != exp[node2][liftIdx]) {
			node1 = exp[node1][liftIdx];
			node2 = exp[node2][liftIdx];
		}
	}
}
```
* Beware that two lifted value has to be different.
* Because you’re trying to find node that is directly below the LCA, not LCA itself.
* The reason we are trying the largest is that the purpose of this is to find the node directly below the LCA, so we need to find the two highest parent nodes with unequal values.
* After we found target nodes, their parent node is the Lowest Common Ancestor.
