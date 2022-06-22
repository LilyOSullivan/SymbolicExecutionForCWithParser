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

function(int,get_sign,[int(X)],[if_stmt(X=0,[return(0)]),if_stmt(X<0,[return(-1)],[return(1)])]).

function(int,get_sign,[int(X)],[assignment(int(Z),5),if_stmt(X=0,[return(1)]),if_stmt(X<0,[return(-1)],[return(1)])]).