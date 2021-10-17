/**
 * @author Forrest Jablonski
 */

lexer grammar FacataTokens;

Plus         : '+'  ;
Minus        : '-'  ;
Times        : '*'  ;
Divide       : '/'  ;
Comma        : ','  ;
LeftParen    : '('  ;
RightParen   : ')'  ;
LeftBracket  : '['  ;
RightBracket : ']'  ;
Assign       : '<-' ;
Newline      : [\n] ;

Scale  : 'Scale'  ;
Trans  : 'Trans'  ;
Width  : 'Width'  ;
Height : 'Height' ;
Auto   : 'Auto'   ;
On     : 'On'     ;
Off    : 'Off'    ;

Integer    : Minus?([0] | [1-9][0-9]*) ;
Decimal    : Integer([.][0-9]+)?       ;

Whitespace : [ \t\r]+       -> skip ;
Comment    : ([/][/]~[\n]*) -> skip ;
