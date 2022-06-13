%{
/* c language declarations and includes*/

#include <string>
#include "y.tab.hpp"
//#include "symtype.hpp"


#define LIST     {strcat(buf,yytext);}
#define PLINE    {buf2 += yytext;}
#define token(t) {LIST; PLINE; if(Opt_T) printf("<%s>\n", #t); return t;}
#define tokenInteger(t,i) {LIST; PLINE; if(Opt_T) printf("<%s:%d>\n", #t, i);}
#define tokenString(t,s) {LIST; PLINE; if(Opt_T) printf("<%s:%s>\n",#t, s); } 
#define tokenReal(t,s) {LIST; PLINE; if(Opt_T) printf("<%s:%f>\n", #t, s);} 

#define MAX_LINE_LENG 256

int linenum = 1;
char buf[MAX_LINE_LENG];
string buf2;
char str_buf[ MAX_LINE_LENG ];
char temp[ MAX_LINE_LENG ];
int Opt_T = 0;
int Opt_TE = 1;
#define SIZE_SYMTABLE 1000

/*struct n_sym
{
	char *iden;
};*/
//struct n_sym sym_tab[SIZE_SYMTABLE]; 

//static int hashfun(char *str,int i);
//static void create_symtable();
//static int lookup(char *str);
//static int insert(char *str);
//static void dump();



%}

digs        [0-9]+
letter      [a-zA-Z]
integer     [-+]?{digs}
plain_real  [-+]?{digs}"."{digs}
expreal     [-+]?{plain_real}[Ee][+-]?{digs}
real        {plain_real}|{expreal}
whitespace  [ ]
string      \"([^"\n]|\"\")*\"
id          [a-zA-Z][a-zA-Z0-9_]*


/* <name><regexp> */

%x COMMENT

%%

 /* comment */

"--".*      {LIST; PLINE;}
 /* ")"       {token(')');} */
"{"               {LIST; PLINE;
                    BEGIN COMMENT;}
<COMMENT>"}"     {LIST; PLINE; BEGIN INITIAL;}   
<COMMENT>.        {LIST; PLINE;}     

 /*token*/
"<"         {token(LT);}
"<="        {token(LE);}
">="        {token(GE);}
">"         {token(GT);}
"="         {token(EQUAL);}
"/="        {token(N_EQUAL);}
":="        {token(ASSIGN);}

"("         {token(LEFTPARENTHESES);}
")"         {token(RIGHTPARENTHESES);} 
"."         {token(PERIOD);}
","         {token(COMMA);}
":"         {token(COLON);}
";"         {token(SEMICOLON);}
"["         {token(LEFTBRACKETS);}
"]"         {token(RIGHTBRACKETS);}

"+"         {token(PLUS);}
"-"         {token(MINUS);}
"*"         {token(MULT);}
"/"         {token(SLASH);}
"%"         {token(REMAINDER);}



 /*KEYWORDS*/

[Aa][Nn][Dd]                          {token(AND);}
[Bb][Ee][Gg][Ii][Nn]                  {token(BEG);}
[Bb][Oo][Oo][Ll][Ee][Aa][Nn]          {token(BOOLEAN);}
[Cc][Hh][Aa][Rr][Aa][Cc][Tt][Ee][Rr]  {token(CHARACTER);}
[Cc][Oo][Nn][Ss][Tt][Aa][Nn][Tt]      {token(CONSTANT);}
[Dd][Ee][Cc][Ll][Aa][Rr][Ee]          {token(DECLARE);}
[Dd][Oo]                              {token(DO);}
[Ee][Ll][Ss][Ee]                      {token(ELSE);}
[Ee][Nn][Dd]                          {token(END);}
[Ff][Aa][Ll][Ss][Ee]                  {tokenString(BOOLEAN, "FALSE"); return FALSE;}
[Ff][Ll][Oo][Aa][Tt]                  {token(FLOAT);}
[Ff][Oo][Rr]                          {token(FOR);}
[Ii][Ff]                              {token(IF);}
[Ii][Nn]                              {token(IN);}
[Ii][Nn][Tt][Ee][Gg][Ee][Rr]          {token(INTEGER);}
[Ll][Oo][Oo][Pp]                      {token(LOOP);}
[Nn][Oo][Tt]                          {token(NOT);}
[Oo][Rr]                              {token(OR);}
[Pp][Rr][Ii][Nn][Tt]                  {token(PRINT);}
[Pp][Rr][Ii][Nn][Tt][Ll][Nn]          {token(PRINTLN);}
[Pp][Rr][Oo][Cc][Ee][Dd][Uu][Rr][Ee]  {token(PROCEDURE);}
[Pp][Rr][Oo][Gg][Rr][Aa][Mm]          {token(PROGRAM);}
[Rr][Ee][Tt][Uu][Rr][Nn]              {token(RETURN);}
[Rr][Ee][Aa][Dd]                      {token(READ);}
[Ss][Tt][Rr][Ii][Nn][Gg]              {token(STRING);}
[Tt][Rr][Uu][Ee]                      {tokenString(BOOLEAN, "TRUE"); return TRUE;}
[Tt][Hh][Ee][Nn]                      {token(THEN);}
[Ww][Hh][Ii][Ll][Ee]                  {token(WHILE);}


