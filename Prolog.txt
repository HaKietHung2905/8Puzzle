% goal state
goal(state(1,2,3,4,5,6,7,8,*)).

%dfs
dfs([State|States], [], Path) :-goal(State), !, reverse([State|States], Path).
dfs([State|States], [Move|Moves], Path) :-
   moveState(State, Next, Move),
   \+member(Next, [State|States]),
   dfs([Next,State|States], Moves, Path).


print_path([], _).
print_path([Move|Moves], [State|States]) :-
   State = state(X1,X2,X3,X4,X5,X6,X7,X8,X9),
   format('~n ~w ~n ~n', [Move]),
   format('~w ~w ~w~n',[X1,X2,X3]),
   format('~w ~w ~w~n',[X4,X5,X6]),
   format('~w ~w ~w~n',[X7,X8,X9]),
   print_path(Moves, States).

%Bottom Move
moveState(state(X1,X2,X3,X4,X5,X6,*,X8,X9), state(X1,X2,X3,X4,X5,X6,X8,*,X9), botleft ).
moveState(state(X1,X2,X3,X4,X5,X6,*,X8,X9), state(X1,X2,X3,*,X5,X6,X4,X8,X9), botup).
moveState(state(X1,X2,X3,X4,X5,X6,X7,*,X9), state(X1,X2,X3,X4,X5,X6,*,X7,X9), botlef).
moveState(state(X1,X2,X3,X4,X5,X6,X7,*,X9), state(X1,X2,X3,X4,*,X6,X7,X5,X9), botup).
moveState(state(X1,X2,X3,X4,X5,X6,X7,*,X9), state(X1,X2,X3,X4,X5,X6,X7,X9,*), botright).
moveState(state(X1,X2,X3,X4,X5,X6,X7,X8,*), state(X1,X2,X3,X4,X5,*,X7,X8,X6), botup).
moveState(state(X1,X2,X3,X4,X5,X6,X7,X8,*), state(X1,X2,X3,X4,X5,X6,X7,*,X8), botleft).

%Top Move
moveState(state(*,X2,X3,X4,X5,X6,X7,X8,X9), state(X2,*,X3,X4,X5,X6,X7,X8,X9), topright).
moveState(state(*,X2,X3,X4,X5,X6,X7,X8,X9), state(X4,X2,X3,*,X5,X6,X7,X8,X9), topdown).
moveState(state(X1,*,X3,X4,X5,X6,X7,X8,X9), state(*,X1,X3,X4,X5,X6,X7,X8,X9), topleft).
moveState(state(X1,*,X3,X4,X5,X6,X7,X8,X9), state(X1,X3,*,X4,X5,X6,X7,X8,X9), topright).
moveState(state(X1,*,X3,X4,X5,X6,X7,X8,X9), state(X1,X5,X3,X4,*,X6,X7,X8,X9), topdown).
moveState(state(X1,X2,*,X4,X5,X6,X7,X8,X9), state(X1,*,X2,X4,X5,X6,X7,X8,X9), topleft).
moveState(state(X1,X2,*,X4,X5,X6,X7,X8,X9), state(X1,X2,X6,X4,X5,*,X7,X8,X9), topdown).

%Middle Move
moveState(state(X1,X2,X3,*,X5,X6,X7,X8,X9), state(*,X2,X3,X1,X5,X6,X7,X8,X9), midup).
moveState(state(X1,X2,X3,*,X5,X6,X7,X8,X9), state(X1,X2,X3,X5,*,X6,X7,X8,X9), midright).
moveState(state(X1,X2,X3,*,X5,X6,X7,X8,X9), state(X1,X2,X3,X7,X5,X6,*,X8,X9), middown).
moveState(state(X1,X2,X3,X4,*,X6,X7,X8,X9), state(X1,*,X3,X4,X2,X6,X7,X8,X9), midup).
moveState(state(X1,X2,X3,X4,*,X6,X7,X8,X9), state(X1,X2,X3,X4,X6,*,X7,X8,X9), midright).
moveState(state(X1,X2,X3,X4,*,X6,X7,X8,X9), state(X1,X2,X3,X4,X8,X6,X7,*,X9), middown).
moveState(state(X1,X2,X3,X4,*,X6,X7,X8,X9), state(X1,X2,X3,*,X4,X6,X7,X8,X9), midleft).
moveState(state(X1,X2,X3,X4,X5,*,X7,X8,X9), state(X1,X2,*,X4,X5,X3,X7,X8,X9), midup).
moveState(state(X1,X2,X3,X4,X5,*,X7,X8,X9), state(X1,X2,X3,X4,*,X5,X7,X8,X9), midleft).
moveState(state(X1,X2,X3,X4,X5,*,X7,X8,X9), state(X1,X2,X3,X4,X5,X9,X7,X8,*), middown).
