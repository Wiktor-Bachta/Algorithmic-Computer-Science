on(block1, block2).
on(block2, block3).
on(block3, block4).

above(Block1, Block2) :- on(Block1, Block2).
above(Block1, Block2) :- on(Block1, X), above(X, Block2).

