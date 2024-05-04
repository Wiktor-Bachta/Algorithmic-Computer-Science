% algorytm Kadane

max_sum(L, S) :-
	helper(0, 0, L, S).

helper(_, S, [], S).

helper(Old_max_ending_here, Old_max_so_far, [X|L], S) :-
	New_max_ending_here is max(X, Old_max_ending_here + X),
	New_max_so_far is max(Old_max_so_far, New_max_ending_here),
	helper(New_max_ending_here, New_max_so_far, L, S).