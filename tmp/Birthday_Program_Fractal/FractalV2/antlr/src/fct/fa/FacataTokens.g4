/**
 * @author Forrest Jablonski
 */

lexer grammar FacataTokens;

Plus         : '+'  ;
Minus        : '-'  ;
Times        : '*'  ;
Divide       : '/'  ;
LeftParen    : '('  ;
RightParen   : ')'  ;
Assign       : '<-' ;
Newline      : [\n] ;

Width  : 'Width'  ;
Height : 'Height' ;
NIters : 'NIters' ;
Gamma  : 'Gamma'  ;

Integer    : [0] | (Minus?[1-9][0-9]*) ;
Decimal    : Integer([.][0-9]+)?       ;

Whitespace : [ \t\r]+       -> skip ;
Comment    : ([/][/]~[\n]*) -> skip ;
