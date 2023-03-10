// $Id$

/*
 Copyright (c) 2007-2015, Trustees of The Leland Stanford Junior University
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 Redistributions in binary form must reproduce the above copyright notice, this
 list of conditions and the following disclaimer in the documentation and/or
 other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _ROUTERLESS_HPP_
#define _ROUTERLESS_HPP_

#include "network.hpp"
#include "routefunc.hpp"
#include <cassert>
#include <string>
#include <map>
#include <list>

class RouterLess : public Network {

  string file_name;
  //associtation between  nodes and routers

  vector<vector<int> > ring; //vector of rings
  vector<int> vRing; //contains all vertical rings ids only (no node ids) 
  vector<int> hRing; //same as above except for horizantal rings
  vector<vector<vector<int> > > shortestRing;
  //[router][dest_node]= vector of rings sorted in order from shortest.

  void _ComputeSize( const Configuration &config );
  void _BuildNet( const Configuration &config );



  void _ComputeSizeRL( const Configuration &config );
  void _BuildNetRL( const Configuration &config );

  void readFileRL();
  void readRingsRL(ifstream &);
  int  countChannelsRL();
  void readShortestRingsRL(ifstream &);
  int _countPassingRingsRL(int ) ;



public:
  RouterLess( const Configuration &config, const string & name );
  ~RouterLess();

  int GetN( ) const{ return -1;}
  int GetK( ) const{ return -1;}

  static void RegisterRoutingFunctions();
  double Capacity( ) const {return -1;}
  void InsertRandomFaults( const Configuration &config ){}
};

void min_RouterLess( const Router *r, const Flit *f, int in_channel,
		      OutputSet *outputs, bool inject );
#endif
