/***************************************************************************
**  *   union-type.c version 20151023.214135                                  *
**  *                                                                         *
**  *   An union example to make a general type 'atype'                       *
**  *   Copyright (C) 2015 by Ruben Carlo Benante (beco)                      *
**  ***************************************************************************
**  *   This program is free software; you can redistribute it and/or modify  *
**  *  *   it under the terms of the GNU General Public License as published by  *
**  *   the Free Software Foundation; either version 2 of the License, or     *
**  *   (at your option) any later version.                                   *
**  *                                                                         *
**  *   This program is distributed in the hope that it will be useful,       *
**  *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
**  *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
**  *   GNU General Public License for more details.                          *
**  *                                                                         *
**  *   You should have received a copy of the GNU General Public License     *
**  *   along with this program; if not, write to the                         *
**  *   Free Software Foundation, Inc.,                                       *
**  *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
**  ***************************************************************************
**  *   To contact the author, please write to:                               *
**  *   Ruben Carlo Benante                                                   *
**  *   Email: rcb@beco.cc                                                    *
**  *   Webpage: www.beco.cc                                                  *
**  *   Phone: +55 (81) 3184-7555                                             *
**  ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAXS 256

typedef enum { INTEGER, STRING, REAL, POINTER } thetype;

typedef struct
{
    thetype type;
    union
    {
        int integer;
        char *string;
        float real;
        void *pointer;
    } value;
} atype;

atype func(atype a);
void printatype(atype a);

int main(void)
{
    int i;
    char s[MAXS];
    float r;
    void (*f)(atype);
    int opt;
    atype a;

    do
    {
        printf("\n1 - int\n2 - string\n3 - real\n4 - pointer\n5 - end\n");
        printf("Choose one:");
        opt=((opt=getchar())=='\n'?getchar():opt);
    }while(opt<'1' || opt>'5');

    printf("Chose: %c\n\n", opt);
    switch(opt)
    {
        case '1':
            printf("Type an integer:");
            scanf("%d", &i);
            a.type = INTEGER;
            a.value.integer = i;
            break;
        case '2':
            printf("Type a string (2 or more characters):");
            while(strlen(fgets(s, MAXS, stdin))==1);
            a.type = STRING;
            a.value.string = s;
            break;
        case '3':
            printf("Type a real:");
            scanf("%f", &r);
            a.type = REAL; 
            a.value.real = r;
            break;
        case '4':
            printf("You chose a pointer. Pointing to printatype() function.\n");
            f=printatype;
            a.type = POINTER;
            a.value.pointer = f;
            /* f(a); */
            break;
        case '5':
        default:
            printf("Bye!\n\n");
            return EXIT_SUCCESS;
    }

    a=func(a);
    if(a.type!=POINTER)
        printatype(a);

    return EXIT_SUCCESS;
}

atype func(atype a)
{
    char *p;
    switch(a.type)
    {
        case INTEGER:
            printf("Add one.\n");
            a.value.integer++;
            break;
        case STRING:
            printf("Change cAse.\n");
            a.value.string[0]=tolower(a.value.string[0]);
            a.value.string[1]=toupper(a.value.string[1]);
            if((p=strchr(a.value.string,'\n'))) *p = '\0';
            break;
        case REAL:
            printf("Square root.\n");
            a.value.real=sqrt(a.value.real);
            break;
        case POINTER:
            printf("Calling function by pointer.\n");
            ((void (*)())a.value.pointer)(a);
            break;
        default:
            printf("function func(), type unknow!\n");
    }
    return a;
}

void printatype(atype a)
{
    switch(a.type)
    {
        case INTEGER:
            printf("Integer: %d\n", a.value.integer);
            break;
        case STRING:
            printf("String: %s\n", a.value.string);
            break;
        case REAL:
            printf("Real: %.4f\n", a.value.real);
            break;
        case POINTER:
            printf("Pointer: %p\n", a.value.pointer);
            break;
        default:
            printf("Unknow!\n");
    }
    return;
}

