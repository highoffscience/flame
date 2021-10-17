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
Return : 'Return' ;
Or     : 'Or'     ;
Sin    : 'Sin'    ;
Cos    : 'Cos'    ;
Tan    : 'Tan'    ;
Color  : 'Color'  ;

Keyword    : [A-Z][a-zA-Z0-9]*         ;
Identifier : [a-z][a-zA-Z0-9]*         ;
Integer    : [0] | (Minus?[1-9][0-9]*) ;
Decimal    : Integer([.][0-9]+)?       ;

Whitespace : [ \t\r]+       -> skip ;
Comment    : ([/][/]~[\n]*) -> skip ;
