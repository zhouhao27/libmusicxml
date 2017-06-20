/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

#ifndef __rational__
#define __rational__

#include <string>
#include "exports.h"

using namespace std;

/*!
\brief  Rational number representation.
*/

class EXP rational {

  public:    
  
    // constructors/destructor
    // ------------------------------------------------------
      
    rational (long int num = 0, long int denom = 1);
    rational (const rational& d);
    rational (const string &str);

    // set and get
    // ------------------------------------------------------
                            
    long int              getNumerator () const
                              { return fNumerator; }
                              
    long int              getDenominator () const
                              { return fDenominator; }
                              
    void                  setNumerator (long int d)
                              { fNumerator = d; }
                              
    void                  setDenominator (long int d)
                              { fDenominator = d; }
                              
    void                  set (long int n, long int d)
                              { fNumerator = n; fDenominator = d; }

    // arithmetic operators
    // ------------------------------------------------------
                            
    rational              operator + (const rational &rat) const;
    rational              operator - (const rational &rat) const;
                            //! Useful for notes with dots.
    rational              operator * (const rational &rat) const; 
    rational              operator / (const rational &rat) const;
                            // (i.e. rat * 3/2 or rat * 7/4)

    rational              operator * (int num) const; 
    rational              operator / (int num) const;

    rational&             operator *= (long int num)
                              { fNumerator *= num; return *this; }
    rational&             operator /= (long int num)
                              { fDenominator *= num; return *this; }

    rational&             operator += (const rational &rat);
    rational&             operator -= (const rational &rat);
                            //! Useful for notes with dots.
    rational&             operator *= (const rational &rat); 
    rational&             operator /= (const rational &rat);
                            // (i.e. rat * 3/2 or rat * 7/4)

    // copy operator
    // ------------------------------------------------------
                            
    rational&             operator =  (const rational& rat);

    // logical operators
    // ------------------------------------------------------
                            
    bool                  operator >  (const rational &rat) const;
    bool                  operator >= (const rational &rat) const
                              { return !(*this < rat); }
    bool                  operator <  (const rational &rat) const;
    bool                  operator <= (const rational &rat) const
                              { return !(*this > rat); }
        
    bool                  operator == (const rational &rat) const;
    bool                  operator != (const rational &rat) const
                              { return !(*this == rat); }
  
    bool                  operator >  (double num) const;
    bool                  operator >= (double num) const;
    bool                  operator <  (double num) const;
    bool                  operator <= (double num) const;    
    bool                  operator == (double) const;

    // type conversions
    // ------------------------------------------------------

    operator              string () const;
    operator              double () const;
    operator              float ()  const;
    operator              int ()    const; 

    // virtual string toString() const;  Why ?? SL
    string                toString () const;
    double                toDouble () const;
    float                 toFloat ()  const;
    int                   toInt ()    const;

    // rationalize
    // ------------------------------------------------------

    void                  rationalise();
   
    // print
    // ------------------------------------------------------

    void                  print (ostream& os);

  private:    

    // gcd
    // ------------------------------------------------------
    
    // Used by rationalise ()
    long int              gcd (long int a, long int b); 

  private:    
   
    long int              fNumerator;
    long int              fDenominator;        

};

EXP ostream& operator<< (ostream& os, rational& rat);

#endif
