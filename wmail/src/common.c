///////////////////////////////////////////////////////////////////////////////
// common.c
// common defines and typedefs, part of wmail
//
// Copyright 2000-2002, Sven Geisenhainer <sveng@informatik.uni-jena.de>.
// Copyright 2016-2017, Doug Torrance <dtorrance@piedmont.edu>.
// Copyright 2019, Jeremy Sowden <jeremy@azazel.net>.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions, and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions, and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


#ifdef HAVE_CONFIG_H
#ifndef CONFIG_H_INCLUDED
#include "../config.h"
#define CONFIG_H_INCLUDED
#endif
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "common.h"

#ifdef DEBUG
void TRACE( const char *fmt, ... )
{
    va_list args;
    va_start( args, fmt );
    vfprintf( stderr, fmt, args );
    fflush( stderr );
    va_end( args );
}
#endif

void ABORT( const char *fmt, ... )
{
    va_list args;
    va_start( args, fmt );
    fprintf( stderr, "wmail error: " );
    vfprintf( stderr, fmt, args );
    fflush( stderr );
    va_end( args );

    exit( 1 );
}

void WARNING( const char *fmt, ... )
{
    va_list args;
    va_start( args, fmt );
    fprintf( stderr, "wmail warning: " );
    vfprintf( stderr, fmt, args );
    fflush( stderr );
    va_end( args );
}

char *MakePathName( const char *dir, const char *file )
{
    size_t dir_len  = strlen( dir );
    size_t file_len = strlen( file );

    size_t len;
    const char *fmt;

    char *fullName;

    if( dir[dir_len - 1] != '/' )
    {
	len = dir_len + 1 + file_len + 1;
	fmt = "%s/%s";
    }
    else
    {
	len = dir_len + file_len + 1;
	fmt = "%s%s";
    }

    fullName = malloc( len );
    if( fullName != NULL )
	snprintf( fullName, len, fmt, dir, file );
    return fullName;
}