{integer}   {tokenInteger(num_integer, atoi(yytext));
             yylval.int_val = atoi(yytext);
             return num_integer;}
{real}      {tokenReal(num_real, yytext);
             yylval.real_val = atof(yytext);
             return num_real;}
{string}    {
              for(int i = 1; i < strlen(yytext) - 1; i++)
              {
                strncat(str_buf, yytext+i, 1);
                if(yytext[i]=='\"') i++;
              }
              tokenString(string_val, str_buf);
              yylval.stringVal = new string(str_buf);
              str_buf[0]='\0';              
              return string_val;
            }

{id}        {
            tokenString(identifier, yytext);
            yylval.stringVal = new string(yytext);
            return identifier;
            }



<COMMENT>\n |         
\n                    {
                      LIST; 
                      if(Opt_TE) fout << "/*  " << linenum << ": " << buf2 << "  */" << endl;
                      if(Opt_T) cout << linenum << ":" << buf;
                      ++linenum;
                      buf[0] = '\0';
                      buf2 = "";
                      }

whitespace  {LIST; PLINE;}

[ \t]*      {LIST; PLINE;}

.           {
            LIST; PLINE;
            printf("%d:%s\n", linenum+1, buf);
            printf("bad character:'%s'\n",yytext);
            exit(-1);
            }  

%%
/*static int hashfun(char *s, int i)
{
    unsigned long hnum = 1234;
    int index;

    while (index == *s++) 
    {
      hnum = hashfun(s, i) + index;
    }
  
    return ((int)((hnum + i) % SIZE_SYMTABLE));
}

static void create_symtable()
{
	for(int i = 0; i < SIZE_SYMTABLE; i++)
  {
		sym_tab[i].iden = (char *)malloc(256);
		strcpy(sym_tab[i].iden, "nil");
	}
	return;
}

static int lookup(char *s)
{
  for(int i = 0, index = hashfun(s, i); i < SIZE_SYMTABLE && strcmp(sym_tab[index].iden, "nil") != 0; i++, index = hashfun(s, i))
  {
    if(strcmp(sym_tab[index].iden, s) == 0)
    {
      return index;
    }
  }
	return -1;
}

static int insert(char *s)
{
	if(lookup(s) == -1) 
  {
		int index;
    for(int i = 0; i < SIZE_SYMTABLE; i++)
    {
      index = hashfun(s, i);
      if(strcmp(sym_tab[index].iden, "nil") == 0)
      {
        strcpy(sym_tab[index].iden, s);
        return index;
      }
    }
  }
  return -1; // not find

}

static void dump()
{
	printf("\nSymbol Table:\n");
	for(int i = 0; i < SIZE_SYMTABLE; i++)
  {
		if(strcmp(sym_tab[i].iden, "nil") != 0)
    {
			printf("%s\n", sym_tab[i].iden);
    }
	}
  return;
}*/


/*int main()
{
  create_symtable();
  yylex();
  dump();
  return 0;
}*/
