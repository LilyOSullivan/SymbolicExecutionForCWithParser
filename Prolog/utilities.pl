write_to_file(LibraryName,Params,ResultOfCall) :-
    concat_string([LibraryName,".txt"],Filename),
    open(Filename,append,Stream),
    write(Stream,Params),
    write(Stream,ResultOfCall),
    write(Stream,'\n'),
    close(Stream).