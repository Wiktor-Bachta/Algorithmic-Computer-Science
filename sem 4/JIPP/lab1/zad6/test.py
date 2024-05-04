import wrapper as l

def test_factorial_loop():
    assert l.python_factorial_loop(0) == 1
    assert l.python_factorial_loop(1) == 1
    assert l.python_factorial_loop(5) == 120


def test_gcd_loop():
    assert l.python_gcd_loop(12, 18) == 6
    assert l.python_gcd_loop(35, 49) == 7
    assert l.python_gcd_loop(17, 23) == 1


def test_diophatine_loop():
    solution = l.Solution_loop(2, 3, 5)
    assert solution.exists == True
    assert (solution.x * 2 + solution.y * 3 == 5)

    solution = l.Solution_loop(3, 6, 9)
    assert solution.exists == True
    assert (solution.x * 3 + solution.y * 6 == 9)


def test_factorial_rec():
    assert l.python_factorial_rec(0) == 1
    assert l.python_factorial_rec(1) == 1
    assert l.python_factorial_rec(5) == 120


def test_gcd_rec():
    assert l.python_gcd_rec(12, 18) == 6
    assert l.python_gcd_rec(35, 49) == 7
    assert l.python_gcd_rec(17, 23) == 1


def test_diophatine_rec():
    solution = l.Solution_rec(2, 3, 5)
    assert solution.exists == True
    assert (solution.x * 2 + solution.y * 3 == 5)
    
    solution = l.Solution_rec(3, 6, 9)
    assert solution.exists == True
    assert (solution.x * 3 + solution.y * 6 == 9)


if __name__ == "__main__":
    print("Running tests...")
    test_factorial_loop()
    test_gcd_loop()
    test_diophatine_loop()
    test_factorial_rec()
    test_gcd_rec()
    test_diophatine_rec()
    print("All tests passed!")
