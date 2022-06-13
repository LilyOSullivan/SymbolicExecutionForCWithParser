function(int,get_sign,[int(X)],
    body([
        ifStmt(X=0,
            [return(0)]),
        ifStmt(X<0,
            [return(-1)],
        [return(1)])
    ])
).

function(int,get_sign,[int(X)],[ifStmt(X<0,[return(-1)])]).
function(int,get_sign,[int(X)],[ifStmt(X=0,[return(-1)],[return(1)])]).

function(int,get_sign,[int(X)],[ifStmt(X=0,[return(0)]),ifStmt(X<0,[return(-1)],[return(1)])]).