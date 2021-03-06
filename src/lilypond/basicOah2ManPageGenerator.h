/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

#ifndef ___basicOah2ManPageGenerator___
#define ___basicOah2ManPageGenerator___

#include "oahBasicTypes.h"

#include "oah2ManPageGenerators.h"


namespace MusicXML2
{

//________________________________________________________________________
class basicOah2ManPageGenerator : virtual public oah2ManPageGenerator,

  public visitor<S_oahPrefix>,

  public visitor<S_oahGroup>,

  public visitor<S_oahSubGroup>,

  public visitor<S_oahAtom>,

  public visitor<S_oahAtomSynonym>,

  public visitor<S_oahOptionsUsageAtom>,

  public visitor<S_oahOptionsSummaryAtom>,

  public visitor<S_oahAtomWithVariableName>,

  public visitor<S_oahOptionNameHelpAtom>,

  public visitor<S_oahBooleanAtom>,
  public visitor<S_oahTwoBooleansAtom>,
  public visitor<S_oahThreeBooleansAtom>,

  public visitor<S_oahCombinedBooleansAtom>,

  public visitor<S_oahMultiplexBooleansAtom>,

  public visitor<S_oahValuedAtom>,

  public visitor<S_oahIntegerAtom>,
  public visitor<S_oahTwoIntegersAtom>,

  public visitor<S_oahFloatAtom>,

  public visitor<S_oahStringAtom>,

  public visitor<S_oahRationalAtom>,

  public visitor<S_oahMonoplexStringAtom>,

  public visitor<S_oahStringWithDefaultValueAtom>,

  public visitor<oahNaturalNumbersSetAtom>,

  public visitor<S_oahStringSetAtom>,

  public visitor<S_oahRGBColorAtom>,

  public visitor<S_oahStringAndIntegerAtom>,
  public visitor<S_oahStringAndTwoIntegersAtom>

{
  public:

    basicOah2ManPageGenerator (
      const S_oahHandler handler,
      indentedOstream&   logOstream,
      ostream&           manPageOutputStream);

    virtual ~basicOah2ManPageGenerator ();

  protected:

    virtual void visitStart (S_oahHandler& elt);
    virtual void visitEnd   (S_oahHandler& elt);

    virtual void visitStart (S_oahGroup& elt);
    virtual void visitEnd   (S_oahGroup& elt);

    virtual void visitStart (S_oahPrefix& elt);
    virtual void visitEnd   (S_oahPrefix& elt);

    virtual void visitStart (S_oahSubGroup& elt);
    virtual void visitEnd   (S_oahSubGroup& elt);

    virtual void visitStart (S_oahAtom& elt);
    virtual void visitEnd   (S_oahAtom& elt);

    virtual void visitStart (S_oahAtomSynonym& elt);
    virtual void visitEnd   (S_oahAtomSynonym& elt);

    virtual void visitStart (S_oahOptionsUsageAtom& elt);
    virtual void visitEnd   (S_oahOptionsUsageAtom& elt);

    virtual void visitStart (S_oahOptionsSummaryAtom& elt);
    virtual void visitEnd   (S_oahOptionsSummaryAtom& elt);

    virtual void visitStart (S_oahAtomWithVariableName& elt);
    virtual void visitEnd   (S_oahAtomWithVariableName& elt);

    virtual void visitStart (S_oahOptionNameHelpAtom& elt);
    virtual void visitEnd   (S_oahOptionNameHelpAtom& elt);

    virtual void visitStart (S_oahBooleanAtom& elt);
    virtual void visitEnd   (S_oahBooleanAtom& elt);
    virtual void visitStart (S_oahTwoBooleansAtom& elt);
    virtual void visitEnd   (S_oahTwoBooleansAtom& elt);
    virtual void visitStart (S_oahThreeBooleansAtom& elt);
    virtual void visitEnd   (S_oahThreeBooleansAtom& elt);

    virtual void visitStart (S_oahCombinedBooleansAtom& elt);
    virtual void visitEnd   (S_oahCombinedBooleansAtom& elt);

    virtual void visitStart (S_oahMultiplexBooleansAtom& elt);
    virtual void visitEnd   (S_oahMultiplexBooleansAtom& elt);

    virtual void visitStart (S_oahValuedAtom& elt);
    virtual void visitEnd   (S_oahValuedAtom& elt);

    virtual void visitStart (S_oahIntegerAtom& elt);
    virtual void visitEnd   (S_oahIntegerAtom& elt);
    virtual void visitStart (S_oahTwoIntegersAtom& elt);
    virtual void visitEnd   (S_oahTwoIntegersAtom& elt);

    virtual void visitStart (S_oahFloatAtom& elt);
    virtual void visitEnd   (S_oahFloatAtom& elt);

    virtual void visitStart (S_oahStringAtom& elt);
    virtual void visitEnd   (S_oahStringAtom& elt);

    virtual void visitStart (S_oahRationalAtom& elt);
    virtual void visitEnd   (S_oahRationalAtom& elt);

    virtual void visitStart (S_oahMonoplexStringAtom& elt);
    virtual void visitEnd   (S_oahMonoplexStringAtom& elt);

    virtual void visitStart (S_oahStringWithDefaultValueAtom& elt);
    virtual void visitEnd   (S_oahStringWithDefaultValueAtom& elt);

    virtual void visitStart (S_oahNaturalNumbersSetAtom& elt);
    virtual void visitEnd   (S_oahNaturalNumbersSetAtom& elt);

    virtual void visitStart (S_oahStringSetAtom& elt);
    virtual void visitEnd   (S_oahStringSetAtom& elt);

    virtual void visitStart (S_oahRGBColorAtom& elt);
    virtual void visitEnd   (S_oahRGBColorAtom& elt);

    virtual void visitStart (S_oahStringAndIntegerAtom& elt);
    virtual void visitEnd   (S_oahStringAndIntegerAtom& elt);

    virtual void visitStart (S_oahStringAndTwoIntegersAtom& elt);
    virtual void visitEnd   (S_oahStringAndTwoIntegersAtom& elt);
};
typedef SMARTP<basicOah2ManPageGenerator> S_basicOah2ManPageGenerator;


}


#endif
