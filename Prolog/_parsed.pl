function(int,get_sign,[int(X)],
    body([
        ifStmt(X=0,
            [return(0)]),
        ifStmt(X<0,
            [return(-1)],
        [return(1)])
    ])
).

function(int,get_sign,[int(X)],[
        if_stmt(X=0,[return(0)]),
        if_stmt(X<0,
            [return(-1)],
        [return(1)])
    ]
).
function(int,get_sign,[int(X)],[if_stmt(X=0,[return(0)]),if_stmt(X<0,[return(-1)],[return(1)])]).
function(int,get_sign,[int(X)],[if_stmt(X=0,[return(0)]),if_stmt(X<0,[return(-1)],[return(1)])]).

function(int,get_sign,[int(X)],[if_stmt(X=0,[return(0)   ]   ),if_stmt(X<0,[return(-1)   ]   ,[return(1)])]).


function(int,assignment,[int(X)],[assignment(int(Z),5),return(Z)]).



function(int,defer_test,[int(X)],[assignment(int(Z),extern(ADDONE(X),"addOne")),
                                    if_stmt(X>0 and Z>0,
                                        [return(1)],
                                    [return(0)])
                                ]).

function(int,defer_test,[int(X)],[assignment(int(Z),extern(f(X),"library.so")),if_stmt(X>0 and Z>0,[return(1)],[return(0)])]).