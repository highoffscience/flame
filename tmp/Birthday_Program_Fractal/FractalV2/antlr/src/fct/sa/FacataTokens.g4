/**
 * @author Forrest Jablonski
 */

lexer grammar FacataTokens;

Equal        : '='  ;
NotEqual     : '~'  ;
Plus         : '+'  ;
Minus        : '-'  ;
Times        : '*'  ;
Divide       : '/'  ;
Comma        : ','  ;
Less         : '<'  ;
Greater      : '>'  ;
LeftParen    : '('  ;
RightParen   : ')'  ;
LeftBracket  : '['  ;
RightBracket : ']'  ;
LessEqual    : '<=' ;
GreaterEqual : '>=' ;
Assign       : '<-' ;
Newline      : [\n] ;

If     : 'If'     ;
End    : 'End'    ;
And    : 'And'    ;
Or     : 'Or'     ;
Pre    : 'Pre'    ;
Post   : 'Post'   ;
Ias    : 'Ias'    ;
Ifs    : 'Ifs'    ;
None   : 'None'   ;

Matrix     : [M][0-9]+                   ;
Keyword    : [A-Z][a-zA-Z0-9]*           ;
Identifier : [a-z][a-zA-Z0-9_]*          ;
Integer    : Minus?([0] | ([1-9][0-9]*)) ;
Decimal    : Integer([.][0-9]+)?         ;

Whitespace : [ \t\r]+       -> skip ;
Comment    : ([/][/]~[\n]*) -> skip ;
