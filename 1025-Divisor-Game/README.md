### 1025. Divisor Game

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < N and N % x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.

Return True if and only if Alice wins the game, assuming both players play optimally.

#### Example 1:

Input: 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.

#### Example 2:

Input: 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.


Note:

1 <= N <= 1000

### Prove

- If N is even, then Alice can choose 1 at every step, then the oppnent will get 1 at last to lose the game.
- If N is odd, Alice will lose the game.  Following is the prove:
    1. Because N is odd, we can suppose N = 2n + 1.
    2. We choose x to substract, x s.t. N % x = 0, 1 < x < N. So x must be 2m + 1.
    3. Then we get the new N by N - x = (2n + 1) - (2m + 1) = 2(n - m), that is an even number. So the opponent can beat us by choosing 1. We lose the game.
