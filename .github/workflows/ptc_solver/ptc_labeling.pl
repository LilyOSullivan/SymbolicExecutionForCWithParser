%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Christophe Meudec
% Eclipse 7.1 program
% takes care of the labelling of variables in the solver's format
% various strategy could be implemented including the use of local search algorithms (Hill climbing, Tabu Search etc.)
%  see Eclipse sample programs
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
:- module(ptc_labeling).
:- export ptc_labeling__integers/2, ptc_labeling__integers/1, ptc_labeling__enums/1, ptc_labeling__reals/2, ptc_labeling__set_flag/2.
:- import ptc_enum__sample/1 from ptc_enum.
:- lib(ic).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
:- setval(epsilon, 0.001).	%precision wanted during labeling of breals
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ptc_labeling__set_flag(Flag, Value) :-
    (Flag == epsilon -> %the ic library also allows to set the intervals propagation threshold see the ic:set_threshold/1 predicate
        ((Value>0, Value<1) ->
            setval(epsilon, Value)
         ;
			ptc_solver:ptc_solver__error("In ptc_labeling__set_flag/2, the epsilon flag must be a decimal between 0 and 1 (e.g. 0.001) so the following is not allowed", Value)
        )
	;
		ptc_solver:ptc_solver__error("In ptc_labeling__set_flag/2, the following flag does not exist", Flag)
	).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%can fail, leave choice points
%make take a long time to complete on integers with very large intervals: may need a timeout
ptc_labeling__integers(L) :-
	ptc_labeling__integers(L, 'indomain_middle').	%this is the default

ptc_labeling__integers(L, ChoiceMethod) :-
	%the choice method could also be indomain_random (and use seed for reproducible choices)
	((ChoiceMethod == 'indomain_middle' ; ChoiceMethod == 'indomain_random') ->
		ic:search(L, 0, most_constrained, ChoiceMethod, complete, [])	%exhaustive search
	;
		ptc_solver:ptc_solver__error("ChoiceMethod argument in ptc_solver__label_integers/2 is invalid", ChoiceMethod)
	).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%can fail, leave choice points
%EL is the in list of original enumeration variables
%remark: EL can contain ground terms
ptc_labeling__enums([]).
ptc_labeling__enums([E|EL]) :-
	(nonground(E) ->
	    ptc_enum__sample(E)		%take a sample, can be resatisfied
	;
	    true
	),
	ptc_labeling__enums(EL).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%can fail, leave choice points
%VL is the list of IC vars (or breal numbers) to label
%returns as FL a list corresponding floats as approximation
%make take a long time to complete on reals with very large intervals: may need a timeout
ptc_labeling__reals(VL, FL) :-
	getval(epsilon, Precision),
	ic:locate(VL, VL, Precision, log),	%reduce the intervals of the vars in L, down to less than the precision given
										%the outcome is a list of breals or IC real vars: both representations are interval based
	force_instantiation(VL, FL).

%force the breals and IC Vars to become ground and returns a list corresponding floats as approximation
force_instantiation([], []).
force_instantiation([V|VL], [F|FL]) :-
	sample_ICVar(V),
	F is float(V),
	force_instantiation(VL, FL).

%can fail
%R is the real variable to sample
%constrain R to a value or fail
%the sampling is not exhaustive i.e. a failure does not indicate an absence of solution
% (contrast with sample_integer/1)
%remark: bias towards 0.0;
% with a domain size of 2000 about 18 samples are taken (3+5+5+5)
sample_ICVar(R) :-
	ic:get_float_bounds(R, InfR, SupR),
	SizeR is SupR - InfR,               %the size of the domaim of R
	frandom(N),
    Mid is InfR + (SizeR/2)*(0.95+N/10),%mid is chosen to be around +- 5 percent of the true middle
	(	R $= Mid
    ;	% choice point
	    R $= InfR
	;	% choice point
	    R $= SupR
	;	% choice point
	    sample_real_around(mid, R, Mid, SizeR, 0.1) %trying different samples around Mid
    ;	% choice point
	    sample_real_around(inf, R, InfR, SizeR, 0.1) %trying different samples around Inf
	;	% choice point
	    sample_real_around(sup, R, SupR, SizeR, 0.1) %trying different samples around Sup
	).

%can fail; choice points
%R is the real variable to sample
%Point is a point of the domain of R
%SizeR is the size of the domain of R
%the last argument, N, is a float which is increased after each recursion
% it is used to stop the recursion as well as to increase the gap between the mid point
% and the sample value generated after each recursion
sample_real_around(Region, R, Point, SizeR, Limit) :-
	(Limit > SizeR -> %arbritrary stop of the recursion
		(!,
	     fail
	    )
    ;
		(random(N1),
	     random(N2),
	     (N1 > N2 ->         %generate a standard deviation
			Deviation is N2/N1
	     ;
	        (Region == mid ->
                Deviation is -N1/N2
            ;
                Deviation is N1/N2
        	)
	    ),
%generate a sample value around the mid point, with limit increasing after each recursion
	    (Region == sup ->
            Sample is Point - Limit*Deviation
        ;
            Sample is Limit*Deviation + Point
        ),
	    (   R $= Sample            %try the sample
	    ;	% choice point
	    	(Next_limit is Limit*10, %increase the limit
		 	 sample_real_around(Region, R, Point, SizeR, Next_limit) %try again
	        )
	    )
	   )
	).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%