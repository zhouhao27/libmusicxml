/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

#include <climits>      /* INT_MIN, INT_MAX */
#include <iostream>
#include <list>
#include <algorithm>
#include <iomanip>      // setw, set::precision, ...

#include "msr.h"

using namespace std;

namespace MusicXML2 
{

// notes names languages
// ------------------------------------------------------

map<string, msrQuatertonesPitchesLanguage>
  gQuatertonesPitchesLanguagesMap;

map<msrQuartertonesPitch, string> gNederlandsPitchName;
map<msrQuartertonesPitch, string> gCatalanPitchName;
map<msrQuartertonesPitch, string> gDeutschPitchName;
map<msrQuartertonesPitch, string> gEnglishPitchName;
map<msrQuartertonesPitch, string> gEspanolPitchName;
map<msrQuartertonesPitch, string> gFrancaisPitchName;
map<msrQuartertonesPitch, string> gItalianoPitchName;
map<msrQuartertonesPitch, string> gNorskPitchName;
map<msrQuartertonesPitch, string> gPortuguesPitchName;
map<msrQuartertonesPitch, string> gSuomiPitchName;
map<msrQuartertonesPitch, string> gSvenskaPitchName;
map<msrQuartertonesPitch, string> gVlaamsPitchName;

void initializePitchesLanguages ()
{
  gQuatertonesPitchesLanguagesMap ["nederlands"] = kNederlands;
  gQuatertonesPitchesLanguagesMap ["catalan"]    = kCatalan;
  gQuatertonesPitchesLanguagesMap ["deutsch"]    = kDeutsch;
  gQuatertonesPitchesLanguagesMap ["english"]    = kEnglish;
  gQuatertonesPitchesLanguagesMap ["espanol"]    = kEspanol;
  gQuatertonesPitchesLanguagesMap ["italiano"]   = kItaliano;
  gQuatertonesPitchesLanguagesMap ["francais"]   = kFrancais;
  gQuatertonesPitchesLanguagesMap ["norsk"]      = kNorsk;
  gQuatertonesPitchesLanguagesMap ["portugues"]  = kPortugues;
  gQuatertonesPitchesLanguagesMap ["suomi"]      = kSuomi;
  gQuatertonesPitchesLanguagesMap ["svenska"]    = kSvenska;
  gQuatertonesPitchesLanguagesMap ["vlaams"]     = kVlaams;

  // nederlands
  gNederlandsPitchName [k_aDoubleFlat]  = "aeses";
  gNederlandsPitchName [k_aSesquiFlat]  = "aeseh";
  gNederlandsPitchName [k_aFlat]        = "aes";
  gNederlandsPitchName [k_aSemiFlat]    = "aeh";
  gNederlandsPitchName [k_aNatural]     = "a";
  gNederlandsPitchName [k_aSemiSharp]   = "aih";
  gNederlandsPitchName [k_aSharp]       = "ais";
  gNederlandsPitchName [k_aSesquiSharp] = "aisih";
  gNederlandsPitchName [k_aDoubleSharp] = "aisis";
    
  gNederlandsPitchName [k_bDoubleFlat]  = "beses";
  gNederlandsPitchName [k_bSesquiFlat]  = "beseh";
  gNederlandsPitchName [k_bFlat]        = "bes";
  gNederlandsPitchName [k_bSemiFlat]    = "beh";
  gNederlandsPitchName [k_bNatural]     = "b";
  gNederlandsPitchName [k_bSemiSharp]   = "bih";
  gNederlandsPitchName [k_bSharp]       = "bis";
  gNederlandsPitchName [k_bSesquiSharp] = "bisih";
  gNederlandsPitchName [k_bDoubleSharp] = "bisis";
    
  gNederlandsPitchName [k_cDoubleFlat]  = "ceses";
  gNederlandsPitchName [k_cSesquiFlat]  = "ceseh";
  gNederlandsPitchName [k_cFlat]        = "ces";
  gNederlandsPitchName [k_cSemiFlat]    = "ceh";
  gNederlandsPitchName [k_cNatural]     = "c";
  gNederlandsPitchName [k_cSemiSharp]   = "cih";
  gNederlandsPitchName [k_cSharp]       = "cis";
  gNederlandsPitchName [k_cSesquiSharp] = "cisih";
  gNederlandsPitchName [k_cDoubleSharp] = "cisis";
    
  gNederlandsPitchName [k_dDoubleFlat]  = "deses";
  gNederlandsPitchName [k_dSesquiFlat]  = "deseh";
  gNederlandsPitchName [k_dFlat]        = "des";
  gNederlandsPitchName [k_dSemiFlat]    = "deh";
  gNederlandsPitchName [k_dNatural]     = "d";
  gNederlandsPitchName [k_dSemiSharp]   = "dih";
  gNederlandsPitchName [k_dSharp]       = "dis";
  gNederlandsPitchName [k_dSesquiSharp] = "disih";
  gNederlandsPitchName [k_dDoubleSharp] = "disis";

  gNederlandsPitchName [k_eDoubleFlat]  = "eeses";
  gNederlandsPitchName [k_eSesquiFlat]  = "eeseh";
  gNederlandsPitchName [k_eFlat]        = "ees";
  gNederlandsPitchName [k_eSemiFlat]    = "eeh";
  gNederlandsPitchName [k_eNatural]     = "e";
  gNederlandsPitchName [k_eSemiSharp]   = "eih";
  gNederlandsPitchName [k_eSharp]       = "eis";
  gNederlandsPitchName [k_eSesquiSharp] = "eisih";
  gNederlandsPitchName [k_eDoubleSharp] = "eisis";
    
  gNederlandsPitchName [k_fDoubleFlat]  = "feses";
  gNederlandsPitchName [k_fSesquiFlat]  = "feseh";
  gNederlandsPitchName [k_fFlat]        = "fes";
  gNederlandsPitchName [k_fSemiFlat]    = "feh";
  gNederlandsPitchName [k_fNatural]     = "f";
  gNederlandsPitchName [k_fSemiSharp]   = "fih";
  gNederlandsPitchName [k_fSharp]       = "fis";
  gNederlandsPitchName [k_fSesquiSharp] = "fisih";
  gNederlandsPitchName [k_fDoubleSharp] = "fisis";
    
  gNederlandsPitchName [k_gDoubleFlat]  = "geses";
  gNederlandsPitchName [k_gSesquiFlat]  = "geseh";
  gNederlandsPitchName [k_gFlat]        = "ges";
  gNederlandsPitchName [k_gSemiFlat]    = "geh";
  gNederlandsPitchName [k_gNatural]     = "g";
  gNederlandsPitchName [k_gSemiSharp]   = "gih";
  gNederlandsPitchName [k_gSharp]       = "gis";
  gNederlandsPitchName [k_gSesquiSharp] = "gisih";
  gNederlandsPitchName [k_gDoubleSharp] = "gisis";

  // catalan
  gCatalanPitchName [k_aDoubleFlat]  = "labb";
  gCatalanPitchName [k_aSesquiFlat]  = "labSesquiFlat???";
  gCatalanPitchName [k_aFlat]        = "lab";
  gCatalanPitchName [k_aSemiFlat]    = "aSemiFlat???";
  gCatalanPitchName [k_aNatural]     = "la";
  gCatalanPitchName [k_aSemiSharp]   = "aSemiSharp???";
  gCatalanPitchName [k_aSharp]       = "lad";
  gCatalanPitchName [k_aSesquiSharp] = "laSesquiSharp???";
  gCatalanPitchName [k_aDoubleSharp] = "ladd";
    
  gCatalanPitchName [k_bDoubleFlat]  = "sibb";
  gCatalanPitchName [k_bSesquiFlat]  = "sibSesquiFlat???";
  gCatalanPitchName [k_bFlat]        = "sib";
  gCatalanPitchName [k_bSemiFlat]    = "bSemiFlat???";
  gCatalanPitchName [k_bNatural]     = "b";
  gCatalanPitchName [k_bSemiSharp]   = "bSemiSharp???";
  gCatalanPitchName [k_bSharp]       = "sid";
  gCatalanPitchName [k_bSesquiSharp] = "siSesquiSharp???";
  gCatalanPitchName [k_bDoubleSharp] = "sidd";
    
  gCatalanPitchName [k_cDoubleFlat]  = "dobb";
  gCatalanPitchName [k_cSesquiFlat]  = "doSesquiFlat???";
  gCatalanPitchName [k_cFlat]        = "dob";
  gCatalanPitchName [k_cSemiFlat]    = "cSemiFlat???";
  gCatalanPitchName [k_cNatural]     = "do";
  gCatalanPitchName [k_cSemiSharp]   = "cSemiSharp???";
  gCatalanPitchName [k_cSharp]       = "dod";
  gCatalanPitchName [k_cSesquiSharp] = "doSesquiSharp???";
  gCatalanPitchName [k_cDoubleSharp] = "dodd";
    
  gCatalanPitchName [k_dDoubleFlat]  = "rebb";
  gCatalanPitchName [k_dSesquiFlat]  = "reSesquiFlat???";
  gCatalanPitchName [k_dFlat]        = "reb";
  gCatalanPitchName [k_dSemiFlat]    = "dSemiFlat???";
  gCatalanPitchName [k_dNatural]     = "re";
  gCatalanPitchName [k_dSemiSharp]   = "dSemiSharp???";
  gCatalanPitchName [k_dSharp]       = "red";
  gCatalanPitchName [k_dSesquiSharp] = "reSesquiSharp???";
  gCatalanPitchName [k_dDoubleSharp] = "redd";

  gCatalanPitchName [k_eDoubleFlat]  = "mibb";
  gCatalanPitchName [k_eSesquiFlat]  = "miSesquiFlat???";
  gCatalanPitchName [k_eFlat]        = "mib";
  gCatalanPitchName [k_eSemiFlat]    = "eSemiFlat???";
  gCatalanPitchName [k_eNatural]     = "mi";
  gCatalanPitchName [k_eSemiSharp]   = "eSemiSharp???";
  gCatalanPitchName [k_eSharp]       = "mid";
  gCatalanPitchName [k_eSesquiSharp] = "miSesquiSharp???";
  gCatalanPitchName [k_eDoubleSharp] = "midd";
    
  gCatalanPitchName [k_fDoubleFlat]  = "fabb";
  gCatalanPitchName [k_fSesquiFlat]  = "faSesquiFlat???";
  gCatalanPitchName [k_fFlat]        = "fab";
  gCatalanPitchName [k_fSemiFlat]    = "fSemiFlat???";
  gCatalanPitchName [k_fNatural]     = "fa";
  gCatalanPitchName [k_fSemiSharp]   = "fSemiSharp???";
  gCatalanPitchName [k_fSharp]       = "fad";
  gCatalanPitchName [k_fSesquiSharp] = "faSesquiSharp???";
  gCatalanPitchName [k_fDoubleSharp] = "fadd";
    
  gCatalanPitchName [k_gDoubleFlat]  = "solbb";
  gCatalanPitchName [k_gSesquiFlat]  = "solSesquiFlat???";
  gCatalanPitchName [k_gFlat]        = "solb";
  gCatalanPitchName [k_gSemiFlat]    = "gSemiFlat???";
  gCatalanPitchName [k_gNatural]     = "sol";
  gCatalanPitchName [k_gSemiSharp]   = "gSemiSharp???";
  gCatalanPitchName [k_gSharp]       = "sold";
  gCatalanPitchName [k_gSesquiSharp] = "solSesquiSharp???";
  gCatalanPitchName [k_gDoubleSharp] = "soldd";

  // deutsch
  gDeutschPitchName [k_aDoubleFlat]  = "asas";
  gDeutschPitchName [k_aSesquiFlat]  = "asah";
  gDeutschPitchName [k_aFlat]        = "as";
  gDeutschPitchName [k_aSemiFlat]    = "aeh";
  gDeutschPitchName [k_aNatural]     = "a";
  gDeutschPitchName [k_aSemiSharp]   = "aih";
  gDeutschPitchName [k_aSharp]       = "ais";
  gDeutschPitchName [k_aSesquiSharp] = "aisih";
  gDeutschPitchName [k_aDoubleSharp] = "aisis";
    
  gDeutschPitchName [k_bDoubleFlat]  = "heses";
  gDeutschPitchName [k_bSesquiFlat]  = "heseh";
  gDeutschPitchName [k_bFlat]        = "b";
  gDeutschPitchName [k_bSemiFlat]    = "beh";
  gDeutschPitchName [k_bNatural]     = "h";
  gDeutschPitchName [k_bSemiSharp]   = "hih";
  gDeutschPitchName [k_bSharp]       = "his";
  gDeutschPitchName [k_bSesquiSharp] = "hisih";
  gDeutschPitchName [k_bDoubleSharp] = "hisis";
    
  gDeutschPitchName [k_cDoubleFlat]  = "ceses";
  gDeutschPitchName [k_cSesquiFlat]  = "ceseh";
  gDeutschPitchName [k_cFlat]        = "ces";
  gDeutschPitchName [k_cSemiFlat]    = "ceh";
  gDeutschPitchName [k_cNatural]     = "c";
  gDeutschPitchName [k_cSemiSharp]   = "cih";
  gDeutschPitchName [k_cSharp]       = "cis";
  gDeutschPitchName [k_cSesquiSharp] = "cisih";
  gDeutschPitchName [k_cDoubleSharp] = "cisis";
    
  gDeutschPitchName [k_dDoubleFlat]  = "deses";
  gDeutschPitchName [k_dSesquiFlat]  = "deseh";
  gDeutschPitchName [k_dFlat]        = "des";
  gDeutschPitchName [k_dSemiFlat]    = "deh";
  gDeutschPitchName [k_dNatural]     = "d";
  gDeutschPitchName [k_dSemiSharp]   = "dih";
  gDeutschPitchName [k_dSharp]       = "dis";
  gDeutschPitchName [k_dSesquiSharp] = "disih";
  gDeutschPitchName [k_dDoubleSharp] = "disis";

  gDeutschPitchName [k_eDoubleFlat]  = "eses";
  gDeutschPitchName [k_eSesquiFlat]  = "esseh";
  gDeutschPitchName [k_eFlat]        = "es";
  gDeutschPitchName [k_eSemiFlat]    = "eeh";
  gDeutschPitchName [k_eNatural]     = "e";
  gDeutschPitchName [k_eSemiSharp]   = "eih";
  gDeutschPitchName [k_eSharp]       = "eis";
  gDeutschPitchName [k_eSesquiSharp] = "eisih";
  gDeutschPitchName [k_eDoubleSharp] = "eisis";
    
  gDeutschPitchName [k_fDoubleFlat]  = "feses";
  gDeutschPitchName [k_fSesquiFlat]  = "feseh";
  gDeutschPitchName [k_fFlat]        = "fes";
  gDeutschPitchName [k_fSemiFlat]    = "feh";
  gDeutschPitchName [k_fNatural]     = "f";
  gDeutschPitchName [k_fSemiSharp]   = "fih";
  gDeutschPitchName [k_fSharp]       = "fis";
  gDeutschPitchName [k_fSesquiSharp] = "fisih";
  gDeutschPitchName [k_fDoubleSharp] = "fisis";
    
  gDeutschPitchName [k_gDoubleFlat]  = "geses";
  gDeutschPitchName [k_gSesquiFlat]  = "geseh";
  gDeutschPitchName [k_gFlat]        = "ges";
  gDeutschPitchName [k_gSemiFlat]    = "geh";
  gDeutschPitchName [k_gNatural]     = "g";
  gDeutschPitchName [k_gSemiSharp]   = "gih";
  gDeutschPitchName [k_gSharp]       = "gis";
  gDeutschPitchName [k_gSesquiSharp] = "gisih";
  gDeutschPitchName [k_gDoubleSharp] = "gisis";

  // english
  gEnglishPitchName [k_aDoubleFlat]  = "aff";
  gEnglishPitchName [k_aSesquiFlat]  = "atqf";
  gEnglishPitchName [k_aFlat]        = "af";
  gEnglishPitchName [k_aSemiFlat]    = "aqf";
  gEnglishPitchName [k_aNatural]     = "a";
  gEnglishPitchName [k_aSemiSharp]   = "aqs";
  gEnglishPitchName [k_aSharp]       = "as";
  gEnglishPitchName [k_aSesquiSharp] = "atqs";
  gEnglishPitchName [k_aDoubleSharp] = "a";
    
  gEnglishPitchName [k_bDoubleFlat]  = "bfqf";
  gEnglishPitchName [k_bSesquiFlat]  = "btqf";
  gEnglishPitchName [k_bFlat]        = "bf";
  gEnglishPitchName [k_bSemiFlat]    = "bqf";
  gEnglishPitchName [k_bNatural]     = "b";
  gEnglishPitchName [k_bSemiSharp]   = "bqs";
  gEnglishPitchName [k_bSharp]       = "bs";
  gEnglishPitchName [k_bSesquiSharp] = "btqs";
  gEnglishPitchName [k_bDoubleSharp] = "bx";
    
  gEnglishPitchName [k_cDoubleFlat]  = "cff";
  gEnglishPitchName [k_cSesquiFlat]  = "ctqf";
  gEnglishPitchName [k_cFlat]        = "cf";
  gEnglishPitchName [k_cSemiFlat]    = "cqf";
  gEnglishPitchName [k_cNatural]     = "c";
  gEnglishPitchName [k_cSemiSharp]   = "cqs";
  gEnglishPitchName [k_cSharp]       = "cs";
  gEnglishPitchName [k_cSesquiSharp] = "ctqs";
  gEnglishPitchName [k_cDoubleSharp] = "cx";
    
  gEnglishPitchName [k_dDoubleFlat]  = "dff";
  gEnglishPitchName [k_dSesquiFlat]  = "dtqf";
  gEnglishPitchName [k_dFlat]        = "df";
  gEnglishPitchName [k_dSemiFlat]    = "dqf";
  gEnglishPitchName [k_dNatural]     = "d";
  gEnglishPitchName [k_dSemiSharp]   = "dqs";
  gEnglishPitchName [k_dSharp]       = "ds";
  gEnglishPitchName [k_dSesquiSharp] = "dtqs";
  gEnglishPitchName [k_dDoubleSharp] = "dx";

  gEnglishPitchName [k_eDoubleFlat]  = "eff";
  gEnglishPitchName [k_eSesquiFlat]  = "etqf";
  gEnglishPitchName [k_eFlat]        = "ef";
  gEnglishPitchName [k_eSemiFlat]    = "eqf";
  gEnglishPitchName [k_eNatural]     = "e";
  gEnglishPitchName [k_eSemiSharp]   = "eqs";
  gEnglishPitchName [k_eSharp]       = "es";
  gEnglishPitchName [k_eSesquiSharp] = "etqs";
  gEnglishPitchName [k_eDoubleSharp] = "ex";
    
  gEnglishPitchName [k_fDoubleFlat]  = "fff";
  gEnglishPitchName [k_fSesquiFlat]  = "ftqf";
  gEnglishPitchName [k_fFlat]        = "ff";
  gEnglishPitchName [k_fSemiFlat]    = "fqf";
  gEnglishPitchName [k_fNatural]     = "f";
  gEnglishPitchName [k_fSemiSharp]   = "fqs";
  gEnglishPitchName [k_fSharp]       = "fs";
  gEnglishPitchName [k_fSesquiSharp] = "ftqs";
  gEnglishPitchName [k_fDoubleSharp] = "fx";
    
  gEnglishPitchName [k_gDoubleFlat]  = "gff";
  gEnglishPitchName [k_gSesquiFlat]  = "gtqf";
  gEnglishPitchName [k_gFlat]        = "gf";
  gEnglishPitchName [k_gSemiFlat]    = "gqf";
  gEnglishPitchName [k_gNatural]     = "g";
  gEnglishPitchName [k_gSemiSharp]   = "gqs";
  gEnglishPitchName [k_gSharp]       = "gs";
  gEnglishPitchName [k_gSesquiSharp] = "gtqs";
  gEnglishPitchName [k_gDoubleSharp] = "gx";

  // espanol
  gEspanolPitchName [k_aDoubleFlat]  = "labb";
  gEspanolPitchName [k_aSesquiFlat]  = "latcb";
  gEspanolPitchName [k_aFlat]        = "lab";
  gEspanolPitchName [k_aSemiFlat]    = "lacb";
  gEspanolPitchName [k_aNatural]     = "la";
  gEspanolPitchName [k_aSemiSharp]   = "lacs";
  gEspanolPitchName [k_aSharp]       = "las";
  gEspanolPitchName [k_aSesquiSharp] = "latcs";
  gEspanolPitchName [k_aDoubleSharp] = "lax";
    
  gEspanolPitchName [k_bDoubleFlat]  = "sibb";
  gEspanolPitchName [k_bSesquiFlat]  = "sitcb";
  gEspanolPitchName [k_bFlat]        = "sib";
  gEspanolPitchName [k_bSemiFlat]    = "sicb";
  gEspanolPitchName [k_bNatural]     = "si";
  gEspanolPitchName [k_bSemiSharp]   = "sics";
  gEspanolPitchName [k_bSharp]       = "sis";
  gEspanolPitchName [k_bSesquiSharp] = "sitcs";
  gEspanolPitchName [k_bDoubleSharp] = "six";
    
  gEspanolPitchName [k_cDoubleFlat]  = "dobb";
  gEspanolPitchName [k_cSesquiFlat]  = "dotcb";
  gEspanolPitchName [k_cFlat]        = "dob";
  gEspanolPitchName [k_cSemiFlat]    = "docb";
  gEspanolPitchName [k_cNatural]     = "do";
  gEspanolPitchName [k_cSemiSharp]   = "docs";
  gEspanolPitchName [k_cSharp]       = "dos";
  gEspanolPitchName [k_cSesquiSharp] = "dotcs";
  gEspanolPitchName [k_cDoubleSharp] = "dox";
    
  gEspanolPitchName [k_dDoubleFlat]  = "rebb";
  gEspanolPitchName [k_dSesquiFlat]  = "retcb";
  gEspanolPitchName [k_dFlat]        = "reb";
  gEspanolPitchName [k_dSemiFlat]    = "recb";
  gEspanolPitchName [k_dNatural]     = "re";
  gEspanolPitchName [k_dSemiSharp]   = "recs";
  gEspanolPitchName [k_dSharp]       = "res";
  gEspanolPitchName [k_dSesquiSharp] = "retcs";
  gEspanolPitchName [k_dDoubleSharp] = "rex";

  gEspanolPitchName [k_eDoubleFlat]  = "mibb";
  gEspanolPitchName [k_eSesquiFlat]  = "mitcb";
  gEspanolPitchName [k_eFlat]        = "mib";
  gEspanolPitchName [k_eSemiFlat]    = "micb";
  gEspanolPitchName [k_eNatural]     = "mi";
  gEspanolPitchName [k_eSemiSharp]   = "mics";
  gEspanolPitchName [k_eSharp]       = "mis";
  gEspanolPitchName [k_eSesquiSharp] = "mitcs";
  gEspanolPitchName [k_eDoubleSharp] = "mix";
    
  gEspanolPitchName [k_fDoubleFlat]  = "fabb";
  gEspanolPitchName [k_fSesquiFlat]  = "fatcb";
  gEspanolPitchName [k_fFlat]        = "fab";
  gEspanolPitchName [k_fSemiFlat]    = "facb";
  gEspanolPitchName [k_fNatural]     = "fa";
  gEspanolPitchName [k_fSemiSharp]   = "facs";
  gEspanolPitchName [k_fSharp]       = "fas";
  gEspanolPitchName [k_fSesquiSharp] = "fatcs";
  gEspanolPitchName [k_fDoubleSharp] = "fax";
    
  gEspanolPitchName [k_gDoubleFlat]  = "solbb";
  gEspanolPitchName [k_gSesquiFlat]  = "soltcb";
  gEspanolPitchName [k_gFlat]        = "solb";
  gEspanolPitchName [k_gSemiFlat]    = "solcb";
  gEspanolPitchName [k_gNatural]     = "sol";
  gEspanolPitchName [k_gSemiSharp]   = "solcs";
  gEspanolPitchName [k_gSharp]       = "sols";
  gEspanolPitchName [k_gSesquiSharp] = "soltcs";
  gEspanolPitchName [k_gDoubleSharp] = "solx";

  // francais
  gFrancaisPitchName [k_aDoubleFlat]  = "labb";
  gFrancaisPitchName [k_aSesquiFlat]  = "labtqt";
  gFrancaisPitchName [k_aFlat]        = "lab";
  gFrancaisPitchName [k_aSemiFlat]    = "labqt";
  gFrancaisPitchName [k_aNatural]     = "la";
  gFrancaisPitchName [k_aSemiSharp]   = "lasqt";
  gFrancaisPitchName [k_aSharp]       = "lad";
  gFrancaisPitchName [k_aSesquiSharp] = "lastqt";
  gFrancaisPitchName [k_aDoubleSharp] = "lass";
    
  gFrancaisPitchName [k_bDoubleFlat]  = "sibb";
  gFrancaisPitchName [k_bSesquiFlat]  = "sibtqt";
  gFrancaisPitchName [k_bFlat]        = "sib";
  gFrancaisPitchName [k_bSemiFlat]    = "sibqt";
  gFrancaisPitchName [k_bNatural]     = "si";
  gFrancaisPitchName [k_bSemiSharp]   = "sisqt";
  gFrancaisPitchName [k_bSharp]       = "sid";
  gFrancaisPitchName [k_bSesquiSharp] = "sistqt";
  gFrancaisPitchName [k_bDoubleSharp] = "siss";
    
  gFrancaisPitchName [k_cDoubleFlat]  = "dobb";
  gFrancaisPitchName [k_cSesquiFlat]  = "dobtqt";
  gFrancaisPitchName [k_cFlat]        = "dob";
  gFrancaisPitchName [k_cSemiFlat]    = "dobqt";
  gFrancaisPitchName [k_cNatural]     = "do";
  gFrancaisPitchName [k_cSemiSharp]   = "dosqt";
  gFrancaisPitchName [k_cSharp]       = "dod";
  gFrancaisPitchName [k_cSesquiSharp] = "dostqt";
  gFrancaisPitchName [k_cDoubleSharp] = "doss";
    
  gFrancaisPitchName [k_dDoubleFlat]  = "rebb";
  gFrancaisPitchName [k_dSesquiFlat]  = "rebtqt";
  gFrancaisPitchName [k_dFlat]        = "reb";
  gFrancaisPitchName [k_dSemiFlat]    = "rebqt";
  gFrancaisPitchName [k_dNatural]     = "re";
  gFrancaisPitchName [k_dSemiSharp]   = "resqt";
  gFrancaisPitchName [k_dSharp]       = "red";
  gFrancaisPitchName [k_dSesquiSharp] = "restqt";
  gFrancaisPitchName [k_dDoubleSharp] = "ress";

  gFrancaisPitchName [k_eDoubleFlat]  = "mibb";
  gFrancaisPitchName [k_eSesquiFlat]  = "mibtqt";
  gFrancaisPitchName [k_eFlat]        = "mib";
  gFrancaisPitchName [k_eSemiFlat]    = "mibqt";
  gFrancaisPitchName [k_eNatural]     = "mi";
  gFrancaisPitchName [k_eSemiSharp]   = "misqt";
  gFrancaisPitchName [k_eSharp]       = "mid";
  gFrancaisPitchName [k_eSesquiSharp] = "mistqt";
  gFrancaisPitchName [k_eDoubleSharp] = "miss";
    
  gFrancaisPitchName [k_fDoubleFlat]  = "fabb";
  gFrancaisPitchName [k_fSesquiFlat]  = "fabtqt";
  gFrancaisPitchName [k_fFlat]        = "fab";
  gFrancaisPitchName [k_fSemiFlat]    = "fabqt";
  gFrancaisPitchName [k_fNatural]     = "fa";
  gFrancaisPitchName [k_fSemiSharp]   = "fasqt";
  gFrancaisPitchName [k_fSharp]       = "fad";
  gFrancaisPitchName [k_fSesquiSharp] = "fastqt";
  gFrancaisPitchName [k_fDoubleSharp] = "fass";
    
  gFrancaisPitchName [k_gDoubleFlat]  = "solbb";
  gFrancaisPitchName [k_gSesquiFlat]  = "solbtqt";
  gFrancaisPitchName [k_gFlat]        = "solb";
  gFrancaisPitchName [k_gSemiFlat]    = "solbqt";
  gFrancaisPitchName [k_gNatural]     = "sol";
  gFrancaisPitchName [k_gSemiSharp]   = "solsqt";
  gFrancaisPitchName [k_gSharp]       = "sold";
  gFrancaisPitchName [k_gSesquiSharp] = "solstqt";
  gFrancaisPitchName [k_gDoubleSharp] = "solss";

  // italiano
  gItalianoPitchName [k_aDoubleFlat]  = "labb";
  gItalianoPitchName [k_aSesquiFlat]  = "labsb";
  gItalianoPitchName [k_aFlat]        = "lab";
  gItalianoPitchName [k_aSemiFlat]    = "lasb";
  gItalianoPitchName [k_aNatural]     = "la";
  gItalianoPitchName [k_aSemiSharp]   = "lasd";
  gItalianoPitchName [k_aSharp]       = "lad";
  gItalianoPitchName [k_aSesquiSharp] = "ladsd";
  gItalianoPitchName [k_aDoubleSharp] = "ladd";
    
  gItalianoPitchName [k_bDoubleFlat]  = "sibb";
  gItalianoPitchName [k_bSesquiFlat]  = "sibsb";
  gItalianoPitchName [k_bFlat]        = "sib";
  gItalianoPitchName [k_bSemiFlat]    = "sisb";
  gItalianoPitchName [k_bNatural]     = "si";
  gItalianoPitchName [k_bSemiSharp]   = "sisd";
  gItalianoPitchName [k_bSharp]       = "sid";
  gItalianoPitchName [k_bSesquiSharp] = "sidsd";
  gItalianoPitchName [k_bDoubleSharp] = "sidd";
    
  gItalianoPitchName [k_cDoubleFlat]  = "dobb";
  gItalianoPitchName [k_cSesquiFlat]  = "dobsb";
  gItalianoPitchName [k_cFlat]        = "dob";
  gItalianoPitchName [k_cSemiFlat]    = "dosb";
  gItalianoPitchName [k_cNatural]     = "do";
  gItalianoPitchName [k_cSemiSharp]   = "dosd";
  gItalianoPitchName [k_cSharp]       = "dod";
  gItalianoPitchName [k_cSesquiSharp] = "dodsd";
  gItalianoPitchName [k_cDoubleSharp] = "dodd";
    
  gItalianoPitchName [k_dDoubleFlat]  = "rebb";
  gItalianoPitchName [k_dSesquiFlat]  = "rebsb";
  gItalianoPitchName [k_dFlat]        = "reb";
  gItalianoPitchName [k_dSemiFlat]    = "resb";
  gItalianoPitchName [k_dNatural]     = "re";
  gItalianoPitchName [k_dSemiSharp]   = "resd";
  gItalianoPitchName [k_dSharp]       = "red";
  gItalianoPitchName [k_dSesquiSharp] = "redsd";
  gItalianoPitchName [k_dDoubleSharp] = "redd";

  gItalianoPitchName [k_eDoubleFlat]  = "mibb";
  gItalianoPitchName [k_eSesquiFlat]  = "mibsb";
  gItalianoPitchName [k_eFlat]        = "mib";
  gItalianoPitchName [k_eSemiFlat]    = "misb";
  gItalianoPitchName [k_eNatural]     = "mi";
  gItalianoPitchName [k_eSemiSharp]   = "misd";
  gItalianoPitchName [k_eSharp]       = "mid";
  gItalianoPitchName [k_eSesquiSharp] = "midsd";
  gItalianoPitchName [k_eDoubleSharp] = "midd";
    
  gItalianoPitchName [k_fDoubleFlat]  = "fabb";
  gItalianoPitchName [k_fSesquiFlat]  = "fabsb";
  gItalianoPitchName [k_fFlat]        = "fab";
  gItalianoPitchName [k_fSemiFlat]    = "fasb";
  gItalianoPitchName [k_fNatural]     = "fa";
  gItalianoPitchName [k_fSemiSharp]   = "fasd";
  gItalianoPitchName [k_fSharp]       = "fad";
  gItalianoPitchName [k_fSesquiSharp] = "fadsd";
  gItalianoPitchName [k_fDoubleSharp] = "fadd";
    
  gItalianoPitchName [k_gDoubleFlat]  = "solbb";
  gItalianoPitchName [k_gSesquiFlat]  = "solbsb";
  gItalianoPitchName [k_gFlat]        = "solb";
  gItalianoPitchName [k_gSemiFlat]    = "solsb";
  gItalianoPitchName [k_gNatural]     = "sol";
  gItalianoPitchName [k_gSemiSharp]   = "solsd";
  gItalianoPitchName [k_gSharp]       = "sold";
  gItalianoPitchName [k_gSesquiSharp] = "soldsd";
  gItalianoPitchName [k_gDoubleSharp] = "soldd";

  // norsk
  gNorskPitchName [k_aDoubleFlat]  = "aeses";
  gNorskPitchName [k_aSesquiFlat]  = "aSesquiFlat???";
  gNorskPitchName [k_aFlat]        = "aes";
  gNorskPitchName [k_aSemiFlat]    = "aSemiFlat???";
  gNorskPitchName [k_aNatural]     = "a";
  gNorskPitchName [k_aSemiSharp]   = "aSemiSharp???";
  gNorskPitchName [k_aSharp]       = "ais";
  gNorskPitchName [k_aSesquiSharp] = "aSesquiSharp???";
  gNorskPitchName [k_aDoubleSharp] = "aisis";
    
  gNorskPitchName [k_bDoubleFlat]  = "beses";
  gNorskPitchName [k_bSesquiFlat]  = "bSesquiFlat???";
  gNorskPitchName [k_bFlat]        = "bes";
  gNorskPitchName [k_bSemiFlat]    = "bSemiFlat???";
  gNorskPitchName [k_bNatural]     = "b";
  gNorskPitchName [k_bSemiSharp]   = "bSemiSharp???";
  gNorskPitchName [k_bSharp]       = "bis";
  gNorskPitchName [k_bSesquiSharp] = "bSesquiSharp???";
  gNorskPitchName [k_bDoubleSharp] = "bisis";
    
  gNorskPitchName [k_cDoubleFlat]  = "ceses";
  gNorskPitchName [k_cSesquiFlat]  = "cSesquiFlat???";
  gNorskPitchName [k_cFlat]        = "ces";
  gNorskPitchName [k_cSemiFlat]    = "cSemiFlat???";
  gNorskPitchName [k_cNatural]     = "c";
  gNorskPitchName [k_cSemiSharp]   = "cSemiSharp???";
  gNorskPitchName [k_cSharp]       = "cis";
  gNorskPitchName [k_cSesquiSharp] = "cSesquiSharp???";
  gNorskPitchName [k_cDoubleSharp] = "cisis";
    
  gNorskPitchName [k_dDoubleFlat]  = "deses";
  gNorskPitchName [k_dSesquiFlat]  = "dSesquiFlat???";
  gNorskPitchName [k_dFlat]        = "des";
  gNorskPitchName [k_dSemiFlat]    = "dSemiFlat???";
  gNorskPitchName [k_dNatural]     = "d";
  gNorskPitchName [k_dSemiSharp]   = "dSemiSharp???";
  gNorskPitchName [k_dSharp]       = "dis";
  gNorskPitchName [k_dSesquiSharp] = "dSesquiSharp???";
  gNorskPitchName [k_dDoubleSharp] = "disis";

  gNorskPitchName [k_eDoubleFlat]  = "eeses";
  gNorskPitchName [k_eSesquiFlat]  = "eSesquiFlat???";
  gNorskPitchName [k_eFlat]        = "ees";
  gNorskPitchName [k_eSemiFlat]    = "eSemiFlat???";
  gNorskPitchName [k_eNatural]     = "e";
  gNorskPitchName [k_eSemiSharp]   = "eSemiSharp???";
  gNorskPitchName [k_eSharp]       = "eis";
  gNorskPitchName [k_eSesquiSharp] = "eSesquiSharp???";
  gNorskPitchName [k_eDoubleSharp] = "eisis";
    
  gNorskPitchName [k_fDoubleFlat]  = "feses";
  gNorskPitchName [k_fSesquiFlat]  = "fSesquiFlat???";
  gNorskPitchName [k_fFlat]        = "fes";
  gNorskPitchName [k_fSemiFlat]    = "fSemiFlat???";
  gNorskPitchName [k_fNatural]     = "f";
  gNorskPitchName [k_fSemiSharp]   = "fSemiSharp???";
  gNorskPitchName [k_fSharp]       = "fis";
  gNorskPitchName [k_fSesquiSharp] = "fSesquiSharp???";
  gNorskPitchName [k_fDoubleSharp] = "fisis";
    
  gNorskPitchName [k_gDoubleFlat]  = "geses";
  gNorskPitchName [k_gSesquiFlat]  = "gSesquiFlat???";
  gNorskPitchName [k_gFlat]        = "ges";
  gNorskPitchName [k_gSemiFlat]    = "gSemiFlat???";
  gNorskPitchName [k_gNatural]     = "g";
  gNorskPitchName [k_gSemiSharp]   = "gSemiSharp???";
  gNorskPitchName [k_gSharp]       = "gis";
  gNorskPitchName [k_gSesquiSharp] = "gSesquiSharp???";
  gNorskPitchName [k_gDoubleSharp] = "gisis";

  // portugues
  gPortuguesPitchName [k_aDoubleFlat]  = "labb";
  gPortuguesPitchName [k_aSesquiFlat]  = "labtqt";
  gPortuguesPitchName [k_aFlat]        = "lab";
  gPortuguesPitchName [k_aSemiFlat]    = "lasb";
  gPortuguesPitchName [k_aNatural]     = "la";
  gPortuguesPitchName [k_aSemiSharp]   = "lasd";
  gPortuguesPitchName [k_aSharp]       = "lad";
  gPortuguesPitchName [k_aSesquiSharp] = "ladsd";
  gPortuguesPitchName [k_aDoubleSharp] = "ladd";
    
  gPortuguesPitchName [k_bDoubleFlat]  = "sibb";
  gPortuguesPitchName [k_bSesquiFlat]  = "sibtqt";
  gPortuguesPitchName [k_bFlat]        = "sib";
  gPortuguesPitchName [k_bSemiFlat]    = "sisb";
  gPortuguesPitchName [k_bNatural]     = "si";
  gPortuguesPitchName [k_bSemiSharp]   = "sisd";
  gPortuguesPitchName [k_bSharp]       = "sid";
  gPortuguesPitchName [k_bSesquiSharp] = "sidsd";
  gPortuguesPitchName [k_bDoubleSharp] = "sidd";
    
  gPortuguesPitchName [k_cDoubleFlat]  = "dobb";
  gPortuguesPitchName [k_cSesquiFlat]  = "dobtqt";
  gPortuguesPitchName [k_cFlat]        = "dob";
  gPortuguesPitchName [k_cSemiFlat]    = "dosb";
  gPortuguesPitchName [k_cNatural]     = "do";
  gPortuguesPitchName [k_cSemiSharp]   = "dosd";
  gPortuguesPitchName [k_cSharp]       = "dod";
  gPortuguesPitchName [k_cSesquiSharp] = "dodsd";
  gPortuguesPitchName [k_cDoubleSharp] = "dodd";
    
  gPortuguesPitchName [k_dDoubleFlat]  = "rebb";
  gPortuguesPitchName [k_dSesquiFlat]  = "rebtqt";
  gPortuguesPitchName [k_dFlat]        = "reb";
  gPortuguesPitchName [k_dSemiFlat]    = "resb";
  gPortuguesPitchName [k_dNatural]     = "re";
  gPortuguesPitchName [k_dSemiSharp]   = "resd";
  gPortuguesPitchName [k_dSharp]       = "red";
  gPortuguesPitchName [k_dSesquiSharp] = "redsd";
  gPortuguesPitchName [k_dDoubleSharp] = "redd";

  gPortuguesPitchName [k_eDoubleFlat]  = "mibb";
  gPortuguesPitchName [k_eSesquiFlat]  = "mibtqt";
  gPortuguesPitchName [k_eFlat]        = "mib";
  gPortuguesPitchName [k_eSemiFlat]    = "misb";
  gPortuguesPitchName [k_eNatural]     = "mi";
  gPortuguesPitchName [k_eSemiSharp]   = "misd";
  gPortuguesPitchName [k_eSharp]       = "mid";
  gPortuguesPitchName [k_eSesquiSharp] = "midsd";
  gPortuguesPitchName [k_eDoubleSharp] = "midd";
    
  gPortuguesPitchName [k_fDoubleFlat]  = "fabb";
  gPortuguesPitchName [k_fSesquiFlat]  = "fabtqt";
  gPortuguesPitchName [k_fFlat]        = "fab";
  gPortuguesPitchName [k_fSemiFlat]    = "fasb";
  gPortuguesPitchName [k_fNatural]     = "fa";
  gPortuguesPitchName [k_fSemiSharp]   = "fasd";
  gPortuguesPitchName [k_fSharp]       = "fad";
  gPortuguesPitchName [k_fSesquiSharp] = "fadsd";
  gPortuguesPitchName [k_fDoubleSharp] = "fadd";
    
  gPortuguesPitchName [k_gDoubleFlat]  = "solbb";
  gPortuguesPitchName [k_gSesquiFlat]  = "solbtqt";
  gPortuguesPitchName [k_gFlat]        = "solb";
  gPortuguesPitchName [k_gSemiFlat]    = "solsb";
  gPortuguesPitchName [k_gNatural]     = "sol";
  gPortuguesPitchName [k_gSemiSharp]   = "solsd";
  gPortuguesPitchName [k_gSharp]       = "sold";
  gPortuguesPitchName [k_gSesquiSharp] = "soldsd";
  gPortuguesPitchName [k_gDoubleSharp] = "soldd";

  // suomi
  gSuomiPitchName [k_aDoubleFlat]  = "asas";
  gSuomiPitchName [k_aSesquiFlat]  = "aSesquiFlat???";
  gSuomiPitchName [k_aFlat]        = "as";
  gSuomiPitchName [k_aSemiFlat]    = "aSemiFlat???";
  gSuomiPitchName [k_aNatural]     = "a";
  gSuomiPitchName [k_aSemiSharp]   = "aSemiSharp???";
  gSuomiPitchName [k_aSharp]       = "ais";
  gSuomiPitchName [k_aSesquiSharp] = "aSesquiSharp???";
  gSuomiPitchName [k_aDoubleSharp] = "aisis";
    
  gSuomiPitchName [k_bDoubleFlat]  = "bes";
  gSuomiPitchName [k_bSesquiFlat]  = "bSesquiFlat???";
  gSuomiPitchName [k_bFlat]        = "b";
  gSuomiPitchName [k_bSemiFlat]    = "bSemiFlat???";
  gSuomiPitchName [k_bNatural]     = "h";
  gSuomiPitchName [k_bSemiSharp]   = "bSemiSharp???";
  gSuomiPitchName [k_bSharp]       = "his";
  gSuomiPitchName [k_bSesquiSharp] = "bSesquiSharp???";
  gSuomiPitchName [k_bDoubleSharp] = "hisis";
    
  gSuomiPitchName [k_cDoubleFlat]  = "ceses";
  gSuomiPitchName [k_cSesquiFlat]  = "cSesquiFlat???";
  gSuomiPitchName [k_cFlat]        = "ces";
  gSuomiPitchName [k_cSemiFlat]    = "cSemiFlat???";
  gSuomiPitchName [k_cNatural]     = "c";
  gSuomiPitchName [k_cSemiSharp]   = "cSemiSharp???";
  gSuomiPitchName [k_cSharp]       = "cis";
  gSuomiPitchName [k_cSesquiSharp] = "cSesquiSharp???";
  gSuomiPitchName [k_cDoubleSharp] = "cisis";
    
  gSuomiPitchName [k_dDoubleFlat]  = "deses";
  gSuomiPitchName [k_dSesquiFlat]  = "dSesquiFlat???";
  gSuomiPitchName [k_dFlat]        = "des";
  gSuomiPitchName [k_dSemiFlat]    = "dSemiFlat???";
  gSuomiPitchName [k_dNatural]     = "d";
  gSuomiPitchName [k_dSemiSharp]   = "dSemiSharp???";
  gSuomiPitchName [k_dSharp]       = "dis";
  gSuomiPitchName [k_dSesquiSharp] = "dSesquiSharp???";
  gSuomiPitchName [k_dDoubleSharp] = "disis";

  gSuomiPitchName [k_eDoubleFlat]  = "eses";
  gSuomiPitchName [k_eSesquiFlat]  = "eSesquiFlat???";
  gSuomiPitchName [k_eFlat]        = "es";
  gSuomiPitchName [k_eSemiFlat]    = "eSemiFlat???";
  gSuomiPitchName [k_eNatural]     = "e";
  gSuomiPitchName [k_eSemiSharp]   = "eSemiSharp???";
  gSuomiPitchName [k_eSharp]       = "eis";
  gSuomiPitchName [k_eSesquiSharp] = "eSesquiSharp???";
  gSuomiPitchName [k_eDoubleSharp] = "eisis";
    
  gSuomiPitchName [k_fDoubleFlat]  = "feses";
  gSuomiPitchName [k_fSesquiFlat]  = "fSesquiFlat???";
  gSuomiPitchName [k_fFlat]        = "fes";
  gSuomiPitchName [k_fSemiFlat]    = "fSemiFlat???";
  gSuomiPitchName [k_fNatural]     = "f";
  gSuomiPitchName [k_fSemiSharp]   = "fSemiSharp???";
  gSuomiPitchName [k_fSharp]       = "fis";
  gSuomiPitchName [k_fSesquiSharp] = "fSesquiSharp???";
  gSuomiPitchName [k_fDoubleSharp] = "fisis";
    
  gSuomiPitchName [k_gDoubleFlat]  = "geses";
  gSuomiPitchName [k_gSesquiFlat]  = "gSesquiFlat???";
  gSuomiPitchName [k_gFlat]        = "ges";
  gSuomiPitchName [k_gSemiFlat]    = "gSemiFlat???";
  gSuomiPitchName [k_gNatural]     = "g";
  gSuomiPitchName [k_gSemiSharp]   = "gSemiSharp???";
  gSuomiPitchName [k_gSharp]       = "gis";
  gSuomiPitchName [k_gSesquiSharp] = "gSesquiSharp???";
  gSuomiPitchName [k_gDoubleSharp] = "gisis";

  // svenska
  gSvenskaPitchName [k_aDoubleFlat]  = "assess";
  gSvenskaPitchName [k_aSesquiFlat]  = "aSesquiFlat???";
  gSvenskaPitchName [k_aFlat]        = "ass";
  gSvenskaPitchName [k_aSemiFlat]    = "aSemiFlat???";
  gSvenskaPitchName [k_aNatural]     = "a";
  gSvenskaPitchName [k_aSemiSharp]   = "aSemiSharp???";
  gSvenskaPitchName [k_aSharp]       = "aiss";
  gSvenskaPitchName [k_aSesquiSharp] = "aSesquiSharp???";
  gSvenskaPitchName [k_aDoubleSharp] = "aississ";
    
  gSvenskaPitchName [k_bDoubleFlat]  = "hessess";
  gSvenskaPitchName [k_bSesquiFlat]  = "bSesquiFlat???";
  gSvenskaPitchName [k_bFlat]        = "b";
  gSvenskaPitchName [k_bSemiFlat]    = "bSemiFlat???";
  gSvenskaPitchName [k_bNatural]     = "h";
  gSvenskaPitchName [k_bSemiSharp]   = "bSemiSharp???";
  gSvenskaPitchName [k_bSharp]       = "hiss";
  gSvenskaPitchName [k_bSesquiSharp] = "bSesquiSharp???";
  gSvenskaPitchName [k_bDoubleSharp] = "hississ";
    
  gSvenskaPitchName [k_cDoubleFlat]  = "cessess";
  gSvenskaPitchName [k_cSesquiFlat]  = "cSesquiFlat???";
  gSvenskaPitchName [k_cFlat]        = "cess";
  gSvenskaPitchName [k_cSemiFlat]    = "cSemiFlat???";
  gSvenskaPitchName [k_cNatural]     = "c";
  gSvenskaPitchName [k_cSemiSharp]   = "cSemiSharp???";
  gSvenskaPitchName [k_cSharp]       = "ciss";
  gSvenskaPitchName [k_cSesquiSharp] = "cSesquiSharp???";
  gSvenskaPitchName [k_cDoubleSharp] = "cississ";
    
  gSvenskaPitchName [k_dDoubleFlat]  = "dessess";
  gSvenskaPitchName [k_dSesquiFlat]  = "dSesquiFlat???";
  gSvenskaPitchName [k_dFlat]        = "dess";
  gSvenskaPitchName [k_dSemiFlat]    = "dSemiFlat???";
  gSvenskaPitchName [k_dNatural]     = "d";
  gSvenskaPitchName [k_dSemiSharp]   = "dSemiSharp???";
  gSvenskaPitchName [k_dSharp]       = "diss";
  gSvenskaPitchName [k_dSesquiSharp] = "dSesquiSharp???";
  gSvenskaPitchName [k_dDoubleSharp] = "dississ";

  gSvenskaPitchName [k_eDoubleFlat]  = "essess";
  gSvenskaPitchName [k_eSesquiFlat]  = "eSesquiFlat???";
  gSvenskaPitchName [k_eFlat]        = "ess";
  gSvenskaPitchName [k_eSemiFlat]    = "eSemiFlat???";
  gSvenskaPitchName [k_eNatural]     = "e";
  gSvenskaPitchName [k_eSemiSharp]   = "eSemiSharp???";
  gSvenskaPitchName [k_eSharp]       = "eiss";
  gSvenskaPitchName [k_eSesquiSharp] = "eSesquiSharp???";
  gSvenskaPitchName [k_eDoubleSharp] = "eississ";
    
  gSvenskaPitchName [k_fDoubleFlat]  = "fessess";
  gSvenskaPitchName [k_fSesquiFlat]  = "fSesquiFlat???";
  gSvenskaPitchName [k_fFlat]        = "fess";
  gSvenskaPitchName [k_fSemiFlat]    = "fSemiFlat???";
  gSvenskaPitchName [k_fNatural]     = "f";
  gSvenskaPitchName [k_fSemiSharp]   = "fSemiSharp???";
  gSvenskaPitchName [k_fSharp]       = "fiss";
  gSvenskaPitchName [k_fSesquiSharp] = "fSesquiSharp???";
  gSvenskaPitchName [k_fDoubleSharp] = "fississ";
    
  gSvenskaPitchName [k_gDoubleFlat]  = "gessess";
  gSvenskaPitchName [k_gSesquiFlat]  = "gSesquiFlat???";
  gSvenskaPitchName [k_gFlat]        = "gess";
  gSvenskaPitchName [k_gSemiFlat]    = "gSemiFlat???";
  gSvenskaPitchName [k_gNatural]     = "g";
  gSvenskaPitchName [k_gSemiSharp]   = "gSemiSharp???";
  gSvenskaPitchName [k_gSharp]       = "giss";
  gSvenskaPitchName [k_gSesquiSharp] = "gSesquiSharp???";
  gSvenskaPitchName [k_gDoubleSharp] = "gississ";

  // vlaams
  gVlaamsPitchName [k_aDoubleFlat]  = "labb";
  gVlaamsPitchName [k_aSesquiFlat]  = "laSesquiFlat???";
  gVlaamsPitchName [k_aFlat]        = "lab";
  gVlaamsPitchName [k_aSemiFlat]    = "laSemiFlat???";
  gVlaamsPitchName [k_aNatural]     = "la";
  gVlaamsPitchName [k_aSemiSharp]   = "laSemiSharp???";
  gVlaamsPitchName [k_aSharp]       = "lak";
  gVlaamsPitchName [k_aSesquiSharp] = "laSesquiSharp???";
  gVlaamsPitchName [k_aDoubleSharp] = "lakk";
    
  gVlaamsPitchName [k_bDoubleFlat]  = "sibb";
  gVlaamsPitchName [k_bSesquiFlat]  = "siSesquiFlat???";
  gVlaamsPitchName [k_bFlat]        = "sib";
  gVlaamsPitchName [k_bSemiFlat]    = "siSemiFlat???";
  gVlaamsPitchName [k_bNatural]     = "si";
  gVlaamsPitchName [k_bSemiSharp]   = "siSemiSharp???";
  gVlaamsPitchName [k_bSharp]       = "sik";
  gVlaamsPitchName [k_bSesquiSharp] = "siSesquiSharp???";
  gVlaamsPitchName [k_bDoubleSharp] = "sikk";
    
  gVlaamsPitchName [k_cDoubleFlat]  = "dobb";
  gVlaamsPitchName [k_cSesquiFlat]  = "doSesquiFlat???";
  gVlaamsPitchName [k_cFlat]        = "dob";
  gVlaamsPitchName [k_cSemiFlat]    = "doSemiFlat???";
  gVlaamsPitchName [k_cNatural]     = "do";
  gVlaamsPitchName [k_cSemiSharp]   = "doSemiSharp???";
  gVlaamsPitchName [k_cSharp]       = "dok";
  gVlaamsPitchName [k_cSesquiSharp] = "doSesquiSharp???";
  gVlaamsPitchName [k_cDoubleSharp] = "dokk";
    
  gVlaamsPitchName [k_dDoubleFlat]  = "rebb";
  gVlaamsPitchName [k_dSesquiFlat]  = "reSesquiFlat???";
  gVlaamsPitchName [k_dFlat]        = "reb";
  gVlaamsPitchName [k_dSemiFlat]    = "reSemiFlat???";
  gVlaamsPitchName [k_dNatural]     = "re";
  gVlaamsPitchName [k_dSemiSharp]   = "reSemiSharp???";
  gVlaamsPitchName [k_dSharp]       = "rek";
  gVlaamsPitchName [k_dSesquiSharp] = "reSesquiSharp???";
  gVlaamsPitchName [k_dDoubleSharp] = "rekk";

  gVlaamsPitchName [k_eDoubleFlat]  = "mibb";
  gVlaamsPitchName [k_eSesquiFlat]  = "miSesquiFlat???";
  gVlaamsPitchName [k_eFlat]        = "mib";
  gVlaamsPitchName [k_eSemiFlat]    = "miSemiFlat???";
  gVlaamsPitchName [k_eNatural]     = "mi";
  gVlaamsPitchName [k_eSemiSharp]   = "miSemiSharp???";
  gVlaamsPitchName [k_eSharp]       = "mik";
  gVlaamsPitchName [k_eSesquiSharp] = "miSesquiSharp???";
  gVlaamsPitchName [k_eDoubleSharp] = "mikk";
    
  gVlaamsPitchName [k_fDoubleFlat]  = "fabb";
  gVlaamsPitchName [k_fSesquiFlat]  = "faSesquiFlat???";
  gVlaamsPitchName [k_fFlat]        = "fab";
  gVlaamsPitchName [k_fSemiFlat]    = "faSemiFlat???";
  gVlaamsPitchName [k_fNatural]     = "fa";
  gVlaamsPitchName [k_fSemiSharp]   = "faSemiSharp???";
  gVlaamsPitchName [k_fSharp]       = "fak";
  gVlaamsPitchName [k_fSesquiSharp] = "faSesquiSharp???";
  gVlaamsPitchName [k_fDoubleSharp] = "fakk";
    
  gVlaamsPitchName [k_gDoubleFlat]  = "solbb";
  gVlaamsPitchName [k_gSesquiFlat]  = "solSesquiFlat???";
  gVlaamsPitchName [k_gFlat]        = "solb";
  gVlaamsPitchName [k_gSemiFlat]    = "solSemiFlat???";
  gVlaamsPitchName [k_gNatural]     = "sol";
  gVlaamsPitchName [k_gSemiSharp]   = "solSemiSharp???";
  gVlaamsPitchName [k_gSharp]       = "solk";
  gVlaamsPitchName [k_gSesquiSharp] = "solSesquiSharp???";
  gVlaamsPitchName [k_gDoubleSharp] = "solkk";

  gChordsLanguagesMap [k_GermanChords]     = "german";
  gChordsLanguagesMap [k_SemiGermanChords] = "semiGerman";
  gChordsLanguagesMap [k_ItalianChords]    = "italian";
  gChordsLanguagesMap [k_FrenchChords]     = "french";
}

msrDiatonicPitch msrDiatonicPitchFromString (
  char diatonicNoteName)
{
  msrDiatonicPitch result;
  
  switch (diatonicNoteName) {
    case 'a':
    case 'A':
      result = kA;
       break;
    case 'b':
    case 'B':
      result = kB;
      break;
    case 'c':
    case 'C':
      result = kC;
      break;
    case 'd':
    case 'D':
      result = kD;
      break;
    case 'e':
    case 'E':
      result = kE;
      break;
    case 'f':
    case 'F':
      result = kF;
      break;
    case 'g':
    case 'G':
      result = kG;
      break;
    default: {}
  } // switch

  return result;
}

string msrDiatonicPitchAsString (
  msrDiatonicPitch diatonicPitch) // JMI
{
  string result;
  
  switch (diatonicPitch) {
    case kA: result = "a"; break;
    case kB: result = "b"; break;
    case kC: result = "c"; break;
    case kD: result = "d"; break;
    case kE: result = "e"; break;
    case kF: result = "f"; break;
    case kG: result = "g"; break;
  } // switch

  return result;
}

string msrQuatertonesPitchesLanguageAsString (
  msrQuatertonesPitchesLanguage language)
{
  string result;
  
  switch (language) {
    case kNederlands:
      result = "nederlands";
      break;
    case kCatalan:
      result = "catalan";
      break;
    case kDeutsch:
      result = "deutsch";
      break;
    case kEnglish:
      result = "english";
      break;
    case kEspanol:
      result = "espanol";
      break;
    case kFrancais:
      result = "francais";
      break;
    case kItaliano:
      result = "italiano";
      break;
    case kNorsk:
      result = "norsk";
      break;
    case kPortugues:
      result = "portugues";
      break;
    case kSuomi:
      result = "suomi";
      break;
    case kSvenska:
      result = "svenska";
      break;
    case kVlaams:
      result = "vlaams";
      break;
  } // switch

  return result;
}

msrAlteration msrAlterationFromMusicXMLAlter (
  float alter)
{

/*
  The alter element represents chromatic alteration
  in number of semitones (e.g., -1 for flat, 1 for sharp).
  Decimal values like 0.5 (quarter tone sharp) are used for microtones:

  semi-sharp semi-flat sesqui-sharp sesqui-flat double-sharp double-flat
      +0.5      -0.5        +1.5       -1.5         +2.0        -2.0
*/

  msrAlteration result;
  
  if      (alter == 0 ) {
    result = kNatural;
  }
  
  else if (alter == -1 ) {
    result = kFlat;
  }
  
  else if (alter == 1 ) {
    result = kSharp;
  }
  
  else if (alter == -0.5 ) {
    result = kSemiFlat;
  }
  
  else if (alter == +0.5 ) {
    result = kSemiSharp;
  }
  
  else if (alter == -1.5 ) {
    result = kSesquiFlat;
  }
  
  else if (alter == +1.5 ) {
    result = kSesquiSharp;
  }
  
  else if (alter == -2 ) {
    result = kDoubleFlat;
  }
  
  else if (alter == +2 ) {
    result = kDoubleSharp;
  }
  
  else {
    result = k_NoAlteration;
  }

  return result;
}

string msrAlterationAsString (
  msrAlteration alteration)
{
  string result;
  
  switch (alteration) {
    case kDoubleFlat:
      result = "DoubleFlat";
      break;
    case kSesquiFlat:
      result = "SesquiFlat";
      break;
    case kFlat:
      result = "Flat";
      break;
    case kSemiFlat:
      result = "SemiFlat";
      break;
    case kNatural:
      result = "Natural";
      break;
    case kSemiSharp:
      result = "SemiSharp";
      break;
    case kSharp:
      result = "Sharp";
      break;
    case kSesquiSharp:
      result = "SesquiSharp";
      break;
    case kDoubleSharp:
      result = "DoubleSharp";
      break;
    case k_NoAlteration:
      result = "alteration???";
      break;
  } // switch

  return result;
}

void setDiatonicPitchAndAlteration (
  msrQuartertonesPitch quartertonesPitch,
  msrDiatonicPitch& diatonicPitch,
  msrAlteration& alteration)
{
  switch (quartertonesPitch) {
    case k_aDoubleFlat:
      diatonicPitch = kA;
      alteration    = kDoubleFlat;
      break;
    case k_aSesquiFlat:
      diatonicPitch = kA;
      alteration    = kSesquiFlat;
      break;
    case k_aFlat:
      diatonicPitch = kA;
      alteration    = kFlat;
      break;
    case k_aSemiFlat:
      diatonicPitch = kA;
      alteration    = kSemiFlat;
      break;
    case k_aNatural:
      diatonicPitch = kA;
      alteration    = kNatural;
      break;
    case k_aSemiSharp:
      diatonicPitch = kA;
      alteration    = kSemiSharp;
      break;
    case k_aSharp:
      diatonicPitch = kA;
      alteration    = kSharp;
      break;
    case k_aSesquiSharp:
      diatonicPitch = kA;
      alteration    = kSesquiSharp;
      break;
    case k_aDoubleSharp:
      diatonicPitch = kA;
      alteration    = kDoubleSharp;
      break;

    case k_bDoubleFlat:
      diatonicPitch = kB;
      alteration    = kDoubleFlat;
      break;
    case k_bSesquiFlat:
      diatonicPitch = kB;
      alteration    = kSesquiFlat;
      break;
    case k_bFlat:
      diatonicPitch = kB;
      alteration    = kFlat;
      break;
    case k_bSemiFlat:
      diatonicPitch = kB;
      alteration    = kSemiFlat;
      break;
    case k_bNatural:
      diatonicPitch = kB;
      alteration    = kNatural;
      break;
    case k_bSemiSharp:
      diatonicPitch = kB;
      alteration    = kSemiSharp;
      break;
    case k_bSharp:
      diatonicPitch = kB;
      alteration    = kSharp;
      break;
    case k_bSesquiSharp:
      diatonicPitch = kB;
      alteration    = kSesquiSharp;
      break;
    case k_bDoubleSharp:
      diatonicPitch = kB;
      alteration    = kDoubleSharp;
      break;

    case k_cDoubleFlat:
      diatonicPitch = kC;
      alteration    = kDoubleFlat;
      break;
    case k_cSesquiFlat:
      diatonicPitch = kC;
      alteration    = kSesquiFlat;
      break;
    case k_cFlat:
      diatonicPitch = kC;
      alteration    = kFlat;
      break;
    case k_cSemiFlat:
      diatonicPitch = kC;
      alteration    = kSemiFlat;
      break;
    case k_cNatural:
      diatonicPitch = kC;
      alteration    = kNatural;
      break;
    case k_cSemiSharp:
      diatonicPitch = kC;
      alteration    = kSemiSharp;
      break;
    case k_cSharp:
      diatonicPitch = kC;
      alteration    = kSharp;
      break;
    case k_cSesquiSharp:
      diatonicPitch = kC;
      alteration    = kSesquiSharp;
      break;
    case k_cDoubleSharp:
      diatonicPitch = kC;
      alteration    = kDoubleSharp;
      break;

    case k_dDoubleFlat:
      diatonicPitch = kD;
      alteration    = kDoubleFlat;
      break;
    case k_dSesquiFlat:
      diatonicPitch = kD;
      alteration    = kSesquiFlat;
      break;
    case k_dFlat:
      diatonicPitch = kD;
      alteration    = kFlat;
      break;
    case k_dSemiFlat:
      diatonicPitch = kD;
      alteration    = kSemiFlat;
      break;
    case k_dNatural:
      diatonicPitch = kD;
      alteration    = kNatural;
      break;
    case k_dSemiSharp:
      diatonicPitch = kD;
      alteration    = kSemiSharp;
      break;
    case k_dSharp:
      diatonicPitch = kD;
      alteration    = kSharp;
      break;
    case k_dSesquiSharp:
      diatonicPitch = kD;
      alteration    = kSesquiSharp;
      break;
    case k_dDoubleSharp:
      diatonicPitch = kD;
      alteration    = kDoubleSharp;
      break;

    case k_eDoubleFlat:
      diatonicPitch = kE;
      alteration    = kDoubleFlat;
      break;
    case k_eSesquiFlat:
      diatonicPitch = kE;
      alteration    = kSesquiFlat;
      break;
    case k_eFlat:
      diatonicPitch = kE;
      alteration    = kFlat;
      break;
    case k_eSemiFlat:
      diatonicPitch = kE;
      alteration    = kSemiFlat;
      break;
    case k_eNatural:
      diatonicPitch = kE;
      alteration    = kNatural;
      break;
    case k_eSemiSharp:
      diatonicPitch = kE;
      alteration    = kSemiSharp;
      break;
    case k_eSharp:
      diatonicPitch = kE;
      alteration    = kSharp;
      break;
    case k_eSesquiSharp:
      diatonicPitch = kE;
      alteration    = kSesquiSharp;
      break;
    case k_eDoubleSharp:
      diatonicPitch = kE;
      alteration    = kDoubleSharp;
      break;

    case k_fDoubleFlat:
      diatonicPitch = kF;
      alteration    = kDoubleFlat;
      break;
    case k_fSesquiFlat:
      diatonicPitch = kF;
      alteration    = kSesquiFlat;
      break;
    case k_fFlat:
      diatonicPitch = kF;
      alteration    = kFlat;
      break;
    case k_fSemiFlat:
      diatonicPitch = kF;
      alteration    = kSemiFlat;
      break;
    case k_fNatural:
      diatonicPitch = kF;
      alteration    = kNatural;
      break;
    case k_fSemiSharp:
      diatonicPitch = kF;
      alteration    = kSemiSharp;
      break;
    case k_fSharp:
      diatonicPitch = kF;
      alteration    = kSharp;
      break;
    case k_fSesquiSharp:
      diatonicPitch = kF;
      alteration    = kSesquiSharp;
      break;
    case k_fDoubleSharp:
      diatonicPitch = kF;
      alteration    = kDoubleSharp;
      break;

    case k_gDoubleFlat:
      diatonicPitch = kG;
      alteration    = kDoubleFlat;
      break;
    case k_gSesquiFlat:
      diatonicPitch = kG;
      alteration    = kSesquiFlat;
      break;
    case k_gFlat:
      diatonicPitch = kG;
      break;
    case k_gSemiFlat:
      diatonicPitch = kG;
      alteration    = kSemiFlat;
      break;
    case k_gNatural:
      diatonicPitch = kG;
      alteration    = kNatural;
      break;
    case k_gSemiSharp:
      diatonicPitch = kG;
      alteration    = kSemiSharp;
      break;
    case k_gSharp:
      diatonicPitch = kG;
      alteration    = kSharp;
      break;
    case k_gSesquiSharp:
      diatonicPitch = kG;
      alteration    = kSesquiSharp;
      break;
    case k_gDoubleSharp:
      diatonicPitch = kG;
      alteration    = kDoubleSharp;
      break;
      
    case k_Rest:
      diatonicPitch = kA; // any value would fit JMI
      alteration    = k_NoAlteration;
      
      break;
    case k_NoPitch:
      diatonicPitch = kA; // any value would fit
      alteration    = k_NoAlteration;
      break;
  } // switch
}

msrQuartertonesPitch quatertonesPitchFromDiatonicPitchAndAlteration (
  int              inputLineNumber,
  msrDiatonicPitch diatonicPitch,
  msrAlteration    alteration)
{
  msrQuartertonesPitch result;
  
  switch (diatonicPitch) {
    case kA:
      switch (alteration) {
        case kDoubleFlat:
          result = k_aDoubleFlat;
          break;
        case kSesquiFlat:
          result = k_aSesquiFlat;
          break;
        case kFlat:
          result = k_aFlat;
          break;
        case kSemiFlat:
          result = k_aSemiFlat;
          break;
        case kNatural:
          result = k_aNatural;
          break;
        case kSemiSharp:
          result = k_aSemiSharp;
          break;
        case kSharp:
          result = k_aSharp;
          break;
        case kSesquiSharp:
          result = k_aSesquiSharp;
          break;
        case kDoubleSharp:
          result = k_aDoubleSharp;
          break;
        case k_NoAlteration:
          {
            stringstream s;

            s <<
              "'A' alteration has not been set"
              ", line = " << inputLineNumber;

            msrInternalError (
              inputLineNumber,
              s.str());
          }
          break;
      } // switch
      break;
      
    case kB:
      switch (alteration) {
        case kDoubleFlat:
          result = k_bDoubleFlat;
          break;
        case kSesquiFlat:
          result = k_bSesquiFlat;
          break;
        case kFlat:
          result = k_bFlat;
          break;
        case kSemiFlat:
          result = k_bSemiFlat;
          break;
        case kNatural:
          result = k_bNatural;
          break;
        case kSemiSharp:
          result = k_bSemiSharp;
          break;
        case kSharp:
          result = k_bSharp;
          break;
        case kSesquiSharp:
          result = k_bSesquiSharp;
          break;
        case kDoubleSharp:
          result = k_bDoubleSharp;
          break;
        case k_NoAlteration:
          {
            stringstream s;

            s <<
              "'B' alteration has not been set"
              ", line = " << inputLineNumber;

            msrInternalError (
              inputLineNumber,
              s.str());
          }
          break;
      } // switch
      break;
      
      break;
      
    case kC:
      switch (alteration) {
        case kDoubleFlat:
          result = k_cDoubleFlat;
          break;
        case kSesquiFlat:
          result = k_cSesquiFlat;
          break;
        case kFlat:
          result = k_cFlat;
          break;
        case kSemiFlat:
          result = k_cSemiFlat;
          break;
        case kNatural:
          result = k_cNatural;
          break;
        case kSemiSharp:
          result = k_cSemiSharp;
          break;
        case kSharp:
          result = k_cSharp;
          break;
        case kSesquiSharp:
          result = k_cSesquiSharp;
          break;
        case kDoubleSharp:
          result = k_cDoubleSharp;
          break;
        case k_NoAlteration:
          {
            stringstream s;

            s <<
              "'C' alteration has not been set"
              ", line = " << inputLineNumber;

            msrInternalError (
              inputLineNumber,
              s.str());
          }
          break;
      } // switch
      break;
      
    case kD:
      switch (alteration) {
        case kDoubleFlat:
          result = k_dDoubleFlat;
          break;
        case kSesquiFlat:
          result = k_dSesquiFlat;
          break;
        case kFlat:
          result = k_dFlat;
          break;
        case kSemiFlat:
          result = k_dSemiFlat;
          break;
        case kNatural:
          result = k_dNatural;
          break;
        case kSemiSharp:
          result = k_dSemiSharp;
          break;
        case kSharp:
          result = k_dSharp;
          break;
        case kSesquiSharp:
          result = k_dSesquiSharp;
          break;
        case kDoubleSharp:
          result = k_dDoubleSharp;
          break;
        case k_NoAlteration:
          {
            stringstream s;

            s <<
              "'D' alteration has not been set"
              ", line = " << inputLineNumber;

            msrInternalError (
              inputLineNumber,
              s.str());
          }
          break;
      } // switch
      break;
      
    case kE:
      switch (alteration) {
        case kDoubleFlat:
          result = k_eDoubleFlat;
          break;
        case kSesquiFlat:
          result = k_eSesquiFlat;
          break;
        case kFlat:
          result = k_eFlat;
          break;
        case kSemiFlat:
          result = k_eSemiFlat;
          break;
        case kNatural:
          result = k_eNatural;
          break;
        case kSemiSharp:
          result = k_eSemiSharp;
          break;
        case kSharp:
          result = k_eSharp;
          break;
        case kSesquiSharp:
          result = k_eSesquiSharp;
          break;
        case kDoubleSharp:
          result = k_eDoubleSharp;
          break;
        case k_NoAlteration:
          {
            stringstream s;

            s <<
              "'E' alteration has not been set"
              ", line = " << inputLineNumber;

            msrInternalError (
              inputLineNumber,
              s.str());
          }
          break;
      } // switch
      break;
      
    case kF:
      switch (alteration) {
        case kDoubleFlat:
          result = k_fDoubleFlat;
          break;
        case kSesquiFlat:
          result = k_fSesquiFlat;
          break;
        case kFlat:
          result = k_fFlat;
          break;
        case kSemiFlat:
          result = k_fSemiFlat;
          break;
        case kNatural:
          result = k_fNatural;
          break;
        case kSemiSharp:
          result = k_fSemiSharp;
          break;
        case kSharp:
          result = k_fSharp;
          break;
        case kSesquiSharp:
          result = k_fSesquiSharp;
          break;
        case kDoubleSharp:
          result = k_fDoubleSharp;
          break;
        case k_NoAlteration:
          {
            stringstream s;

            s <<
              "'F' alteration has not been set"
              ", line = " << inputLineNumber;

            msrInternalError (
              inputLineNumber,
              s.str());
          }
          break;
      } // switch
      break;
      
    case kG:
      switch (alteration) {
        case kDoubleFlat:
          result = k_gDoubleFlat;
          break;
        case kSesquiFlat:
          result = k_gSesquiFlat;
          break;
        case kFlat:
          result = k_gFlat;
          break;
        case kSemiFlat:
          result = k_gSemiFlat;
          break;
        case kNatural:
          result = k_gNatural;
          break;
        case kSemiSharp:
          result = k_gSemiSharp;
          break;
        case kSharp:
          result = k_gSharp;
          break;
        case kSesquiSharp:
          result = k_gSesquiSharp;
          break;
        case kDoubleSharp:
          result = k_gDoubleSharp;
          break;
        case k_NoAlteration:
          {
            stringstream s;

            s <<
              "'G' alteration has not been set"
              ", line = " << inputLineNumber;

            msrInternalError (
              inputLineNumber,
              s.str());
          }
          break;
      } // switch
      break;
  } // switch

  return result;
}

msrDiatonicPitch msrDiatonicPitchFromQuatertonesPitch (
  int                  inputLineNumber,
  msrQuartertonesPitch quartertonesPitch)
{
  msrDiatonicPitch result;
  
  switch (quartertonesPitch) {
    case k_aDoubleFlat:
    case k_aSesquiFlat:
    case k_aFlat:
    case k_aSemiFlat:
    case k_aNatural:
    case k_aSemiSharp:
    case k_aSharp:
    case k_aSesquiSharp:
    case k_aDoubleSharp:
      result = kA;
      break;

    case k_bDoubleFlat:
    case k_bSesquiFlat:
    case k_bFlat:
    case k_bSemiFlat:
    case k_bNatural:
    case k_bSemiSharp:
    case k_bSharp:
    case k_bSesquiSharp:
    case k_bDoubleSharp:
      result = kB;
      break;

    case k_cDoubleFlat:
    case k_cSesquiFlat:
    case k_cFlat:
    case k_cSemiFlat:
    case k_cNatural:
    case k_cSemiSharp:
    case k_cSharp:
    case k_cSesquiSharp:
    case k_cDoubleSharp:
      result = kC;
      break;

    case k_dDoubleFlat:
    case k_dSesquiFlat:
    case k_dFlat:
    case k_dSemiFlat:
    case k_dNatural:
    case k_dSemiSharp:
    case k_dSharp:
    case k_dSesquiSharp:
    case k_dDoubleSharp:
      result = kD;
      break;

    case k_eDoubleFlat:
    case k_eSesquiFlat:
    case k_eFlat:
    case k_eSemiFlat:
    case k_eNatural:
    case k_eSemiSharp:
    case k_eSharp:
    case k_eSesquiSharp:
    case k_eDoubleSharp:
      result = kE;
      break;

    case k_fDoubleFlat:
    case k_fSesquiFlat:
    case k_fFlat:
    case k_fSemiFlat:
    case k_fNatural:
    case k_fSemiSharp:
    case k_fSharp:
    case k_fSesquiSharp:
    case k_fDoubleSharp:
      result = kF;
      break;

    case k_gDoubleFlat:
    case k_gSesquiFlat:
    case k_gFlat:
    case k_gSemiFlat:
    case k_gNatural:
    case k_gSemiSharp:
    case k_gSharp:
    case k_gSesquiSharp:
    case k_gDoubleSharp:
      result = kG;
      break;

    case k_Rest:
      {
        stringstream s;

        s <<
          "cannot get the diatonic pitch of a rest"
          ", line = " << inputLineNumber;

        msrInternalError (
          inputLineNumber,
          s.str());
      }
  } // switch

  return result;
}

string msrQuartertonesPitchAsString (
  msrQuatertonesPitchesLanguage language,
  msrQuartertonesPitch          quartertonesPitch)
{
   string result;
  
  switch (language) {
    case kNederlands:
      result = gNederlandsPitchName [quartertonesPitch];
      break;
    case kCatalan:
      result = gCatalanPitchName [quartertonesPitch];
      break;
    case kDeutsch:
      result = gDeutschPitchName [quartertonesPitch];
      break;
    case kEnglish:
      result = gEnglishPitchName [quartertonesPitch];
      break;
    case kEspanol:
      result = gEspanolPitchName [quartertonesPitch];
      break;
    case kFrancais:
      result = gFrancaisPitchName [quartertonesPitch];
      break;
    case kItaliano:
      result = gItalianoPitchName [quartertonesPitch];
      break;
    case kNorsk:
      result = gNorskPitchName [quartertonesPitch];
      break;
    case kPortugues:
      result = gPortuguesPitchName [quartertonesPitch];
      break;
    case kSuomi:
      result = gSuomiPitchName [quartertonesPitch];
      break;
    case kSvenska:
      result = gSvenskaPitchName [quartertonesPitch];
      break;
    case kVlaams:
      result = gVlaamsPitchName [quartertonesPitch];
      break;
  } // switch

  return result;
}

//_______________________________________________________________________________
S_msrOptions msrOptions::create ()
{
  msrOptions* o = new msrOptions();
  assert(o!=0);
  return o;
}

msrOptions::msrOptions ()
{}

bool msrOptions::setQuartertonesPitchesLanguage (string language)
{
  // is language in the note names languages map?
  map<string, msrQuatertonesPitchesLanguage>::const_iterator
    it =
      gQuatertonesPitchesLanguagesMap.find (language);
        
  if (it == gQuatertonesPitchesLanguagesMap.end ()) {
    // no, language is unknown in the map

/* JMI
    cerr <<
      endl << endl;

    cerr <<
      "gQuatertonesPitchesLanguagesMap.size () = " <<
      gQuatertonesPitchesLanguagesMap.size () <<
      endl << endl;
      
    for (
      map<string, quartertonesPitchLanguage>::const_iterator i=gQuatertonesPitchesLanguagesMap.begin();
      i!=gQuatertonesPitchesLanguagesMap.end();
      i++) {
      cerr <<
        (*i).first << ": " << (*i).second <<
        endl << endl;
    } // for
*/
    
    return false;
  }

  fQuatertonesPitchesLanguage = (*it).second;
  
  return true;
}

msrOptions::~msrOptions () {}

S_msrOptions gMsrOptions;

//______________________________________________________________________________
msrElement::msrElement (
  int           inputLineNumber)
{
  fInputLineNumber = inputLineNumber;  
}

msrElement::~msrElement() {}

void msrElement::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr <<
      "==> msrElement::acceptIn()" << endl;
      
  if (visitor<S_msrElement>*
    p =
      dynamic_cast<visitor<S_msrElement>*> (v)) {
        S_msrElement elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr <<
            "==> Launching msrElement::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrElement::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr <<
      "==> msrElement::acceptOut()" << endl;

  if (visitor<S_msrElement>*
    p =
      dynamic_cast<visitor<S_msrElement>*> (v)) {
        S_msrElement elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr <<
            "==> Launching msrElement::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

ostream& operator<< (ostream& os, const S_msrElement& elt)
{
  elt->print (os);
  return os;
}

void msrElement::print (ostream& os)
{
  os << "??? Element ???" << endl;
}

//______________________________________________________________________________
ostream& operator<< (ostream& os, msrNoteData& noteData)
{
  noteData.print (os);
  return os;
}

void msrNoteData::init ()
{
  fNoteDiatonicPitch    = kA; // any value would fit
  fNoteAlteration           = k_NoAlteration;
  fNoteQuatertonesPitch = k_NoPitch;

  fNoteIsARest = false;
  
  fNoteIsUnpitched = false;;
  
  fNoteOctave = -1;

  // MusicXML durations are in divisions per quarter note.
  // LilyPond durations are in whole notes,
  // hence the "* 4" multiplications
  
  // the note duration when played
  fNoteDivisions = -17;

  // tuplets member notes need another value for display
  fNoteDisplayDivisions = -19;

  fNoteDotsNumber = 0;
  
  fNoteType = "";

  fNoteIsAGraceNote = false;
  
  fNoteBelongsToAChord = false;
  
  fNoteBelongsToATuplet = false;

  fNoteStaffNumber = 0;
  fNoteVoiceNumber = 0;
}

msrNoteData::msrNoteData ()
{
  init ();
}


void msrNoteData::setNoteQuartertonesPitch (
  msrQuartertonesPitch quartertonesPitch)
{
  fNoteQuatertonesPitch = quartertonesPitch;

  // set fNoteDiatonicPitch and fNoteAlteration accordingly  
  setDiatonicPitchAndAlteration (
    quartertonesPitch,
    fNoteDiatonicPitch, fNoteAlteration);
}

void msrNoteData::setNoteDiatonicPitchAndAlteration (
  int              inputLineNumber,
  msrDiatonicPitch diatonicPitch,
  msrAlteration    alteration)
{
  fNoteDiatonicPitch = diatonicPitch;

  // set fNoteQuatertonesPitch accordingly
  fNoteQuatertonesPitch =
    quatertonesPitchFromDiatonicPitchAndAlteration (
      inputLineNumber,
      diatonicPitch, alteration);
}

void msrNoteData::print (ostream& os)
{
  const int width = 21;
  
  os <<
    idtr << left <<
      setw(width) << "fNoteIsARest" << " = " <<
      fNoteIsARest <<
      endl <<
    idtr << left <<
      setw(width) << "fNoteDiatonicPitch" << " = " <<
      msrDiatonicPitchAsString (fNoteDiatonicPitch) <<
      endl <<
    idtr << left <<
      setw(width) << "fNoteAlteration" << " = " <<
      fNoteAlteration <<
      endl <<
    idtr << left <<
      setw(width) <<
      "fNoteQuatertonesPitch" << " = " <<
      msrQuartertonesPitchAsString (
        gMsrOptions->fQuatertonesPitchesLanguage,
        fNoteQuatertonesPitch) <<
      endl <<
    idtr << left <<
      setw(width) << "fOctave" << " = " <<
      fNoteOctave <<
      endl <<
    idtr << left <<
      setw(width) << "fDivisions" << " = " <<
      fNoteDivisions <<
      endl <<
    idtr << left <<
      setw(width) << "fDisplayDivisions" << " = " <<
      fNoteDisplayDivisions <<
      endl <<
    idtr << left <<
      setw(width) << "fDotsNumber" << " = " <<
      fNoteDotsNumber <<
      endl <<
    idtr << left <<
      setw(width) << "fType" << " = " <<
      fNoteType <<
      endl <<
      
    idtr << left <<
      setw(width) << "fNoteBelongsToAChord" << " = " <<
      fNoteBelongsToAChord <<
      endl <<
          
    idtr << left <<
      setw(width) << "fNoteBelongsToATuplet" << " = " <<
      fNoteBelongsToATuplet <<
      endl <<
          
    idtr << left <<
      setw(width) << "fStaffNumber" << " = " <<
      fNoteStaffNumber <<
      endl <<
    idtr <<
      setw(width) << "fVoiceNumber" << " = " <<
      fNoteVoiceNumber <<
      endl;
};


//______________________________________________________________________________
void msrBeatData::print (ostream& os)
{
  os <<
    left << setw(26) << "fBeatUnit = " << fBeatUnit <<  endl <<
    left << setw(26) << "fDots = " << fDots <<  endl;
};

//______________________________________________________________________________
S_msrOctaveShift msrOctaveShift::create (
  int                inputLineNumber,
  msrOctaveShiftKind octaveShiftKind,
  int                octaveShiftSize)
{
  msrOctaveShift* o =
    new msrOctaveShift (
      inputLineNumber, octaveShiftKind, octaveShiftSize);
  assert(o!=0);
  return o;
}

msrOctaveShift::msrOctaveShift (
  int                inputLineNumber,
  msrOctaveShiftKind octaveShiftKind,
  int                octaveShiftSize)
    : msrElement (inputLineNumber)
{
  fOctaveShiftKind = octaveShiftKind;

  fOctaveShiftSize = octaveShiftSize;
}

msrOctaveShift::~msrOctaveShift() {}

void msrOctaveShift::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrOctaveShift::acceptIn()" << endl;
      
  if (visitor<S_msrOctaveShift>*
    p =
      dynamic_cast<visitor<S_msrOctaveShift>*> (v)) {
        S_msrOctaveShift elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrOctaveShift::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrOctaveShift::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrOctaveShift::acceptOut()" << endl;

  if (visitor<S_msrOctaveShift>*
    p =
      dynamic_cast<visitor<S_msrOctaveShift>*> (v)) {
        S_msrOctaveShift elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrOctaveShift::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrOctaveShift::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrOctaveShift& elt)
{
  elt->print (os);
  return os;
}

string msrOctaveShift::octaveShiftKindAsString () const
{
  string result;
  
  switch (fOctaveShiftKind) {
    case kOctaveShiftUp:
      result = "up";
      break;
    case kOctaveShiftDown:
      result = "down";
      break;
    case kOctaveShiftStop:
      result = "stop";
      break;
  } // switch

  return result;
}

void msrOctaveShift::print (ostream& os)
{
  idtr++;
  
  os <<
    "OctaveShift" <<
    ", kind: " << octaveShiftKindAsString () <<
    ", size: " << fOctaveShiftSize <<
    endl;

  idtr--;
}

//______________________________________________________________________________
S_msrStem msrStem::create (
  int           inputLineNumber,
  msrStemKind   stemKind)
{
  msrStem* o =
    new msrStem (
      inputLineNumber, stemKind);
  assert(o!=0);
  return o;
}

msrStem::msrStem (
  int           inputLineNumber,
  msrStemKind   stemKind)
    : msrElement (inputLineNumber)
{
  fStemKind   = stemKind; 
}

msrStem::~msrStem() {}

void msrStem::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrStem::acceptIn()" << endl;
      
  if (visitor<S_msrStem>*
    p =
      dynamic_cast<visitor<S_msrStem>*> (v)) {
        S_msrStem elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrStem::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrStem::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrStem::acceptOut()" << endl;

  if (visitor<S_msrStem>*
    p =
      dynamic_cast<visitor<S_msrStem>*> (v)) {
        S_msrStem elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrStem::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrStem::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrStem& elt)
{
  elt->print (os);
  return os;
}

string msrStem::stemKindAsString (
  msrStemKind stemKind)
{
  string result;
  
  switch (stemKind) {
    case k_NoStem:
      result = "none";
      break;
    case kStemUp:
      result = "up";
      break;
    case kStemDown:
      result = "down";
      break;
    case kStemNone:
      result = "none";
      break;
    case kStemDouble:
      result = "double";
      break;
  } // switch

  return result;
}

void msrStem::print (ostream& os)
{
  idtr++;
  
  os <<
    "Stem" " " <<
    stemKindAsString (fStemKind) <<
    ", line " << fInputLineNumber <<
    endl;

  idtr--;
}

//______________________________________________________________________________
S_msrBeam msrBeam::create (
  int           inputLineNumber,
  int           number,
  msrBeamKind   beamKind)
{
  msrBeam* o =
    new msrBeam (
      inputLineNumber, number, beamKind);
  assert(o!=0);
  return o;
}

msrBeam::msrBeam (
  int           inputLineNumber,
  int           number,
  msrBeamKind   beamKind)
    : msrElement (inputLineNumber)
{
  fBeamNumber = number;
  fBeamKind   = beamKind; 
}

msrBeam::~msrBeam() {}

void msrBeam::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrBeam::acceptIn()" << endl;
      
  if (visitor<S_msrBeam>*
    p =
      dynamic_cast<visitor<S_msrBeam>*> (v)) {
        S_msrBeam elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrBeam::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrBeam::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrBeam::acceptOut()" << endl;

  if (visitor<S_msrBeam>*
    p =
      dynamic_cast<visitor<S_msrBeam>*> (v)) {
        S_msrBeam elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrBeam::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrBeam::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrBeam& elt)
{
  elt->print (os);
  return os;
}

string msrBeam::beamKindAsString (
  msrBeamKind beamKind)
{
  string result;
  
  switch (beamKind) {
    case kBeginBeam:
      result = "begin";
      break;
    case kContinueBeam:
      result = "continue";
      break;
    case kEndBeam:
      result = "end";
      break;
    case kForwardHookBeam:
      result = "forward";
      break;
    case kBackwardHookBeam:
      result = "backward";
      break;
    case k_NoBeam:
      result = "### none ###";
      break;
  } // switch

  return result;
}

void msrBeam::print (ostream& os)
{
  idtr++;
  
  os <<
    "Beam" <<
    " number " << fBeamNumber <<
    ", line " << fInputLineNumber << " " <<
    beamKindAsString (fBeamKind) <<
    endl;

  idtr--;
}

//______________________________________________________________________________
S_msrArticulation msrArticulation::create (
  int                 inputLineNumber,
  msrArticulationKind articulationKind)
{
  msrArticulation* o =
    new msrArticulation (
      inputLineNumber, articulationKind);
  assert (o!=0);
  return o;
}

msrArticulation::msrArticulation (
  int                 inputLineNumber,
  msrArticulationKind articulationKind)
    : msrElement (inputLineNumber)
{
  fArticulationKind = articulationKind;
}

msrArticulation::~msrArticulation() {}

string msrArticulation::articulationKindAsString () const
{
  string result;
  
  switch (fArticulationKind) {
    case msrArticulation::kAccent:
      result = "accent";
      break;
    case msrArticulation::kBreathMark:
      result = "breathMark";
      break;
    case msrArticulation::kCaesura:
      result = "caesura";
      break;
    case msrArticulation::kSpiccato:
      result = "spiccato";
      break;
    case msrArticulation::kStaccato:
      result = "staccato";
      break;
    case msrArticulation::kStaccatissimo:
      result = "staccatissimo";
      break;
    case msrArticulation::kStress:
      result = "stress";
      break;
    case msrArticulation::kUnstress:
      result = "unstress";
      break;
    case msrArticulation::kDetachedLegato:
      result = "detached legato";
      break;
    case msrArticulation::kStrongAccent:
      result = "strong accent";
      break;
    case msrArticulation::kTenuto:
      result = "tenuto";
      break;
    case msrArticulation::kFermata:
      result = "fermata";
      break;
    case msrArticulation::kArpeggiato:
      result = "arpeggiato";
      break;
    case msrArticulation::kDoit:
      result = "doit";
      break;
    case msrArticulation::kFalloff:
      result = "falloff";
      break;
    case msrArticulation::kPlop:
      result = "plop";
      break;
    case msrArticulation::kScoop:
      result = "scoop";
      break;
  } // switch

  return result;
}

void msrArticulation::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrArticulation::acceptIn()" << endl;
      
  if (visitor<S_msrArticulation>*
    p =
      dynamic_cast<visitor<S_msrArticulation>*> (v)) {
        S_msrArticulation elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrArticulation::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrArticulation::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrArticulation::acceptOut()" << endl;

  if (visitor<S_msrArticulation>*
    p =
      dynamic_cast<visitor<S_msrArticulation>*> (v)) {
        S_msrArticulation elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrArticulation::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrArticulation::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrArticulation& elt)
{
  elt->print (os);
  return os;
}

void msrArticulation::print (ostream& os)
{
  os <<
    "Articulation" " " <<
    articulationKindAsString () <<
    ", line " << fInputLineNumber <<
    endl;
}

//______________________________________________________________________________
S_msrOrnament msrOrnament::create (
  int             inputLineNumber,
  msrOrnamentKind ornamentKind)
{
  msrOrnament* o =
    new msrOrnament (
      inputLineNumber, ornamentKind);
  assert (o!=0);
  return o;
}

msrOrnament::msrOrnament (
  int             inputLineNumber,
  msrOrnamentKind ornamentKind)
    : msrElement (inputLineNumber)
{
  fOrnamentKind = ornamentKind;
}

msrOrnament::~msrOrnament() {}

string msrOrnament::ornamentKindAsString () const
{
  string result;
  
  switch (fOrnamentKind) {
    case msrOrnament::kTrillMark:
      result = "trill";
      break;
    case msrOrnament::kWavyLine:
      result = "wayvy line";
      break;
    case msrOrnament::kTurn:
      result = "turn";
      break;
    case msrOrnament::kInvertedTurn:
      result = "inverted turn";
      break;
    case msrOrnament::kDelayedTurn:
      result = "delayed turn";
      break;
    case msrOrnament::kDelayedInvertedTurn:
      result = "delayed inverted turn";
      break;
    case msrOrnament::kVerticalTurn:
      result = "vertical turn";
      break;
    case msrOrnament::kMordent:
      result = "mordent";
      break;
    case msrOrnament::kInvertedMordent:
      result = "inverted mordent";
      break;
    case msrOrnament::kSchleifer:
      result = "schleifer";
      break;
    case msrOrnament::kShake:
      result = "shake";
      break;
  } // switch

  return result;
}

string msrOrnament::ornamentPlacementKindAsString () const
{
  string result;
  
  switch (fOrnamentPlacementKind) {
    case msrOrnament::k_NoPlacementKind:
      result = "none";
      break;
    case msrOrnament::kAbove:
      result = "above";
      break;
    case msrOrnament::kBelow:
      result = "below";
      break;
  } // switch

  return result;
}

string msrOrnament::ornamentAccidentalMarkKindAsString () const
{
  string result;
  
  switch (fOrnamentAccidentalMarkKind) {
    case msrOrnament::kNatural:
      result = "natural";
      break;
    case msrOrnament::kSharp:
      result = "sharp";
      break;
    case msrOrnament::kFlat:
      result = "flat";
      break;
  } // switch

  return result;
}

void msrOrnament::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrOrnament::acceptIn()" << endl;
      
  if (visitor<S_msrOrnament>*
    p =
      dynamic_cast<visitor<S_msrOrnament>*> (v)) {
        S_msrOrnament elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrOrnament::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrOrnament::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrOrnament::acceptOut()" << endl;

  if (visitor<S_msrOrnament>*
    p =
      dynamic_cast<visitor<S_msrOrnament>*> (v)) {
        S_msrOrnament elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrOrnament::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrOrnament::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrOrnament& elt)
{
  elt->print (os);
  return os;
}

void msrOrnament::print (ostream& os)
{
  os <<
    "Ornament" " " <<
    ornamentKindAsString () <<
    ", line " << fInputLineNumber <<
    ", placement" << " = " << ornamentPlacementKindAsString () <<
    ", accidental mark" << " = " << ornamentAccidentalMarkKindAsString () <<
    ", note uplink" << " = " << fOrnamentNoteUplink->noteAsShortString () <<
    endl;
}

//______________________________________________________________________________
S_msrRehearsal msrRehearsal::create (
  int              inputLineNumber,
  msrRehearsalKind rehearsalKind,
  string           rehearsalText)
{
  msrRehearsal* o =
    new msrRehearsal (
      inputLineNumber, rehearsalKind, rehearsalText);
  assert (o!=0);
  return o;
}

msrRehearsal::msrRehearsal (
  int              inputLineNumber,
  msrRehearsalKind rehearsalKind,
  string           rehearsalText)
    : msrElement (inputLineNumber)
{
  fRehearsalKind = rehearsalKind;

  fRehearsalText = rehearsalText;
}

msrRehearsal::~msrRehearsal() {}

void msrRehearsal::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrRehearsal::acceptIn()" << endl;
      
  if (visitor<S_msrRehearsal>*
    p =
      dynamic_cast<visitor<S_msrRehearsal>*> (v)) {
        S_msrRehearsal elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrRehearsal::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrRehearsal::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrRehearsal::acceptOut()" << endl;

  if (visitor<S_msrRehearsal>*
    p =
      dynamic_cast<visitor<S_msrRehearsal>*> (v)) {
        S_msrRehearsal elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrRehearsal::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrRehearsal::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrRehearsal& elt)
{
  elt->print (os);
  return os;
}

string msrRehearsal::rehearsalKindAsString (
  msrRehearsalKind rehearsalKind)
{
  string result;
  
  switch (rehearsalKind) {
    case kNone:
      result = "none";
      break;
    case kRectangle:
      result = "rectangle";
      break;
    case kOval:
      result = "oval";
      break;
    case kCircle:
      result = "circle";
      break;
    case kBracket:
      result = "bracket";
      break;
    case kTriangle:
      result = "triangle";
      break;
    case kDiamond:
      result = "diamond";
      break;
  } // switch

  return result;
}

void msrRehearsal::print (ostream& os)
{
  os <<
    "Rehearsal" << " " << fRehearsalText <<
    " kind: " <<
    rehearsalKindAsString (fRehearsalKind) <<
    endl;
}

//______________________________________________________________________________
S_msrDynamics msrDynamics::create (
  int             inputLineNumber,
  msrDynamicsKind dynamicsKind)
{
  msrDynamics* o =
    new msrDynamics (
      inputLineNumber, dynamicsKind);
    assert(o!=0);
  return o;
}

msrDynamics::msrDynamics (
  int             inputLineNumber,
  msrDynamicsKind dynamicsKind)
    : msrElement (inputLineNumber)
{
  fDynamicsKind = dynamicsKind; 
}
msrDynamics::~msrDynamics() {}

string msrDynamics::dynamicsKindAsString ()
{
  stringstream s;
  
  switch (fDynamicsKind) {
    case kF:
      s << "f";
      break;
    case kFF:
      s << "ff"; break;
    case kFFF:
      s << "fff"; break;
    case kFFFF:
      s << "ffff"; break;
    case kFFFFF:
      s << "fffff"; break;
    case kFFFFFF:
      s << "ffffff"; break;

    case kP:
      s << "p"; break;
    case kPP:
      s << "pp"; break;
    case kPPP:
      s << "ppp"; break;
    case kPPPP:
      s << "pppp"; break;
    case kPPPPP:
      s << "ppppp"; break;
    case kPPPPPP:
      s << "pppppp"; break;

    case kMF:
      s << "mf"; break;
    case kMP:
      s << "mp"; break;
    case kFP:
      s << "fp"; break;
    case kFZ:
      s << "fz"; break;
    case kRF:
      s << "rf"; break;
    case kSF:
      s << "sf"; break;

    case kRFZ:
      s << "rfz"; break;
    case kSFZ:
      s << "sfz"; break;
    case kSFP:
      s << "sfp"; break;
    case kSFPP:
      s << "sfpp"; break;
    case kSFFZ:
      s << "sffz"; break;

    default:
      {
      stringstream s;
      
      s << "Dynamics " << fDynamicsKind << " is unknown";
      
      msrMusicXMLError (
        fInputLineNumber,
        s.str());
      }
  } // switch
  
  return s.str();
}

void msrDynamics::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrDynamics::acceptIn()" << endl;
      
  if (visitor<S_msrDynamics>*
    p =
      dynamic_cast<visitor<S_msrDynamics>*> (v)) {
        S_msrDynamics elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrDynamics::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrDynamics::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrDynamics::acceptOut()" << endl;

  if (visitor<S_msrDynamics>*
    p =
      dynamic_cast<visitor<S_msrDynamics>*> (v)) {
        S_msrDynamics elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrDynamics::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}


void msrDynamics::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrDynamics& elt)
{
  elt->print (os);
  return os;
}

void msrDynamics::print (ostream& os)
{
  os <<
    "Dynamics" " " << dynamicsKindAsString () <<
    ", line " << fInputLineNumber <<
    endl;
}

//______________________________________________________________________________
S_msrWedge msrWedge::create (
  int           inputLineNumber,
  msrWedgeKind  wedgeKind)
{
  msrWedge* o =
    new msrWedge (
      inputLineNumber, wedgeKind);
  assert(o!=0);
  return o;
}

msrWedge::msrWedge (
  int           inputLineNumber,
  msrWedgeKind  wedgeKind)
    : msrElement (inputLineNumber)
{
  fWedgeKind = wedgeKind; 
}
msrWedge::~msrWedge() {}

string msrWedge::wedgeKindAsString ()
{
  stringstream s;
  
  switch (fWedgeKind) {
    case msrWedge::kCrescendoWedge:
      s << "crescendo";
      break;
    case msrWedge::kDecrescendoWedge:
      s << "decrescendo";
      break;
    case msrWedge::kStopWedge:
      s << "stop";
      break;
  } // switch
    
  return s.str();
}

void msrWedge::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrWedge::acceptIn()" << endl;
      
  if (visitor<S_msrWedge>*
    p =
      dynamic_cast<visitor<S_msrWedge>*> (v)) {
        S_msrWedge elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrWedge::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrWedge::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrWedge::acceptOut()" << endl;

  if (visitor<S_msrWedge>*
    p =
      dynamic_cast<visitor<S_msrWedge>*> (v)) {
        S_msrWedge elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrWedge::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrWedge::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrWedge& elt)
{
  elt->print (os);
  return os;
}

void msrWedge::print (ostream& os)
{
  os <<
    "Wedge" << " " << wedgeKindAsString () <<
    endl;
}

//______________________________________________________________________________
S_msrTie msrTie::create (
  int           inputLineNumber,
  msrTieKind    tieKind)
{
  msrTie* o =
    new msrTie (
      inputLineNumber, tieKind);
  assert(o!=0);
  return o;
}

msrTie::msrTie (
  int           inputLineNumber,
  msrTieKind    tieKind)
    : msrElement (inputLineNumber)
{
  fTieKind = tieKind; 
}
msrTie::~msrTie() {}

string msrTie::tieKindAsString (msrTieKind tieKind)
{
  stringstream s;
  
  switch (tieKind) {
    case kStartTie:
      s << "start";
      break;
    case kContinueTie:
      s << "continue";
      break;
    case kStopTie:
      s << "stop";
      break;
    default:
      s << "Tie" << tieKind << "???";
  } // switch
    
  return s.str();
}

void msrTie::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrTie::acceptIn()" << endl;
      
  if (visitor<S_msrTie>*
    p =
      dynamic_cast<visitor<S_msrTie>*> (v)) {
        S_msrTie elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrTie::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrTie::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrTie::acceptOut()" << endl;

  if (visitor<S_msrTie>*
    p =
      dynamic_cast<visitor<S_msrTie>*> (v)) {
        S_msrTie elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrTie::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}


void msrTie::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrTie& elt)
{
  elt->print (os);
  return os;
}

void msrTie::print (ostream& os)
{
  os <<
    "Tie" << " " << tieKindAsString () <<
    endl;
}

//______________________________________________________________________________
S_msrSlur msrSlur::create (
  int           inputLineNumber,
  int           slurNumber,
  msrSlurKind   slurKind)
{
  msrSlur* o =
    new msrSlur (
      inputLineNumber, slurNumber, slurKind);
  assert(o!=0);
  return o;
}

msrSlur::msrSlur (
  int           inputLineNumber,
  int           slurNumber,
  msrSlurKind   slurKind)
    : msrElement (inputLineNumber)
{
  fSlurNumber = slurNumber;
  fSlurKind   = slurKind; 
}
msrSlur::~msrSlur() {}

string msrSlur::slurKindAsString (
  msrSlurKind slurKind)
{
  stringstream s;
  
  switch (slurKind) {
    case msrSlur::kStartSlur:
      s << "start";
      break;
    case msrSlur::kContinueSlur:
      s << "continue";
      break;
    case msrSlur::kStopSlur:
      s << "stop";
      break;
    default:
      s << "Slur" << slurKind << "???";
  } // switch
    
  return s.str();
  
}
      
string msrSlur::slurKindAsString ()
{
  return slurKindAsString (fSlurKind);
}

void msrSlur::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrSlur::acceptIn()" << endl;
      
  if (visitor<S_msrSlur>*
    p =
      dynamic_cast<visitor<S_msrSlur>*> (v)) {
        S_msrSlur elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrSlur::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrSlur::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrSlur::acceptOut()" << endl;

  if (visitor<S_msrSlur>*
    p =
      dynamic_cast<visitor<S_msrSlur>*> (v)) {
        S_msrSlur elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrSlur::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}


void msrSlur::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrSlur& elt)
{
  elt->print (os);
  return os;
}

void msrSlur::print (ostream& os)
{
  os <<
    "Slur" " " << slurKindAsString () <<
    ", line " << fInputLineNumber << " " <<
    endl;
}

//______________________________________________________________________________
S_msrGracenotes msrGracenotes::create (
  int        inputLineNumber,
  bool       slashed,
  S_msrVoice gracenotesVoiceUplink)
{
  msrGracenotes* o =
    new msrGracenotes (
      inputLineNumber,
      slashed, gracenotesVoiceUplink);
  assert(o!=0);
  return o;
}

msrGracenotes::msrGracenotes (
  int        inputLineNumber,
  bool       slashed,
  S_msrVoice gracenotesVoiceUplink)
    : msrElement (inputLineNumber)
{
  fGracenotesIsSlashed = slashed;

  fGracenotesVoiceUplink =
    gracenotesVoiceUplink;

/* JMI
  // create the segment that will receive the notes
  fGracenotesSegment =
    msrSegment::create (
      fInputLineNumber,
      gracenotesVoiceUplink->
        getVoiceDivisionsPerWholeNote (),
      gracenotesVoiceUplink);
      */
}

msrGracenotes::~msrGracenotes() {}

S_msrGracenotes msrGracenotes::createGracenotesBareClone (
  S_msrVoice voiceClone)
{
//  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> creating a bare clone of grace notes" <<
      gracenotesAsShortString () <<
      endl;
  
  S_msrGracenotes
    clone =
      msrGracenotes::create (
        fInputLineNumber,
        fGracenotesIsSlashed,
        voiceClone);

  clone->fGracenotesIsSlashed =
    fGracenotesIsSlashed;
    
  return clone;
}

S_msrGracenotes msrGracenotes::createSkipGracenotesClone (
  S_msrVoice voiceClone)
{
//  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> creating a skip clone of grace notes" <<
      gracenotesAsShortString () <<
      endl;
  
  S_msrGracenotes
    clone =
      msrGracenotes::create (
        fInputLineNumber,
        fGracenotesIsSlashed,
        voiceClone);

  clone->fGracenotesIsSlashed =
    fGracenotesIsSlashed;

  // populating the clone with skips
  for (
    list<S_msrNote>::const_iterator i=fGracenotesNotesList.begin();
    i!=fGracenotesNotesList.end();
    i++) {
    S_msrNote note = (*i);
    
    cerr << "FAA" << endl;

  // create skip with same length as note
    S_msrNote
      skip =
        msrNote::createSkipNote (
          note->getInputLineNumber (),
          note->getNoteDivisions (),
          note->getNoteDivisionsPerWholeNote (),
          voiceClone->getStaffRelativeVoiceNumber (), // JMI
          voiceClone->getExternalVoiceNumber ());

    cerr << "FOO" << endl;
      /*
   static SMARTP<msrNote> createSkipNote (
      int           inputLineNumber,
      int           divisions,
      int           divisionsPerWholeNote,
      int           staffNumber,
      int           externalVoiceNumber);
      */

    clone->
      appendNoteToGracenotes (skip);
  } // for
    
  return clone;
}

void msrGracenotes::appendNoteToGracenotes (S_msrNote note)
{
  /*
  fGracenotesSegment->
    appendNoteToSegment (note);
    */

  fGracenotesNotesList.push_back (note);

/*
  // JMI
  cerr <<
    endl <<
    idtr;
  this->print (cerr);
  cerr <<
    endl << endl;
    
  cerr <<
    endl <<
    idtr;
  fGracenotesVoiceUplink->print (cerr);
  cerr <<
    endl << endl;
    */
}

void msrGracenotes::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrGracenotes::acceptIn()" << endl;
      
  if (visitor<S_msrGracenotes>*
    p =
      dynamic_cast<visitor<S_msrGracenotes>*> (v)) {
        S_msrGracenotes elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrGracenotes::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrGracenotes::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrGracenotes::acceptOut()" << endl;

  if (visitor<S_msrGracenotes>*
    p =
      dynamic_cast<visitor<S_msrGracenotes>*> (v)) {
        S_msrGracenotes elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrGracenotes::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrGracenotes::browseData (basevisitor* v)
{
  list<S_msrNote>::const_iterator i;

  for (
    i=fGracenotesNotesList.begin();
    i!=fGracenotesNotesList.end();
    i++) {
    // browse the note
    msrBrowser<msrNote> browser (v);
    browser.browse (*(*i));
  } // for

  /* JMI
  // browse the segment
  msrBrowser<msrSegment> browser (v);
  browser.browse (*fGracenotesSegment);
  */
}

ostream& operator<< (ostream& os, const S_msrGracenotes& elt)
{
  elt->print (os);
  return os;
}

string msrGracenotes::gracenotesAsShortString ()
{
  stringstream s;

  s <<
    "Gracenotes" " ";

  list<S_msrNote>::const_iterator
    iBegin = fGracenotesNotesList.begin(),
    iEnd   = fGracenotesNotesList.end(),
    i      = iBegin;
  for ( ; ; ) {
    s << (*i)->noteAsShortString ();
    if (++i == iEnd) break;
    s << " ";
  } // for

  return s.str();
}

void msrGracenotes::print (ostream& os)
{
  os <<
    "Gracenotes" <<
    ", line " << fInputLineNumber <<
    ", " <<
    singularOrPlural (
      fGracenotesNotesList.size (), "note", "notes") <<
    ", slashed: " <<
    booleanAsString (fGracenotesIsSlashed) <<
    endl;
  
  idtr++;
  
 // JMI os << fGracenotesSegment;
          
  list<S_msrNote>::const_iterator
    iBegin = fGracenotesNotesList.begin(),
    iEnd   = fGracenotesNotesList.end(),
    i      = iBegin;
  for ( ; ; ) {
    os << idtr << (*i);
    if (++i == iEnd) break;
 // JMI   os << endl;
  } // for

  idtr--;
}

//______________________________________________________________________________
S_msrAftergracenotes msrAftergracenotes::create (
  int             inputLineNumber,
  bool            slashed,
  S_msrNote       aftergracenotesNote,
  S_msrVoice      aftergracenotesVoiceUplink)
{
  msrAftergracenotes* o =
    new msrAftergracenotes (
      inputLineNumber,
      slashed,
      aftergracenotesNote,
      aftergracenotesVoiceUplink);
  assert(o!=0);
  return o;
}

msrAftergracenotes::msrAftergracenotes (
  int             inputLineNumber,
  bool            slashed,
  S_msrNote       aftergracenotesNote,
  S_msrVoice      aftergracenotesVoiceUplink)
    : msrElement (inputLineNumber)
{
  fAftergracenotesIsSlashed = slashed;
  
  fAftergracenotesNote = aftergracenotesNote;

  fAftergracenotesVoiceUplink =
    aftergracenotesVoiceUplink;

  // create the segment that will receive the notes
  fAftergracenotesSegment =
    msrSegment::create (
      fInputLineNumber,
      aftergracenotesVoiceUplink->
        getVoiceDivisionsPerWholeNote (),
      aftergracenotesVoiceUplink);
}

msrAftergracenotes::~msrAftergracenotes() {}

S_msrAftergracenotes msrAftergracenotes::createAftergracenotesBareClone (
  S_msrVoice voiceClone)
{
//  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> creating a bare clone of grace notes" <<
      endl;
  
  S_msrAftergracenotes
    clone =
      msrAftergracenotes::create (
        fInputLineNumber,
        fAftergracenotesIsSlashed,
        fAftergracenotesNote,
        voiceClone);
  
  return clone;
}

void msrAftergracenotes::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrAftergracenotes::acceptIn()" << endl;
      
  if (visitor<S_msrAftergracenotes>*
    p =
      dynamic_cast<visitor<S_msrAftergracenotes>*> (v)) {
        S_msrAftergracenotes elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrAftergracenotes::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrAftergracenotes::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrAftergracenotes::acceptOut()" << endl;

  if (visitor<S_msrAftergracenotes>*
    p =
      dynamic_cast<visitor<S_msrAftergracenotes>*> (v)) {
        S_msrAftergracenotes elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrAftergracenotes::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrAftergracenotes::browseData (basevisitor* v)
{
  {
  // browse the note
  msrBrowser<msrNote> browser (v);
  browser.browse (*fAftergracenotesNote);
  }

  {
  // browse the segment
  msrBrowser<msrSegment> browser (v);
  browser.browse (*fAftergracenotesSegment);
  }
}

ostream& operator<< (ostream& os, const S_msrAftergracenotes& elt)
{
  elt->print (os);
  return os;
}

void msrAftergracenotes::print (ostream& os)
{
  os <<
    "Aftergracenotes" <<
    ", line " << fInputLineNumber <<
    ", slashed: " <<
    booleanAsString (fAftergracenotesIsSlashed) <<
    endl;
  
  idtr++;

  os << idtr <<
    fAftergracenotesNote <<
    endl;
  os << fAftergracenotesSegment;
      
  idtr--;
}

//______________________________________________________________________________
S_msrNote msrNote::createFromNoteData (
  int           inputLineNumber,
  msrNoteData&  noteData)
{  
  msrNote * o =
    new msrNote (
      inputLineNumber, noteData);
  assert(o!=0); 
  return o;
}

msrNote::msrNote (
  int           inputLineNumber,
  msrNoteData&  noteData)
  :
    msrElement (inputLineNumber),
    fNoteData (noteData)
{
//  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebugDebug) {
  if (gGeneralOptions->fDebugDebug) {
    cerr << idtr <<
      "==> fNoteData contains:" <<
      endl;

    idtr++;
    
    cerr <<
      fNoteData;

    idtr--;

    cerr <<
      idtr <<
        "<==" <<
        endl << endl;
  }

  fNoteKind = k_NoNoteKind;

  fNoteOccupiesAFullMeasure = false;

  fNoteMeasureNumber = -10011;
  fNotePositionInMeasure = -20022;
    
  fNoteHasATrill = false;

  fNoteHasADelayedOrnament = false;
  
  if (
    fNoteData.getNoteDiatonicPitch () < 'A'
      ||
    fNoteData.getNoteDiatonicPitch () > 'G') {
    if (! fNoteData.fNoteIsARest) {
      stringstream s;
      
      s <<
        "step value " << fNoteData.getNoteDiatonicPitch () <<
        " is not a letter from A to G";
        
    msrMusicXMLError (
 // JMI   msrMusicXMLWarning (
      fInputLineNumber,
      s.str());
    }
  }

//  cerr << "=== xmlPart2MsrVisitor::visitStart ( S_step& elt ) " << fCurrentStep << endl;
// JMI

/* JMI
  switch (fNoteData.getNoteDiatonicPitch ()) {
    case 'A': fNoteData.fNoteDiatonicPitch = kA; break;
    case 'B': fNoteData.fNoteDiatonicPitch = kB; break;
    case 'C': fNoteData.fNoteDiatonicPitch = kC; break;
    case 'D': fNoteData.fNoteDiatonicPitch = kD; break;
    case 'E': fNoteData.fNoteDiatonicPitch = kE; break;
    case 'F': fNoteData.fNoteDiatonicPitch = kF; break;
    case 'G': fNoteData.fNoteDiatonicPitch = kG; break;
    default: {}
  } // switch
*/

  // how many quater tones from A?s // JMI
  int noteQuatertonesFromA;
  
  switch (fNoteData.getNoteDiatonicPitch ()) {
    case 'A': noteQuatertonesFromA =  0; break;
    case 'B': noteQuatertonesFromA =  4; break;
    case 'C': noteQuatertonesFromA =  6; break;
    case 'D': noteQuatertonesFromA = 10; break;
    case 'E': noteQuatertonesFromA = 14; break;
    case 'F': noteQuatertonesFromA = 16; break;
    case 'G': noteQuatertonesFromA = 20; break;
    default: {}    
  } // switch

//   if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebugDebug) {
  if (gGeneralOptions->fDebugDebug) {
    cerr << idtr <<
      "--> fNoteData.getNoteAlteration () = " <<
      msrAlterationAsString (
        fNoteData.getNoteAlteration ()) <<
      endl;
  }

/* JMI
  if (gGeneralOptions->fDebugDebug)
    cerr <<
      "--> noteQuatertonesFromA = " << noteQuatertonesFromA <<
      endl;
*/
}

msrNote::~msrNote()
{}

S_msrNote msrNote::createNoteBareClone ()
{
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> Creating a bare clone of note " <<
      noteAsString () <<
      endl;

  S_msrNote
    clone =
      msrNote::createFromNoteData (
        fInputLineNumber,
        fNoteData);

  clone->fNoteKind =
    fNoteKind;
  
  clone->fNoteOctaveShift =
    fNoteOctaveShift;
  
  clone->fNoteStem =
    fNoteStem;

  clone->fNoteDivisionsPerWholeNote =
    fNoteDivisionsPerWholeNote;
  
  clone->fNoteSyllableExtendKind =
    fNoteSyllableExtendKind;

  clone->fNoteMeasureNumber =
    fNoteMeasureNumber;
  clone->fNotePositionInMeasure =
    fNotePositionInMeasure;
  clone-> fNoteOccupiesAFullMeasure =
    fNoteOccupiesAFullMeasure;

  clone->fNoteHasATrill =
    fNoteHasATrill;

  clone->fNoteHasADelayedOrnament =
    fNoteHasADelayedOrnament;

  return clone;
}

void msrNote::setNoteBelongsToAChord () {
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> note " << noteAsString () <<
      ", line " << fInputLineNumber <<
      ", is set to belong to a chord" << endl;

  fNoteData.fNoteBelongsToAChord = true;
  fNoteKind = msrNote::kChordMemberNote;
}

void msrNote::applyTupletMemberDisplayFactorToNote (
  int actualNotes, int normalNotes)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> applying tuplet display factor " <<
      actualNotes << "/" << normalNotes <<
      " to note " << noteAsShortString () <<
      ", line " << fInputLineNumber <<
      endl;

  fNoteData.fNoteDisplayDivisions =
    fNoteData.fNoteDisplayDivisions
      *
    actualNotes
      /
    normalNotes;
}

void msrNote::addBeamToNote (S_msrBeam beam)
{
  fNoteBeams.push_back (beam);
}

void msrNote::addArticulationToNote (S_msrArticulation art)
{
  fNoteArticulations.push_back (art);
}

void msrNote::addOrnamentToNote (S_msrOrnament ornament)
{
  // append the ornament to the note ornaments list
  fNoteOrnaments.push_back (ornament);

  switch (ornament->getOrnamentKind ()) {
    case msrOrnament::kTrillMark:
      fNoteHasATrill = true;
      break;

    case msrOrnament::kDelayedTurn:
    case msrOrnament::kDelayedInvertedTurn:
      fNoteHasADelayedOrnament = true;
      break;

    default:
      {}
  } // switch

  // set ornament's note uplink
  ornament->
    setOrnamentNoteUplink (this);
}

void msrNote::addDynamicsToNote (S_msrDynamics dynamics)
{
  fNoteDynamics.push_back (dynamics);
}

void msrNote::addWordsToNote (S_msrWords words)
{
  fNoteWords.push_back (words);
}

void msrNote::addSlurToNote (S_msrSlur slur)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "% --> adding slur " << slur << " to note " << noteAsString ()
       << endl;

  if (fNoteSlurs.size ()) {
    if (
      fNoteSlurs.back ()->getSlurKind () == msrSlur::kStartSlur
        &&
      slur->getSlurKind () == msrSlur::kStopSlur
        &&
      fNoteSlurs.back ()->getSlurNumber () == slur->getSlurNumber ()
      ) {
      // it may happen that a given note has a 'slur start'
      // and a 'slur stop' in sequence, ignore both

      stringstream s;
      
      s <<
        "a 'slur start' is immediately followed by a 'slur stop'" <<
        endl <<
        "with the same number, ignoring both of them at line " <<
        slur->getInputLineNumber ();
        
      msrMusicXMLWarning (
        slur->getInputLineNumber (),
        s.str());
        
      // rmeove 'slur start'
      fNoteSlurs.pop_back ();

      // don't register 'slur stop'
    }

    else
      fNoteSlurs.push_back (slur);
  }

  else
    fNoteSlurs.push_back (slur);
}

void msrNote::addWedgeToNote (S_msrWedge wedge)
{
  fNoteWedges.push_back (wedge);
}

S_msrDynamics msrNote::removeFirstDynamics () // JMI
{
  S_msrDynamics dyn = fNoteDynamics.front ();
  fNoteDynamics.pop_front ();
  return dyn;
}

S_msrWedge msrNote::removeFirstWedge () // JMI
{
  S_msrWedge wedge = fNoteWedges.front ();
  fNoteWedges.pop_front ();
  return wedge;
}

void msrNote::appendSyllableToNote (S_msrSyllable syllable)
{
// JMI  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> appending syllable " <<
      syllable->syllableAsString () <<
      " to note " << noteAsString () <<
      endl;

  fNoteSyllables.push_back (syllable);
}

S_msrNote msrNote::createSkipNote (
  int           inputLineNumber,
  int           divisions,
  int           divisionsPerWholeNote,
  int           staffNumber,
  int           externalVoiceNumber)
{
  msrNoteData noteData;

  noteData.setNoteQuartertonesPitch (k_NoPitch);
  noteData.fNoteIsARest = true; // JMI
  
  noteData.fNoteDivisions = divisions;
  noteData.fNoteDisplayDivisions = divisions;
    
  noteData.fNoteStaffNumber = staffNumber;
  noteData.fNoteVoiceNumber = externalVoiceNumber;

  msrNote * o =
    new msrNote (
      inputLineNumber, noteData);
  assert(o!=0);

  // set skip's note kind
  o->fNoteKind =
    kSkipNote;
  
  // set skip's divisions per whole note
  o->fNoteDivisionsPerWholeNote =
    divisionsPerWholeNote;
  
  return o;
}    

void msrNote::acceptIn (basevisitor* v)
{
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrNote::acceptIn()" << endl;
      
  if (visitor<S_msrNote>*
    p =
      dynamic_cast<visitor<S_msrNote>*> (v)) {
        S_msrNote elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrNote::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrNote::acceptOut (basevisitor* v)
{
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrNote::acceptOut()" << endl;

  if (visitor<S_msrNote>*
    p =
      dynamic_cast<visitor<S_msrNote>*> (v)) {
        S_msrNote elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrNote::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrNote::browseData (basevisitor* v)
{
  if (fNoteOctaveShift) {
    // browse the octave shift
    msrBrowser<msrOctaveShift> browser (v);
    browser.browse (*fNoteOctaveShift);
  }

  if (fNoteStem) {
    // browse the stem
    msrBrowser<msrStem> browser (v);
    browser.browse (*fNoteStem);
  }

  // browse the beams if any
  if (fNoteBeams.size()) {
    idtr++;
    list<S_msrBeam>::const_iterator i;
    for (i=fNoteBeams.begin(); i!=fNoteBeams.end(); i++) {
      // browse the beam
      msrBrowser<msrBeam> browser (v);
      browser.browse (*(*i));
    } // for
    idtr--;
  }
  
  // browse the articulations if any
  if (fNoteArticulations.size()) {
    idtr++;
    list<S_msrArticulation>::const_iterator i;
    for (i=fNoteArticulations.begin(); i!=fNoteArticulations.end(); i++) {
      // browse the articulation
      msrBrowser<msrArticulation> browser (v);
      browser.browse (*(*i));
    } // for
    idtr--;
  }
  
  // browse the ornaments if any
  if (fNoteOrnaments.size()) {
    idtr++;
    list<S_msrOrnament>::const_iterator i;
    for (i=fNoteOrnaments.begin(); i!=fNoteOrnaments.end(); i++) {
      // browse the ornament
      msrBrowser<msrOrnament> browser (v);
      browser.browse (*(*i));
    } // for
    idtr--;
  }
  
  if (fNoteTie) {
    // browse the tie
    msrBrowser<msrTie> browser (v);
    browser.browse (*fNoteTie);
  }

  // browse the dynamics if any
  if (fNoteDynamics.size()) {
    idtr++;
    list<S_msrDynamics>::const_iterator i;
    for (i=fNoteDynamics.begin(); i!=fNoteDynamics.end(); i++) {
      // browse the dynamics
      msrBrowser<msrDynamics> browser (v);
      browser.browse (*(*i));
    } // for
    idtr--;
  }

  // browse the words if any
  if (fNoteWords.size()) {
    idtr++;
    list<S_msrWords>::const_iterator i;
    for (i=fNoteWords.begin(); i!=fNoteWords.end(); i++) {
      // browse the words
      msrBrowser<msrWords> browser (v);
      browser.browse (*(*i));
    } // for
    idtr--;
  }
  
  // browse the slur if any
  if (fNoteSlurs.size()) {
    idtr++;
    list<S_msrSlur>::const_iterator i;
    for (i=fNoteSlurs.begin(); i!=fNoteSlurs.end(); i++) {
      // browse the slur
      msrBrowser<msrSlur> browser (v);
      browser.browse (*(*i));
    } // for
    idtr--;
  }

  // browse the wedges if any
  if (fNoteWedges.size()) {
    idtr++;
    list<S_msrWedge>::const_iterator i;
    for (i=fNoteWedges.begin(); i!=fNoteWedges.end(); i++) {
      // browse the wedge
      msrBrowser<msrWedge> browser (v);
      browser.browse (*(*i));
    } // for
    idtr--;
  }

  // browse the syllables if any
  if (fNoteSyllables.size()) {
    idtr++;
    list<S_msrSyllable>::const_iterator i;
    for (i=fNoteSyllables.begin(); i!=fNoteSyllables.end(); i++) {
      // browse the wedge
      msrBrowser<msrSyllable> browser (v);
      browser.browse (*(*i));
    } // for
    idtr--;
  }

  if (fNoteHarmony) {
    // browse the harmony
    msrBrowser<msrHarmony> browser (v);
    browser.browse (*fNoteHarmony);
  }
}

string msrNote::notePitchAsString () const
{
  stringstream s;
  
  /*
  cerr << "msrNote::notePitchAsString (), isRest = " <<
    fNoteData.fNoteIsARest <<
    ", fQuartertonesPitch = " << fQuartertonesPitch << endl;
  */
  
  if (fNoteData.fNoteIsARest)

    s << "r"; // JMI R ???

  else if (fNoteData.fNoteIsUnpitched)

    s << "unpitched ";

  else {

    s <<
      msrDiatonicPitchAsString (
        fNoteData.getNoteDiatonicPitch ()) <<    
      msrAlterationAsString (
        fNoteData.getNoteAlteration ());
  }
  
  return s.str();
}

string msrNote::noteDivisionsAsMSRString () const
{
  string result;
  int    computedNumberOfDots;
  string errorMessage;

  result =
    divisionsAsMSRDuration (
      fNoteData.fNoteDisplayDivisions,
      fNoteDivisionsPerWholeNote,
      fNoteData.fNoteDotsNumber,
      computedNumberOfDots,
      errorMessage,
      false); // 'true' to debug it

  if (errorMessage.size ())
    msrMusicXMLError (
      fInputLineNumber,
      errorMessage);

  return result;
}

string msrNote::noteTypeAsMSRString () const
{
  string result;
  string errorMessage;

  result =
    noteTypeAsMSRDuration (
      fNoteData.fNoteType,
      errorMessage);

  if (errorMessage.size ())
    msrMusicXMLError (
      fInputLineNumber,
      errorMessage);

  return result;
}

string msrNote::noteDiatonicPitchAsString () const
{
  return
    msrDiatonicPitchAsString (
      fNoteData.getNoteDiatonicPitch ());
      /* JMI
  // fNoteData.fNoteStep is a char
  switch () {
    case kA: return "A"; break;
    case kB: return "B"; break;
    case kC: return "C"; break;
    case kD: return "D"; break;
    case kE: return "E"; break;
    case kF: return "F"; break;
    case kG: return "G"; break;
    default: return "?";
  } // switch
  */
}

string msrNote::noteAsShortStringWithRawDivisions () const
{
  stringstream s;

  switch (fNoteKind) {
    case msrNote::k_NoNoteKind:
      s <<
        "???";
      break;
      
    case msrNote::kStandaloneNote:
      s <<
        notePitchAsString () <<
        "[" << fNoteData.fNoteOctave << "]" <<
        ":" <<
        fNoteData.fNoteDivisions;
        
      if (fNoteData.fNoteDivisions != fNoteData.fNoteDisplayDivisions)
        s <<
          "_" << fNoteData.fNoteDisplayDivisions;
          
      s << " divs";
      break;
      
    case msrNote::kGraceNote:
      s <<
        notePitchAsString () <<
        "[" << fNoteData.fNoteOctave << "]" <<
        ":" <<
        noteTypeAsMSRString ();
        
      for (int i = 0; i < fNoteData.fNoteDotsNumber; i++) {
        s << ".";
      } // for
      break;
      
    case msrNote::kRestNote:
      s <<
        "R" <<
        ":" <<
        fNoteData.fNoteDivisions << " divs";
      break;
      
    case msrNote::kSkipNote:
      s <<
        "S" <<
        ":" <<
        fNoteData.fNoteDivisions;
        
      if (fNoteData.fNoteDivisions != fNoteData.fNoteDisplayDivisions)
        s <<
          "_" << fNoteData.fNoteDisplayDivisions;
          
      s << " divs";
      break;
      
    case msrNote::kChordMemberNote:
      s <<
        notePitchAsString () <<
        "[" << fNoteData.fNoteOctave << "]" <<
        ":" <<
        fNoteData.fNoteDivisions;
        
      if (fNoteData.fNoteDivisions != fNoteData.fNoteDisplayDivisions)
        s <<
          "_" << fNoteData.fNoteDisplayDivisions;
          
      s << " divs";
      break;
      
    case msrNote::kTupletMemberNote:
      s <<
        notePitchAsString ();

      if (! fNoteData.fNoteIsARest)
        s <<
          "[" << fNoteData.fNoteOctave << "]";

      s <<
        ":" <<
        fNoteData.fNoteDivisions;
        
      if (fNoteData.fNoteDivisions != fNoteData.fNoteDisplayDivisions)
        s <<
          "_" << fNoteData.fNoteDisplayDivisions;
            
        s << " divs";
      break;
  } // switch

  return s.str();
}

string msrNote::noteAsShortString () const
{
  stringstream s;

  switch (fNoteKind) {
    case msrNote::k_NoNoteKind:
      s <<
        "???";
      break;
      
    case msrNote::kStandaloneNote:
      s <<
        notePitchAsString () <<
        "[" << fNoteData.fNoteOctave << "]" <<
        ":" <<
        noteDivisionsAsMSRString ();
      break;
      
    case msrNote::kGraceNote:
      s <<
        notePitchAsString () <<
        "[" << fNoteData.fNoteOctave << "]" <<
        ":" <<
        noteTypeAsMSRString ();
        
      for (int i = 0; i < fNoteData.fNoteDotsNumber; i++) {
        s << ".";
      } // for
      break;
      
    case msrNote::kRestNote:
      s <<
        "R" <<
        ":" <<
        noteDivisionsAsMSRString ();
      break;
      
    case msrNote::kSkipNote:
      s <<
        "S" <<
        ":" <<
        noteDivisionsAsMSRString ();
      break;
      
    case msrNote::kChordMemberNote:
      s <<
        notePitchAsString () <<
        "[" << fNoteData.fNoteOctave << "]" <<
        ":" <<
        noteDivisionsAsMSRString ();
      break;
      
    case msrNote::kTupletMemberNote:
      s <<
        notePitchAsString ();

      if (! fNoteData.fNoteIsARest)
        s <<
          "[" << fNoteData.fNoteOctave << "]";

      s <<
        ":" <<
        noteDivisionsAsMSRString ();
      break;
  } // switch

  return s.str();
}

string msrNote::noteAsString () const
{
  stringstream s;

  s <<
    "[=== ";
    
  switch (fNoteKind) {
    case msrNote::k_NoNoteKind:
      s <<
        "k_NoNoteKind ???";
      break;
      
    case msrNote::kStandaloneNote:
      s <<
        "Standalone note" " "<<
        notePitchAsString () <<
        "[" << fNoteData.fNoteOctave << "]" <<
        ":" <<
        noteDivisionsAsMSRString ();
      break;
      
    case msrNote::kGraceNote:
      s <<
        "Grace note" " "<<
        notePitchAsString () <<
        "[" << fNoteData.fNoteOctave << "]" <<
        ":" <<
        noteTypeAsMSRString ();
        
      for (int i = 0; i < fNoteData.fNoteDotsNumber; i++) {
        s << ".";
      } // for
      break;
      
    case msrNote::kRestNote:
      s <<
        "Rest" <<
        ":" <<
        noteDivisionsAsMSRString ();
      break;
      
    case msrNote::kSkipNote:
      s <<
        "Skip" <<
        ":" <<
        noteDivisionsAsMSRString ();
      break;
      
    case msrNote::kChordMemberNote:
      s <<
        "Chord member note" " "<<
        notePitchAsString () <<
        "[" << fNoteData.fNoteOctave << "]" <<
        ":" <<
        noteDivisionsAsMSRString ();
      break;
      
    case msrNote::kTupletMemberNote:
      s <<
        "Tuplet member note"  " "<<
        notePitchAsString ();

      if (! fNoteData.fNoteIsARest)
        s <<
          "[" << fNoteData.fNoteOctave << "]";

      s <<
        ":";

      if (fNoteData.fNoteType.size ())
        s <<
          noteTypeAsMSRString ();
      else
        s <<
          noteDivisionsAsMSRString ();

      break;
  } // switch

/* JMI
  if (fNoteTie) {
    if (fNoteTie->getTieKind () != msrTie::k_NoTie ) {
      s <<
        ", " << fNoteTie->tieKindAsString ();
    }
  }
*/

  s <<
    " ===]";
  
  return s.str();
}

ostream& operator<< (ostream& os, const S_msrNote& elt)
{
  elt->print (os);
  return os;
}

void msrNote::print (ostream& os)
{
  // print the note itself and its position
  os <<
    noteAsString ();

  if (fNoteData.fNoteType.size ())
    os <<
      " (" << fNoteData.fNoteType << ")" <<
      ", line " << fInputLineNumber;

  // print display divisions
  os <<
    ", " <<
    "(divs: ";
    
  if (fNoteKind == kGraceNote) {
    os <<
      fNoteData.fNoteDisplayDivisions;
  }
  
  else {
    if (
        fNoteData.fNoteDivisions
          ==
        fNoteData.fNoteDisplayDivisions) {
      os <<
        fNoteData.fNoteDivisions;
    }
    else {
      os <<
        fNoteData.fNoteDivisions <<
        "_" <<
        fNoteData.fNoteDisplayDivisions;
    }
  }

  os <<
    "/" <<
    fNoteDivisionsPerWholeNote <<
    ")";

  // print measure related information
  os <<
    " meas ";
    
  if (fNoteMeasureNumber < 0)
    os << "?";
  else
    os << fNoteMeasureNumber;

  os <<
    ":";
    
  if (fNotePositionInMeasure < 0)
    os << "?";
  else
    os << fNotePositionInMeasure;
    
  os <<
    "/" <<
    fNoteDivisionsPerWholeNote;

  // print simplified position in measure if relevant
  rational
    notePosition (
      fNotePositionInMeasure,
      fNoteDivisionsPerWholeNote);

  notePosition.rationalise ();
  
  if (notePosition.getNumerator () != fNotePositionInMeasure)
    // print simplified rational view
    os <<
      " (" <<
      notePosition.getNumerator () <<
      "/" <<
      notePosition.getDenominator() <<
      ")";

  os <<
      endl;
    
  // are there syllables associated to this note?
  if (fNoteSyllables.size ()) {
    idtr++;

    os <<
      idtr <<
      "Syllables:" <<
      endl;
      
    idtr++;
    
    list<S_msrSyllable>::const_iterator
      iBegin = fNoteSyllables.begin(),
      iEnd   = fNoteSyllables.end(),
      i      = iBegin;
    for ( ; ; ) {
      os <<
        idtr <<
        " \"" << (*i)->getSyllableText () << "\"" <<
        ", line " << (*i)->getInputLineNumber ();
      if (++i == iEnd) break;
      os << endl;
    } // for

    idtr--;
    
    os <<
      endl;

    idtr--;
  }

/*
  // print the note's voice uplink JMI
  idtr++;
  os <<
    idtr <<
    "NoteVoiceDirectUplink" " = " <<
    fNoteMeasureUplink->getMeasureVoiceDirectUplink () <<
    endl;
  idtr--;
*/

  // print the extend kind if relevant
  switch (fNoteSyllableExtendKind) {
    
    case msrSyllable::kStandaloneSyllableExtend:
    case msrSyllable::kStartSyllableExtend:
    case msrSyllable::kContinueSyllableExtend:
    case msrSyllable::kStopSyllableExtend:
      idtr++;
      os <<
        idtr <<
        "NoteSyllableExtendKind" " = " <<
        msrSyllable::syllableExtendKindAsString (
          fNoteSyllableExtendKind) <<
        endl;
      idtr--;
      break;
      
    case msrSyllable::k_NoSyllableExtend:
      break;
  } // switch

/*
   switch (elt->getNoteKind ()) { // JMI
    case msrNote::k_NoNoteKind:
      break;
    case msrNote::kStandaloneNote:
      break;
    case msrNote::kGraceNote:
      break;
    case msrNote::kRestNote:
      break;
    case msrNote::kSkipNote:
      break;
    case msrNote::kChordMemberNote:
      break;
    case msrNote::kTupletMemberNote:
      break;
  } // switch
 */

  // print the octave shift if any
  if (fNoteOctaveShift) {
    idtr++;
    os <<
      idtr << fNoteOctaveShift;
    idtr--;
  }

  // print the stem if any
  if (fNoteStem) {
    idtr++;
    os <<
      idtr << fNoteStem;
    idtr--;
  }
    
  // print the beams if any
  if (fNoteBeams.size()) {
    idtr++;

    list<S_msrBeam>::const_iterator
      iBegin = fNoteBeams.begin(),
      iEnd   = fNoteBeams.end(),
      i      = iBegin;
    for ( ; ; ) {
      os << idtr << (*i);
      if (++i == iEnd) break;
      os << endl;
    } // for
        
    idtr--;
  }
  
  // print the articulations if any
  if (fNoteArticulations.size()) {
    idtr++;

    list<S_msrArticulation>::const_iterator
      iBegin = fNoteArticulations.begin(),
      iEnd   = fNoteArticulations.end(),
      i      = iBegin;
    for ( ; ; ) {
      os << idtr << (*i);
      if (++i == iEnd) break;
      os << endl;
    } // for
        
    idtr--;
  }
  
  // print the ornaments if any
  if (fNoteOrnaments.size()) {
    idtr++;

    list<S_msrOrnament>::const_iterator
      iBegin = fNoteOrnaments.begin(),
      iEnd   = fNoteOrnaments.end(),
      i      = iBegin;
    for ( ; ; ) {
      os << idtr << (*i);
      if (++i == iEnd) break;
      os << endl;
    } // for
        
    idtr--;
  }
  
  // print the tie if any
  if (fNoteTie) {
    idtr++;
    os <<
      idtr << fNoteTie;
    idtr--;
  }
    
  // print the dynamics if any
  if (fNoteDynamics.size()) {
    idtr++;
    
    list<S_msrDynamics>::const_iterator
      iBegin = fNoteDynamics.begin(),
      iEnd   = fNoteDynamics.end(),
      i      = iBegin;
    for ( ; ; ) {
      os << idtr << (*i);
      if (++i == iEnd) break;
      os << endl;
    } // for

    idtr--;
  }

  // print the words if any
  if (fNoteWords.size()) {
    idtr++;
    
    list<S_msrWords>::const_iterator
      iBegin = fNoteWords.begin(),
      iEnd   = fNoteWords.end(),
      i      = iBegin;
    for ( ; ; ) {
      os << idtr << (*i);
      if (++i == iEnd) break;
      os << endl;
    } // for

    idtr--;
  }

  // print the slurs if any
  if (fNoteSlurs.size()) {
    idtr++;
    
    list<S_msrSlur>::const_iterator
      iBegin = fNoteSlurs.begin(),
      iEnd   = fNoteSlurs.end(),
      i      = iBegin;
    for ( ; ; ) {
      os << idtr << (*i);
      if (++i == iEnd) break;
  // JMI    os << endl;
    } // for
    
    idtr--;
  }
  
  // print the wedges if any
  if (fNoteWedges.size()) {
    idtr++;
    
    list<S_msrWedge>::const_iterator
      iBegin = fNoteWedges.begin(),
      iEnd   = fNoteWedges.end(),
      i      = iBegin;
    for ( ; ; ) {
      os << idtr << (*i);
      if (++i == iEnd) break;
  // JMI    os << endl;
    } // for
    
    idtr--;
  }

  // print the harmony if any
  if (fNoteHarmony) {
    idtr++;
    os <<
      idtr <<
        fNoteHarmony <<
        endl;
    idtr--;
  }
}

//______________________________________________________________________________
S_msrChord msrChord::create (
  int    inputLineNumber,
  int    chordDivisions,
  string chordNotesType)
{
  msrChord* o =
    new msrChord (
      inputLineNumber, chordDivisions, chordNotesType);
  assert(o!=0);
  return o;
}

msrChord::msrChord (
  int    inputLineNumber,
  int    chordDivisions,
  string chordNotesType)
    : msrElement (inputLineNumber)
{
  fChordDivisions = chordDivisions;

  fChordNotesType = chordNotesType;
}

msrChord::~msrChord() {}

S_msrChord msrChord::createChordBareClone ()
{
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> Creating a bare clone of chord" <<
      endl;

  S_msrChord
    clone =
      msrChord::create (
        fInputLineNumber,
        fChordDivisions,
        fChordNotesType);

  clone->
    fChordDivisionsPerWholeNote =
      fChordDivisionsPerWholeNote;

  clone->
    fChordPositionInMeasure =
      fChordPositionInMeasure;
    
  clone->fChordTie =
    fChordTie; // JMI

  return clone;
}
    
string msrChord::chordNotesTypeAsMSRString () const
{
  string result;
  string errorMessage;

  result =
    noteTypeAsMSRDuration (
      fChordNotesType,
      errorMessage);

  if (errorMessage.size ())
    msrMusicXMLError (
      fInputLineNumber,
      errorMessage);

  return result;
}

void msrChord::addFirstNoteToChord (S_msrNote note)
{
//  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> adding first note '" <<
      note->noteAsString () <<
      "' to chord '" <<
      chordAsString () <<
      "'" <<
      endl;

  fChordNotes.push_back (note);
  
  note->setNoteBelongsToAChord ();
  
  // populate note's measure number
  note->setNoteMeasureNumber (
    fChordMeasureNumber);

  // populate note's position in measure // JMI
  note->setNotePositionInMeasure (
    fChordPositionInMeasure);
}

void msrChord::addAnotherNoteToChord (S_msrNote note)
{
//  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> adding another note '" <<
      note->noteAsString () <<
      "' to chord '" <<
      chordAsString () <<
      "'" <<
      endl;

  fChordNotes.push_back (note);
  
  note->setNoteBelongsToAChord ();
  
  // populate note's measure number
  note->setNoteMeasureNumber (
    fChordMeasureNumber);

  // populate note's position in measure
  note->setNotePositionInMeasure (
    fChordPositionInMeasure);
}

void msrChord::setChordFirstNotePositionInMeasure (
  int position)
{
  if (fChordNotes.size ()) {
    fChordNotes.front ()->
      setNotePositionInMeasure (position);
  }
  else {
    // JMI XXL
   // abort ();
 }
}
                    
void msrChord::setChordFirstNoteMeasureNumber (
  int measureNumber)
{
  if (fChordNotes.size ()) {
    fChordNotes.front ()->
      setNoteMeasureNumber (measureNumber);
  }
  else {
    // JMI XXL
   // abort ();
 }
}
                    
void msrChord::addArticulationToChord (S_msrArticulation art)
{
  msrArticulation::msrArticulationKind
    articulationKind =
      art->
        getArticulationKind ();

  // don't add the same articulation several times
  for (
    list<S_msrArticulation>::const_iterator i = fChordArticulations.begin();
    i!=fChordArticulations.end();
    i++) {
      if ((*i)->getArticulationKind () == articulationKind)
        return;
  } // for

//  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> adding articulation '" <<
      art->articulationKindAsString () <<
      "' to chord" <<
      endl;

  fChordArticulations.push_back (art);
}

void msrChord::addOrnamentToChord (S_msrOrnament orn)
{
  msrOrnament::msrOrnamentKind
    ornamentKind =
      orn->
        getOrnamentKind ();

  // don't add the same ornament several times
  for (
    list<S_msrOrnament>::const_iterator i = fChordOrnaments.begin();
    i!=fChordOrnaments.end();
    i++) {
      if ((*i)->getOrnamentKind () == ornamentKind)
        return;
  } // for

//  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> adding ornament '" <<
      orn->ornamentKindAsString () <<
      "' to chord" <<
      endl;

  fChordOrnaments.push_back (orn);
}

void msrChord::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrChord::acceptIn()" << endl;
      
  if (visitor<S_msrChord>*
    p =
      dynamic_cast<visitor<S_msrChord>*> (v)) {
        S_msrChord elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrChord::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrChord::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrChord::acceptOut()" << endl;

  if (visitor<S_msrChord>*
    p =
      dynamic_cast<visitor<S_msrChord>*> (v)) {
        S_msrChord elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrChord::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrChord::browseData (basevisitor* v)
{
  for (
    vector<S_msrNote>::const_iterator i = fChordNotes.begin();
    i != fChordNotes.end();
    i++ ) {
    // browse chord member note
    msrBrowser<msrNote> browser (v);
    browser.browse (*(*i));
  } // for

  for (
    list<S_msrArticulation>::const_iterator i = fChordArticulations.begin();
    i != fChordArticulations.end();
    i++ ) {
    // browse the articulation
    msrBrowser<msrArticulation> browser (v);
    browser.browse (*(*i));
  } // for

  for (
    list<S_msrOrnament>::const_iterator i = fChordOrnaments.begin();
    i != fChordOrnaments.end();
    i++ ) {
    // browse the ornament
    msrBrowser<msrOrnament> browser (v);
    browser.browse (*(*i));
  } // for

  for (
    list<S_msrDynamics>::const_iterator i = fChordDynamics.begin();
    i != fChordDynamics.end();
    i++ ) {
    // browse the dynamics
    msrBrowser<msrDynamics> browser (v);
    browser.browse (*(*i));
  } // for

  for (
    list<S_msrWords>::const_iterator i = fChordWords.begin();
    i != fChordWords.end();
    i++ ) {
    // browse the words
    msrBrowser<msrWords> browser (v);
    browser.browse (*(*i));
  } // for

  for (
    list<S_msrSlur>::const_iterator i = fChordSlurs.begin();
    i != fChordSlurs.end();
    i++ ) {
    // browse the slur
    msrBrowser<msrSlur> browser (v);
    browser.browse (*(*i));
  } // for
  
  for (
    list<S_msrWedge>::const_iterator i = fChordWedges.begin();
    i != fChordWedges.end();
    i++ ) {
    // browse the wedge
    msrBrowser<msrWedge> browser (v);
    browser.browse (*(*i));
  } // for

  if (fChordHarmony) {
    // browse the harmony
    msrBrowser<msrHarmony> browser (v);
    browser.browse (*fChordHarmony);
  }
}

ostream& operator<< (ostream& os, const S_msrChord& elt)
{
  elt->print (os);
  return os;
}

string msrChord::chordDivisionsAsMSRString () const
{
  string result;
  int    computedNumberOfDots;
  string errorMessage;

  int inputSourceSuppliedNumberOfDots =
    fChordNotes [1]-> 
      getNoteDotsNumber (); // any chord member note is fine
    
  result =
    divisionsAsMSRDuration (
      fChordDivisions,
      fChordDivisionsPerWholeNote,
      inputSourceSuppliedNumberOfDots,
      computedNumberOfDots,
      errorMessage,
      false); // 'true' to debug it

  if (errorMessage.size ())
    msrMusicXMLError (
      fInputLineNumber,
      errorMessage);

  return result;
}

void msrChord::applyTupletMemberDisplayFactorToChordMembers (
  int actualNotes, int normalNotes)
{
  for (
    vector<S_msrNote>::const_iterator i = fChordNotes.begin();
    i != fChordNotes.end();
    ++i) {
    (*i)->
      applyTupletMemberDisplayFactorToNote (
        actualNotes, normalNotes);
  } // for
}

string msrChord::chordAsString () const
{
  stringstream s;

  s << "<";

  if (fChordNotes.size ()) {
    vector<S_msrNote>::const_iterator
      iBegin = fChordNotes.begin(),
      iEnd   = fChordNotes.end(),
      i      = iBegin;
    for ( ; ; ) {
      S_msrNote
        note = (*i);
        
      s <<
        note->notePitchAsString () <<
        "[" << note->getNoteOctave () << "]" <<
        ":" <<
        note->noteDivisionsAsMSRString ();

      if (++i == iEnd) break;
      s << " ";
    } // for
  }

  s << ">";
  
  return s.str();
}

void msrChord::print (ostream& os)
{
  os <<
    "Chord" <<
    ", " <<
    singularOrPlural (
      fChordNotes.size (), "note", "notes") <<
    ", divs: " <<
    chordDivisionsAsMSRString () <<
    "/" <<
    fChordDivisionsPerWholeNote <<
    ", mea. "<<
    getChordMeasureNumber () <<
    ":" <<
    fChordPositionInMeasure <<
    "/" <<
    fChordDivisionsPerWholeNote;

  // print simplified position in measure if relevant
  rational
    chordPosition (
      fChordPositionInMeasure,
      fChordDivisionsPerWholeNote);

  chordPosition.rationalise ();
  
  if (chordPosition.getNumerator () != fChordPositionInMeasure)
    // print simplified rational view
    os <<
      " (" <<
      chordPosition.getNumerator () <<
      "/" <<
      chordPosition.getDenominator() <<
      ")";

  os <<
    endl;
    
  idtr++;
  
  // print the member notes if any
  if (fChordNotes.size()) {
    vector<S_msrNote>::const_iterator i;
    for (i=fChordNotes.begin(); i!=fChordNotes.end(); i++) {
      os << idtr << (*i);
    } // for

/* JMI   vector<S_msrNote>::const_iterator
      iBegin = fChordNotes.begin(),
      iEnd   = fChordNotes.end(),
      i      = iBegin;
    for ( ; ; ) {
   //   os << (*i)->notePitchAsString (); JMI
      os << idtr << (*i);
      if (++i == iEnd) break;
 //     os << endl;
    } // for
    */
  }
  
  // print the articulations if any
  if (fChordArticulations.size()) {
    list<S_msrArticulation>::const_iterator i;
    for (i=fChordArticulations.begin(); i!=fChordArticulations.end(); i++) {
      os << idtr << (*i);
    } // for
  }

  // print the ornaments if any
  if (fChordOrnaments.size()) {
    list<S_msrOrnament>::const_iterator i;
    for (i=fChordOrnaments.begin(); i!=fChordOrnaments.end(); i++) {
      os << idtr << (*i);
    } // for
  }

  // print the dynamics if any
  if (fChordDynamics.size()) {
    list<S_msrDynamics>::const_iterator i;
    for (i=fChordDynamics.begin(); i!=fChordDynamics.end(); i++) {
      os << idtr << (*i);
    } // for
  }

  // print the words if any
  if (fChordWords.size()) {
    list<S_msrWords>::const_iterator i;
    for (i=fChordWords.begin(); i!=fChordWords.end(); i++) {
      os << idtr << (*i);
    } // for
  }

  // print the slurs if any
  if (fChordSlurs.size()) {
    list<S_msrSlur>::const_iterator i;
    for (i=fChordSlurs.begin(); i!=fChordSlurs.end(); i++) {
      os << idtr << (*i);
    } // for
  }

  // print the wedges if any
  if (fChordWedges.size()) {
    list<S_msrWedge>::const_iterator i;
    for (i=fChordWedges.begin(); i!=fChordWedges.end(); i++) {
      os << idtr << (*i);
    } // for
  }

  // print the harmony if any
  if (fChordHarmony) {
    os << idtr <<
      "Chord harmony: " <<
      endl;
        
    idtr++;

    os << idtr <<
      fChordHarmony->harmonyAsString () <<
      endl;
      
    idtr--;
  }

  idtr--;
}

//______________________________________________________________________________
S_msrComment msrComment::create (
  int               inputLineNumber,
  string            contents,
  msrCommentGapKind commentGapKind)
{
  msrComment* o =
    new msrComment (
      inputLineNumber, contents, commentGapKind);
  assert(o!=0);
  return o;
}

msrComment::msrComment (
  int               inputLineNumber,
  string            contents,
  msrCommentGapKind commentGapKind)
    : msrElement (inputLineNumber)
{
  fContents       = contents;
  fCommentGapKind = commentGapKind;
}
msrComment::~msrComment() {}

void msrComment::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrComment::acceptIn()" << endl;
      
  if (visitor<S_msrComment>*
    p =
      dynamic_cast<visitor<S_msrComment>*> (v)) {
        S_msrComment elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrComment::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrComment::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrComment::acceptOut()" << endl;

  if (visitor<S_msrComment>*
    p =
      dynamic_cast<visitor<S_msrComment>*> (v)) {
        S_msrComment elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrComment::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrComment::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrComment& elt)
{
  elt->print (os);
  return os;
}

void msrComment::print (ostream& os)
{
  os << "Comment" << endl;
  
  idtr++;
  
  os << idtr <<
    "% " << fContents <<
    endl;
    
  if (fCommentGapKind == kGapAfterwards)
    os <<
      endl;
      
  idtr--;
}

//______________________________________________________________________________
S_msrBreak msrBreak::create (
  int           inputLineNumber,
  int           nextBarNumber)
{
  msrBreak* o =
    new msrBreak (
      inputLineNumber, nextBarNumber);
  assert(o!=0);
  return o;
}

msrBreak::msrBreak (
  int           inputLineNumber,
  int           nextBarNumber)
    : msrElement (inputLineNumber)
{
  fNextBarNumber = nextBarNumber; 

  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Creating a break before measure " << fNextBarNumber <<
      endl;
}

msrBreak::~msrBreak() {}

string msrBreak::breakAsString () const
{
  stringstream s;

  s <<
    "Break" << ", next bar number = " << fNextBarNumber;

  return s.str();
}

void msrBreak::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrBreak::acceptIn()" << endl;
      
  if (visitor<S_msrBreak>*
    p =
      dynamic_cast<visitor<S_msrBreak>*> (v)) {
        S_msrBreak elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrBreak::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrBreak::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrBreak::acceptOut()" << endl;

  if (visitor<S_msrBreak>*
    p =
      dynamic_cast<visitor<S_msrBreak>*> (v)) {
        S_msrBreak elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrBreak::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrBreak::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrBreak& elt)
{
  elt->print (os);
  return os;
}

void msrBreak::print (ostream& os)
{
  os <<
    breakAsString () <<
    endl << endl;
}

//______________________________________________________________________________
S_msrBarCheck msrBarCheck::create (
  int           inputLineNumber,
  int           nextBarNumber)
{
  msrBarCheck* o =
    new msrBarCheck (
      inputLineNumber, nextBarNumber);
  assert(o!=0);
  return o;
}

msrBarCheck::msrBarCheck (
  int           inputLineNumber,
  int           nextBarNumber)
    : msrElement (inputLineNumber)
{
  fNextBarNumber = nextBarNumber; 

  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Creating a bar check before measure " << fNextBarNumber <<
      endl;
}
msrBarCheck::~msrBarCheck() {}

string msrBarCheck::barCheckAsString () const
{
  stringstream s;

  s <<
    "BarCheck" << ", next bar number = " << fNextBarNumber;

  return s.str();
}

void msrBarCheck::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrBarCheck::acceptIn()" << endl;
      
  if (visitor<S_msrBarCheck>*
    p =
      dynamic_cast<visitor<S_msrBarCheck>*> (v)) {
        S_msrBarCheck elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrBarCheck::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrBarCheck::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrBarCheck::acceptOut()" << endl;

  if (visitor<S_msrBarCheck>*
    p =
      dynamic_cast<visitor<S_msrBarCheck>*> (v)) {
        S_msrBarCheck elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrBarCheck::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrBarCheck::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrBarCheck& elt)
{
  elt->print (os);
  return os;
}

void msrBarCheck::print (ostream& os)
{
  os <<
    barCheckAsString () <<
    endl;
}

//______________________________________________________________________________
S_msrBarnumberCheck msrBarnumberCheck::create (
  int           inputLineNumber,
  int           nextBarNumber)
{
  msrBarnumberCheck* o =
    new msrBarnumberCheck (
      inputLineNumber, nextBarNumber);
  assert(o!=0);
  return o;
}

msrBarnumberCheck::msrBarnumberCheck (
  int           inputLineNumber,
  int           nextBarNumber)
    : msrElement (inputLineNumber)
{
  fNextBarNumber=nextBarNumber; 
}
msrBarnumberCheck::~msrBarnumberCheck() {}

string msrBarnumberCheck::barnumberCheckAsString () const
{
  stringstream s;

  s <<
    "BarnumberCheck" << ", next bar number = " << fNextBarNumber;

  return s.str();
}

void msrBarnumberCheck::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrBarnumberCheck::acceptIn()" << endl;
      
  if (visitor<S_msrBarnumberCheck>*
    p =
      dynamic_cast<visitor<S_msrBarnumberCheck>*> (v)) {
        S_msrBarnumberCheck elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrBarnumberCheck::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrBarnumberCheck::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrBarnumberCheck::acceptOut()" << endl;

  if (visitor<S_msrBarnumberCheck>*
    p =
      dynamic_cast<visitor<S_msrBarnumberCheck>*> (v)) {
        S_msrBarnumberCheck elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrBarnumberCheck::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrBarnumberCheck::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrBarnumberCheck& elt)
{
  elt->print (os);
  return os;
}

void msrBarnumberCheck::print (ostream& os)
{
  os <<
    barnumberCheckAsString () <<
    endl;
}

//______________________________________________________________________________
/*
S_msrTupletMember msrTupletMember::create (
  int                 inputLineNumber,
  msrTupletMemberKind tupletMemberKind,
  S_msrElement        tupletMember)
{
  msrTupletMember* o =
    new msrTupletMember (
      inputLineNumber,
      tupletMemberKind, tupletMember);
  assert(o!=0);
  return o;
}

msrTupletMember::msrTupletMember (
  int                 inputLineNumber,
  msrTupletMemberKind tupletMemberKind,
  S_msrElement        tupletMember)
  : msrElement (inputLineNumber)
{  
  fTupletMemberKind = tupletMemberKind;
  
  fTupletMember = tupletMember;
}

msrTupletMember::~msrTupletMember() {}

S_msrTupletMember msrTupletMember::createTupletBareClone ()
{
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> Creating a bare clone of a tuplet member" <<
      endl;

  S_msrTupletMember
    clone =
      msrTupletMember::create (
        fInputLineNumber,
        fTupletMemberKind,
        fTupletMember);
  
  return clone;
}

void msrTupletMember::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrTupletMember::acceptIn()" << endl;
      
  if (visitor<S_msrTupletMember>*
    p =
      dynamic_cast<visitor<S_msrTupletMember>*> (v)) {
        S_msrTupletMember elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrTupletMember::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrTupletMember::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrTupletMember::acceptOut()" << endl;

  if (visitor<S_msrTupletMember>*
    p =
      dynamic_cast<visitor<S_msrTupletMember>*> (v)) {
        S_msrTupletMember elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrTupletMember::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrTupletMember::browseData (basevisitor* v)
{
  // browse tuplet member
  msrBrowser<msrElement> browser (v);
  browser.browse (*fTupletMember);
}

ostream& operator<< (ostream& os, const S_msrTupletMember& elt)
{
  elt->print (os);
  return os;
}

/ * JMI
string msrTupletMember::tupletMemberKindAsString (
  msrTupletMemberKind tupletMemberKind) const
{
  string result;
  
  switch (tupletMemberKind) {
    case msrTupletMember::kNoteTupletMember:
      result =
        "NoteTupletMember";
      break;

    case msrTupletMember::kChordTupletMember:
      result =
        "ChordTupletMember";
      break;

    case msrTupletMember::kTupletTupletMember:
      result =
        "TupletTupletMember";
      break;
  } // switch

  return result;
}
* /

string msrTupletMember::tupletMemberAsString () const
{
  stringstream s;

  s <<
    "TupletMember" " ";
  // JMI  tupletMemberKindAsString (fTupletMemberKind) <<
  //  ", ";

/ *

  switch (fTupletMemberKind) {
    case msrTupletMember::kNoteTupletMember:
      {
        S_msrNote note = fTupletMember;
        
        s <<
          "NoteTupletMember" << " " <<
          note->noteAsShortString ();
      }
      break;

    case msrTupletMember::kChordTupletMember:
      {
        S_msrChord chord = fTupletMember;
        
        s <<
          "ChordTupletMember" << " " <<
          chord->chordAsString ();
      }
      break;

    case msrTupletMember::kTupletTupletMember:
      {
        S_msrTuplet tuplet = fTupletMember;
        
        s <<
          "TupletTupletMember" << " " <<
          tuplet->tupletAsString ();
      }
      break;
  } // switch
* /

  return s.str();
}

void msrTupletMember::print (ostream& os)
{
  os <<
    "TupletMember" " ";
/ *
  switch (fTupletMemberKind) {
    case msrTupletMember::kNoteTupletMember:
      {
        S_msrNote note = fTupletMember;
        
        s <<
          "NoteTupletMember" << " " <<
          note->noteAsShortString ();
      }
      break;

    case msrTupletMember::kChordTupletMember:
      {
        S_msrChord chord = fTupletMember;
        
        s <<
          "ChordTupletMember" << " " <<
          chord->chordAsString ();
      }
      break;

    case msrTupletMember::kTupletTupletMember:
      {
        S_msrTuplet tuplet = fTupletMember;
        
        s <<
          "TupletTupletMember" << " " <<
          tuplet->tupletAsString ();
      }
      break;
  } // switch
 * /
    
// JMI    tupletMemberKindAsString (fTupletMemberKind) <<

  os <<
    ", " <<
    fTupletMember <<
    endl;
}
*/

//______________________________________________________________________________
S_msrTuplet msrTuplet::create (
  int           inputLineNumber,
  int           number,
  int           actualNotes,
  int           normalNotes,
  int           notePositionInMeasure)
{
  msrTuplet* o =
    new msrTuplet (
      inputLineNumber,
      number, actualNotes, normalNotes, notePositionInMeasure);
  assert(o!=0);
  return o;
}

msrTuplet::msrTuplet (
  int           inputLineNumber,
  int           number,
  int           actualNotes,
  int           normalNotes,
  int           notePositionInMeasure)
    : msrElement (inputLineNumber)
{  
  fTupletNumber = number;
  
  fTupletActualNotes = actualNotes;
  fTupletNormalNotes = normalNotes;
  
  fTupletDivisions        = 0;
  fTupletDisplayDivisions = 0;

  fTupletPositionInMeasure = notePositionInMeasure;
}

msrTuplet::~msrTuplet() {}

S_msrTuplet msrTuplet::createTupletBareClone ()
{
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> Creating a bare clone of a tuplet" <<
      endl;

  S_msrTuplet
    clone =
      msrTuplet::create (
        fInputLineNumber,
        fTupletNumber,
        fTupletActualNotes,
        fTupletNormalNotes,
        fTupletPositionInMeasure);

  clone->fTupletDivisions =
    fTupletDivisions;

  clone->fTupletDisplayDivisions =
    fTupletDisplayDivisions;

  clone->fTupletDivisionsPerWholeNote =
    fTupletDivisionsPerWholeNote;

  clone->fTupletMeasureNumber =
    fTupletMeasureNumber;

    
  return clone;
}

void msrTuplet::addNoteToTuplet (S_msrNote note)
{
//  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> adding note '" <<
      note->noteAsShortStringWithRawDivisions () <<
        // the information is missing to display it the normal way
      "' to tuplet '" <<
      tupletAsShortString () <<
      "'" <<
      endl;

  fTupletElements.push_back (note);

  // account for note duration
  fTupletDivisions +=
    note->getNoteDivisions ();
  fTupletDisplayDivisions += // JMI
    note->getNoteDisplayDivisions ();  
    
  // populate note's measure number
  note->setNoteMeasureNumber (
    fTupletMeasureNumber);

  // populate note's position in measure
  note->setNotePositionInMeasure (
    fTupletPositionInMeasure);
}

void msrTuplet::addChordToTuplet (S_msrChord chord)
{
//  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> adding chord '" <<
      chord->chordAsString () <<
      "' to tuplet '" <<
      tupletAsString () <<
      "'" <<
      endl;

  fTupletElements.push_back (chord);
    
  // account for chord duration
  fTupletDivisions +=
    chord->getChordDivisions ();
    /*
  fTupletDisplayDivisions += // JMI
    chord->getChordDisplayDivisions ();  
    */
    
  // populate chord's measure number
  chord->setChordMeasureNumber (
    fTupletMeasureNumber);

  // populate chord's position in measure
  chord->setChordPositionInMeasure (
    fTupletPositionInMeasure);
}

void msrTuplet::addTupletToTuplet (S_msrTuplet tuplet)
{
//  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> adding tuplet '" <<
      tuplet->tupletAsString () <<
      "' to tuplet '" <<
      tupletAsString () <<
      "'" <<
      endl;

/* JMI
  // unapply containing tuplet factor,
  // i.e 3/2 inside 5/4 becomes 15/8 in MusicXML...
  tuplet->
    unapplyDisplayFactorToTupletMembers (
      this->fTupletActualNotes,
      this->fTupletNormalNotes);
  */
  
  // register tuplet in elements list
  fTupletElements.push_back (tuplet);
    
  // account for tuplet duration
  fTupletDivisions +=
    tuplet->getTupletDivisions ();
    
    /*
  fTupletDisplayDivisions += // JMI
    tuplet->getTupletDisplayDivisions ();  
    */

  // don't populate tuplet's measure number nor position in measure,
  // this will be done in setTupletMeasureNumber()
  /* JMI
  tuplet->setTupletMeasureNumber (
    fTupletMeasureNumber);

  // populate tuplet's position in measure
  tuplet->setTupletPositionInMeasure (
    fTupletPositionInMeasure);
    */
}

void msrTuplet::addTupletToTupletClone (S_msrTuplet tuplet)
{
//  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> adding tuplet '" <<
      tuplet->tupletAsString () <<
      "' to tuplet '" <<
      tupletAsString () <<
      "'" <<
      endl;

  // dont' unapply containing tuplet factor,
  // this has been done when building the MSR from MusicXML
  
  // register tuplet in elements list
  fTupletElements.push_back (tuplet);
    
  // account for tuplet duration
  fTupletDivisions +=
    tuplet->getTupletDivisions ();
}

void msrTuplet::removeFirstNoteFromTuplet (
  int       inputLineNumber,
  S_msrNote note)
{
//  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> removing first note " <<
      note->noteAsString () <<
      " from tuplet '" <<
      tupletAsString () <<
      "'" <<
      endl;

  if (fTupletElements.size ()) {
    S_msrElement
      firstTupletElement =
        fTupletElements.front ();

    for (
      list<S_msrElement>::iterator i=fTupletElements.begin();
      i!=fTupletElements.end();
      ++i) {
      if ((*i) == note) {
        // found note, erase it
        fTupletElements.erase (i);
        
        // don't update measure number nor position in measure: // JMI
        // they have not been set yet
  
        // return from function
        return;
      }
    } // for
    
    msrInternalError (
      inputLineNumber,
      "cannot remove note " <<
      note <<
      " from tuplet " << tupletAsString () <<
      "' in voice \"" <<
      fTupletMeasureUplink->
        getMeasureSegmentUplink ()->
          getSegmentVoiceUplink ()->
            getVoiceName () <<
      "\"," <<
      " since it has not been found");
  }
  
  else {
    msrInternalError (
      inputLineNumber,
      "cannot remove note " <<
      note <<
      " from empty tuplet " <<
      "' in voice \"" <<
      fTupletMeasureUplink->
        getMeasureSegmentUplink ()->
          getSegmentVoiceUplink ()->
            getVoiceName () <<
      "\"," <<
      " since it has not been found");
  }
}

void msrTuplet::setTupletMeasureNumber (int measureNumber) // JMI
{
  fTupletMeasureNumber = measureNumber;

  // propagate measure number to the tuplets elements
  for (
    list<S_msrElement>::const_iterator i = fTupletElements.begin();
    i != fTupletElements.end();
    i++ ) {
    // set tuplet element measure number

  //  SMARTP<msrNote>* note = dynamic_cast<SMARTP<msrNote>*>(&(*tupletMember));

  // BON   SMARTP<msrNote> note = dynamic_cast<msrNote*>(&(*tupletMember));

    if (
      S_msrNote note = dynamic_cast<msrNote*>(&(**i))
      ) {    
      note->setNoteMeasureNumber (measureNumber);
    }
  
    else if (
      S_msrChord chord = dynamic_cast<msrChord*>(&(**i))
      ) {
      chord->setChordMeasureNumber (measureNumber);
    }
    
    else if (
      S_msrTuplet tuplet = dynamic_cast<msrTuplet*>(&(**i))
      ) {
      tuplet->setTupletMeasureNumber (measureNumber);
    }
    
    else {
      msrInternalError (
        fInputLineNumber,
        "tuplet member should be a note, a chord or another tuplet");
    }
  } // for
}

int msrTuplet::setTupletPositionInMeasure (int position)
  // returns the position after the tuplet
{
  fTupletPositionInMeasure = position;

  int currentPosition = position;
  
  // compute position in measure for the tuplets elements
  for (
    list<S_msrElement>::const_iterator i = fTupletElements.begin();
    i != fTupletElements.end();
    i++ ) {
    // set tuplet element position in measure
    
    if (
      S_msrNote note = dynamic_cast<msrNote*>(&(**i))
      ) {    
      note->
        setNotePositionInMeasure (currentPosition);
        
      currentPosition +=
        note->getNoteDivisions ();
    }
  
    else if (
      S_msrChord chord = dynamic_cast<msrChord*>(&(**i))
      ) {
      chord->
        setChordPositionInMeasure (currentPosition);
        
      currentPosition +=
        chord->getChordDivisions ();
    }
    
    else if (
      S_msrTuplet tuplet = dynamic_cast<msrTuplet*>(&(**i))
      ) {
      currentPosition =
        tuplet->
          setTupletPositionInMeasure (currentPosition);
    }
    
    else {
      msrInternalError (
        fInputLineNumber,
        "tuplet member should be a note, a chord or another tuplet");
    }

  } // for

  return currentPosition;
}

void msrTuplet::applyDisplayFactorToTupletMembers ()
{
  for (
    list<S_msrElement>::const_iterator i = fTupletElements.begin();
    i != fTupletElements.end();
    i++ ) {
    // apply display factor to tuplet element
    
    if (
      S_msrNote note = dynamic_cast<msrNote*>(&(**i))
      ) {    
      note->
        applyTupletMemberDisplayFactorToNote (
          fTupletActualNotes, fTupletNormalNotes);
     }
  
    else if (
      S_msrChord chord = dynamic_cast<msrChord*>(&(**i))
      ) {
      chord->
        applyTupletMemberDisplayFactorToChordMembers (
          fTupletActualNotes, fTupletNormalNotes);
    }
    
    else if (
      S_msrTuplet tuplet = dynamic_cast<msrTuplet*>(&(**i))
      ) {
      // don't apply the display factor to nested tuplets
 // JMI     tuplet->
       // applyDisplayFactorToTupletMembers ();
    }
    
    else {
      msrInternalError (
        fInputLineNumber,
        "tuplet member should be a note, a chord or another tuplet");
    }

  } // for
}

void msrTuplet::unapplyDisplayFactorToTupletMembers (
  int containingTupletActualNotes,
  int containingTupletNormalNotes)
{
  if (gGeneralOptions->fDebugDebug) {
    cerr <<
      idtr <<
        "% ==> unapplyDisplayFactorToTupletMembers()" <<
        endl;

    idtr++;
    
    cerr <<
      idtr <<
        "% fTupletActualNotes = " <<
        fTupletActualNotes <<
        ", fTupletNormalNotes = " <<
        fTupletNormalNotes <<
        endl <<
      idtr <<
        "% containingTupletActualNotes = " <<
        containingTupletActualNotes <<
        ", containingTupletNormalNotes = " <<
        containingTupletNormalNotes <<
        endl <<
      endl;

    idtr--;
  }

  fTupletActualNotes /=
    containingTupletActualNotes;
  fTupletNormalNotes /=
    containingTupletNormalNotes;
}

void msrTuplet::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrTuplet::acceptIn()" << endl;
      
  if (visitor<S_msrTuplet>*
    p =
      dynamic_cast<visitor<S_msrTuplet>*> (v)) {
        S_msrTuplet elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrTuplet::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrTuplet::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrTuplet::acceptOut()" << endl;

  if (visitor<S_msrTuplet>*
    p =
      dynamic_cast<visitor<S_msrTuplet>*> (v)) {
        S_msrTuplet elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrTuplet::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrTuplet::browseData (basevisitor* v)
{
  for (
    list<S_msrElement>::const_iterator i = fTupletElements.begin();
    i != fTupletElements.end();
    i++ ) {
    // browse tuplet element
    msrBrowser<msrElement> browser (v);
    browser.browse (*(*i));
  } // for
}

ostream& operator<< (ostream& os, const S_msrTuplet& elt)
{
  elt->print (os);
  return os;
}

string msrTuplet::tupletAsShortString () const
{
  stringstream s;

  s <<
    "Tuplet " <<
    fTupletActualNotes << "/" << fTupletNormalNotes <<
    " (" << fTupletDivisions <<
    "/" <<
    fTupletDivisionsPerWholeNote <<
    ") @"<<
    fTupletMeasureNumber <<
    ":";

  if (fTupletPositionInMeasure < 0)
    s << "?";
  else
    s << fTupletPositionInMeasure;
  
  s <<
    "/" <<
    fTupletDivisionsPerWholeNote <<
    " ";

  s << "[[";

  if (fTupletElements.size ()) {
    list<S_msrElement>::const_iterator
      iBegin = fTupletElements.begin(),
      iEnd   = fTupletElements.end(),
      i      = iBegin;
    for ( ; ; ) {
      
      if (
        S_msrNote note = dynamic_cast<msrNote*>(&(**i))
        ) {    
        s <<
          note->noteAsShortStringWithRawDivisions ();
      }
    
      else if (
        S_msrChord chord = dynamic_cast<msrChord*>(&(**i))
        ) {
        s <<
          chord->chordAsString ();
      }
      
      else if (
        S_msrTuplet tuplet = dynamic_cast<msrTuplet*>(&(**i))
        ) {
        s <<
          tuplet->tupletAsString ();
      }
      
      else {
        msrInternalError (
          fInputLineNumber,
          "tuplet member should be a note, a chord or another tuplet");
      }
  
      if (++i == iEnd) break;
      s << " ";
      
    } // for
  }

  s << "]]";
  
  return s.str();
}

string msrTuplet::tupletAsString () const
{
  stringstream s;

  s <<
    "Tuplet " <<
    fTupletActualNotes << "/" << fTupletNormalNotes <<
    " (" << fTupletDivisions <<
    "/" <<
    fTupletDivisionsPerWholeNote <<
    ") @"<<
    fTupletMeasureNumber <<
    ":";

  if (fTupletPositionInMeasure < 0)
    s << "?";
  else
    s << fTupletPositionInMeasure;
  
  s <<
    "/" <<
    fTupletDivisionsPerWholeNote <<
    " ";

  s << "[[";

  if (fTupletElements.size ()) {
    list<S_msrElement>::const_iterator
      iBegin = fTupletElements.begin(),
      iEnd   = fTupletElements.end(),
      i      = iBegin;
    for ( ; ; ) {

      s << idtr;
      
      if (
        S_msrNote note = dynamic_cast<msrNote*>(&(**i))
        ) {    
        s <<
          note->noteAsShortString ();
      }
    
      else if (
        S_msrChord chord = dynamic_cast<msrChord*>(&(**i))
        ) {
        s <<
          chord->chordAsString ();
      }
      
      else if (
        S_msrTuplet tuplet = dynamic_cast<msrTuplet*>(&(**i))
        ) {
        s <<
          tuplet->tupletAsString ();
      }
      
      else {
        msrInternalError (
          fInputLineNumber,
          "tuplet member should be a note, a chord or another tuplet");
      }
  
      if (++i == iEnd) break;
      s << " ";
    } // for
  }

  s << "]]";
  
  return s.str();
}

void msrTuplet::print (ostream& os)
{
  os <<
    "Tuplet " <<
    fTupletActualNotes << "/" << fTupletNormalNotes <<
    ", " <<
    singularOrPlural (
      fTupletElements.size (), "element", "elements") <<
    " (" << fTupletDivisions <<
    "/" <<
    fTupletDivisionsPerWholeNote <<
    ") @"<<
    fTupletMeasureNumber <<
    ":";
    
  if (fTupletPositionInMeasure < 0)
    os << "?";
  else
    os << fTupletPositionInMeasure;

  os <<
    "/" <<
    fTupletDivisionsPerWholeNote <<
    endl;
    
  if (fTupletElements.size ()) {
    idtr++;

    list<S_msrElement>::const_iterator
      iBegin = fTupletElements.begin(),
      iEnd   = fTupletElements.end(),
      i      = iBegin;
    for ( ; ; ) {
      os << idtr << (*i);
      if (++i == iEnd) break;
      os << endl;
    } // for
    
    idtr--;
    
    os <<
      endl;
  }
}

//______________________________________________________________________________
S_msrPageGeometry msrPageGeometry::create (
  int           inputLineNumber)
{
  msrPageGeometry* o =
    new msrPageGeometry (
      inputLineNumber);
  assert(o!=0);
  return o;
}

msrPageGeometry::msrPageGeometry (
  int           inputLineNumber)
    : msrElement (inputLineNumber)
{
  fPaperWidth   = -1.0;
  fPaperHeight  = -1.0;
  fTopMargin    = -1.0;
  fBottomMargin = -1.0;
  fLeftMargin   = -1.0;
  fRightMargin  = -1.0;
    
  fBetweenSystemSpace = -1.0;
  fPageTopSpace       = -1.0;

  fMillimeters = -1;
  fTenths      = -1;
}

msrPageGeometry::~msrPageGeometry() {}

float msrPageGeometry::globalStaffSize () const
{
  if (fMillimeters > 0)
    return fMillimeters * 72.27 / 25.4;
  else
    return 20.0; // LilyPond default
}

void msrPageGeometry::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrPageGeometry::acceptIn()" << endl;
      
  if (visitor<S_msrPageGeometry>*
    p =
      dynamic_cast<visitor<S_msrPageGeometry>*> (v)) {
        S_msrPageGeometry elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrPageGeometry::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrPageGeometry::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrPageGeometry::acceptOut()" << endl;

  if (visitor<S_msrPageGeometry>*
    p =
      dynamic_cast<visitor<S_msrPageGeometry>*> (v)) {
        S_msrPageGeometry elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrPageGeometry::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrPageGeometry::browseData (basevisitor* v)
{
  /* JMI
  if (fPaperWidth) {
    // browse identification
    msrBrowser<fPaperWidth> browser (v);
    browser.browse (*fPaperWidth);
  }

  if (fPaperHeight) {
    // browse identification
    msrBrowser<fPaperWidth> browser (v);
    browser.browse (*fPaperHeight);
  }

  if (fTopMargin) {
    // browse identification
    msrBrowser<fPaperWidth> browser (v);
    browser.browse (*fTopMargin);
  }

  if (fBottomMargin) {
    // browse identification
    msrBrowser<fPaperWidth> browser (v);
    browser.browse (*fPaperWidth);
  }

  if (fLeftMargin) {
    // browse identification
    msrBrowser<fPaperWidth> browser (v);
    browser.browse (*fPaperWidth);
  }

  if (fRightMargin) {
    // browse identification
    msrBrowser<fPaperWidth> browser (v);
    browser.browse (*fRightMargin);
  }
  */
}

ostream& operator<< (ostream& os, const S_msrPageGeometry& elt) {
  elt->print (os);
  return os;
}

void msrPageGeometry::print (ostream& os) {
  os << "PageGeometry" << endl;

  bool emptyGeometry = true;
  
  idtr++;
  
  if (fPaperWidth > 0) {
    os <<
      idtr << setw(12) << left << "PaperWidth" << " = " <<
      setprecision(4) << fPaperWidth << " cm" << endl;
    emptyGeometry = false;
  }
  if (fPaperHeight > 0) {
    os <<
      idtr << setw(12) << left << "PaperHeight" << " = " <<
      setprecision(4) << fPaperHeight << " cm" << endl;
    emptyGeometry = false;
  }
  
  if (fTopMargin > 0) {
    os <<
      idtr << setw(12) << left << "TopMargin" << " = " <<
      setprecision(4) << fTopMargin << " cm" << endl;
    emptyGeometry = false;
  }
  if (fBottomMargin > 0) {
    os <<
      idtr << setw(12) << left << "BottomMargin" << " = " <<
      setprecision(4) << fBottomMargin << " cm" << endl;
    emptyGeometry = false;
  }
  if (fLeftMargin > 0) {
    os <<
      idtr << setw(12) << left << "LeftMargin" << " = " <<
      setprecision(4) << fLeftMargin << " cm" << endl;
    emptyGeometry = false;
  }
  if (fRightMargin > 0) {
    os <<
      idtr << setw(12) << left << "RightMargin" << " = " <<
      setprecision(4) << fRightMargin << " cm" << endl;
    emptyGeometry = false;
  }

  if (fMillimeters > 0) {
    os <<
      idtr << setw(12) << left << "Millimeters" << " = " <<
      setprecision(4) << fMillimeters << endl;
    emptyGeometry = false;
  }

  if (fTenths > 0) {
    os <<
      idtr << setw(12) << left << "Tenths" << " = " <<
      setprecision(4) << fTenths << endl;
    emptyGeometry = false;
  }

  if (emptyGeometry)
    os << idtr <<
      " " << "nothing specified" << endl;
  
  os << endl;

  idtr--;
}

/*
  if (fBetweenSystemSpace > 0) {
    os << idtr <<
      "between-system-space = " <<
      setprecision(4) << fBetweenSystemSpace << "\\cm" << endl;
  }

  if (fPageTopSpace > 0) {
    os << idtr <<
      "page-top-space = " <<
      setprecision(4) << fPageTopSpace << "\\cm" << endl;
  }
*/


//______________________________________________________________________________

S_msrVarValAssoc msrVarValAssoc::create (
  int           inputLineNumber,
  string        variableName,
  string        value)
{
  msrVarValAssoc* o =
    new msrVarValAssoc(
      inputLineNumber,
      variableName, value);
  assert(o!=0);
  return o;
}

msrVarValAssoc::msrVarValAssoc (
  int           inputLineNumber,
  string        variableName,
  string        value)
    : msrElement (inputLineNumber)
{
  fVariableName    = variableName;
  fVariableValue   = value;
}

msrVarValAssoc::~msrVarValAssoc() {}

void msrVarValAssoc::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrVarValAssoc::acceptIn()" << endl;
      
  if (visitor<S_msrVarValAssoc>*
    p =
      dynamic_cast<visitor<S_msrVarValAssoc>*> (v)) {
        S_msrVarValAssoc elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrVarValAssoc::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrVarValAssoc::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrVarValAssoc::acceptOut()" << endl;

  if (visitor<S_msrVarValAssoc>*
    p =
      dynamic_cast<visitor<S_msrVarValAssoc>*> (v)) {
        S_msrVarValAssoc elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrVarValAssoc::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}


void msrVarValAssoc::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrVarValAssoc& elt) {
  elt->print (os);
  return os;
}

void msrVarValAssoc::print (ostream& os)
{
  os << "MSR VarValAssoc" << endl;
  
  idtr++;

  // escape quotes if any
  string variableName;

  for_each (
    fVariableName.begin(),
    fVariableName.end(),
    stringQuoteEscaper (variableName));
    
  string variableValue;

  for_each (
    fVariableValue.begin(),
    fVariableValue.end(),
    stringQuoteEscaper (variableValue));

  // print resulting strings
  os <<
    idtr << "variable name : " <<
    "\"" << variableName << "\"" << endl <<
    idtr << "variable value: " <<
    "\"" << variableValue << "\"" << endl <<
    endl;
  
  idtr--;
}

//______________________________________________________________________________
S_msrLayout msrLayout::create (
  int           inputLineNumber)
{
  msrLayout* o =
    new msrLayout (
      inputLineNumber);
  assert(o!=0);
  return o;
}

msrLayout::msrLayout (
  int           inputLineNumber)
    : msrElement (inputLineNumber)
{}
msrLayout::~msrLayout() {}

void msrLayout::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrLayout::acceptIn()" << endl;
      
  if (visitor<S_msrLayout>*
    p =
      dynamic_cast<visitor<S_msrLayout>*> (v)) {
        S_msrLayout elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrLayout::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrLayout::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrLayout::acceptOut()" << endl;

  if (visitor<S_msrLayout>*
    p =
      dynamic_cast<visitor<S_msrLayout>*> (v)) {
        S_msrLayout elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrLayout::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrLayout::browseData (basevisitor* v)
{
  int n1 = fVarValAssocs.size();
  
  for (int i = 0; i < n1; i++ ) {
    // browse the stanza
    msrBrowser<msrVarValAssoc> browser (v);
    browser.browse (*fVarValAssocs [i]);
  } // for
}

ostream& operator<< (ostream& os, const S_msrLayout& elt)
{
  elt->print (os);
  return os;
}

void msrLayout::print (ostream& os)
{
  os << "Layout" << endl;

  idtr++;

  int n1 = fVarValAssocs.size();
  
  for (int i = 0; i < n1; i++ ) {
    os << idtr << fVarValAssocs [i];
  } // for

    /* JMI
  int n2 = fMsrSchemeVarValAssocs.size();
  for (int i = 0; i < n2; i++ ) {
    os << idtr << fMsrSchemeVarValAssocs[i];
  } // for
  */
  
  idtr--;
}

//______________________________________________________________________________
S_msrCreditWords msrCreditWords::create (
  int     inputLineNumber,
  string  creditWordsContents,
  int     creditWordsFontSize)
{
  msrCreditWords* o =
    new msrCreditWords (
      inputLineNumber,
      creditWordsContents,
      creditWordsFontSize);
  assert(o!=0);
  return o;
}

msrCreditWords::msrCreditWords (
  int     inputLineNumber,
  string  creditWordsContents,
  int     creditWordsFontSize)
    : msrElement (inputLineNumber)
{
  fCreditWordsContents = creditWordsContents;

  fCreditWordsFontSize = creditWordsFontSize;
}

msrCreditWords::~msrCreditWords() {}

void msrCreditWords::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrCreditWords::acceptIn()" << endl;
      
  if (visitor<S_msrCreditWords>*
    p =
      dynamic_cast<visitor<S_msrCreditWords>*> (v)) {
        S_msrCreditWords elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrCreditWords::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrCreditWords::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrCreditWords::acceptOut()" << endl;

  if (visitor<S_msrCreditWords>*
    p =
      dynamic_cast<visitor<S_msrCreditWords>*> (v)) {
        S_msrCreditWords elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrCreditWords::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrCreditWords::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrCreditWords& elt)
{
  elt->print (os);
  return os;
}

void msrCreditWords::print (ostream& os)
{
  os <<
    "CreditWords" <<
    endl;

  idtr++;
  
  os <<
    idtr <<
      setw(20) << "fCreditWordsContents" << " = " << fCreditWordsContents <<
      endl <<
    idtr <<
      setw(20) << "fCreditWordsFontSize" << " = " << fCreditWordsFontSize <<
      endl <<
    endl;

  idtr--;
}

//______________________________________________________________________________
S_msrCredit msrCredit::create (
  int inputLineNumber,
  int creditPageNumber)
{
  msrCredit* o =
    new msrCredit (
      inputLineNumber, creditPageNumber);
  assert(o!=0);
  return o;
}

msrCredit::msrCredit (
  int inputLineNumber,
  int creditPageNumber)
    : msrElement (inputLineNumber)
{
  fCreditPageNumber = creditPageNumber;
}

msrCredit::~msrCredit() {}

void msrCredit::appendCreditWordsToCredit (
  int     inputLineNumber,
  string  creditWordsContents,
  int     creditWordsFontSize)
{
  S_msrCreditWords
    creditWords =
      msrCreditWords::create (
        inputLineNumber,
        creditWordsContents,
        creditWordsFontSize);
        
  fCreditWordsList.push_back (creditWords);
}

void msrCredit::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrCredit::acceptIn()" << endl;
      
  if (visitor<S_msrCredit>*
    p =
      dynamic_cast<visitor<S_msrCredit>*> (v)) {
        S_msrCredit elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrCredit::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrCredit::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrCredit::acceptOut()" << endl;

  if (visitor<S_msrCredit>*
    p =
      dynamic_cast<visitor<S_msrCredit>*> (v)) {
        S_msrCredit elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrCredit::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrCredit::browseData (basevisitor* v)
{
  int n1 = fCreditWordsList.size();
  
  for (int i = 0; i < n1; i++ ) {
    // browse the credit words
    msrBrowser<msrCreditWords> browser (v);
    browser.browse (*fCreditWordsList [i]);
  } // for
}

ostream& operator<< (ostream& os, const S_msrCredit& elt)
{
  elt->print (os);
  return os;
}

void msrCredit::print (ostream& os)
{
  os <<
    "Credit" <<
    endl;

  idtr++;
  
  os <<
    idtr <<
      setw(21) << "fCreditPageNumber" << " = " << fCreditPageNumber <<
      endl <<
    endl;

  vector<S_msrCreditWords>::const_iterator
    iBegin = fCreditWordsList.begin(),
    iEnd   = fCreditWordsList.end(),
    i      = iBegin;

  for ( ; ; ) {
    os << idtr << (*i);
    if (++i == iEnd) break;
// JMI    os << endl;
  } // for
  
  idtr--;
}

//______________________________________________________________________________
S_msrClef msrClef::create (
  int          inputLineNumber,
  msrClefKind  clefKind)
{
  msrClef* o =
    new msrClef (
      inputLineNumber, clefKind);
  assert(o!=0);
  return o;
}

msrClef::msrClef (
  int          inputLineNumber,
  msrClefKind  clefKind)
    : msrElement (inputLineNumber)
{
  fClefKind = clefKind;
}

msrClef::~msrClef() {}

bool msrClef::clefIsATablatureClef () const
{
  switch (fClefKind) {
    case msrClef::kTablature4Clef:
    case msrClef::kTablature5Clef:
    case msrClef::kTablature6Clef:
    case msrClef::kTablature7Clef:
      return true;
      break;
    default:
      return false;
  } // switch
}

bool msrClef::clefIsAPercussionClef () const
{
  switch (fClefKind) {
    case msrClef::kPercussionClef:
      return true;
      break;
    default:
      return false;
  } // switch
}

void msrClef::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrClef::acceptIn()" << endl;
      
  if (visitor<S_msrClef>*
    p =
      dynamic_cast<visitor<S_msrClef>*> (v)) {
        S_msrClef elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrClef::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrClef::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrClef::acceptOut()" << endl;

  if (visitor<S_msrClef>*
    p =
      dynamic_cast<visitor<S_msrClef>*> (v)) {
        S_msrClef elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrClef::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrClef::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrClef& elt)
{
  elt->print (os);
  return os;
}

string msrClef::clefAsString () const
{
  stringstream s;

  s <<
    "Clef" " \"";
   
  switch (fClefKind) {
    case msrClef::k_NoClef:
      s << "none";
      break;
    case msrClef::kTrebleClef:
      s << "treble";
      break;
    case msrClef::kAltoClef:
      s << "alto";
      break;
    case msrClef::kTenorClef:
      s << "tenor";
      break;
    case msrClef::kBassClef:
      s << "bass";
      break;
    case msrClef::kTrebleLine1Clef:
      s << "treble line 1";
      break;
    case msrClef::kTrebleMinus15Clef:
      s << "treble -15";
      break;
    case msrClef::kTrebleMinus8Clef:
      s << "treble -8";
      break;
    case msrClef::kTreblePlus8Clef:
      s << "treble +8";
      break;
    case msrClef::kTreblePlus15Clef:
      s << "treble +15";
      break;
    case msrClef::kBassMinus15Clef:
      s << "bass -15";
      break;
    case msrClef::kBassMinus8Clef:
      s << "bass -8";
      break;
    case msrClef::kBassPlus8Clef:
      s << "bass +8";
      break;
    case msrClef::kBassPlus15Clef:
      s << "bass +15";
      break;
    case msrClef::kTablature4Clef:
      s << "tablature 4 lines";
      break;
    case msrClef::kTablature5Clef:
      s << "tablature 5 lines";
      break;
    case msrClef::kTablature6Clef:
      s << "tablature 6 lines";
      break;
    case msrClef::kTablature7Clef:
      s << "tablature 7 lines";
      break;
    case msrClef::kPercussionClef:
      s << "percussion";
      break;
  } // switch

  s <<
    "\", line " << fInputLineNumber;

  return s.str();
}

void msrClef::print (ostream& os)
{
  os <<
    clefAsString () <<
    endl;
}

//______________________________________________________________________________
S_msrKey msrKey::create (
  int           inputLineNumber,
  int           fifths,
  string        mode,
  int           cancel)
{
  msrKey* o =
    new msrKey (
      inputLineNumber, fifths, mode, cancel);
  assert (o!=0);
  return o;
}

msrKey::msrKey (
  int           inputLineNumber,
  int           fifths,
  string        mode,
  int           cancel)
    : msrElement (inputLineNumber)
{
  fKeyFifths = fifths;
  fKeyMode   = mode;
  fKeyCancel = cancel;

  string                 tonicNote;
  msrKey::msrKeyModeKind keyModeKind;
  
  switch (fKeyFifths) {
    case 0:
      tonicNote = "c";
      keyModeKind = msrKey::kMajor;
      break;
    case 1:
      tonicNote = "g";
      keyModeKind = msrKey::kMajor;
      break;
    case 2:
      tonicNote = "d";
      keyModeKind = msrKey::kMajor;
      break;
    case 3:
      tonicNote = "a";
      keyModeKind = msrKey::kMajor;
      break;
    case 4:
      tonicNote = "e";
      keyModeKind = msrKey::kMajor;
      break;
    case 5:
      tonicNote = "b";
      keyModeKind = msrKey::kMajor;
      break;
    case 6:
       tonicNote = "fis";
      keyModeKind = msrKey::kMajor;
      break;
    case 7:
      tonicNote = "cis";
      keyModeKind = msrKey::kMajor;
      break;
    case -1:
      tonicNote = "f";
      keyModeKind = msrKey::kMajor;
      break;
    case -2:
      tonicNote = "bes";
      keyModeKind = msrKey::kMajor;
      break;
    case -3:
      tonicNote = "ees";
      keyModeKind = msrKey::kMajor;
      break;
    case -4:
      tonicNote = "aes";
      keyModeKind = msrKey::kMajor;
      break;
    case -5:
      tonicNote = "des";
      keyModeKind = msrKey::kMajor;
      break;
    case -6:
      tonicNote = "ges";
      keyModeKind = msrKey::kMajor;
      break;
    case -7:
      tonicNote = "ces";
      keyModeKind = msrKey::kMajor;
      break;
    default: // unknown key sign !!
      {
      stringstream s;
      
      s << 
        "ERROR: unknown key sign \"" << fKeyFifths << "\"";
        
      msrMusicXMLError (
        fInputLineNumber,
        s.str());
      }
  } // switch
  
  fKeyTonic    = tonicNote;
  fKeyModeKind = keyModeKind; 
}

msrKey::~msrKey() {}

void msrKey::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrKey::acceptIn()" << endl;
      
  if (visitor<S_msrKey>*
    p =
      dynamic_cast<visitor<S_msrKey>*> (v)) {
        S_msrKey elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrKey::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrKey::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrKey::acceptOut()" << endl;

  if (visitor<S_msrKey>*
    p =
      dynamic_cast<visitor<S_msrKey>*> (v)) {
        S_msrKey elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrKey::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}


void msrKey::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrKey& elt)
{
  elt->print (os);
  return os;
}

string msrKey::keyAsString () const
{
  stringstream s;

  s << "Key \"" << fKeyTonic << " ";
  if (fKeyModeKind == kMajor)
    s << "major";
  else
    s << "minor";

  s <<
    "\", line " << fInputLineNumber;

  return s.str();
}

void msrKey::print (ostream& os)
{
  os << keyAsString () << endl;
}

//______________________________________________________________________________
S_msrTime msrTime::create (
  int           inputLineNumber,
  int           beatsNumber,
  int           beatsValue)
{
  msrTime* o =
    new msrTime (
      inputLineNumber,
      beatsNumber, beatsValue);
  assert (o!=0);
  return o;
}

msrTime::msrTime (
  int           inputLineNumber,
  int           beatsNumber,
  int           beatsValue)
    : msrElement (inputLineNumber)
{
  fBeatsNumber = beatsNumber;
  fBeatsValue  = beatsValue;
}

msrTime::~msrTime() {}

void msrTime::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrTime::acceptIn()" << endl;
      
  if (visitor<S_msrTime>*
    p =
      dynamic_cast<visitor<S_msrTime>*> (v)) {
        S_msrTime elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrTime::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrTime::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrTime::acceptOut()" << endl;

  if (visitor<S_msrTime>*
    p =
      dynamic_cast<visitor<S_msrTime>*> (v)) {
        S_msrTime elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrTime::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrTime::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrTime& elt)
{
  elt->print (os);
  return os;
}

string msrTime::timeAsString () const
{
  stringstream s;

  s <<
    "Time \"" << 
    fBeatsNumber << "/" << fBeatsValue <<
    "\", line " << fInputLineNumber;

  return s.str();
}

void msrTime::print (ostream& os)
{
  os << timeAsString () << endl;
}

//______________________________________________________________________________
S_msrTranspose msrTranspose::create (
  int           inputLineNumber,
  int           transposeDiatonic,
  int           transposeChromatic)
{
  msrTranspose* o =
    new msrTranspose (
      inputLineNumber,
      transposeDiatonic, transposeChromatic);
  assert (o!=0);
  return o;
}

msrTranspose::msrTranspose (
  int           inputLineNumber,
  int           transposeDiatonic,
  int           transposeChromatic)
    : msrElement (inputLineNumber)
{
  fTransposeDiatonic  = transposeDiatonic;
  fTransposeChromatic = transposeChromatic;
}

msrTranspose::~msrTranspose() {}

void msrTranspose::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrTranspose::acceptIn()" << endl;
      
  if (visitor<S_msrTranspose>*
    p =
      dynamic_cast<visitor<S_msrTranspose>*> (v)) {
        S_msrTranspose elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrTranspose::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrTranspose::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrTranspose::acceptOut()" << endl;

  if (visitor<S_msrTranspose>*
    p =
      dynamic_cast<visitor<S_msrTranspose>*> (v)) {
        S_msrTranspose elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrTranspose::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrTranspose::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrTranspose& elt)
{
  elt->print (os);
  return os;
}

string msrTranspose::transposeAsString () const
{
  stringstream s;

  s <<
    "Transpose " << 
    "diatonic = " << fTransposeDiatonic <<
    ", chromatic= " << fTransposeChromatic;

  return s.str();
}

void msrTranspose::print (ostream& os)
{
  os << transposeAsString () << endl;
}

//______________________________________________________________________________
S_msrWords msrWords::create (
  int                   inputLineNumber,
  msrWordsPlacementKind wordsPlacementKind,
  string                wordsContents,
  string                wordsFontStyle,
  string                wordsFontSize,
  string                wordsFontWeight,
  string                wordsFontXMLLang)
{
  msrWords* o =
    new msrWords (
      inputLineNumber,
      wordsPlacementKind,
      wordsContents,
      wordsFontStyle,
      wordsFontSize,
      wordsFontWeight,
      wordsFontXMLLang);
  assert(o!=0);
  return o;
}

msrWords::msrWords (
  int                   inputLineNumber,
  msrWordsPlacementKind wordsPlacementKind,
  string                wordsContents,
  string                wordsFontStyle,
  string                wordsFontSize,
  string                wordsFontWeight,
  string                wordsFontXMLLang)
    : msrElement (inputLineNumber)
{
  fWordsPlacementKind = wordsPlacementKind;
  
  fWordsContents      = wordsContents;

  fWordsFontStyle     = wordsFontStyle;
  fWordsFontSize      = wordsFontSize;
  fWordsFontWeight    = wordsFontWeight;
  fWordsFontXMLLang   = wordsFontXMLLang;
}
msrWords::~msrWords() {}

void msrWords::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrWords::acceptIn()" << endl;
      
  if (visitor<S_msrWords>*
    p =
      dynamic_cast<visitor<S_msrWords>*> (v)) {
        S_msrWords elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrWords::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrWords::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrWords::acceptOut()" << endl;

  if (visitor<S_msrWords>*
    p =
      dynamic_cast<visitor<S_msrWords>*> (v)) {
        S_msrWords elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrWords::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}


void msrWords::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrWords& elt)
{
  elt->print (os);
  return os;
}

string msrWords::wordsPlacementKindAsString (
  msrWordsPlacementKind wordsPlacementKind)
{
  string result;

  switch (wordsPlacementKind) {
    case kAbove:
      result = "above";
      break;
    case kBelow:
      result = "below";
      break;
  } // switch

  return result;
}

string msrWords::wordsAsString () const
{
  stringstream s;

  s <<
    "Words" << " " <<
    fWordsContents << ", placement = " <<
    wordsPlacementKindAsString (fWordsPlacementKind);

  return s.str();
}

void msrWords::print (ostream& os)
{
// JMI  os << wordsAsString () << endl;

  os <<
    "Words" " \"" << fWordsContents << "\"" <<
    endl;

  idtr++;

  os <<
    idtr << left <<
      setw(16) << "Placement" << " = " <<
      wordsPlacementKindAsString (fWordsPlacementKind) <<
      endl <<
    idtr <<
      setw(16) << "WordsFontStyle" << " = " << fWordsFontStyle <<
      endl <<
    idtr <<
      setw(16) << "WordsFontSize" << " = " << fWordsFontSize <<
      endl <<
    idtr <<
      setw(16) << "WordsFontWeight" << " = " << fWordsFontWeight <<
      endl <<
    idtr <<
      setw(16) << "WordsFontXMLLang" << " = " << fWordsFontXMLLang <<
      endl;
  
  idtr--;
}

//______________________________________________________________________________
S_msrTempo msrTempo::create (
  int           inputLineNumber,
  int           tempoUnit,
  int           perMinute)
{
  msrTempo* o =
    new msrTempo (
      inputLineNumber, tempoUnit, perMinute);
  assert(o!=0);
  return o;
}

msrTempo::msrTempo (
  int           inputLineNumber,
  int           tempoUnit,
  int           perMinute)
    : msrElement (inputLineNumber)
{
  fTempoIndication = "";
  
  fTempoUnit = tempoUnit;
  fPerMinute = perMinute;
}
msrTempo::~msrTempo() {}

void msrTempo::setTempoIndication (string indication)
{
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "Setting indication of tempo " <<
      fTempoUnit << " = " << fPerMinute <<
      " to \"" << indication << "\"" <<
      endl;
      
  fTempoIndication = indication;
}

void msrTempo::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrTempo::acceptIn()" << endl;
      
  if (visitor<S_msrTempo>*
    p =
      dynamic_cast<visitor<S_msrTempo>*> (v)) {
        S_msrTempo elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrTempo::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrTempo::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrTempo::acceptOut()" << endl;

  if (visitor<S_msrTempo>*
    p =
      dynamic_cast<visitor<S_msrTempo>*> (v)) {
        S_msrTempo elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrTempo::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}


void msrTempo::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrTempo& elt)
{
  elt->print (os);
  return os;
}

string msrTempo::tempoAsString () const
{
  stringstream s;

  s <<
    "Tempo" << " " <<
    ", indication = \"" << fTempoIndication << "\"" <<
    ", " << fTempoUnit << " = " << fPerMinute;

  return s.str();
}

void msrTempo::print (ostream& os)
{
  os << tempoAsString () << endl;
}

//______________________________________________________________________________
S_msrSyllable msrSyllable::create (
  int                   inputLineNumber,
  msrSyllableKind       syllableKind,
  string                syllableText,
  msrSyllableExtendKind syllableExtendKind,
  int                   divisions,
  S_msrStanza           syllableStanzaUplink)
{
  msrSyllable* o =
    new msrSyllable (
      inputLineNumber,
      syllableKind, syllableText, syllableExtendKind,
      divisions,
      syllableStanzaUplink);
  assert(o!=0);
  return o;
}

msrSyllable::msrSyllable (
  int                   inputLineNumber,
  msrSyllableKind       syllableKind,
  string                syllableText,
  msrSyllableExtendKind syllableExtendKind,
  int                   divisions,
  S_msrStanza           syllableStanzaUplink)
    : msrElement (inputLineNumber)
{
  fSyllableKind = syllableKind;
  fSyllableText = syllableText;
  fSyllableDivisions  = divisions;

  fSyllableExtendKind = syllableExtendKind;
  
  fSyllableStanzaUplink = syllableStanzaUplink;

  // fSyllableNoteUplink will be set
  // by setSyllableNoteUplink() later
}

msrSyllable::~msrSyllable()
{}

S_msrSyllable msrSyllable::createSyllableBareClone ()
{
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> Creating a bare clone of a syllable" <<
      endl;

  S_msrSyllable
    clone =
      msrSyllable::create (
        fInputLineNumber,
        fSyllableKind,
        fSyllableText,
        fSyllableExtendKind,
        fSyllableDivisions,
        fSyllableStanzaUplink);
    
  // dont't set 'clone->fSyllableStanzaUplink'
  // nor 'clone->fSyllableNoteUplink',
  // this will be done by the caller

   clone->fSyllableNoteUplink = fSyllableNoteUplink; // TEMP
  
  return clone;
}

void msrSyllable::setSyllableNoteUplink (S_msrNote note)
{
  fSyllableNoteUplink = note;

  // register syllable in note if its text is not empty
  if (fSyllableText.size ())
     note->
      appendSyllableToNote (this); // JMI
  
  if (true || gGeneralOptions->fDebugDebug) {
//  if (gGeneralOptions->fDebugDebug) {
    cerr <<
      idtr <<
      "==> setting syllable note uplink for:" <<
      endl;

    idtr++;
    
    cerr <<
      idtr <<
        syllableAsString () <<
    // JMI    "to '" << note->noteAsString () <<
      ", line " << note->getInputLineNumber () <<
      endl;

    idtr--;
      
/*
    if (note) { // JMI
      cerr <<
        note->noteAsString () <<
        ", line " << note->getInputLineNumber ();
    }
    else {
      cerr << "none";
    }
    
    cerr <<
      endl;
      */
  }
}

void msrSyllable::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrSyllable::acceptIn()" << endl;
      
  if (visitor<S_msrSyllable>*
    p =
      dynamic_cast<visitor<S_msrSyllable>*> (v)) {
        S_msrSyllable elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrSyllable::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrSyllable::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrSyllable::acceptOut()" << endl;

  if (visitor<S_msrSyllable>*
    p =
      dynamic_cast<visitor<S_msrSyllable>*> (v)) {
        S_msrSyllable elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrSyllable::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrSyllable::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrSyllable& elt)
{
  elt->print (os);
  return os;
}

string msrSyllable::syllableKindAsString (
  msrSyllableKind syllableKind)
{
  string result;
    
  switch (syllableKind) {
    case msrSyllable::kSingleSyllable:
      result = "single";
      break;
    case msrSyllable::kBeginSyllable:
      result = "begin";
      break;
    case msrSyllable::kMiddleSyllable:
      result = "middle";
      break;
    case msrSyllable::kEndSyllable:
      result = "end";
      break;
      
    case msrSyllable::kRestSyllable:
      result = "rest";
      break;
      
    case msrSyllable::kSkipSyllable:
      result = "skip";
      break;
      
    case msrSyllable::kSlurSyllable:
      result = "slur";
      break;
    case msrSyllable::kSlurBeyondEndSyllable:
      result = "slur beyond end";
      break;
      
    case msrSyllable::kTiedSyllable:
      result = "tied";
      break;
      
    case msrSyllable::kBarcheckSyllable:
      result = "bar check";
      break;
      
    case msrSyllable::kBarnumberCheckSyllable:
      result = "barnumber check";
      break;
      
    case msrSyllable::kBreakSyllable:
      result = "break";
      break;
      
    case msrSyllable::k_NoSyllable:
      result = "k_NoSyllable ???";
      break;
  } // switch

  return result;
}

string msrSyllable::syllableKindAsString () const
{
  return syllableKindAsString (fSyllableKind);
}

string msrSyllable::syllableExtendKindAsString (
  msrSyllableExtendKind syllableExtendKind)
{
  string result;
  
  switch (syllableExtendKind) {
    case msrSyllable::kStandaloneSyllableExtend:
      result = "standalone";
      break;
    case msrSyllable::kStartSyllableExtend:
      result = "start";
      break;
    case msrSyllable::kContinueSyllableExtend:
      result = "continue";
      break;
    case msrSyllable::kStopSyllableExtend:
      result = "stop";
      break;
    case msrSyllable::k_NoSyllableExtend:
      result = "none";
      break;
  } // switch

  return result;
}

string msrSyllable::syllableDivisionsAsString () const
{
  string errorMessage;

  int divisionsPerWholeNote =
    fSyllableStanzaUplink->
      getStanzaVoiceUplink ()->
        getVoiceDivisionsPerWholeNote ();

  string result =
    divisionsAsMSRDuration (
      fSyllableDivisions,
      divisionsPerWholeNote,
      errorMessage,
      false); // 'true' to debug it;

    if (errorMessage.size ())
      msrInternalError (
        fInputLineNumber,
        errorMessage);

  return result;
}

string msrSyllable::syllableNoteUplinkAsString () const
{
  string result;

  if (fSyllableNoteUplink)
    result =
      "==> "
        +
      fSyllableNoteUplink->noteAsString ();
  else
    result =
      "no syllable note uplink";

  return result;
}

string msrSyllable::syllableAsString () const
{
  stringstream s;
  
  switch (fSyllableKind) {
    case kSingleSyllable:
      s <<
        "single" <<
        ", " << "\"" << fSyllableText << "\"" <<
        ":" << syllableDivisionsAsString () <<
        " (" << fSyllableDivisions << ")" <<
        ", line " << fInputLineNumber <<
        ", " <<
        syllableNoteUplinkAsString () <<
        ", NoteSyllableExtendKind: " <<
        syllableExtendKindAsString (fSyllableExtendKind);
      break;
      
    case kBeginSyllable:
      s << 
        "begin" <<
        ", " << "\"" << fSyllableText << "\"" <<
         ":" << syllableDivisionsAsString () <<
        " (" << fSyllableDivisions << ")" <<
        ", line " << fInputLineNumber <<
        ", " <<
        syllableNoteUplinkAsString () <<
        ", NoteSyllableExtendKind: " <<
        syllableExtendKindAsString (fSyllableExtendKind);
      break;
      
    case kMiddleSyllable:
      s << 
        "middle" <<
        ", " << "\"" << fSyllableText << "\"" <<
        ":" << syllableDivisionsAsString () <<
        " (" << fSyllableDivisions << ")" <<
        ", line " << fInputLineNumber <<
        ", " <<
        syllableNoteUplinkAsString () <<
        ", NoteSyllableExtendKind: " <<
        syllableExtendKindAsString (fSyllableExtendKind);
      break;
      
    case kEndSyllable:
      s << 
        "end" <<
        ", " << "\"" << fSyllableText << "\"" <<
        ":" << syllableDivisionsAsString () <<
        " (" << fSyllableDivisions << ")" <<
        ", line " << fInputLineNumber <<
        ", " <<
        syllableNoteUplinkAsString () <<
        ", NoteSyllableExtendKind: " <<
        syllableExtendKindAsString (fSyllableExtendKind);
      break;
      
    case kRestSyllable:
       s << 
        "rest" << ":" << syllableDivisionsAsString () <<
        " (" << fSyllableDivisions << ")" <<
        ", line " << fInputLineNumber <<
        ", " <<
        syllableNoteUplinkAsString ();
      break;
      
    case kSkipSyllable:
      s << 
        "skip" << ":" << syllableDivisionsAsString () <<
        " (" << fSyllableDivisions << ")" <<
        ", line " << fInputLineNumber;
      break;
      
    case kSlurSyllable:
      s << 
        "slur" << ":" << syllableDivisionsAsString () <<
        " (" << fSyllableDivisions << ")" <<
        ", line " << fInputLineNumber <<
        ", " <<
        syllableNoteUplinkAsString ();
      break;
      
    case kSlurBeyondEndSyllable:
      s << 
        "slur beyond end" << ":" << syllableDivisionsAsString () <<
        ", line " << fInputLineNumber <<
        ", " <<
        syllableNoteUplinkAsString ();
      break;
      
    case kTiedSyllable:
      s << 
        "tied" << ":" << syllableDivisionsAsString () <<
        " (" << fSyllableDivisions << ")" <<
        ", line " << fInputLineNumber <<
        ", " <<
        syllableNoteUplinkAsString () <<
        " " << "\"" << fSyllableText << "\"";
      break;
      
    case kBarcheckSyllable:
      // fSyllableText contains the measure number
      s << 
        "bar check" <<
        " measure " << fSyllableText;
      break;
      
    case kBarnumberCheckSyllable:
      // fSyllableText contains the measure number
      s << 
        "bar number check" <<
        " measure " << fSyllableText;
      break;
      
    case kBreakSyllable:
      // fSyllableText contains the measure number
      s << 
        "break" <<
        " measure " << fSyllableText;
      break;
      
    case k_NoSyllable:
      msrInternalError (
        fInputLineNumber,
        "syllable type has not been set");
      break;
  } // switch

  return s.str();
}


void msrSyllable::print (ostream& os)
{  
  os <<
    "Syllable" << " " <<
    setw(15) << syllableAsString () <<
    endl;
}

//______________________________________________________________________________
S_msrStanza msrStanza::create (
  int           inputLineNumber,
  int           stanzaNumber,
  msrStanzaKind stanzaKind,
  S_msrVoice    stanzaVoiceUplink)
{
  msrStanza* o =
    new msrStanza (
      inputLineNumber,
      stanzaNumber,
      stanzaKind,
      stanzaVoiceUplink);
  assert(o!=0);
  return o;
}

msrStanza::msrStanza (
  int           inputLineNumber,
  int           stanzaNumber,
  msrStanzaKind stanzaKind,
  S_msrVoice    stanzaVoiceUplink)
    : msrElement (inputLineNumber)
{
  fStanzaNumber = stanzaNumber;
  fStanzaKind   = stanzaKind;

  msrAssert(
    stanzaVoiceUplink != 0, "stanzaVoiceUplink is null");

  fStanzaVoiceUplink  = stanzaVoiceUplink;
  
  switch (fStanzaKind) {
    case kRegularStanza:
      fStanzaName =
        fStanzaVoiceUplink->getVoiceName() +
        "_Stanza_" +
        int2EnglishWord (fStanzaNumber);
      break;
      
    case kMasterStanza:
      fStanzaName =
        fStanzaVoiceUplink->getVoiceName() +
        "_Stanza_" +
        "MASTER";
      break;
  } // switch
 
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Creating stanza " << getStanzaName () << endl;

  fStanzaTextPresent = false;
}

string msrStanza::getStanzaName () const
{
  return fStanzaName;
}

msrStanza::~msrStanza() {}

S_msrStanza msrStanza::createStanzaBareClone (S_msrVoice clonedVoice)
{
 // JMI if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> Creating a bare clone of stanza \"" <<
      getStanzaName () <<
      "\" in voice " << clonedVoice->getVoiceName () <<
      endl;

  S_msrStanza
    clone =
      msrStanza::create (
        fInputLineNumber,
        fStanzaNumber,
        fStanzaKind,
        clonedVoice);

  clone->fStanzaTextPresent =
    fStanzaTextPresent;

  // add the stanza clone to the cloned voice
  clonedVoice->
    addStanzaToVoiceWithoutCatchUp (clone);
    
  return clone;
}

void msrStanza::appendSyllableToStanza (
  S_msrSyllable syllable)
{
 // JMI if (gGeneralOptions->fDebug)
    cerr <<
      idtr <<
        "--> appending syllable " << syllable->syllableAsString () <<
      idtr <<
        "to stanza" << getStanzaName () <<
      endl;
      
  fSyllables.push_back (syllable);

  // does this stanza contain text?
  switch (syllable->getSyllableKind ()) {
    
    case msrSyllable::kSingleSyllable:
    case msrSyllable::kBeginSyllable:
    case msrSyllable::kMiddleSyllable:
    case msrSyllable::kEndSyllable:
      // only now, in case addSyllableToStanza() is called
      // from LPSR for example
      fStanzaTextPresent = true;
      break;
      
    case msrSyllable::kRestSyllable:
    case msrSyllable::kSkipSyllable:
    case msrSyllable::kSlurSyllable:
    case msrSyllable::kSlurBeyondEndSyllable:
    case msrSyllable::kTiedSyllable:
    case msrSyllable::kBarcheckSyllable:
    case msrSyllable::kBarnumberCheckSyllable:
    case msrSyllable::kBreakSyllable:
      break;
      
    case msrSyllable::k_NoSyllable:
      msrInternalError (
        fInputLineNumber,
        "syllable type has not been set");
      break;
  } // switch
}

S_msrSyllable msrStanza::addRestSyllableToStanza (
  int inputLineNumber,
  int divisions)
{
 // if (true || gGeneralOptions->fForceDebug || gGeneralOptions->fDebug) {
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug) {
    S_msrStaff
      staff =
        fStanzaVoiceUplink->getVoiceStaffUplink ();
    S_msrPart
      part =
        staff-> getStaffPartUplink ();
    
    cerr << idtr <<
      "--> adding 'Rest' syllable:" << divisions <<
      " to stanza " << getStanzaName () <<
      ", divisions = " << divisions <<
      endl;
  }
  
  // create stanza rest syllable
  S_msrSyllable
    syllable =
      msrSyllable::create (
        inputLineNumber,
        msrSyllable::kRestSyllable, "",
        msrSyllable::k_NoSyllableExtend,
        divisions,
        this);

  // add syllable to this stanza
  fSyllables.push_back (syllable);

  // and return it
  return syllable;
}

S_msrSyllable msrStanza::addSkipSyllableToStanza (
  int inputLineNumber,
  int divisions)
{
//  if (true || gGeneralOptions->fForceDebug || gGeneralOptions->fDebug) {
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug) {
    S_msrStaff
      staff =
        fStanzaVoiceUplink->getVoiceStaffUplink ();
    S_msrPart
      part =
        staff-> getStaffPartUplink ();
    
    cerr << idtr <<
      "--> adding 'Skip' syllable:" << divisions <<
      " to stanza " << getStanzaName () <<
      ", divisions = " << divisions <<
      endl;
  }
  
  // create stanza skip syllable
  S_msrSyllable
    syllable =
      msrSyllable::create (
        inputLineNumber,
        msrSyllable::kSkipSyllable,
        "",
        msrSyllable::k_NoSyllableExtend,
        divisions,
        this);

  // add syllable to this stanza
  fSyllables.push_back (syllable);

  // and return it
  return syllable;
}

S_msrSyllable msrStanza::addTiedSyllableToStanza (
  int inputLineNumber,
  int divisions)
{
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug) {
    S_msrStaff
      staff =
        fStanzaVoiceUplink->getVoiceStaffUplink ();
    S_msrPart
      part =
        staff-> getStaffPartUplink ();
    
    cerr << idtr <<
      "--> Adding 'Tied' syllable: " << divisions <<
      " to stanza " << getStanzaName () << endl;
  }
  
  // create stanza tied syllable
  S_msrSyllable
    syllable =
      msrSyllable::create (
        inputLineNumber,
        msrSyllable::kTiedSyllable,
        "",
        msrSyllable::k_NoSyllableExtend,
        divisions,
        this);
        
  // add syllable to this stanza
  fSyllables.push_back (syllable);

  // and return it
  return syllable;
}

S_msrSyllable msrStanza::addSlurSyllableToStanza (
  int inputLineNumber,
  int divisions)
{
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug) {
    S_msrStaff
      staff =
        fStanzaVoiceUplink->getVoiceStaffUplink ();
    S_msrPart
      part =
        staff-> getStaffPartUplink ();
    
    cerr << idtr <<
      "--> Adding 'Slur' syllable:" << divisions <<
      " to stanza " << getStanzaName () << endl;
  }
  
  // create stanza slur syllable
  S_msrSyllable
    syllable =
      msrSyllable::create (
        inputLineNumber,
        msrSyllable::kSlurSyllable, "",
        msrSyllable::k_NoSyllableExtend,
        divisions,
        this);
        
  // add syllable to this stanza
  fSyllables.push_back (syllable);

  // and return it
  return syllable;
}

S_msrSyllable msrStanza::addSlurBeyondEndSyllableToStanza (
  int inputLineNumber,
  int divisions)
{
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug) {
    S_msrStaff
      staff =
        fStanzaVoiceUplink->getVoiceStaffUplink ();
    S_msrPart
      part =
        staff-> getStaffPartUplink ();
    
    cerr << idtr <<
      "--> Adding a 'SlurBeyondEnd' syllable: " << divisions <<
      " to stanza " << getStanzaName () << endl;
  }
  
  // create stanza slur syllable
  S_msrSyllable
    syllable =
      msrSyllable::create (
        inputLineNumber,
        msrSyllable::kSlurBeyondEndSyllable, "",
        msrSyllable::k_NoSyllableExtend,
        divisions,
        this);
        
  // add syllable to this stanza
  fSyllables.push_back (syllable);

  // and return it
  return syllable;
}

S_msrSyllable msrStanza::addBarcheckSyllableToStanza (
  int inputLineNumber,
  int nextMeasureNumber)
{
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug) {
    S_msrStaff
      staff =
        fStanzaVoiceUplink->getVoiceStaffUplink ();
    S_msrPart
      part =
        staff-> getStaffPartUplink ();
    
    cerr << idtr <<
      "--> Adding a 'barcheck' syllable" <<
      " to stanza " << getStanzaName () << endl;
  }

  // convert nextMeasureNumber to string
  stringstream s;
  s << nextMeasureNumber;
  
  // create stanza break syllable
  S_msrSyllable
    syllable =
      msrSyllable::create (
        inputLineNumber,
        msrSyllable::kBarcheckSyllable,
        s.str(),
        msrSyllable::k_NoSyllableExtend,
        0,
        this);
       
  // add syllable to this stanza
  fSyllables.push_back (syllable);

  // and return it
  return syllable;
}

S_msrSyllable msrStanza::addBarnumberCheckSyllableToStanza (
  int inputLineNumber,
  int nextMeasureNumber)
{
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug) {
    S_msrStaff
      staff =
        fStanzaVoiceUplink->getVoiceStaffUplink ();
    S_msrPart
      part =
        staff-> getStaffPartUplink ();
    
    cerr << idtr <<
      "--> Adding a 'barcheck' syllable" <<
      " to stanza " << getStanzaName () << endl;
  }

  // convert nextMeasureNumber to string
  stringstream s;
  s << nextMeasureNumber;
  
  // create stanza break syllable        
  S_msrSyllable
    syllable =
      msrSyllable::create (
        inputLineNumber,
        msrSyllable::kBarnumberCheckSyllable,
        s.str(),
        msrSyllable::k_NoSyllableExtend,
        0,
        this);
       
  // add syllable to this stanza
  fSyllables.push_back (syllable);

  // and return it
  return syllable;
}

S_msrSyllable msrStanza::addBreakSyllableToStanza (
  int inputLineNumber,
  int nextMeasureNumber)
{
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug) {
    S_msrStaff
      staff =
        fStanzaVoiceUplink->getVoiceStaffUplink ();
    S_msrPart
      part =
        staff-> getStaffPartUplink ();
    
    cerr << idtr <<
      "--> Adding a 'Break' syllable" <<
      " to stanza " << getStanzaName () << endl;
  }

  // convert nextMeasureNumber to string
  stringstream s;
  s << nextMeasureNumber;
  
  // create stanza break syllable
  S_msrSyllable
    syllable =
      msrSyllable::create (
        inputLineNumber,
        msrSyllable::kBreakSyllable,
        s.str(),
        msrSyllable::k_NoSyllableExtend,
        0,
        this);
        
  // add syllable to this stanza
  fSyllables.push_back (syllable);

  // and return it
  return syllable;
}

void msrStanza::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrStanza::acceptIn()" << endl;
      
  if (visitor<S_msrStanza>*
    p =
      dynamic_cast<visitor<S_msrStanza>*> (v)) {
        S_msrStanza elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrStanza::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrStanza::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrStanza::acceptOut()" << endl;

  if (visitor<S_msrStanza>*
    p =
      dynamic_cast<visitor<S_msrStanza>*> (v)) {
        S_msrStanza elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrStanza::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrStanza::browseData (basevisitor* v)
{
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrStanza::browseData()" << endl;

  idtr++;
  
  // browse the syllables
  int n = fSyllables.size ();
  for (int i = 0; i < n; i++) {
    // browse the syllable
    msrBrowser<msrSyllable> browser (v);
    browser.browse (*fSyllables [i]);
  } // for
  cerr <<
    endl;

  idtr--;

  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "<== msrStanza::browseData()" << endl;
}

ostream& operator<< (ostream& os, const S_msrStanza& elt)
{
  elt->print (os);
  return os;
}

string msrStanza::stanzaKindAsString (
  msrStanzaKind stanzaKind)
{
 string result;
  
  switch (stanzaKind) {
    case msrStanza::kRegularStanza:
      result = "regular";
      break;
      
    case msrStanza::kMasterStanza:
      result = "master";
      break;
  } // switch

  return result;
}

void msrStanza::print (ostream& os)
{
  // getch stanza kind with an initial uppper case letter
  string stanzaKind =
    stanzaKindAsString (fStanzaKind);

  stanzaKind [0] = toupper (stanzaKind [0]);
  
  os <<
    stanzaKind << " " "stanza" " " << getStanzaName () <<
    " (" << fSyllables.size () << " syllables)";
    
  if (! fStanzaTextPresent)
    os << " (No actual text)";

  os << endl;

//  if (fStanzaTextPresent) {  JMI
    idtr++;

    int n = fSyllables.size();
    for (int i = 0; i < n; i++) {
      os << idtr << fSyllables [i];
    } // for
    os << endl;

    idtr--;
 // }
}

//______________________________________________________________________________
S_msrHarmony msrHarmony::create (
  int                  inputLineNumber,
  msrQuartertonesPitch harmonyRootQuartertonesPitch,
  msrHarmonyKind       harmonyKind,
  string               harmonyKindText,
  msrQuartertonesPitch harmonyBassQuartertonesPitch,
  S_msrPart            harmonyPartUplink)
{
  msrHarmony* o =
    new msrHarmony (
      inputLineNumber,
      harmonyRootQuartertonesPitch,
      harmonyKind, harmonyKindText,
      harmonyBassQuartertonesPitch,
      harmonyPartUplink);
  assert(o!=0);
  return o;
}

msrHarmony::msrHarmony (
  int                  inputLineNumber,
  msrQuartertonesPitch harmonyRootQuartertonesPitch,
  msrHarmonyKind       harmonyKind,
  string               harmonyKindText,
  msrQuartertonesPitch harmonyBassQuartertonesPitch,
  S_msrPart            harmonyPartUplink)
    : msrElement (inputLineNumber)
{
  fHarmonyRootQuartertonesPitch = harmonyRootQuartertonesPitch;
 
  fHarmonyKind                 = harmonyKind;
  fHarmonyKindText             = harmonyKindText;
 
  fHarmonyBassQuartertonesPitch = harmonyBassQuartertonesPitch;
 
  fHarmonyPartUplink = harmonyPartUplink;
}

msrHarmony::~msrHarmony() {}

S_msrHarmony msrHarmony::createHarmonyBareClone (S_msrPart clonedPart)
{
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> Creating a bare clone or a harmony" <<
      endl;

  S_msrHarmony
    clone =
      msrHarmony::create (
        fInputLineNumber,
        fHarmonyRootQuartertonesPitch,
        fHarmonyKind, fHarmonyKindText,
        fHarmonyBassQuartertonesPitch,
        clonedPart);
  
  return clone;
}

string msrHarmony::harmonyKindAsString () const
{
  string result;
  
  switch (fHarmonyKind) {
    case msrHarmony::kMajor:
      result = "Major";
      break;
    case msrHarmony::kMinor:
      result = "Minor";
      break;
    case msrHarmony::kDominant:
      result = "Dominant";
      break;
    case msrHarmony::kAugmented:
      result = "Augmented";
      break;
    case msrHarmony::kDiminished:
      result = "Diminished";
      break;
    case msrHarmony::kSuspendedFourth:
      result = "SuspendedFourth";
      break;
    case msrHarmony::kMajorSeventh:
      result = "MajorSeventh";
      break;
    case msrHarmony::kMinorSeventh:
      result = "MinorSeventh";
      break;
    case msrHarmony::kMajorNinth:
      result = "MajorNinth";
      break;
    case msrHarmony::kMinorNinth:
      result = "MinorNinth";
      break;
    case msrHarmony::k_NoHarmony:
      result = "Harmony???";
      break;
  } // switch

  return result;
}

string msrHarmony::harmonyKindAsShortString () const
{
  string result;
  
  switch (fHarmonyKind) {
    case msrHarmony::kMajor:
      break;
    case msrHarmony::kMinor:
      result = "m";
      break;
    case msrHarmony::kDominant:
      result = "7";
      break;
    case msrHarmony::kAugmented:
      result = "+";
      break;
    case msrHarmony::kDiminished:
      result = "dim";
      break;
    case msrHarmony::kSuspendedFourth:
      result = "sus4";
      break;
    case msrHarmony::kMajorSeventh:
      result = "∆7";
      break;
    case msrHarmony::kMinorSeventh:
      result = "m7";
      break;
    case msrHarmony::kMajorNinth:
      result = "9";
      break;
    case msrHarmony::kMinorNinth:
      result = "-9";
      break;
    case msrHarmony::k_NoHarmony:
      result = "Harmony???";
      break;
  } // switch

  return result;
}

string msrHarmony::harmonyAsString () const
{
  stringstream s;

  s <<
    msrDiatonicPitchAsString (
      msrDiatonicPitchFromQuatertonesPitch (
        fInputLineNumber,
        fHarmonyRootQuartertonesPitch)) <<        
    harmonyKindAsShortString ();

  if (fHarmonyKindText.size ())
    s <<
      " (" <<fHarmonyKindText << ") ";

  if (fHarmonyRootQuartertonesPitch != k_NoPitch)
    s <<
      "/" <<
      msrDiatonicPitchAsString (
        msrDiatonicPitchFromQuatertonesPitch (
          fInputLineNumber,
          fHarmonyRootQuartertonesPitch));

  return s.str();
}

void msrHarmony::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrHarmony::acceptIn()" << endl;
      
  if (visitor<S_msrHarmony>*
    p =
      dynamic_cast<visitor<S_msrHarmony>*> (v)) {
        S_msrHarmony elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrHarmony::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrHarmony::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrHarmony::acceptOut()" << endl;

  if (visitor<S_msrHarmony>*
    p =
      dynamic_cast<visitor<S_msrHarmony>*> (v)) {
        S_msrHarmony elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrHarmony::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrHarmony::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrHarmony& elt)
{
  elt->print (os);
  return os;
}

void msrHarmony::print (ostream& os)
{  
  os <<
    "Harmony" <<
    endl;
    
  idtr++;

  os << left <<
    idtr <<
      setw(15) << "HarmonyRoot" << " = " <<
      msrDiatonicPitchAsString (
        msrDiatonicPitchFromQuatertonesPitch (
          fInputLineNumber,
          fHarmonyRootQuartertonesPitch)) <<        
      endl <<
    idtr <<
      setw(15) << "HarmonyKind" << " = " <<
      harmonyKindAsString () <<
      endl <<
    idtr <<
      setw(15) << "HarmonyKindText" << " = " <<
      fHarmonyKindText <<
      endl <<
    idtr <<
      setw(15) << "HarmonyBass" << " = " <<
      msrDiatonicPitchAsString (
        msrDiatonicPitchFromQuatertonesPitch (
          fInputLineNumber,
          fHarmonyBassQuartertonesPitch)) <<        
      endl;

  idtr--;
}

//______________________________________________________________________________
S_msrChords msrChords::create (
  int       inputLineNumber,
  S_msrPart chordsPartUplink)
{
  msrChords* o =
    new msrChords (
      inputLineNumber,
      chordsPartUplink);
  assert(o!=0);
  return o;
}

msrChords::msrChords (
  int       inputLineNumber,
  S_msrPart chordsPartUplink)
    : msrElement (inputLineNumber)
{
  fChordsPartUplink  = chordsPartUplink;
  
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Creating chords " << getChordsName () << endl;

  fChordsPresent = false;
}

string msrChords::getChordsName () const
{
  return
    fChordsPartUplink->getPartName() +
    "_Chords";
}

msrChords::~msrChords() {}

S_msrChords msrChords::createChordsBareClone (S_msrPart clonedPart)
{
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> Creating a bare clone of a chord" <<
      endl;

  S_msrChords
    clone =
      msrChords::create (
        fInputLineNumber,
        clonedPart);

  clone->fChordsPresent = fChordsPresent;
  
  return clone;
}

void msrChords::appendSKipToChords (
  int       inputLineNumber,
  int       divisions)
{
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug) {
    cerr << idtr <<
      "--> Adding skip:" << divisions <<
      " to chords " << getChordsName () << endl;
  }

  /* JMI
  // create stanza skip syllable
  S_msrSyllable
    skip =
      msrSyllable::create (
        inputLineNumber,
        msrSyllable::kSkipSyllable, "",
        msrSyllable::k_NoSyllableExtend
        divisions,
        this);
  
  // add syllable to this stanza
  fChordsElements.push_back (skip);
  */
}

void msrChords::appendHarmonyToChords (S_msrHarmony harmony)
{
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "--> Appending harmony " << harmony <<
      " to chord " << getChordsName () << endl;
      
  fChordsElements.push_back (harmony);

  fChordsPresent = true;
}

void msrChords::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrChords::acceptIn()" << endl;
      
  if (visitor<S_msrChords>*
    p =
      dynamic_cast<visitor<S_msrChords>*> (v)) {
        S_msrChords elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrChords::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrChords::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrChords::acceptOut()" << endl;

  if (visitor<S_msrChords>*
    p =
      dynamic_cast<visitor<S_msrChords>*> (v)) {
        S_msrChords elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrChords::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrChords::browseData (basevisitor* v)
{
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrChords::browseData()" << endl;

  idtr++;
  
  // browse the Chords syllables
  int n = fChordsElements.size ();
  for (int i = 0; i < n; i++) {
    // browse the element
    msrBrowser<msrElement> browser (v);
    browser.browse (*fChordsElements [i]);
  } // for
  cerr << endl;

  idtr--;

  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "<== msrStanza::browseData()" << endl;
}

ostream& operator<< (ostream& os, const S_msrChords& elt)
{
  elt->print (os);
  return os;
}

void msrChords::print (ostream& os)
{  
 os <<
    "Chords" << " " << getChordsName () <<
    " (" <<
    singularOrPlural (
      fChordsElements.size (), "chords element", "chords elements");

  if (! fChordsPresent)
    os << " (No actual chords)";

  os << endl;
  
//  if (fChordsPresent) {  JMI
    idtr++;

    int n = fChordsElements.size();
    for (int i = 0; i < n; i++) {
      os << idtr << fChordsElements [i];
    } // for
    os << endl;

    idtr--;
 // }
}

//______________________________________________________________________________
S_msrSegno msrSegno::create (
  int                       inputLineNumber)
{
  msrSegno* o =
    new msrSegno (
      inputLineNumber);
  assert(o!=0);
  return o;
}

msrSegno::msrSegno (
  int                       inputLineNumber)
    : msrElement (inputLineNumber)
{}

msrSegno::~msrSegno() {}

void msrSegno::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrSegno::acceptIn()" << endl;
      
  if (visitor<S_msrSegno>*
    p =
      dynamic_cast<visitor<S_msrSegno>*> (v)) {
        S_msrSegno elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrSegno::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrSegno::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrSegno::acceptOut()" << endl;

  if (visitor<S_msrSegno>*
    p =
      dynamic_cast<visitor<S_msrSegno>*> (v)) {
        S_msrSegno elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrSegno::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrSegno::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrSegno& elt)
{
  elt->print (os);
  return os;
}

void msrSegno::print (ostream& os)
{
  os <<
    "Segno" <<
    ", line " << fInputLineNumber <<
    endl;
}

//______________________________________________________________________________
S_msrCoda msrCoda::create (
  int                       inputLineNumber)
{
  msrCoda* o =
    new msrCoda (
      inputLineNumber);
  assert(o!=0);
  return o;
}

msrCoda::msrCoda (
  int                       inputLineNumber)
    : msrElement (inputLineNumber)
{}

msrCoda::~msrCoda() {}

void msrCoda::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrCoda::acceptIn()" << endl;
      
  if (visitor<S_msrCoda>*
    p =
      dynamic_cast<visitor<S_msrCoda>*> (v)) {
        S_msrCoda elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrCoda::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrCoda::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrCoda::acceptOut()" << endl;

  if (visitor<S_msrCoda>*
    p =
      dynamic_cast<visitor<S_msrCoda>*> (v)) {
        S_msrCoda elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrCoda::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrCoda::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrCoda& elt)
{
  elt->print (os);
  return os;
}

void msrCoda::print (ostream& os)
{
  os <<
    "Coda" <<
    ", line " << fInputLineNumber <<
    endl;
}

//______________________________________________________________________________
S_msrEyeglasses msrEyeglasses::create (
  int                       inputLineNumber)
{
  msrEyeglasses* o =
    new msrEyeglasses (
      inputLineNumber);
  assert(o!=0);
  return o;
}

msrEyeglasses::msrEyeglasses (
  int                       inputLineNumber)
    : msrElement (inputLineNumber)
{}

msrEyeglasses::~msrEyeglasses() {}

void msrEyeglasses::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrEyeglasses::acceptIn()" << endl;
      
  if (visitor<S_msrEyeglasses>*
    p =
      dynamic_cast<visitor<S_msrEyeglasses>*> (v)) {
        S_msrEyeglasses elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrEyeglasses::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrEyeglasses::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrEyeglasses::acceptOut()" << endl;

  if (visitor<S_msrEyeglasses>*
    p =
      dynamic_cast<visitor<S_msrEyeglasses>*> (v)) {
        S_msrEyeglasses elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrEyeglasses::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrEyeglasses::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrEyeglasses& elt)
{
  elt->print (os);
  return os;
}

void msrEyeglasses::print (ostream& os)
{
  os <<
    "Eyeglasses" <<
    ", line " << fInputLineNumber <<
    endl;
}

//______________________________________________________________________________
S_msrPedal msrPedal::create (
  int              inputLineNumber,
  msrPedalType     pedalType,
  msrPedalLine     pedalLine)
{
  msrPedal* o =
    new msrPedal (
      inputLineNumber,
      pedalType, pedalLine);
  assert(o!=0);
  return o;
}

msrPedal::msrPedal (
  int              inputLineNumber,
  msrPedalType     pedalType,
  msrPedalLine     pedalLine)
    : msrElement (inputLineNumber)
{
  fPedalType = pedalType;
  fPedalLine = pedalLine;
}

msrPedal::~msrPedal() {}

string msrPedal::pedalTypeAsString ()
{
  string result;
  
  switch (fPedalType) {
    case kPedalStart:
      result = "start pedal";
      break;
    case kPedalContinue:
      result = "continue pedal";
      break;
    case kPedalChange:
      result = "change pedal";
      break;
    case kPedalStop:
      result = "stop pedal";
      break;
  } // switch

  return result;
}
      
string msrPedal::pedalLineAsString ()
{
  string result;
  
  switch (fPedalLine) {
    case kPedalLineYes:
      result = "pedal line: yes";
      break;
    case kPedalLineNo:
      result = "pedal line: no";
      break;
  } // switch

  return result;
}

void msrPedal::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrPedal::acceptIn()" << endl;
      
  if (visitor<S_msrPedal>*
    p =
      dynamic_cast<visitor<S_msrPedal>*> (v)) {
        S_msrPedal elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrPedal::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrPedal::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrPedal::acceptOut()" << endl;

  if (visitor<S_msrPedal>*
    p =
      dynamic_cast<visitor<S_msrPedal>*> (v)) {
        S_msrPedal elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrPedal::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrPedal::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrPedal& elt)
{
  elt->print (os);
  return os;
}

void msrPedal::print (ostream& os)
{
  os <<
    "Pedal" <<
    ", line " << fInputLineNumber <<
    pedalTypeAsString () << ", " <<
    pedalLineAsString () <<
    endl;
}

//______________________________________________________________________________
S_msrBarline msrBarline::create (
  int                       inputLineNumber,
  bool                      barlineHasSegno,
  bool                      barlineHasCoda,
  msrBarlineLocation        location,
  msrBarlineStyle           style,
  msrBarlineEndingType      endingType,
  string                    endingNumber,
  msrBarlineRepeatDirection repeatDirection,
  msrBarlineRepeatWinged    repeatWinged)
{
  msrBarline* o =
    new msrBarline (
      inputLineNumber,
      barlineHasSegno, barlineHasCoda,
      location, style,
      endingType, endingNumber,
      repeatDirection, repeatWinged);
  assert(o!=0);
  return o;
}

msrBarline::msrBarline (
  int                       inputLineNumber,
  bool                      barlineHasSegno,
  bool                      barlineHasCoda,
  msrBarlineLocation        location,
  msrBarlineStyle           style,
  msrBarlineEndingType      endingType,
  string                    endingNumber,
  msrBarlineRepeatDirection repeatDirection,
  msrBarlineRepeatWinged    repeatWinged)
    : msrElement (inputLineNumber)
{
  fBarlineHasSegno = barlineHasSegno;
  fBarlineHasCoda  = barlineHasCoda;
  
  fLocation        = location;
  fStyle           = style;
  fEndingType      = endingType;
  fEndingNumber    = endingNumber;
  fRepeatDirection = repeatDirection;
  fRepeatWinged    = repeatWinged;
  
  // JMI cerr << "fEndingNumber = " << fEndingNumber << endl;
  
  // extract individual numbers from fEndingNumber
  // that may contain "1, 2"
  fEndingNumbersList =
    extractNumbersFromString (
      fEndingNumber, gGeneralOptions->fDebugDebug);
}

msrBarline::~msrBarline() {}

void msrBarline::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrBarline::acceptIn()" << endl;
      
  if (visitor<S_msrBarline>*
    p =
      dynamic_cast<visitor<S_msrBarline>*> (v)) {
        S_msrBarline elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrBarline::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrBarline::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrBarline::acceptOut()" << endl;

  if (visitor<S_msrBarline>*
    p =
      dynamic_cast<visitor<S_msrBarline>*> (v)) {
        S_msrBarline elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrBarline::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}


void msrBarline::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrBarline& elt)
{
  elt->print (os);
  return os;
}

string msrBarline::barlineLocationAsString (
  msrBarlineLocation barlineLocation)
{
  string result;
  
  switch (barlineLocation) {
    case k_NoLocation:
      result = "none";
      break;
    case kLeft:
      result = "Left";
      break;
    case kMiddle:
      result = "Middle";
      break;
    case kRight:
      result = "Right";
      break;
  } // switch

  return result;
}

string msrBarline::barlineCategoryAsString (
  msrBarlineCategory barlineCategory)
{
  string result;
  
  switch (barlineCategory) {
    case kStandaloneBar:
      result = "standalone";
      break;
    case kRepeatStart:
      result = "repeat start";
      break;
    case kRepeatEnd:
      result = "repeat end";
      break;
    case kHookedEndingStart:
      result = "hooked ending start";
      break;
    case kHookedEndingEnd:
      result = "hooked ending end";
      break;
    case kHooklessEndingStart:
      result = "hookless ending start";
      break;
    case kHooklessEndingEnd:
      result = "hookless ending end";
      break;
  } // switch

  return result;
}

string msrBarline::barlineStyleAsString (
  msrBarlineStyle barlineStyle)
{
  string result;
  
  switch (barlineStyle) {
    case k_NoStyle:
      result = "none";
      break;
    case kRegular:
      result = "Regular";
      break;
    case kDotted:
      result = "Dotted";
      break;
    case kDashed:
      result = "Dashed";
      break;
    case kHeavy:
      result = "Heavy";
      break;
    case kLightLight:
      result = "LightLight";
      break;
    case kLightHeavy:
      result = "LightHeavy";
      break;
    case kHeavyLight:
      result = "HeavyLight";
      break;
    case kHeavyHeavy:
      result = "HeavyHeavy";
      break;
    case kTick:
      result = "Tick";
      break;
    case kShort:
      result = "Short";
      break;
  } // switch

  return result;
}

string msrBarline::barlineEndingTypeAsString (
  msrBarlineEndingType barlineEndingType)
{
  string result;
  
  switch (barlineEndingType) {
    case k_NoEndingType:
      result = "none";
      break;
    case kStart:
      result = "Start";
      break;
    case kStop:
      result = "Stop";
      break;
    case kDiscontinue:
      result = "Discontinue";
      break;
  } // switch

  return result;
}

string msrBarline::barlineRepeatDirectionAsString (
  msrBarlineRepeatDirection barlineRepeatDirection)
{
  string result;
  
  switch (barlineRepeatDirection) {
    case k_NoRepeatDirection:
      result ="none";
      break;
    case kForward:
      result ="Forward";
      break;
    case kBackward:
      result ="Backward";
      break;
  } // switch

  return result;
}

string msrBarline::barlineRepeatWingedAsString (
  msrBarlineRepeatWinged barlineRepeatWinged)
{
  string result;
  
  switch (barlineRepeatWinged) {
    case k_NoRepeatWinged:
      result = "none"; // ??? JMI
      break;
    case kNone:
      result = "none";
      break;
    case kStraight:
      result = "Straight";
      break;
    case kCurved:
      result = "Curved";
      break;
    case kDoubleStraight:
      result = "DoubleStraight";
      break;
    case kDoubleCurved:
      result = "DoubleCurved";
      break;
  } // switch

  return result;
}

string msrBarline::barlineAsString () const
{
  stringstream s;

  s <<
    "Barline " << barlineCategoryAsString (fBarlineCategory) <<
    ", line " << fInputLineNumber <<
    ", EndingType" << " : " <<
    barlineEndingTypeAsString (fEndingType) <<
    ", RepeatDirection" << " : " <<
    barlineRepeatDirectionAsString (fRepeatDirection);
    
  return s.str();
}

void msrBarline::print (ostream& os)
{
  os <<
    "Barline, " << barlineCategoryAsString (fBarlineCategory) <<
    ", line " << fInputLineNumber;

  if (fBarlineHasSegno)
    os << ", has segno";
    
  if (fBarlineHasCoda)
    os << ", has coda";

  os <<
    endl;

  idtr++;

  os <<
    idtr << left <<
      setw(15) << "Location" << " : " <<
      barlineLocationAsString (fLocation) <<
      endl <<
    idtr <<
      setw(15) << "Style" << " : " <<
      barlineStyleAsString (fStyle) <<
      endl <<
    idtr <<
      setw(15) << "EndingType" << " : " <<
      barlineEndingTypeAsString (fEndingType) <<
      endl;
  
  os <<
    idtr <<
      setw(15) << "Ending number" << " : ";
  list<int>::const_iterator i;
  for (i=fEndingNumbersList.begin(); i!=fEndingNumbersList.end(); i++) {
    os << (*i) << " ";
  } // for
  os << endl;
 
  os <<
    idtr <<
      setw(15) << "RepeatDirection" << " : " <<
      barlineRepeatDirectionAsString (fRepeatDirection) <<
      endl;
  
  os <<
    idtr <<
      setw(15) << "RepeatWinged" << " : " <<
      barlineRepeatWingedAsString (fRepeatWinged) <<
      endl;
     
  idtr--;
}

//______________________________________________________________________________
S_msrMeasure msrMeasure::create (
  int           inputLineNumber,
  int           measureNumber,
  int           divisionsPerWholeNote,
  S_msrSegment  segmentUplink)
{
  msrMeasure* o =
    new msrMeasure (
      inputLineNumber,
      measureNumber, divisionsPerWholeNote,
      segmentUplink);
  assert(o!=0);
  return o;
}

msrMeasure::msrMeasure (
  int           inputLineNumber,
  int           measureNumber,
  int           divisionsPerWholeNote,
  S_msrSegment  segmentUplink)
    : msrElement (inputLineNumber)
{
  fMeasureNumber = measureNumber;
  
  fMeasureDivisionsPerWholeNote =
    divisionsPerWholeNote;

  fMeasureSegmentUplink = segmentUplink;

// JMI  assert(fMeasureSegmentUplink->getSegmentAbsoluteNumber () != 6); // XXL

  // set measure voice direct uplink
  fMeasureVoiceDirectUplink =
    fMeasureSegmentUplink->
      getSegmentVoiceUplink ();

  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> creating measure " << fMeasureNumber <<
      " in segment " <<
      fMeasureSegmentUplink->getSegmentAbsoluteNumber () <<
      " in voice \"" <<
      fMeasureVoiceDirectUplink->getVoiceName () <<
      "\"" <<
      endl;

  // set measure part direct uplink
  fMeasurePartDirectUplink =
    fMeasureVoiceDirectUplink->
      getVoiceStaffUplink ()->
        getStaffPartUplink ();

  // fetch measure time from segment
  setMeasureTime (
    fMeasureSegmentUplink->
      getSegmentTime ());
      
  fMeasureKind = kRegularMeasure; // may be changed afterwards

  fMeasurePosition = 1; // ready to receive the first note

  // initialize measure position high tide
  fMeasurePartDirectUplink->
    setPartMeasurePositionHighTide (1);
}

msrMeasure::~msrMeasure()
{}

S_msrMeasure msrMeasure::createMeasureBareClone (
  S_msrSegment clonedSegment)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> Creating a bare clone of measure " << fMeasureNumber <<
      endl;
  
  S_msrMeasure
    clone =
      msrMeasure::create (
        fInputLineNumber,
        fMeasureNumber,
        fMeasureDivisionsPerWholeNote,
        clonedSegment);

  clone->
    setMeasureTime (fMeasureTime);
    
  clone->fMeasureKind =
    fMeasureKind;
    
  return clone;
}

void msrMeasure::setMeasureTime (S_msrTime time)
{ 
/*
  The divisions element indicates how many divisions per quarter note are used to indicate a note's duration. For example, if duration = 1 and divisions = 2, this is an eighth note duration.
*/

  fMeasureTime = time;
  
  fMeasureDivisionsPerFullMeasure =
    fMeasureDivisionsPerWholeNote
      *
    time->getBeatsNumber ()
      /
    time->getBeatsValue ();
}

S_msrMeasure msrMeasure::appendMeasureIfOverflow (
  int inputLineNumber)
{
  S_msrMeasure
    newMeasure;

  // the first barline in a part comes before <divisions/>,
  // hence fMeasureDivisionsPerWholeMeasure may be 0:
  // don't test for measure measure change in that case
  
  if (
    fMeasureDivisionsPerFullMeasure > 0
      &&
    fMeasurePosition > fMeasureDivisionsPerFullMeasure
    ) {
    // measure overflows, we must synchonize all voices in this part
    
    if (gGeneralOptions->fDebug)
      cerr <<
        idtr <<
          "@@@@@@@@@@@@@@@@@ --> measure " << fMeasureNumber <<
          " overflows, line " << inputLineNumber <<
          endl<<
        idtr <<
          "fMeasurePosition = " << fMeasurePosition <<
          ", fMeasureDivisionsPerFullMeasure = " << fMeasureDivisionsPerFullMeasure <<
        endl;
  
    // finalize this measure
    this->
      finalizeMeasure (
        inputLineNumber,
        msrMeasure::kOverfullMeasure); // JMI see cadenzas
      
    // create a new measure
    newMeasure =
      msrMeasure::create (
        inputLineNumber,
        fMeasureNumber + 1,
        fMeasureDivisionsPerWholeNote,
        fMeasureSegmentUplink);

    // append it to the segment
    fMeasureSegmentUplink->
      appendMeasureToSegment (
        newMeasure);
  }

  return newMeasure;
}
  
void msrMeasure::appendBarlineToMeasure (S_msrBarline barline)
{
  /* JMI
  int inputLineNumber =
    barline->getInputLineNumber ();

  if (
    appendMeasureIfOverflow (inputLineNumber)
    ) {
    // a new measure has been appended to the segment
    // append barline to it thru the segment
    fMeasureSegmentUplink->
      appendBarlineToSegment (barline);
  }

  else
  */
  {
    // regular insertion in current measure
    // append the bar check to the measure elements list
    fMeasureElementsList.push_back (barline);
  }  
}

void msrMeasure::appendBarCheckToMeasure (S_msrBarCheck barCheck)
{
  // regular insertion in current measure
  // append the bar check to the measure elements list
  fMeasureElementsList.push_back (barCheck);
}

void msrMeasure::appendNoteToMeasure (S_msrNote note)
{
  int inputLineNumber =
    note->getInputLineNumber ();
    
  if (
    appendMeasureIfOverflow (inputLineNumber)
    ) {
    // a new measure has been appended to the segment
    // append note to it thru the segment
    fMeasureSegmentUplink->
      appendNoteToSegment (note);
  }

  else {
    // regular insertion in current measure
    
    // populate measure uplink
    note->setNoteMeasureUplink (this);

    // register note measure number
    note->setNoteMeasureNumber (fMeasureNumber);
    
    // register note measure position
    note->setNotePositionInMeasure (fMeasurePosition);
    
    // fetch note divisions
    int noteDivisions =
      note->getNoteDivisions ();
      
    // account for note duration in measure position
    fMeasurePosition += noteDivisions;
  
    // update part measure position high tide if need be
    fMeasurePartDirectUplink->
      updatePartMeasurePositionHighTide (
        inputLineNumber, fMeasurePosition);
  
    // determine if the note occupies a full measure
    if (noteDivisions == fMeasureDivisionsPerFullMeasure)
      note->setNoteOccupiesAFullMeasure ();
  
    // append the note to the measure elements list
  // JMI  // only now to make it possible to remove it afterwards
    // if it happens to be the first note of a chord
    fMeasureElementsList.push_back (note);

    // register note as the last one in this measure
    fMeasureLastHandledNote = note;
  }
}

void msrMeasure::appendChordToMeasure (S_msrChord chord) // XXL
{
  int inputLineNumber =
    chord->getInputLineNumber ();
    
  if (
    appendMeasureIfOverflow (inputLineNumber)
    ) {
    // a new measure has been appended to the segment
    // append chord to it thru the segment
    fMeasureSegmentUplink->
      appendChordToSegment (chord);
  }

  else {
    // regular insertion in current measure
    
//  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> appending chord '" << chord->chordAsString () <<
      "' to measure " << fMeasureNumber <<
      " in voice \"" <<
      fMeasureSegmentUplink->
        getSegmentVoiceUplink ()->
          getVoiceName () <<
      "\"" <<
      endl;
  
    // populate measure uplink
    chord->setChordMeasureUplink (this);

    // register chord measure number
    chord->
      setChordMeasureNumber (fMeasureNumber);
    
    // register chord measure position
    chord->
      setChordPositionInMeasure (
        fMeasurePosition);

    // copy measure number to first note, that was created beforehand
    chord->
      setChordFirstNoteMeasureNumber (
        fMeasureNumber);
    
    // copy measure position to first note, that was created beforehand
    chord->
      setChordFirstNotePositionInMeasure (
        fMeasurePosition);

    // fetch chord divisions
    int chordDivisions =
      chord->getChordDivisions ();
      
    // account for chord duration in measure position
    fMeasurePosition += chordDivisions;
  
    // update part measure position high tide if need be
    fMeasurePartDirectUplink->
      updatePartMeasurePositionHighTide (
        inputLineNumber, fMeasurePosition);
  
    // determine if the chord occupies a full measure
// XXL  JMI  if (chordDivisions == fMeasureDivisionsPerWholeMeasure)
      // chord->setChordOccupiesAFullMeasure ();
  
    // append the chord to the measure elements list
    fMeasureElementsList.push_back (chord);
  }
}

void msrMeasure::appendTupletToMeasure (S_msrTuplet tuplet)
{
  int inputLineNumber =
    tuplet->getInputLineNumber ();
    
  if (
    appendMeasureIfOverflow (inputLineNumber)
    ) {
    // a new measure has been appended to the segment
    // append tuplet to it thru the segment
    fMeasureSegmentUplink->
      appendTupletToSegment (tuplet);
  }

  else {
    // regular insertion in current measure
    
//  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> appending tuplet '" << tuplet->tupletAsString () <<
      "' to measure " << fMeasureNumber <<
      " in voice \"" <<
      fMeasureSegmentUplink->
        getSegmentVoiceUplink ()->
          getVoiceName () <<
      "\"" <<
      endl;
  
    // populate measure uplink
    tuplet->setTupletMeasureUplink (this);

    // register tuplet measure number
    tuplet->
      setTupletMeasureNumber (fMeasureNumber);
    
    // register tuplet measure position
    int dummy = // JMI
      tuplet->
        setTupletPositionInMeasure (fMeasurePosition);

/* JMI
    // copy measure number to first note, that was created beforehand
    tuplet->
      setTupletFirstNoteMeasureNumber (fMeasureNumber);
    
    // copy measure position to first note, that was created beforehand
    tuplet->
      setTupletFirstNotePositionInMeasure (fMeasurePosition);
   */
    
    // fetch tuplet divisions
    int tupletDivisions =
      tuplet->getTupletDivisions ();
      
    // account for tuplet duration in measure position
    fMeasurePosition += tupletDivisions;
  
    // set tuplet members' display divisions
    tuplet->
      applyDisplayFactorToTupletMembers ();

    // update part measure position high tide if need be
    fMeasurePartDirectUplink->
      updatePartMeasurePositionHighTide (
        inputLineNumber, fMeasurePosition);
  
    // determine if the tuplet occupies a full measure
// XXL    if (tupletDivisions == fMeasureDivisionsPerWholeMeasure)
      // tuplet->setTupletOccupiesAFullMeasure ();
  
    // append the tuplet to the measure elements list
    fMeasureElementsList.push_back (tuplet);
  }
}

void msrMeasure::appendGracenotesToMeasure (
  S_msrGracenotes gracenotes)
{
  fMeasureElementsList.push_back (gracenotes);
}
  
void msrMeasure::prependGracenotesToMeasure (
  S_msrGracenotes gracenotes)
{
  // in order to work around LilyPond issue 34,
  // we need to insert the skip grace notes
  // after clef, key and time signature if any

  for (
    list<S_msrElement>::iterator i = fMeasureElementsList.begin();
    i != fMeasureElementsList.end();
    i++ ) {

    if (
      S_msrClef clef = dynamic_cast<msrClef*>(&(**i))
      ) {
    }
  
    else if (
      S_msrKey key = dynamic_cast<msrKey*>(&(**i))
      ) {
    }
    
    else if (
      S_msrTime time = dynamic_cast<msrTime*>(&(**i))
      ) {
    }
    
    else {
       // insert gracenotes before (*i) in the list
      fMeasureElementsList.insert (
        i, gracenotes);

      break;
    }
  } // for
}
  
void msrMeasure::prependOtherElementToMeasure (S_msrElement elem)
{
  fMeasureElementsList.push_front (elem); // JMI
}

void msrMeasure::appendOtherElementToMeasure  (S_msrElement elem)
{
  fMeasureElementsList.push_back (elem);
}

void msrMeasure::removeFirstChordNoteFromMeasure (
  int       inputLineNumber,
  S_msrNote note)
{  
  if (true || gGeneralOptions->fDebug) {
//  if (gGeneralOptions->fDebug) {
    cerr << idtr <<
      "--> removing note:" <<
      endl;

    idtr++;
    cerr <<
      idtr <<
      note->noteAsShortString ();
    idtr--;
    
    cerr <<
      endl <<
      idtr <<
      " from measure '" << fMeasureNumber <<
      "' in voice \"" <<
      fMeasureSegmentUplink->
        getSegmentVoiceUplink ()->
          getVoiceName () <<
      "\"," <<
      endl;

    idtr++;
    cerr <<
      idtr <<
      "fMeasureLastHandledNote:" <<
      endl <<
      idtr <<
      fMeasureLastHandledNote <<
      endl;
    idtr--;
  }

  for (
    list<S_msrElement>::iterator i=fMeasureElementsList.begin();
    i!=fMeasureElementsList.end();
    ++i) {
    if ((*i) == note) {
      // found note, erase it
      fMeasureElementsList.erase (i);
      
      // dont update position in measure: // JMI
      // the chord will replace its first note

      // update position in measure
      fMeasurePosition -=
        fMeasureLastHandledNote->getNoteDivisions ();

      // return from function
      return;
    }
  } // for
  
  msrInternalError (
    inputLineNumber,
    "cannot remove note " <<
    note <<
    " from measure " << fMeasureNumber <<
    "' in voice \"" <<
    fMeasureSegmentUplink->
      getSegmentVoiceUplink ()->
        getVoiceName () <<
    "\"," <<
    " since it has not been found");
}

/*
S_msrElement msrMeasure::removeLastElementFromMeasure (
  int inputLineNumber)
{
  // fetching measure last element
  S_msrElement
    measureLastElement =
      fMeasureElementsList.back ();
      
  if (true || gGeneralOptions->fDebug) {
//  if (gGeneralOptions->fDebug) {
    cerr << idtr <<
      "--> removing last element:" <<
      endl;

    idtr++;
    cerr <<
      idtr <<
      measureLastElement;
    idtr--;
    
    cerr <<
      endl <<
      idtr <<
      " from measure '" <<
      fMeasureNumber <<
      "' in voice \"" <<
      fMeasureSegmentUplink->
        getSegmentVoiceUplink ()->
          getVoiceName () <<
      "\"," <<
      endl;

    idtr++;
    cerr <<
      idtr <<
      "fMeasureLastHandledNote:" <<
      endl <<
      idtr <<
      fMeasureLastHandledNote <<
      endl;
    idtr--;
  }
  
  if (fMeasureElementsList.size ()) {

    if (fMeasureLastHandledNote) {
      // there's at least a note in the meastuer
      
      if (fMeasureLastHandledNote == measureLastElement) {
        // remove last element
        fMeasureElementsList.pop_back ();

        // update position in measure
        fMeasurePosition -=
          fMeasureLastHandledNote->getNoteDivisions ();
/ *
// JMI
        // set note's measure position, needed for chord handling
        fMeasureLastHandledNote->
          setNotePositionInMeasure (fMeasurePosition);
* /
      }

      else {
        msrInternalError (
          inputLineNumber,
          "cannot removeLastElementFromMeasure () since "
          "fMeasureLastHandledNote is not the last element");
        }
    }

    else {
      msrInternalError (
        inputLineNumber,
        "cannot removeLastElementFromMeasure () since "
        "fMeasureLastHandledNote is null");
    }
  }
  
  else {
    msrInternalError (
      inputLineNumber,
      "cannot removeLastElementFromMeasure () "
      "since fMeasureElementsList is empty");
  }

  return measureLastElement;
}
*/

bool msrMeasure::checkForIncompleteMeasure (
  int                        inputLineNumber,
  msrMeasure::msrMeasureKind measureKind)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> checking for incompleteness of measure  " <<
      fMeasureNumber <<
      ", line " << inputLineNumber <<
      ", in voice \"" <<
      fMeasureSegmentUplink->
        getSegmentVoiceUplink ()->
          getVoiceName () <<
      "\"" <<
      endl;

  if (gGeneralOptions->fDebug) {
    idtr++;

    cerr <<
      idtr <<
        setw(38) << "MeasureDivisionsPerFullMeasure" << " = " <<
        fMeasureDivisionsPerFullMeasure <<
        endl <<
      idtr <<
        setw(38) << "MeasurePosition" << " = " <<
        fMeasurePosition <<
        endl <<
      idtr <<
        setw(38) << "MeasureLength" << " = " <<
        getMeasureLength () <<
        endl;

    idtr--;
  }

  bool measureIsIncomplete =
    // positions start at 1
    fMeasurePosition <= fMeasureDivisionsPerFullMeasure;

  if (measureIsIncomplete) {    
    if (gGeneralOptions->fTrace) {
      cerr <<
        idtr <<
          "Measure " << fMeasureNumber <<
          " of segment " <<
          fMeasureSegmentUplink->segmentAsString () <<
          " in voice \"" <<
          fMeasureSegmentUplink->
            getSegmentVoiceUplink ()->
              getVoiceName () <<
          "\"" <<
          " is " <<
          string(
            fMeasurePosition == 1
              ? "incomplete"
              : "empty") <<
          ", line " << inputLineNumber <<
          ": position = " << fMeasurePosition <<
          ", divisionsPerWholeMeasure = " <<
          fMeasureDivisionsPerFullMeasure <<
        endl;
    }
    
    // set measure kind
    setMeasureKind (
      measureKind);
  }

  return measureIsIncomplete;
}

void msrMeasure::finalizeMeasure (
  int                        inputLineNumber,
  msrMeasure::msrMeasureKind measureKind)
{
  // fetch the voice
  S_msrVoice
    voice =
      fMeasureSegmentUplink->
        getSegmentVoiceUplink ();
    
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug)
    cerr <<
      idtr <<
      "### --> finalizing measure " << fMeasureNumber <<
      " in voice \"" << voice->getVoiceName () <<
      "\", line " << inputLineNumber <<
      endl;

  int partMeasurePositionHighTide =
    fMeasurePartDirectUplink->
      getPartMeasurePositionHighTide ();
    
  if (fMeasurePosition < partMeasurePositionHighTide) {
    // appending a skip to this measure to reach measurePosition
    int skipDuration =
      partMeasurePositionHighTide - fMeasurePosition;

    // create the skip
    S_msrNote
      skip =
        msrNote::createSkipNote (
          inputLineNumber,
          skipDuration,
          fMeasureSegmentUplink->
            getSegmentDivisionsPerWholeNote (),
          voice->
            getVoiceStaffUplink ()->getStaffNumber (),
          voice->
            getExternalVoiceNumber ());

    // does the skip occupy a full measure?
    if (skipDuration == fMeasureDivisionsPerFullMeasure)
      skip->setNoteOccupiesAFullMeasure ();
  
    // register skip's measure position
    skip->setNotePositionInMeasure (fMeasurePosition);
    
    // apppend the skip to the measure
    if (gGeneralOptions->fDebug)
      cerr << idtr <<
       "--> appending " << skip->noteAsString () <<
       " (" << skipDuration <<
       " divs.) to finalize \"" << voice->getVoiceName () <<
       "\" measure: @" << fMeasureNumber << ":" << fMeasurePosition <<
       " --> @" << fMeasureNumber <<
       ":" << partMeasurePositionHighTide <<
       endl;
       
    // append the skip to the measure elements list
    // only now to make it possible to remove it afterwards
    // if it happens to be the first note of a chord
    appendNoteToMeasure (skip);

    // account for skip duration in measure position
    fMeasurePosition += skipDuration;
  }

  // CAUTION JMI : this is a potential incomplete measure
  bool measureIsIncomplete =
    checkForIncompleteMeasure (
      inputLineNumber,
      measureKind);

  if (measureIsIncomplete)
    if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug)
      cerr << idtr <<
      "### --> measure " << fMeasureNumber <<
      " in voice \"" << voice->getVoiceName () <<
      "\", line " << inputLineNumber <<
      " is incomplete" <<
      endl;
}

void msrMeasure::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrMeasure::acceptIn()" << endl;
      
  if (visitor<S_msrMeasure>*
    p =
      dynamic_cast<visitor<S_msrMeasure>*> (v)) {
        S_msrMeasure elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrMeasure::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrMeasure::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrMeasure::acceptOut()" << endl;

  if (visitor<S_msrMeasure>*
    p =
      dynamic_cast<visitor<S_msrMeasure>*> (v)) {
        S_msrMeasure elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrMeasure::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrMeasure::browseData (basevisitor* v)
{
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrMeasure::browseData()" << endl;

  for (
    list<S_msrElement>::iterator i = fMeasureElementsList.begin();
    i != fMeasureElementsList.end();
    i++) {
    // browse the element
    msrBrowser<msrElement> browser (v);
    browser.browse (*(*i));
  } // for

  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "<== msrMeasure::browseData()" << endl;
}

ostream& operator<< (ostream& os, const S_msrMeasure& elt)
{
  elt->print (os);
  return os;
}

string msrMeasure::getMeasureLengthAsString () const
{
  string result;
  string errorMessage;

  int
    measureLength =
      this->getMeasureLength (); 
  
  if (gGeneralOptions->fDebug)
    cerr <<
      endl <<
      idtr <<
        "% --> measure " << fMeasureNumber <<
        ", measureLength = " << measureLength <<
        ", measureDivisionsPerWholeNote = " <<
        fMeasureDivisionsPerWholeNote <<
        ", fMeasureDivisionsPerFullMeasure = " <<
        fMeasureDivisionsPerFullMeasure <<
      endl;

  if (measureLength > 0) {
    result =
      divisionsAsMSRDuration (
        measureLength,
        fMeasureDivisionsPerWholeNote,
        errorMessage,
        false); // 'true' to debug it;
  
    if (errorMessage.size ())
      msrMusicXMLError (
        fInputLineNumber,
        errorMessage);
  }
  
  else
    result = "0";

  if (gGeneralOptions->fDebug)
    cerr <<
      endl <<
      idtr <<
      "%--> result = " << result <<
      endl;

  return result;
}

string msrMeasure::getMeasureKindAsString () const
{
  string result;

  switch (fMeasureKind) {
    case kRegularMeasure:
      result = "regular";
      break;
    case kIncompleteLeftMeasure:
      result = "incomplete left";
      break;
    case kIncompleteRightMeasure:
      result = "incomplete right";
      break;
    case kOverfullMeasure:
      result = "over full";
      break;
  } // switch

  return result;
}

void msrMeasure::print (ostream& os)
{
  os <<
    endl <<
    idtr << "Measure " << fMeasureNumber <<
      ", line " << fInputLineNumber <<
/*
      ", voice " <<
      fMeasureSegmentUplink->getVoiceUplink ()->getVoiceName () <<
*/
      ", " << fMeasureTime->timeAsString () <<
      ", len: " << getMeasureLength () <<
      " (" << getMeasureLengthAsString () << ")" <<
      ", dpfm:" << fMeasureDivisionsPerFullMeasure <<
      ", dpwn:" << fMeasureDivisionsPerWholeNote <<
      ", pos: " << fMeasurePosition << 
      ", " <<
      singularOrPlural (
        fMeasureElementsList.size (), "elem", "elems") <<
      ", " << getMeasureKindAsString () <<
    endl;

  idtr++;
    
  os <<
    idtr << "Elements:";
  
  if (! fMeasureElementsList.size ())
    os << " none";
    
  else {
    os << endl;
    idtr++;
    
    list<S_msrElement>::const_iterator
      iBegin = fMeasureElementsList.begin(),
      iEnd   = fMeasureElementsList.end(),
      i      = iBegin;
    for ( ; ; ) {
      os << idtr << (*i);
      if (++i == iEnd) break;
  // JMI    os << endl;
    } // for
    
    idtr--;
  }
//  os << endl; JMI
    
  idtr--;
}

//______________________________________________________________________________
int msrSegment::gSegmentsCounter = 0;

S_msrSegment msrSegment::create (
  int        inputLineNumber,
  int        divisionsPerWholeNote,
  S_msrVoice segmentVoicekUplink)
{
  msrSegment* o =
    new msrSegment (
      inputLineNumber,
      divisionsPerWholeNote,
      segmentVoicekUplink);
  assert(o!=0);
  return o;
}

msrSegment::msrSegment (
  int        inputLineNumber,
  int        divisionsPerWholeNote,
  S_msrVoice segmentVoicekUplink)
    : msrElement (inputLineNumber)
{
  fSegmentAbsoluteNumber = ++gSegmentsCounter;
  
  fSegmentVoicekUplink = segmentVoicekUplink;

  fSegmentDivisionsPerWholeNote =
    divisionsPerWholeNote;
    /*
    fSegmentVoicekUplink->
      getVoiceDivisionsPerWholeNote ();
*/

  fSegmentTime =
    fSegmentVoicekUplink->
      getVoiceTime ();


//  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> new segment gets absolute number " <<
      fSegmentAbsoluteNumber <<
      endl;

  if (! fSegmentTime) {
    // use the implicit initial 4/4 time signature
    fSegmentTime =
      msrTime::create (
        fInputLineNumber,
        4, 4);
  }

  // has measure number 0 been met?
  bool measureZeroHasBeenMet = // JMI
    fSegmentVoicekUplink->
      getVoiceStaffUplink ()->
        getStaffPartUplink ()->
          getMeasureZeroHasBeenMetInPart ();

  // first measure number
  int firstMeasureNumber =
    measureZeroHasBeenMet
      ? 0
      : 1;

  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug)
    cerr <<
      idtr <<
        "--> Creating segment " << segmentAsString () <<
        "'s first measure with number " <<
        firstMeasureNumber <<
        ", fSegmentDivisionsPerWholeNote = " << fSegmentDivisionsPerWholeNote <<
        ", in voice \"" << fSegmentVoicekUplink->getVoiceName () << "\"" <<
        endl;

  // create a first measure
  // fSegmentDivisionsPerWholeNote may be 0 though JMI ???
  S_msrMeasure
    measure =
      msrMeasure::create (
        inputLineNumber,
        firstMeasureNumber,
        fSegmentDivisionsPerWholeNote,
        this);

  // set the measure clef, key and time if any
  /* JMI
  measure->setMeasureClef (
    lastMeasure->getMeasureClef ());
  measure->setMeasureKey (
    lastMeasure->getMeasureKey ());
    */
  measure->
    setMeasureTime (
      fSegmentTime);
        
  // append the measure to the segment
  appendMeasureToSegment (measure);

  fMeasureNumberHasBeenSetInSegment = false;
}

msrSegment::~msrSegment() {}

S_msrSegment msrSegment::createSegmentBareClone (
  S_msrVoice clonedVoice)
{
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> Creating a bare clone of segment " <<
      segmentAsString () <<
      endl;

  S_msrSegment
    clone =
      msrSegment::create (
        fInputLineNumber,
        fSegmentDivisionsPerWholeNote,
        clonedVoice);

  clone->fSegmentTime =
    fSegmentTime;

    /* JMI
  clone->fSegmentDivisionsPerWholeNote =
    fSegmentDivisionsPerWholeNote;
*/

  // remove the initial measure created implicitly
  fSegmentMeasuresList.clear ();
  
  return clone;
}

void msrSegment::setSegmentDivisionsPerWholeNote (
  int divisionsPerWholeNote)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> setting segment " << segmentAsString () <<
        "'s divisions per whole note to " <<
      divisionsPerWholeNote <<
      endl;

  fSegmentDivisionsPerWholeNote =
    divisionsPerWholeNote;

  setAllSegmentMeasuresDivisionsPerWholeNote (
    divisionsPerWholeNote);
}

void msrSegment::setAllSegmentMeasuresDivisionsPerWholeNote (
  int divisionsPerWholeNote)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> setAllSegmentMeasuresDivisionsPerWholeNote()" <<
      ", line " << fInputLineNumber <<
      ", divisionsPerWholeNote = " << divisionsPerWholeNote <<
      ", in segment " << fSegmentAbsoluteNumber <<
      endl;

  for (
    list<S_msrMeasure>::iterator i = fSegmentMeasuresList.begin();
    i != fSegmentMeasuresList.end();
    i++) {
    (*i)->
      setMeasureDivisionsPerWholeNote (
        divisionsPerWholeNote);
  } // for
}

bool msrSegment::checkForIncompleteSegmentLastMeasure (
  int                        inputLineNumber,
  msrMeasure::msrMeasureKind measureKind)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> checking for incomplete last measure in segment '" <<
      segmentAsString () <<
      "', line " << inputLineNumber <<
      ", in voice \"" <<
      fSegmentVoicekUplink->
        getVoiceName () <<
      "\"" <<
      endl;

  // fetch segment last measure
  S_msrMeasure
    lastMeasure =
      fSegmentMeasuresList.back ();

  return
    lastMeasure->
      checkForIncompleteMeasure (
        inputLineNumber,
        measureKind);
        
/* JMI
  // fetch its last measure position and length
  int
    lastMeasureNumber =
      lastMeasure->
        getMeasureNumber (),
        
    lastMeasurePosition =
      lastMeasure->
        getMeasurePosition (),
      
    lastMeasureLength =
      lastMeasure->
        getMeasureLength (),
      
    lastMeasureDivisionsPerFullMeasure =
      lastMeasure->
        getMeasureDivisionsPerFullMeasure ();
        
 // JMI if (true || gGeneralOptions->fDebug) {
  if (gGeneralOptions->fDebug) {
    idtr++;

    cerr <<
      idtr <<
        setw(38) << "lastMeasureNumber" << " = " <<
        lastMeasureNumber <<
        endl <<
      idtr <<
        setw(38) << "lastMeasureDivisionsPerFullMeasure" << " = " <<
        lastMeasureDivisionsPerFullMeasure <<
        endl <<
      idtr <<
        setw(38) << "lastMeasurePosition" << " = " <<
        lastMeasurePosition <<
        endl <<
      idtr <<
        setw(38) << "lastMeasureLength" << " = " <<
        lastMeasureLength <<
        endl;

    idtr--;
  }

  bool lastMeasureIsIncomplete =
    // is the last measure full? (positions start at 1)
    lastMeasurePosition <= lastMeasureDivisionsPerFullMeasure;

  if (lastMeasureIsIncomplete) {    
    if (gGeneralOptions->fTrace) {
      cerr <<
        idtr <<
          "Measure " << lastMeasureNumber <<
          " of segment " << segmentAsString () <<
          " in voice \"" <<
          getSegmentVoiceUplink ()->getVoiceName () << "\"" <<
          " is " <<
          string(
            lastMeasurePosition == 1
              ? "incomplete"
              : "empty") <<
          ", line " << inputLineNumber <<
          ": position = " << lastMeasurePosition <<
          ", divisionsPerWholeMeasure = " <<
          lastMeasureDivisionsPerFullMeasure <<
        endl;
    }
    
    // set measure kind
    lastMeasure->
      setMeasureKind (
        measureKind);
  }

  return lastMeasureIsIncomplete;
  */
}

void msrSegment::setSegmentMeasureNumber (
  int inputLineNumber,
  int measureNumber)
{
  msrMeasure::msrMeasureKind measureKind;
  
  if (fSegmentMeasuresList.size () == 1) {
    // this is the first measure in the segment
    measureKind =
      msrMeasure::kIncompleteLeftMeasure;
  }
  
  else {
    // this is the last measure in the segment
    measureKind =
      msrMeasure::kIncompleteRightMeasure;
  }

  checkForIncompleteSegmentLastMeasure (
    inputLineNumber,
    measureKind);

  // fetch segment last measure
  S_msrMeasure
    lastMeasure =
      fSegmentMeasuresList.back ();

  /* JMI
  // fetch its last measure position and length
  int
    lastMeasureNumber =
      lastMeasure->
        getMeasureNumber (),
        
    lastMeasurePosition =
      lastMeasure->
        getMeasurePosition (),
      
    lastMeasureLength =
      lastMeasure->
        getMeasureLength (),
      
    lastMeasureDivisionsPerFullMeasure =
      lastMeasure->
        getMeasureDivisionsPerFullMeasure ();

/ * JMI
  msrMeasure::msrMeasureKind
    lastMeasureKind =
      lastMeasure->
        getMeasureKind ();
* /
        
 // JMI if (true || gGeneralOptions->fDebug) {
  if (gGeneralOptions->fDebug) {
    cerr <<
      idtr <<
        setw(38) << "--> setSegmentMeasureNumber (" <<
        measureNumber <<
        ") for segment " << segmentAsString () <<
        endl;

    idtr++;

    cerr <<
      idtr <<
        setw(38) << "lastMeasureNumber" << " = " <<
        lastMeasureNumber <<
        endl <<
      idtr <<
        setw(38) << "lastMeasureDivisionsPerFullMeasure" << " = " <<
        lastMeasureDivisionsPerFullMeasure <<
        endl <<
      idtr <<
        setw(38) << "lastMeasurePosition" << " = " <<
        lastMeasurePosition <<
        endl <<
      idtr <<
        setw(38) << "lastMeasureLength" << " = " <<
        lastMeasureLength <<
        endl;

    idtr--;
  }
      
  // is the last measure full? (positions start at 1)
  if (lastMeasurePosition <= lastMeasureDivisionsPerFullMeasure) {
    // no, register last measure as incomplete
    
    if (gGeneralOptions->fTrace) {
      cerr <<
        idtr <<
          "Measure " << measureNumber <<
          " of segment " << fSegmentAbsoluteNumber <<
          " in voice \"" <<
          getSegmentVoiceUplink ()->getVoiceName () << "\"" <<
          " is " <<
          string(
            lastMeasurePosition == 1
              ? "incomplete"
              : "empty") <<
          ", line " << inputLineNumber <<
          ": position = " << lastMeasurePosition <<
          ", divisionsPerWholeMeasure = " <<
          lastMeasureDivisionsPerFullMeasure <<
        endl;
    }
    
    if (fSegmentMeasuresList.size () == 1) {
      // this is the first measure in the segment
      lastMeasure->
        setMeasureKind (
          msrMeasure::kIncompleteLeftMeasure);
    }
    
    else {
      // this is the last measure in the segment
      lastMeasure->
        setMeasureKind (
          msrMeasure::kIncompleteRightMeasure);
    }
  }
  
  else {
    // yes, last measure is full JMI
  }

  */
  
  fSegmentMeasureNumber = measureNumber; // JMI

  bool doCreateAMeasure = false;
              
  switch (measureNumber) {
    case 0:
      // measure 1 has already been created by default, re-number it a 0
      if (gGeneralOptions->fDebug)
        cerr <<
          idtr <<
            "### there are currently " <<
            fSegmentMeasuresList.size () <<
            " measures in segment " << segmentAsString () <<
            endl <<
          idtr <<
            setw(31) << "--> renumbering measure 1 as 0" <<
            endl;
  
      lastMeasure->
        setMeasureNumber (0);
        
      doCreateAMeasure = false;    
      break;

    case 1:
      if (lastMeasure->getMeasureNumber () == 0) {
        // this is the second measure, that should be created
        if (gGeneralOptions->fDebug)
          cerr <<
            idtr <<
              "### there are currently " <<
              fSegmentMeasuresList.size () <<
            " measures in segment " << segmentAsString () <<
              endl <<
            idtr <<
              setw(31) <<
                "--> measure 1 found after measure 0, "
                "a new measure is being created" <<
              endl;
              
        doCreateAMeasure = true;
      }
      else {
        // measure 1 has already been created by default
      }
      break;
      
    default:
      if (gGeneralOptions->fDebug)
        cerr <<
          idtr <<
            "### there are currently " <<
            fSegmentMeasuresList.size () <<
            " measures in segment " << segmentAsString () <<
            endl <<
          idtr <<
            setw(31) <<
              "--> measure " << measureNumber <<
              " found, a new measure is being created" <<
            endl;
              
      doCreateAMeasure = true;    
  } // switch

  if (doCreateAMeasure) {
    // finalize last measure
    lastMeasure->
      finalizeMeasure (
        inputLineNumber,
        measureKind);
      
    // create a new measure
    S_msrMeasure
      newMeasure =
        msrMeasure::create (
          inputLineNumber,
          measureNumber,
          fSegmentDivisionsPerWholeNote,
          this);
  
    // append it to the segment's measures list
    fSegmentMeasuresList.push_back (
      newMeasure);
  }
  
  fMeasureNumberHasBeenSetInSegment = true;
}

void msrSegment::forceSegmentMeasureNumberTo (int measureNumber) // JMI
{
  fSegmentMeasureNumber = measureNumber;

  if (fSegmentMeasuresList.size ()) {
    fSegmentMeasuresList.back ()->
      setMeasureNumber (measureNumber);
  }
};

void msrSegment::incrementSegmentLastMeasureNumber (
  int inputLineNumber)
{
  if (fSegmentMeasuresList.size ()) {
    fSegmentMeasuresList.back ()->
      incrementMeasureNumber ();
  }

  else {
    stringstream s;

    s <<
      "segment " << fSegmentAbsoluteNumber <<
      " contains no measure," <<
      endl <<
      " cannot increment the absolute number of its last measure";

    msrInternalError (
      inputLineNumber,
      s.str());
  }
};

void msrSegment::finalizeLastMeasureOfSegment (int inputLineNumber)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "### --> finalizing last measure in segment " <<
      segmentAsString () <<
      ", line " << inputLineNumber <<
      endl;

  fSegmentMeasuresList.back ()->
    finalizeMeasure (
      inputLineNumber,
      msrMeasure::kIncompleteRightMeasure);
}

void msrSegment::appendClefToSegment (S_msrClef clef)
{
  if (gGeneralOptions->fDebug)
    cerr <<
      idtr <<
        "--> appending clef " << clef->clefAsString () <<
        " to segment " << segmentAsString () <<
        endl;
      
  // register clef in segment
// JMI  fSegmentClef = clef;

  // register clef in segments's current measure
  fSegmentMeasuresList.back ()->
    setMeasureClef (clef);
    
  // append it to this segment
  appendOtherElementToSegment (clef);
}

void msrSegment::appendKeyToSegment (S_msrKey key)
{
  if (gGeneralOptions->fDebug)
    cerr <<
      idtr <<
        "--> appending key " << key->keyAsString () <<
        " to segment " << segmentAsString () <<
        endl;
      
  // register key in segment
// JMI  fSegmentKey = key;

  // register key in segments's current measure
  fSegmentMeasuresList.back ()->
    setMeasureKey (key);
    
  // append it to this segment
  appendOtherElementToSegment (key);
}
    
void msrSegment::appendTimeToSegment (S_msrTime time)
{
  if (gGeneralOptions->fDebug)
    cerr <<
      idtr <<
        "--> appending time " << time->timeAsString () <<
        " to segment " << segmentAsString () <<
        endl;
      
  // register time in segment
  fSegmentTime = time;

  // register time in segments's current measure
  fSegmentMeasuresList.back ()->
    setMeasureTime (time);
    
  // append it to this segment
  appendOtherElementToSegment (time);
}

void msrSegment::appendHarmonyToSegment (S_msrHarmony harmony)
{
  if (gGeneralOptions->fDebug)
    cerr <<
      idtr <<
        "--> appending harmony " << harmony->harmonyAsString () <<
        " to segment " << segmentAsString () <<
        endl;
      
  // append it to this segment
  appendOtherElementToSegment (harmony);
}

void msrSegment::appendMeasureToSegment (S_msrMeasure measure)
{
  bool doAppendMeasure = true;
  
  if (fSegmentMeasuresList.size ()) {

    int inputLineNumber =
      measure-> getInputLineNumber ();
      
    S_msrMeasure
      lastMeasure =
        fSegmentMeasuresList.back ();

    int
      measureNumber =
        measure->getMeasureNumber (),
      lastMeasureNumber =
        lastMeasure->getMeasureNumber ();

    if (gGeneralOptions->fDebug)
      cerr << idtr <<
        "### --> appendMeasureToSegment (" << measureNumber <<
        ") in segment " << segmentAsString () <<
        ", lastMeasureNumber = " << lastMeasureNumber <<
        ", line " << inputLineNumber <<
        endl;
      
// JMI    if (lastMeasureNumber == measureNumber) {
    if (lastMeasureNumber == 1 && measureNumber == 1) {
      // don't append measure 1 if it is already present

      if (gGeneralOptions->fDebug)
        cerr << idtr <<
          "### --> replacing initial measure 1 of segment " <<
          segmentAsString () <<
        " by new one" <<
          ", line " << inputLineNumber <<
          endl;

      // fetch lastMeasure clef, key and time if any
      measure->setMeasureClef (
        lastMeasure->getMeasureClef ());
      measure->setMeasureKey (
        lastMeasure->getMeasureKey ());
      measure->setMeasureTime (
        lastMeasure->getMeasureTime ());

      // remove previous measure with same number XXL
      fSegmentMeasuresList.pop_back ();
    }
    
    else if (lastMeasureNumber == 1 && measureNumber == 0) {
      // remove initial measure 1

      if (gGeneralOptions->fDebug)
        cerr << idtr <<
          "### --> replacing initial measure 1 of segment " <<
          segmentAsString () <<
          " by measure 0" <<
          ", line " << inputLineNumber <<
          endl;

      fSegmentMeasuresList.pop_back ();
    }

    else if (lastMeasureNumber == measureNumber) {
      
   //   if (lastMeasure->getMeasureElementsList ().size ()) {
        // keep existing measure, since it's empty
        if (gGeneralOptions->fDebug)
          cerr << idtr <<
            "### --> keeping measure " << lastMeasureNumber <<
            " of segment " << segmentAsString () <<
            " that already exists" <<
            ", line " << inputLineNumber <<
            endl;

      // fetch measure clef, key and time if any
      lastMeasure->setMeasureClef (
        measure->getMeasureClef ());
      lastMeasure->setMeasureKey (
        measure->getMeasureKey ());
      lastMeasure->setMeasureTime (
        measure->getMeasureTime ());

      // use new measure's input line number for existing one
      lastMeasure->
        forceMeasureInputLineNumber (inputLineNumber);
        
      doAppendMeasure = false;
//      // remove previous measure with same number XXL
 // JMI     fSegmentMeasuresList.pop_back ();
 /*
      }
      
      else {
        stringstream s;

        s <<
          "measure " << measureNumber <<
          " already exists and is not empty" <<
          " cannot append it to segment " <<
          fSegmentAbsoluteNumber;

        msrInternalError (
          inputLineNumber,
          s.str());
      }
    */
    }
  }

  if (doAppendMeasure)
    // append measure to the segment
    fSegmentMeasuresList.push_back (measure);
}

void msrSegment::appendMeasureToSegmentIfNeeded ( // JMI
  int inputLineNumber,
  int measureNumber)
{
  /*
  if (! fSegmentMeasuresList.size ()) {
    // create a new measure
    S_msrMeasure
      newMeasure =
        msrMeasure::create (
          inputLineNumber,
          measureNumber,
          fSegmentDivisionsPerWholeNote,
          this);

    // append it to the segment
    appendMeasureToSegment (
      newMeasure);
  }
  */
}

void msrSegment::prependBarlineToSegment (S_msrBarline barline)
{
  if (gGeneralOptions->fDebug)
    cerr <<
      idtr <<
        "--> prepending barline '" << barline->barlineAsString () <<
        "' to segment '" << segmentAsString () << "'" <<
      endl;

  fSegmentMeasuresList.front ()->
    prependOtherElementToMeasure (barline);
}

void msrSegment::appendBarlineToSegment (S_msrBarline barline)
{
  if (gGeneralOptions->fDebug)
    cerr <<
      idtr <<
        "--> appending barline '" << barline->barlineAsString () <<
        "' to segment '" << segmentAsString () << "'" <<
      endl;

  if (! fSegmentMeasuresList.size ()) {// JMI
  }
  
  fSegmentMeasuresList.back ()->
    appendBarlineToMeasure (barline);
}

void msrSegment::appendBarCheckToSegment (S_msrBarCheck barCheck)
{
  if (gGeneralOptions->fDebug)
    cerr <<
      idtr <<
        "--> appending bar check " << barCheck->barCheckAsString () <<
        " to segment '" << segmentAsString () << "'" <<
      endl;
      
  fSegmentMeasuresList.back ()->
    appendBarCheckToMeasure (barCheck);
}

void msrSegment::appendNoteToSegment (S_msrNote note)
{
  fSegmentMeasuresList.back ()->
    appendNoteToMeasure (note);
}

void msrSegment::appendChordToSegment (S_msrChord chord) // XXL
{
  fSegmentMeasuresList.back ()->
    appendChordToMeasure (chord);
}

void msrSegment::appendTupletToSegment (S_msrTuplet tuplet) // XXL
{
  fSegmentMeasuresList.back ()->
    appendTupletToMeasure (tuplet);
}

void msrSegment::appendGracenotesToSegment (
  S_msrGracenotes gracenotes)
{
  fSegmentMeasuresList.back ()->
    appendGracenotesToMeasure (gracenotes);
}

void msrSegment::prependGracenotesToSegment (
  S_msrGracenotes gracenotes)

{
  fSegmentMeasuresList.front ()->
    prependGracenotesToMeasure (gracenotes); // JMI
}

void msrSegment::appendOtherElementToSegment (S_msrElement elem)
{
  /*
  appendMeasureToSegmentIfNeeded ( // JMI
    elem->getInputLineNumber (),
    fSegmentMeasureNumber + 1);
  */
  
  fSegmentMeasuresList.back ()->
    appendOtherElementToMeasure (elem);
}

/* JMI
void msrSegment::removeElementFromSegment (
  S_msrElement elem)
{
  for (
    list<S_msrElement>::iterator i = fSegmentMeasuresList.begin();
    i != fSegmentMeasuresList.end();
    i++) {
    if ((*i) == elem) {
      fSegmentMeasuresList.erase (i);
      break;
    }
  } // for
}
*/

/*
S_msrElement msrSegment::removeLastElementFromSegment (
  int inputLineNumber)
{
  // this last element can be a note or a tuplet,
  // this method is used when the seconde note of a chord is mest
  
  if (fSegmentMeasuresList.size ()) {
    return
      fSegmentMeasuresList.back ()->
        removeLastElementFromMeasure (
          inputLineNumber);
  }
  
  else {
    msrInternalError (
      inputLineNumber,
      "cannot removeLastElementFromSegment () " <<
      segmentAsString () <<
      " since it is empty");
  }
}
*/

void msrSegment::removeFirstChordNoteFromSegment (
  int       inputLineNumber,
  S_msrNote note)
{  
  if (fSegmentMeasuresList.size ()) {
    fSegmentMeasuresList.back ()->
      removeFirstChordNoteFromMeasure (
        inputLineNumber,
        note);
  }
  
  else {
    msrInternalError (
      inputLineNumber,
      "cannot removeFirstChordNoteFromSegment () " <<
      segmentAsString () <<
      " since it is empty");
  }
}

void msrSegment::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrSegment::acceptIn()" << endl;
      
  if (visitor<S_msrSegment>*
    p =
      dynamic_cast<visitor<S_msrSegment>*> (v)) {
        S_msrSegment elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrSegment::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrSegment::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrSegment::acceptOut()" << endl;

  if (visitor<S_msrSegment>*
    p =
      dynamic_cast<visitor<S_msrSegment>*> (v)) {
        S_msrSegment elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrSegment::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrSegment::browseData (basevisitor* v)
{
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrSegment::browseData()" << endl;

  for (
    list<S_msrMeasure>::iterator i = fSegmentMeasuresList.begin();
    i != fSegmentMeasuresList.end();
    i++) {
    // browse the element
    msrBrowser<msrMeasure> browser (v);
    browser.browse (*(*i));
  } // for

  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "<== msrSegment::browseData()" << endl;
}

string msrSegment::segmentAsString ()
{
  stringstream s;

  s << "Segment " << fSegmentAbsoluteNumber;
  
  if (! fSegmentMeasuresList.size ())
    s <<
      " (No actual measures)";
  else
    s <<
      " (" <<
      singularOrPlural (
        fSegmentMeasuresList.size (), "measure", " measures)");

  return s.str();
}

ostream& operator<< (ostream& os, const S_msrSegment& elt)
{
  elt->print (os);
  return os;
}

void msrSegment::print (ostream& os)
{  
  os << idtr <<
    "Segment " << fSegmentAbsoluteNumber <<
    " (" <<
    singularOrPlural (
      fSegmentMeasuresList.size(), "measure", "measures") <<
    ")" <<
    endl;

  idtr++;

  if (! fSegmentTime) {
    // use the implicit initial 4/4 time signature
    fSegmentTime =
      msrTime::create (
        fInputLineNumber,
        4, 4);
  }

  os <<
    idtr <<
      setw(32) << "(SegmentDivisionsPerWholeNote" << " = " <<
      fSegmentDivisionsPerWholeNote << ")" <<
      endl <<
    idtr <<
      setw(32) << "(fSegmentTime" << " = " <<
      fSegmentTime->timeAsString () << ")" <<
      endl;

  os <<
    idtr << "Measures:";
  
  if (! fSegmentMeasuresList.size ())
    os << " none";
    
  else {    
 //   os << endl;
    idtr++;
    
    list<S_msrMeasure>::const_iterator
      iBegin = fSegmentMeasuresList.begin(),
      iEnd   = fSegmentMeasuresList.end(),
      i      = iBegin;
    for ( ; ; ) {
      os << idtr << (*i);
      if (++i == iEnd) break;
  // JMI    os << endl;
    } // for
    
  idtr--;
  }

  os << endl;
  
  idtr--;
}

//______________________________________________________________________________
S_msrRepeatending msrRepeatending::create (
  int                 inputLineNumber,
  string              repeatendingNumber, // may be "1, 2"
  msrRepeatendingKind repeatendingKind,
  S_msrSegment        segment,
  S_msrRepeat         repeatUplink)
{
  msrRepeatending* o =
    new msrRepeatending (
      inputLineNumber,
      repeatendingNumber,
      repeatendingKind,
      segment,
      repeatUplink);
  assert(o!=0);
  return o;
}

msrRepeatending::msrRepeatending (
  int                 inputLineNumber,
  string              repeatendingNumber, // may be "1, 2"
  msrRepeatendingKind repeatendingKind,
  S_msrSegment        segment,
  S_msrRepeat         repeatUplink)
    : msrElement (inputLineNumber)
{
  fRepeatendingNumber = repeatendingNumber;
  
  fRepeatendingInternalNumber = 0;
    // will be set by msrRepeat::addRepeatending ()
  
  fRepeatendingKind = repeatendingKind;
  
  fRepeatendingSegment = segment;
  
  fRepeatendingRepeatUplink = repeatUplink;
}

msrRepeatending::~msrRepeatending() {}

S_msrRepeatending msrRepeatending::createRepeatendingBareClone (
  S_msrRepeat clonedRepeat)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> Creating a bare clone of a repeat ending" << endl;
  
  S_msrRepeatending
    clone =
      msrRepeatending::create (
        fInputLineNumber,
        fRepeatendingNumber,
        fRepeatendingKind,
        clonedRepeat->getRepeatCommonSegment (), // JMI
        clonedRepeat);
  
  return clone;
}

void msrRepeatending::appendElementToRepeatending (
  S_msrElement elem) // JMI ???
{
  fRepeatendingSegment->
    appendOtherElementToSegment (elem);
}

void msrRepeatending::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrRepeatending::acceptIn()" << endl;
      
  if (visitor<S_msrRepeatending>*
    p =
      dynamic_cast<visitor<S_msrRepeatending>*> (v)) {
        S_msrRepeatending elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrRepeatending::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrRepeatending::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrRepeatending::acceptOut()" << endl;

  if (visitor<S_msrRepeatending>*
    p =
      dynamic_cast<visitor<S_msrRepeatending>*> (v)) {
        S_msrRepeatending elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrRepeatending::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrRepeatending::browseData (basevisitor* v)
{
  // browse the segment
  msrBrowser<msrSegment> browser (v);
  browser.browse (*fRepeatendingSegment);
}

ostream& operator<< (ostream& os, const S_msrRepeatending& elt)
{
  elt->print (os);
  return os;
}

string msrRepeatending::repeatendingKindAsString (
  msrRepeatendingKind repeatendingKind)
{
  string result;
  
  switch (repeatendingKind) {
    case msrRepeatending::kHookedEnding:
      result = "hooked";
      break;
    case msrRepeatending::kHooklessEnding:
      result = "hookless";
      break;
  } // switch
  
  return result;
}

string msrRepeatending::repeatendingAsString () const
{
  stringstream s;

  s <<
   "Repeatending" <<
    ", line " << fInputLineNumber <<
    ", number " << fRepeatendingNumber <<
    ", internal number " << fRepeatendingInternalNumber <<
    ", " << repeatendingKindAsString (fRepeatendingKind) <<
    endl;

  return s.str();
}

void msrRepeatending::print (ostream& os)
{
  os <<
    endl <<
    idtr << "Repeat ending" << repeatendingAsString () <<
    ", line " << fInputLineNumber <<
    endl;
 
  idtr++;

  os <<
    fRepeatendingSegment;

  idtr--;
}

//______________________________________________________________________________
S_msrRepeat msrRepeat::create (
  int          inputLineNumber,
  S_msrVoice   voiceUplink)
{
  msrRepeat* o =
    new msrRepeat (
      inputLineNumber, voiceUplink);
  assert(o!=0);
  return o;
}

msrRepeat::msrRepeat (
  int          inputLineNumber,
  S_msrVoice   voiceUplink)
    : msrElement (inputLineNumber)
{
  fRepeatEndingsInternalCounter = 0;
  
  fRepeatVoiceUplink = voiceUplink;
}

msrRepeat::~msrRepeat() {}

S_msrRepeat msrRepeat::createRepeatBareClone (S_msrVoice clonedVoice)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> creating a bare clone of a repeat" << endl;
  
  S_msrRepeat
    clone =
      msrRepeat::create (
        fInputLineNumber,
        clonedVoice);
  
  return clone;
}

void msrRepeat::setRepeatCommonSegment (
  S_msrSegment repeatCommonSegment)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Setting repeat common segment containing " <<
      singularOrPlural (
        repeatCommonSegment->getSegmentMeasuresList ().size (),
        "measure",
        "measures") <<
      endl;
      
  if (repeatCommonSegment->getSegmentAbsoluteNumber () == 38) { // JMI
 //   msrAssert(false, "fSegmentAbsoluteNumber == 38");
  }

  fRepeatCommonSegment = repeatCommonSegment;
}

void msrRepeat::addRepeatending (S_msrRepeatending repeatending)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Adding ending '" <<
      repeatending->repeatendingAsString () <<
      "' to repeat" <<
      endl;
      
  fRepeatEndings.push_back (repeatending);

  // set repeat ending internal number
  repeatending->
    setRepeatendingInternalNumber (
      ++ fRepeatEndingsInternalCounter);
}

void msrRepeat::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrRepeat::acceptIn()" << endl;
      
  if (visitor<S_msrRepeat>*
    p =
      dynamic_cast<visitor<S_msrRepeat>*> (v)) {
        S_msrRepeat elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrRepeat::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrRepeat::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrRepeat::acceptOut()" << endl;

  if (visitor<S_msrRepeat>*
    p =
      dynamic_cast<visitor<S_msrRepeat>*> (v)) {
        S_msrRepeat elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrRepeat::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrRepeat::browseData (basevisitor* v)
{
  if (fRepeatCommonSegment) {
  // browse the common segment
    msrBrowser<msrSegment> browser (v);
    browser.browse (*fRepeatCommonSegment);
  }
  
  // browse the alternatives
  for (
    vector<S_msrRepeatending>::iterator i = fRepeatEndings.begin();
    i != fRepeatEndings.end();
    i++) {
    // browse the alternative
    msrBrowser<msrRepeatending> browser (v);
    browser.browse (*(*i));
  } // for
}

ostream& operator<< (ostream& os, const S_msrRepeat& elt)
{
  elt->print (os);
  return os;
}

void msrRepeat::print (ostream& os)
{
  os <<
    endl <<
    idtr << "Repeat" <<
    ", line " << fInputLineNumber <<
    " (" << fRepeatEndings.size() << " repeat endings)" <<
    endl;
  
  idtr++;
  
  // print the repeat common segment
  os << idtr <<
    "Common segment: ";
  if (! fRepeatCommonSegment)
    os << "none";
  os << endl;

  if (fRepeatCommonSegment) {
    idtr++;
    
    os <<
      fRepeatCommonSegment;

    idtr--;
  }

  // print the repeat endings
  int endingsNumber =
    fRepeatEndings.size ();
    
  os << idtr <<
    "Repeat endings: ";
  if (endingsNumber)
    os << "(" << endingsNumber << ")";
  else
    os << "none";
  os << endl;
    
  if (endingsNumber) {
    idtr++;
    
    vector<S_msrRepeatending>::const_iterator
      iBegin = fRepeatEndings.begin(),
      iEnd   = fRepeatEndings.end(),
      i      = iBegin;
      
    for ( ; ; ) {
      // print the repeat ending
      os << idtr << (*i);
      if (++i == iEnd) break;
  // JMI    os << endl;
    } // for

    idtr--;
  }

  os << endl;
      
  idtr--;
}

//______________________________________________________________________________ 
S_msrVoice msrVoice::create (
  int          inputLineNumber,
  msrVoiceKind voiceKind,
  int          externalVoiceNumber,
  S_msrStaff   voiceStaffUplink)
{
  msrVoice* o =
    new msrVoice (
      inputLineNumber,
      voiceKind,
      externalVoiceNumber,
      voiceStaffUplink);
  assert(o!=0);
  return o;
}

// for regular voices
msrVoice::msrVoice (
  int          inputLineNumber,
  msrVoiceKind voiceKind,
  int          externalVoiceNumber,
  S_msrStaff   voiceStaffUplink)
    : msrElement (inputLineNumber)
{
  fVoiceKind = voiceKind;
  
  fExternalVoiceNumber = externalVoiceNumber;
  
  fStaffRelativeVoiceNumber = externalVoiceNumber;
    // may be changed afterwards
  
  msrAssert(
    voiceStaffUplink != 0, "voiceStaffUplink is null");

  fVoiceStaffUplink = voiceStaffUplink;

  fVoiceDivisionsPerWholeNote =
    fVoiceStaffUplink->
      getStaffDivisionsPerWholeNote ();

  // compute voice number
  int voiceNumber =
    gMsrOptions-> fCreateStaffRelativeVoiceNumbers // JMI use
      ? fStaffRelativeVoiceNumber
      : fExternalVoiceNumber;
  
  // set voice name
  switch (voiceKind) {
    case msrVoice::kRegularVoice:
      fVoiceName =
        fVoiceStaffUplink->getStaffName() +
        "_Voice_" +
        int2EnglishWord (voiceNumber);
      break;
      
    case msrVoice::kHarmonyVoice:
      fVoiceName =
        fVoiceStaffUplink->getStaffName() +
        "_HARMONY_VOICE";
      break;
      
    case msrVoice::kMasterVoice:
      fVoiceName =
        fVoiceStaffUplink->getStaffName() +
        "_MASTER_VOICE";
      break;
  } // switch

  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Creating voice \"" << fVoiceName <<
      "\" in staff \"" << fVoiceStaffUplink->getStaffName () << "\"" <<
      ", " << fVoiceDivisionsPerWholeNote <<
      " dpwn" <<
      endl;

  // check external voice number
  switch (voiceKind) {
    case msrVoice::kRegularVoice:
      // the external voice number should not be negative
      // (0 is used for the part voice master)
      if (externalVoiceNumber < 0) {
        stringstream s;
    
        s <<
          "regular voice number " << externalVoiceNumber <<
          " is not in the 0..4 range";
          
        msrMusicXMLError (
          inputLineNumber, s.str());
      }
      break;
      
    case msrVoice::kHarmonyVoice:
      if (externalVoiceNumber != -1) {
        stringstream s;
    
        s <<
          "harmony voice number " << externalVoiceNumber <<
          " is not equal to -1";
          
        msrInternalError (
          inputLineNumber, s.str());
      }
      break;
      
    case msrVoice::kMasterVoice:
      if (externalVoiceNumber != 0) {
        stringstream s;
    
        s <<
          "master voice number " << externalVoiceNumber <<
          " is not in the 0..4 range";
          
        msrInternalError (
          inputLineNumber, s.str());
      }
      break;
  } // switch


  // initialize the voice
  init (inputLineNumber);
}

msrVoice::~msrVoice() {}

void msrVoice::init (int inputLineNumber)
{
  // there may be an anacrusis, but let's start with 1 anyway
  fVoiceMeasureNumber = 1;

  fMeasureZeroHasBeenMetInVoice   = false;
  fMeasureNumberHasBeenSetInVoice = false;
  fMusicHasBeenInsertedInVoice    = false;
  
  fVoiceActualNotesCounter     = 0;
  fVoiceActualHarmoniesCounter = 0;

  // add the stanza master for this voice, to
  // collect skips along the way that are used as a 'prelude'
  // by actual stanza that start at later points
  fVoiceStanzaMaster =
    msrStanza::create (
      inputLineNumber,
      0,    // this stanza number is unused anyway
      msrStanza::kMasterStanza,
      this);

  // create the initial segment for this voice
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Creating the initial last segment for voice \"" <<
      getVoiceName () << "\"" <<
      endl;
      
  fVoiceLastSegment =
    msrSegment::create (
      inputLineNumber,
      fVoiceDivisionsPerWholeNote,
      this);

  // register voice first segment for LilyPond issue 34
  fVoiceFirstSegment =
    fVoiceLastSegment;

  // get information from fVoiceStaffUplink if any
  if (fVoiceStaffUplink) {
    // get the initial clef from the staff if any
    {
      S_msrClef
        clef =
          fVoiceStaffUplink->getStaffClef ();
    
      if (clef) {
        // append it to the last segment
        fVoiceLastSegment->
          appendClefToSegment (clef);
        }
    }
      
    // get the initial key from the staff if any
    {
      S_msrKey
        key =
          fVoiceStaffUplink->getStaffKey ();
  
      if (key) {
        // append it to the last segment
        fVoiceLastSegment->
          appendKeyToSegment (key);
      }
    }
    
    // get the initial time from the staff if any
    {
      S_msrTime
        time =
          fVoiceStaffUplink->getStaffTime ();
  
      if (time) {
        // append it to the last segment
        fVoiceLastSegment->
          appendTimeToSegment (time);
      }
    }
    
    // get the initial transpose from the staff if any
    {
      S_msrTranspose
        transpose =
          fVoiceStaffUplink->getStaffTranspose ();
          
      if (transpose) {
        // append it to the last segment
        S_msrElement t = transpose;
        fVoiceLastSegment->
          appendOtherElementToSegment (transpose); //JMI
      }
    }
  }
}

S_msrVoice msrVoice::createVoiceBareClone (S_msrStaff clonedStaff)
{
//  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> Creating a bare clone of voice \"" <<
      getVoiceName () <<
      "\"" <<
      endl;

  S_msrVoice
    clone =
      msrVoice::create (
        fInputLineNumber,
        fVoiceKind,
        fExternalVoiceNumber,
        clonedStaff);

  // populate the voice clone
  clone->fVoiceName =
    fVoiceName;
    
  clone->fVoiceDivisionsPerWholeNote =
    fVoiceDivisionsPerWholeNote;
    
  clone->fExternalVoiceNumber =
    fExternalVoiceNumber;

  clone->fVoiceTime =
    fVoiceTime;

  clone->fMeasureZeroHasBeenMetInVoice =
    fMeasureZeroHasBeenMetInVoice;
  clone->fMeasureNumberHasBeenSetInVoice =
    fMeasureNumberHasBeenSetInVoice;
  clone->fMusicHasBeenInsertedInVoice =
    fMusicHasBeenInsertedInVoice;
  
  return clone;
}

string msrVoice::getVoiceName () const
{
  return fVoiceName;

  /* 
  int voiceNumber =
    gMsrOptions-> fCreateStaffRelativeVoiceNumbers // JMI use
      ? fStaffRelativeVoiceNumber
      : fExternalVoiceNumber;

  string suffix =
    fStaffRelativeVoiceNumber == 0
      ? "MASTER"
      : int2EnglishWord (voiceNumber);
      
  return
    fVoiceStaffUplink->getStaffName() +
    "_Voice_" +
    suffix;
    */
}

void msrVoice::setVoiceDivisionsPerWholeNote (
  int divisionsPerWholeNote)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> setting voice divisions per whole note to " <<
      divisionsPerWholeNote <<
      " in voice \"" << getVoiceName () << "\"" <<
      endl;

  fVoiceDivisionsPerWholeNote =
    divisionsPerWholeNote;

  fVoiceLastSegment->
    setSegmentDivisionsPerWholeNote (
      divisionsPerWholeNote);
}

void msrVoice::setVoiceMeasureNumber (
  int inputLineNumber,
  int measureNumber)
{
  fVoiceMeasureNumber = measureNumber;

  fVoiceLastSegment->
    setSegmentMeasureNumber (
      inputLineNumber,
      fVoiceMeasureNumber);

  fMeasureNumberHasBeenSetInVoice = true;

  if (measureNumber == 0) {  
    fMeasureZeroHasBeenMetInVoice = true;
  }
}

void msrVoice::forceVoiceMeasureNumberTo (int measureNumber) // JMI
{
  fVoiceMeasureNumber = measureNumber;

  fVoiceLastSegment->
    forceSegmentMeasureNumberTo (measureNumber);
};

bool msrVoice::checkForIncompleteVoiceLastMeasure (
  int inputLineNumber)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> checking for incomplete last measure in voice \"" <<
      getVoiceName () << "\"" <<
      ", line " << inputLineNumber <<
      endl;

  return
    fVoiceLastSegment->
      checkForIncompleteSegmentLastMeasure (
        inputLineNumber,
        msrMeasure::kIncompleteRightMeasure);
}

void msrVoice::createNewLastSegmentForVoice (
  int inputLineNumber)
{
  // check for incomplete last measure
  // before creating the new last measure
  bool lastMeasureIsIncomplete =
    checkForIncompleteVoiceLastMeasure (
      inputLineNumber);
    
  // create the segment
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Creating a new segment for voice \"" <<
      getVoiceName () << "\"" <<
      ", line " << inputLineNumber <<
      endl;

  fVoiceLastSegment =
    msrSegment::create (
      inputLineNumber,
      fVoiceDivisionsPerWholeNote,
      this);

  // the new last measure keeps the measure number
  // of the preceeding one whenever the latter is incomplete
  if (! lastMeasureIsIncomplete)
    // increment new segment's first measure's number
    fVoiceLastSegment->
      incrementSegmentLastMeasureNumber (
        inputLineNumber);
}

S_msrStanza msrVoice::addStanzaToVoiceByItsNumber (
  int inputLineNumber,
  int stanzaNumber)
{
  if (fVoiceStanzasMap.count (stanzaNumber)) {
    stringstream s;
    
    s <<
      "stanza " << stanzaNumber <<
      " already exists in voice \"" <<
      getVoiceName () << "\"" <<
      ", line " << inputLineNumber <<
      endl;

    msrInternalError (
      inputLineNumber,
      s.str());

// JMI    return fVoiceStanzasMap [stanzaNumber];
  }

  // create the stanza
  S_msrStanza
    stanza =
      msrStanza::create (
        inputLineNumber,
        stanzaNumber,
        msrStanza::kRegularStanza,
        this);

  // add it to this voice
  addStanzaToVoiceWithCatchUp (stanza);

  // return it
  return stanza;
}

void msrVoice::addStanzaToVoiceWithoutCatchUp (S_msrStanza stanza)
{
  // get stanza number
  int stanzaNumber =
    stanza->getStanzaNumber ();
    
  // register stanza in this voice
// JMI  if (gGeneralOptions->fForceDebug || gGeneralOptions->fTrace)
    cerr << idtr <<
      "Adding stanza " << stanza->getStanzaName () <<
      " (" << stanzaNumber <<
      ") to voice \"" << getVoiceName () << "\"" <<
      endl;

  fVoiceStanzasMap [stanzaNumber] = stanza;
}

void msrVoice::catchUpWithVoiceStanzaMaster (S_msrStanza stanza)
{
  vector<S_msrSyllable>
    masterSyllables =
      fVoiceStanzaMaster->getSyllables ();

  if (masterSyllables.size()) {
// JMI    if (gGeneralOptions->fTrace)
      cerr << idtr <<
        "Copying current contents of voice master stanza to " <<
        stanza->getStanzaName () <<
        endl;
        
    for (
      vector<S_msrSyllable>::const_iterator i =
        masterSyllables.begin();
      i != masterSyllables.end();
      i++) {
      // add syllable to stanza
      stanza->appendSyllableToStanza ((*i));
    } // for
  }
}

void msrVoice::addStanzaToVoiceWithCatchUp (S_msrStanza stanza)
{
  // get stanza number
  int stanzaNumber =
    stanza->getStanzaNumber ();
    
  // register stanza in this voice
// JMI  if (gGeneralOptions->fForceDebug || gGeneralOptions->fTrace)
    cerr << idtr <<
      "Adding stanza " << stanza->getStanzaName () <<
      " (" << stanzaNumber <<
      ") to voice \"" << getVoiceName () << "\"" <<
      endl;

  fVoiceStanzasMap [stanzaNumber] = stanza;

  // catch up with fVoiceStanzaMaster
  // in case the stanza does not start upon the first voice note
  catchUpWithVoiceStanzaMaster (stanza);
}

S_msrStanza msrVoice::createStanzaInVoiceIfNeeded (
  int inputLineNumber,
  int stanzaNumber)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "### --> createStanzaInVoiceIfNeeded (" << inputLineNumber <<
      ", " << stanzaNumber << ")" <<
      ", fVoiceStanzasMap.size() = " << fVoiceStanzasMap.size () <<
      endl;

  S_msrStanza stanza;

  // is stanzaNumber already known in voice?
  if (fVoiceStanzasMap.count (stanzaNumber)) {
    // yes, use it
    stanza = fVoiceStanzasMap [stanzaNumber];
  }
  
  else {
    // no, add it to the voice
    stanza =
      addStanzaToVoiceByItsNumber (
        inputLineNumber, stanzaNumber);
  }

  return stanza;
}

void msrVoice::appendClefToVoice (S_msrClef clef)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending clef '" << clef->clefAsString () <<
      "' to voice \"" << getVoiceName () << "\"" <<
      endl;

  fVoiceLastSegment->
    appendClefToSegment (clef);
}

void msrVoice::appendKeyToVoice (S_msrKey key)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending key '" << key->keyAsString () <<
      "' to voice \"" << getVoiceName () << "\"" <<
      endl;

  fVoiceLastSegment->
    appendKeyToSegment (key);
}

void msrVoice::appendTimeToVoice (S_msrTime time)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending time '" << time->timeAsString () <<
      "' to voice \"" << getVoiceName () << "\"" <<
      endl;

  // register time in voice
  fVoiceTime = time;

  // append it to the last segment
  fVoiceLastSegment->
    appendTimeToSegment (time);
}

void msrVoice::appendHarmonyToVoice (S_msrHarmony harmony)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending harmony '" << harmony->harmonyAsString () <<
      "' to voice \"" << getVoiceName () << "\"" <<
      endl;

  fVoiceLastSegment->
    appendHarmonyToSegment (harmony);

  // register harmony
  fVoiceActualHarmoniesCounter++;
  fMusicHasBeenInsertedInVoice = true;
}

void msrVoice::appendTransposeToVoice (S_msrTranspose transpose)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending transpose '" << transpose->transposeAsString () <<
      "' to voice \"" << getVoiceName () << "\"" <<
      endl;

  fVoiceLastSegment->
    appendOtherElementToSegment (transpose);
}

/* JMI
void msrVoice::appendWordsToVoice (S_msrWords words)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending words '" << words->wordsAsString () <<
      "' to voice " << getVoiceName () << endl;

  S_msrElement w = words;
  fVoiceLastSegment->
    appendOtherElementToSegment (w);
}
*/

void msrVoice::appendTempoToVoice (S_msrTempo tempo)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending tempo '" << tempo->tempoAsString () <<
      "' to voice \"" << getVoiceName () << "\"" <<
      endl;

  fVoiceLastSegment->
    appendOtherElementToSegment (tempo);
}

void msrVoice::appendOctaveShiftToVoice (S_msrOctaveShift octaveShift)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending octave shift '" <<
      octaveShift->octaveShiftKindAsString () <<
      "', size: " << octaveShift->getOctaveShiftSize () <<
      "' to voice \"" << getVoiceName () << "\"" <<
      endl;

  fVoiceLastSegment->
    appendOtherElementToSegment (octaveShift);
}

void msrVoice::appendRehearsalToVoice (S_msrRehearsal rehearsal)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending rehearsal '" << rehearsal->getRehearsalText () <<
      "' to voice \"" << getVoiceName () << "\"" <<
      endl;

  fVoiceLastSegment->
    appendOtherElementToSegment (rehearsal);
}

void msrVoice::appendNoteToVoice (S_msrNote note) {
  if (gGeneralOptions->fDebugDebug) {
    cerr << idtr <<
      "==> appending note:" <<
      endl;

    idtr++;
    
    cerr <<
      idtr <<
        note <<
      idtr <<
        "to voice \"" << getVoiceName () << "\"" <<
        endl;

    idtr--;
  }

  // register actual note
  fVoiceActualNotesCounter++;
  fMusicHasBeenInsertedInVoice = true;

  // append the note to the last segment
  fVoiceLastSegment->
    appendNoteToSegment (note);
  
  // add a skip syllable of the same duration to the stanza master
  int
    noteDivisions =
      note->getNoteDivisions ();

  if (note->getNoteIsARest ())
    fVoiceStanzaMaster->
      addRestSyllableToStanza (
        note->getInputLineNumber (),
        noteDivisions);
  else
    fVoiceStanzaMaster->
      addSkipSyllableToStanza (
        note->getInputLineNumber (),
        noteDivisions);
}

void msrVoice::appendChordToVoice (S_msrChord chord)
{
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "Appending chord '" << chord <<
      "' to voice \"" << getVoiceName () << "\"" <<
      endl;

  fVoiceLastSegment->
    appendChordToSegment (chord);

  fMusicHasBeenInsertedInVoice = true;
}

void msrVoice::appendTupletToVoice (S_msrTuplet tuplet) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "Appending tuplet '" << tuplet->tupletAsString () <<
      "' to voice \"" << getVoiceName () << "\"" <<
      endl;

  fVoiceLastSegment->
    appendTupletToSegment (tuplet);

  fMusicHasBeenInsertedInVoice = true;
}

void msrVoice::appendOtherElementToVoice (S_msrElement elem) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "Appending other element '" << elem <<
      "' to voice \"" << getVoiceName () << "\"" <<
      endl;

  fVoiceLastSegment->
    appendOtherElementToSegment (elem);
}

void msrVoice::appendGracenotesToVoice (
  S_msrGracenotes gracenotes)
{
  if (true || gGeneralOptions->fForceDebug || gGeneralOptions->fDebugDebug)
//  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "Appending grace notes " << // JMI gracenotes <<
      " to voice \"" << getVoiceName () << "\"" <<
      endl;

  fVoiceLastSegment->
    appendGracenotesToSegment (gracenotes);

  fMusicHasBeenInsertedInVoice = true;
}

void msrVoice::prependGracenotesToVoice (
  S_msrGracenotes gracenotes)
{
  if (true || gGeneralOptions->fForceDebug || gGeneralOptions->fDebugDebug)
//  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "Prepending grace notes " << // JMI gracenotes <<
      " to voice \"" << getVoiceName () << "\"" <<
      endl;

  fVoiceFirstSegment->
    prependGracenotesToSegment (gracenotes);

  fMusicHasBeenInsertedInVoice = true;
}

void msrVoice::appendSyllableToVoice (
  int           inputLineNumber,
  int           stanzaNumber,
  S_msrSyllable syllable)
{
  // append syllable to this voice
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug) {
    cerr << idtr <<
      "--> appending syllable " <<
      syllable->syllableAsString () <<
      " to voice \"" << fVoiceName << "\"" <<
      endl;
  }

  // fetch stanzaNumber in this voice
  S_msrStanza
    stanza =
      createStanzaInVoiceIfNeeded (
        inputLineNumber, stanzaNumber);

  // add the syllable to the stanza
  stanza->
    appendSyllableToStanza (
      syllable);
}

void msrVoice::appendBarCheckToVoice (S_msrBarCheck barCheck)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending bar check '" << barCheck->barCheckAsString () <<
      "' to voice \"" << getVoiceName () <<  "\"" <<
      endl;

  fVoiceLastSegment->
    appendOtherElementToSegment (barCheck);

  // add bar check syllable to the voice stanza master
  fVoiceStanzaMaster->
    addBarcheckSyllableToStanza (
      barCheck->getInputLineNumber (),  // [passer barCheck directement? JMI
      barCheck->getNextBarNumber ());
}

void msrVoice::appendBarnumberCheckToVoice (
  S_msrBarnumberCheck barNumberCheck)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending barnumber check '" <<
      barNumberCheck->barnumberCheckAsString () <<
      "' to voice \"" << getVoiceName () <<  "\"" <<
      endl;

  fVoiceLastSegment->
    appendOtherElementToSegment (barNumberCheck);

  // add barnumber check syllable to the voice stanza master
  fVoiceStanzaMaster->
    addBarnumberCheckSyllableToStanza (
      barNumberCheck->getInputLineNumber (),  // [passer barNumberCheck directement? JMI
      barNumberCheck->getNextBarNumber ());
}

void msrVoice::appendBreakToVoice (S_msrBreak break_)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending break '" << break_->breakAsString () <<
      "' to voice \"" << getVoiceName () << "\"" <<
      endl;

  fVoiceLastSegment->
    appendOtherElementToSegment (break_);

  // add break syllable to the voice stanza master
  fVoiceStanzaMaster->
    addBreakSyllableToStanza (
      break_->getInputLineNumber (),
      break_->getNextBarNumber ());
}

void msrVoice::appendRepeatToVoice (int inputLineNumber)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending a repeat to voice \"" << getVoiceName () <<  "\"" <<
      ", line " << inputLineNumber <<
      endl;

  S_msrRepeat
    repeat =
      msrRepeat::create (
        inputLineNumber,
        this);

  // set current segment as the repeat common segment
  repeat->
    setRepeatCommonSegment (
      fVoiceLastSegment);
    
  // append the repeat to the current voice
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> appending the repeat to voice \"" <<
      getVoiceName () <<
      "\"" <<
      endl;

  // register repeat as the (new) current one
  fVoiceCurrentRepeat =
    repeat;

  // append it to the list of repeats and segments
  fVoiceRepeatsAndSegments.push_back (
    repeat);

  // create a new segment for the voice
//  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> creating a new last segment for voice \"" <<
      fVoiceName << "\"" <<
      endl;
      
  createNewLastSegmentForVoice (
    inputLineNumber);
}

void msrVoice::appendRepeatCloneToVoice (
  int         inputLineNumber,
  S_msrRepeat repeatCLone)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending repeat clone to voice clone \"" <<
      getVoiceName () <<  "\"" <<
      endl;


  if (fVoiceName == "P_POne_Staff_One_Voice_One") {
    cerr <<
      endl << endl << endl <<
      "********************" <<
      endl;
    print (cerr);
    cerr <<
      "********************" <<
      endl << endl << endl;
  }
  
  // set current segment as the repeat common segment
  repeatCLone->
    setRepeatCommonSegment (
      fVoiceLastSegment);
    
  // register repeat as the (new) current one
  fVoiceCurrentRepeat =
    repeatCLone;

  // append it to the list of repeats and segments
  fVoiceRepeatsAndSegments.push_back (
    repeatCLone);

  // create a new segment for the voice
//  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> creating a new last segment for voice BOF \"" <<
      fVoiceName << "\"" <<
      endl;
      
  createNewLastSegmentForVoice (
    inputLineNumber);

  if (fVoiceName == "P_POne_Staff_One_Voice_One") {
    cerr <<
      endl << endl << endl <<
      "********************" <<
      endl;
    print (cerr);
    cerr <<
      "********************" <<
      endl << endl << endl;
  
 // JMI   msrAssert(false, "FINI!");
  }
}
    
void msrVoice::appendRepeatendingToVoice (
  int       inputLineNumber,
  string    repeatendingNumber, // may be "1, 2"
  msrRepeatending::msrRepeatendingKind
            repeatendingKind)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending a repeat ending to voice \"" <<
      getVoiceName () <<  "\"" <<
      ", line " << inputLineNumber <<
      endl;

  S_msrRepeatending
    repeatEnding =
      msrRepeatending::create (
        inputLineNumber,
        repeatendingNumber,
        repeatendingKind,
        fVoiceLastSegment,
        fVoiceCurrentRepeat);

  // add the repeat ending it to the voice current repeat
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> appending repeat ending to current repeat in voice " <<
      fVoiceName <<
      endl;
      
  fVoiceCurrentRepeat->
    addRepeatending (repeatEnding);

  // create a new segment for the voice
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> creating new last segment for voice " <<
      fVoiceName <<
      endl;
      
  createNewLastSegmentForVoice (
    inputLineNumber);
}

void msrVoice:: appendRepeatendingCloneToVoice ( // JMI
  S_msrRepeatending repeatendingClone)
{
  // add the repeat ending it to the voice current repeat
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> appending repeat ending clone to current repeat in voice " <<
      fVoiceName <<
      endl;
      
  fVoiceCurrentRepeat->
    addRepeatending (repeatendingClone);

  // create a new segment for the voice
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> creating new last segment for voice " <<
      fVoiceName <<
      endl;
      
  createNewLastSegmentForVoice (
    repeatendingClone->getInputLineNumber ());
}

void msrVoice::prependBarlineToVoice (S_msrBarline barline)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Prepending barline '" <<
      barline->barlineAsString () <<
      "' to voice \"" << getVoiceName () << "\"" <<
      ":" << endl;
      
  idtr++;
  cerr << idtr <<
    barline;
  idtr--;

  fVoiceLastSegment->
    prependBarlineToSegment (barline);
}

void msrVoice::appendBarlineToVoice (S_msrBarline barline)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending barline '" <<
      barline->barlineAsString () <<
      "' to voice \"" << getVoiceName () << "\"" <<
      ":" << endl;
      
  idtr++;
  cerr << idtr <<
    barline;
  idtr--;
  
  fVoiceLastSegment->
    appendBarlineToSegment (barline);
}

void msrVoice::appendSegnoToVoice (S_msrSegno segno)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending a segno to voice \"" << getVoiceName () << "\"" <<
      endl;

  fVoiceLastSegment->
    appendOtherElementToSegment (segno);
}

void msrVoice::appendCodaToVoice (S_msrCoda coda)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending a coda to voice \"" << getVoiceName () << "\"" <<
      ":" << endl;

  fVoiceLastSegment->
    appendOtherElementToSegment (coda);
}

void msrVoice::appendEyeglassesToVoice (S_msrEyeglasses eyeglasses)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending a eyeglasses to voice \"" << getVoiceName () << "\"" <<
      endl;

  fVoiceLastSegment->
    appendOtherElementToSegment (eyeglasses);
}

void msrVoice::appendPedalToVoice (S_msrPedal pedal)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending a pedal to voice \"" << getVoiceName () << "\"" <<
      endl;

  fVoiceLastSegment->
    appendOtherElementToSegment (pedal);
}

/*
S_msrElement msrVoice::removeLastElementFromVoice (
  int inputLineNumber)
{
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "Removing last note" <<
      " from voice " << getVoiceName () <<
      endl;

  return
    fVoiceLastSegment->
      removeLastElementFromSegment (inputLineNumber);
}
*/

void msrVoice::removeFirstChordNoteFromVoice (
  int       inputLineNumber,
  S_msrNote note)
{
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "Removing first chord note " << note->noteAsShortString () <<
      " from voice \"" << getVoiceName () << "\"" <<
      endl;

  fVoiceLastSegment->
    removeFirstChordNoteFromSegment (
      inputLineNumber,
      note);
}

void msrVoice::finalizeLastMeasureOfVoice (int inputLineNumber)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "### --> finalizing last measure in voice " <<
      getVoiceName () <<
      ", line " << inputLineNumber <<
      endl;

  fVoiceLastSegment->
    finalizeLastMeasureOfSegment (inputLineNumber);
}

void msrVoice::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrVoice::acceptIn()" << endl;
      
  if (visitor<S_msrVoice>*
    p =
      dynamic_cast<visitor<S_msrVoice>*> (v)) {
        S_msrVoice elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrVoice::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrVoice::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrVoice::acceptOut()" << endl;

  if (visitor<S_msrVoice>*
    p =
      dynamic_cast<visitor<S_msrVoice>*> (v)) {
        S_msrVoice elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrVoice::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrVoice::browseData (basevisitor* v)
{
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrVoice::browseData()" << endl;

  // browse the voice repeats and segments
  if (fVoiceRepeatsAndSegments.size ()) {
    for (
      list<S_msrElement>::iterator i = fVoiceRepeatsAndSegments.begin();
      i != fVoiceRepeatsAndSegments.end();
      i++) {
      // browse the element
      msrBrowser<msrElement> browser (v);
      browser.browse (*(*i));
    } // for
  }

  // browse the segment
  msrBrowser<msrSegment> browser (v);
  browser.browse (*fVoiceLastSegment);

  // browse the voice stanzas
  if (fVoiceStanzasMap.size ()) {
    for (
      map<int, S_msrStanza>::iterator i = fVoiceStanzasMap.begin();
      i != fVoiceStanzasMap.end();
      i++) {
      // browse the stanza
      msrBrowser<msrStanza> browser (v);
      browser.browse (*((*i).second));
    } // for
  }

  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "<== msrVoice::browseData()" << endl;
}

string msrVoice::voiceKindAsString (
  msrVoiceKind voiceKind)
{
  string result;
  
  switch (voiceKind) {
    case msrVoice::kRegularVoice:
      result = "Regular";
      break;
    case msrVoice::kHarmonyVoice:
      result = "HarmonyVoice";
      break;
    case msrVoice::kMasterVoice:
      result = "MasterVoice";
      break;
  } // switch

  return result;
}

string msrVoice::voiceKindAsString () const
{
  return voiceKindAsString (fVoiceKind);
}
      
ostream& operator<< (ostream& os, const S_msrVoice& elt)
{
  elt->print (os);
  return os;
}

void msrVoice::print (ostream& os)
{
  os <<
    voiceKindAsString (fVoiceKind) <<
    " voice \"" << getVoiceName () <<
    "\" (" <<
    singularOrPlural (
      fVoiceActualHarmoniesCounter, "harmony", "harmonies") <<
     ", " <<
    singularOrPlural (
      fVoiceActualNotesCounter, "actual note", "actual notes") <<
     ", " <<
    singularOrPlural (
      fVoiceStanzasMap.size(), "stanza", "stanzas") <<
    ")" <<
    endl;

  idtr++;

  os <<
    idtr <<
      setw(32) << "(fVoiceDivisionsPerWholeNote" << " = " <<
      fVoiceDivisionsPerWholeNote <<
      ")" <<
      endl <<
    idtr <<
      setw(32) << "(fMeasureZeroHasBeenMetInVoice" << " = " <<
      booleanAsString (fMeasureZeroHasBeenMetInVoice) <<
      ")" <<
      endl <<
    idtr <<
      setw(32) << "(fMeasureNumberHasBeenSetInVoice" << " = " <<
      booleanAsString (fMeasureNumberHasBeenSetInVoice) <<
      ")" <<
      endl <<
    idtr <<
      setw(32) << "(fMusicHasBeenInsertedInVoice" << " = " <<
      booleanAsString (fMusicHasBeenInsertedInVoice) <<
      ")" <<
      endl;

  // print the voice time // JMI
  if (fVoiceTime)
    os << idtr <<
      fVoiceTime->timeAsString () <<
      endl;
  else
    os << idtr <<
      "fVoiceTime == 0 !" << // JMI
      endl;

  os << endl;
    
  // print the voice repeats and segments
  int repeatsAndSegmentsNumber =
    fVoiceRepeatsAndSegments.size ();
    
  os << idtr <<
    "Repeats and segments: ";
  if (repeatsAndSegmentsNumber)
    os << "(" << repeatsAndSegmentsNumber << ")";
  else
    os << "none";
  os <<
    endl;
    
  if (repeatsAndSegmentsNumber) {
    idtr++;

    list<S_msrElement>::const_iterator
      iBegin = fVoiceRepeatsAndSegments.begin(),
      iEnd   = fVoiceRepeatsAndSegments.end(),
      i      = iBegin;
      
    for ( ; ; ) {
      // print the element
      os << idtr << (*i);
      if (++i == iEnd) break;
      os << endl;
    } // for

    idtr--;
  }
  os << endl;
  
  // print the last segment
  os << idtr <<
    "Last segment:" <<
    endl;
    
  idtr++;
  
  os <<
    fVoiceLastSegment <<
    endl;
  
  idtr--;
  
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug) {
    // print the stanza master
    os << idtr <<
      fVoiceStanzaMaster <<
      endl;    
  }
  
  if (! gMsrOptions->fDontDisplayMSRStanzas) {
    // print the voice stanza master
    os << idtr <<
      fVoiceStanzaMaster;
    
    // print the stanza
    if (fVoiceStanzasMap.size()) {
      map<int, S_msrStanza>::const_iterator
        iBegin = fVoiceStanzasMap.begin(),
        iEnd   = fVoiceStanzasMap.end(),
        i      = iBegin;
        
      for ( ; ; ) {
        os << idtr << (*i).second;
        if (++i == iEnd) break;
        os << endl;
      } // for
    }
  }
  
  idtr--;
}

//______________________________________________________________________________
S_msrStafftuning msrStafftuning::create (
  int                  inputLineNumber,
  int                  stafftuningLineNumber,
  msrQuartertonesPitch quartertonesPitch,
  int                  stafftuningOctave)
{
  msrStafftuning* o =
    new msrStafftuning (
      inputLineNumber,
      stafftuningLineNumber,
      quartertonesPitch,
      stafftuningOctave);
  assert(o!=0);
  return o;
}

msrStafftuning::msrStafftuning (
  int                  inputLineNumber,
  int                  stafftuningLineNumber,
  msrQuartertonesPitch quartertonesPitch,
  int                  stafftuningOctave)
    : msrElement (inputLineNumber)
{
  fStafftuningLineNumber        = stafftuningLineNumber;
  fStafftuningQuartertonesPitch = quartertonesPitch;
  fStafftuningOctave            = stafftuningOctave;
}

msrStafftuning::~ msrStafftuning ()
{}

S_msrStafftuning msrStafftuning::createStafftuningBareClone ()
{
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> Creating a bare clone of a staff tuning" <<
      endl;

 S_msrStafftuning
    clone =
      msrStafftuning::create (
        fInputLineNumber,
        fStafftuningLineNumber,
        fStafftuningQuartertonesPitch,
        fStafftuningOctave);
  
  return clone;
}

void msrStafftuning::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrStafftuning::acceptIn()" << endl;
      
  if (visitor<S_msrStafftuning>*
    p =
      dynamic_cast<visitor<S_msrStafftuning>*> (v)) {
        S_msrStafftuning elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrStafftuning::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrStafftuning::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrStafftuning::acceptOut()" << endl;

  if (visitor<S_msrStafftuning>*
    p =
      dynamic_cast<visitor<S_msrStafftuning>*> (v)) {
        S_msrStafftuning elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrStafftuning::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrStafftuning::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrStafftuning& elt)
{
  elt->print (os);
  return os;
}

string msrStafftuning::stafftuningAsString () const
{
  stringstream s;

  s <<
    "line " << fStafftuningLineNumber <<
    ", " <<
    msrQuartertonesPitchAsString (
      gMsrOptions->fQuatertonesPitchesLanguage,
      fStafftuningQuartertonesPitch) <<
    ", octave " << fStafftuningOctave;
    
  return s.str();
}

void msrStafftuning::print (ostream& os)
{
  os <<
    "Stafftuning" <<
    endl;

  idtr++;

  os << left <<  
    idtr <<
      setw(21) << "StafftuningLineNumber" << " = " <<
      fStafftuningLineNumber <<
      endl <<
    idtr <<
      setw(21) << "fStafftuningQuartertonesPitch" << " = " <<
      msrQuartertonesPitchAsString (
        gMsrOptions->fQuatertonesPitchesLanguage,
        fStafftuningQuartertonesPitch) <<
      endl <<
    idtr <<
      setw(21) << "StafftuningOctave" << " = " <<
      fStafftuningOctave <<
      endl;

  idtr--;
}

//______________________________________________________________________________
int msrStaff::gMaxStaffVoices = 4;

S_msrStaff msrStaff::create (
  int          inputLineNumber,
  msrStaffKind staffKind,
  int          staffNumber,
  S_msrPart    staffPartUplink)
{
  msrStaff* o =
    new msrStaff (
      inputLineNumber,
      staffKind, staffNumber,
      staffPartUplink);
  assert(o!=0);
  return o;
}

msrStaff::msrStaff (
  int          inputLineNumber,
  msrStaffKind staffKind,
  int          staffNumber,
  S_msrPart    staffPartUplink)
    : msrElement (inputLineNumber)
{
  fStaffKind = staffKind;
  
  fStaffNumber = staffNumber;

  msrAssert(
    staffPartUplink != 0, "staffPartUplink is null");
  
  fStaffPartUplink   = staffPartUplink;

  fRegisteredVoicesCounter = 0;

  // set staff name
  switch (staffKind) {
    case msrStaff::kRegularStaff:
      fStaffName =
        fStaffPartUplink->getPartMSRName () +
        "_Staff_" +
        int2EnglishWord (fStaffNumber);
      break;
      
    case msrStaff::kTablatureStaff:
        fStaffPartUplink->getPartMSRName () +
        "_Tablature_" +
        int2EnglishWord (fStaffNumber);
      break;
      
    case msrStaff::kPercussionStaff:
        fStaffPartUplink->getPartMSRName () +
        "_Percussion_" +
        int2EnglishWord (fStaffNumber);
      break;
      
    case msrStaff::kHarmonyStaff:
      fStaffName =
        fStaffPartUplink->getPartMSRName () +
        "_Harmony_Staff";
      break;
  } // switch

  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Creating staff \"" << fStaffName <<
      "\" in part " << fStaffPartUplink->getPartCombinedName () <<
      endl;

  // check the staff number
  switch (fStaffKind) {
    case msrStaff::kRegularStaff:
      // the staff number should not be negative
      // (0 is used for hidden staff containing the part voice master) JMI
      if (staffNumber < 0) {
        stringstream s;
    
        s <<
          "regular staff number " << staffNumber <<
          " is not positive";
          
        msrAssert (false, s.str());
      }
      break;
      
    case msrStaff::kTablatureStaff:
      // JMI
      break;
      
    case msrStaff::kPercussionStaff:
      // JMI
      break;
      
    case msrStaff::kHarmonyStaff:
      if (staffNumber != -1) {
        stringstream s;
    
        s <<
          "harmony staff number " << staffNumber <<
          " is not equal to -1";
          
        msrInternalError (
          inputLineNumber, s.str());
      }
      break;
  } // switch

  // populate the staff
  fStaffDivisionsPerWholeNote =
    fStaffPartUplink->
      getPartDivisionsPerWholeNote ();

  // create the staff voice master with relative number 0
  fStaffVoiceMaster =
    addVoiceToStaffByItsRelativeNumber (
      fInputLineNumber,
      msrVoice::kMasterVoice,
      0);

  // mark it as containing music, to prevent it from being removed
  fStaffVoiceMaster->
    setMusicHasBeenInsertedInVoice ();

  // create all 'gMaxStaffVoices' voices for this staff
  // those that remain without music will be removed later
  for (int i = 1; i <= gMaxStaffVoices; i++) {
    addVoiceToStaffByItsRelativeNumber (
      fInputLineNumber,
      msrVoice::kRegularVoice,
      i);
  } // for

  // get the initial clef from the part if any
  {
    S_msrClef
      clef =
        fStaffPartUplink->getPartClef ();
  
    if (clef) {
      if (gGeneralOptions->fTrace)
        cerr << idtr <<
          "Setting staff clef '" << clef->clefAsString () <<
          "' in staff " << fStaffNumber <<
          " in part " << fStaffPartUplink->getPartCombinedName () <<
          endl;

      setStaffClef (clef);
    }
    
    else {
      if (gGeneralOptions->fTrace)
        cerr << idtr <<
          "Setting default treble clef " <<
          " in staff " << fStaffNumber <<
          " in part " << fStaffPartUplink->getPartCombinedName () <<
          endl;

      // create the implicit initial G line 2 clef
      setStaffClef (
        msrClef::create (
          inputLineNumber,
          msrClef::kTrebleClef));
    }
  }
    
  // get the initial key from the part if any
  {
    S_msrKey
      key =
        fStaffPartUplink->getPartKey ();
  
    if (key) {
      if (gGeneralOptions->fTrace)
        cerr << idtr <<
          "Setting staff key '" << key->keyAsString () <<
          "' in staff " << fStaffNumber <<
          " in part " << fStaffPartUplink->getPartCombinedName () <<
          endl;

      setStaffKey (key);
      }
    else {
      if (gGeneralOptions->fTrace)
        cerr << idtr <<
          "Setting default C major key " <<
          " in staff " << fStaffNumber <<
          " in part " << fStaffPartUplink->getPartCombinedName () <<
          endl;
          
      // create the implicit initial C major key
      setStaffKey (
        msrKey::create (
          inputLineNumber,
          0, "major", 0));
    }
  }
  
  // get the initial time from the part if any
  {
    S_msrTime
      time =
        fStaffPartUplink->getPartTime ();

    if (time) {
      if (gGeneralOptions->fTrace)
        cerr << idtr <<
          "Setting staff time '" << time->timeAsString () <<
          "' in staff " << fStaffNumber <<
          " in part " << fStaffPartUplink->getPartCombinedName () <<
          endl;

      setStaffTime (time);
    }
    else {
      if (gGeneralOptions->fTrace)
        cerr << idtr <<
          "Setting default 4/4 time " <<
          " in staff " << fStaffNumber <<
          " in part " << fStaffPartUplink->getPartCombinedName () <<
          endl;
          
      // create the implicit initial 4/4 time signature
      setStaffTime (
        msrTime::create (
          inputLineNumber,
          4, 4));
    }
  }
  
  // get the initial transpose from the part if any
  {
    S_msrTranspose
      transpose =
        fStaffPartUplink->getPartTranspose ();
        
    if (transpose) {
      fStaffTranspose = transpose;
      appendTransposeToAllStaffVoices (transpose);
    }
  }
}

msrStaff::~msrStaff()
{}

S_msrStaff msrStaff::createStaffBareClone (S_msrPart clonedPart)
{
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> Creating a bare clone of staff \"" <<
      fStaffName <<
      "\"" <<
      endl;

  S_msrStaff
    clone =
      msrStaff::create (
        fInputLineNumber,
        fStaffKind,
        fStaffNumber,
        clonedPart);

  clone->fStaffName =
    fStaffName;
    
  return clone;
}

string msrStaff::getStaffName () const
  {
    return fStaffName;

    /*
  return
    fStaffNumber == 0
      ?
        fStaffPartUplink->getPartMSRName () +
        "_S_" +
        "(MASTER)"
      :
        fStaffPartUplink->getPartMSRName () +
        "_S_" +
        int2EnglishWord (fStaffNumber);
        */
  }

void msrStaff::setStaffDivisionsPerWholeNote (
  int divisionsPerWholeNote)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> setting staff divisions per whole note to " <<
      divisionsPerWholeNote <<
      " in staff \"" << getStaffName () << "\"" <<
      endl;

  fStaffDivisionsPerWholeNote =
    divisionsPerWholeNote;

  setAllStaffVoicesDivisionsPerWholeNote (
    divisionsPerWholeNote);
}

void msrStaff::setAllStaffVoicesDivisionsPerWholeNote (
  int divisionsPerWholeNote)
{
  for (
    map<int, S_msrVoice>::const_iterator i = fStaffAllVoicesMap.begin();
    i != fStaffAllVoicesMap.end();
    i++) {
    (*i).second->
      setVoiceDivisionsPerWholeNote (
        divisionsPerWholeNote);
  } // for
}

const int msrStaff::getStaffNumberOfMusicVoices () const
{
  int result = 0;

  for (
    map<int, S_msrVoice>::const_iterator i = fStaffAllVoicesMap.begin();
    i != fStaffAllVoicesMap.end();
    i++) {
      S_msrVoice
        voice =
          (*i).second;

      switch (voice->getVoiceKind ()) {
        case msrVoice::kRegularVoice:
          if (voice->getMusicHasBeenInsertedInVoice ())
            result++;
          break;
        case msrVoice::kHarmonyVoice:
          break;
        case msrVoice::kMasterVoice:
          break;
      } // switch
      
  } // for

  return result;
}

void msrStaff::setStaffMeasureNumber (
  int inputLineNumber,
  int measureNumber)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "### --> setStaffMeasureNumber(), " <<
      ", line " << inputLineNumber <<
      ", measureNumber = " << measureNumber <<
      ", in staff \"" << getStaffName () << "\"" <<
      endl;

  // set part measure location
  fStaffMeasureNumber = measureNumber;

  // propagate it to all staves
  setAllStaffVoicesMeasureNumber (
    inputLineNumber, measureNumber);  
}

/* JMI
S_msrVoice msrStaff::addVoiceMasterToStaff (
  int inputLineNumber)
{
  // create the voice
  S_msrVoice
    voice =
      msrVoice::createMasterVoice (
        inputLineNumber,
        this);

  // add it to this staff as element '0'
  fStaffAllVoicesMap [0] = voice;
  
  // return the voice
  return voice;
}
*/

S_msrVoice msrStaff::addVoiceToStaffByItsRelativeNumber (
  int                    inputLineNumber,
  msrVoice::msrVoiceKind voiceKind,
  int                    voiceRelativeNumber)
{
  // create the voice
  S_msrVoice
    voice =
      msrVoice::create (
        inputLineNumber,
        voiceKind,
        voiceRelativeNumber,
        this);

  // add it to this staff
  fStaffAllVoicesMap [voiceRelativeNumber] = voice;
  
  // return the voice
  return voice;
}

S_msrVoice msrStaff::registerVoiceInStaffByItsExternalNumber (
  int inputLineNumber,
  int externalVoiceNumber)
{
  // take this new voice into account
  fRegisteredVoicesCounter++;

  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Registering voice " << externalVoiceNumber <<
       " as relative voice " << fRegisteredVoicesCounter <<
     " of staff \"" << getStaffName () <<
      "\", line " << inputLineNumber <<
 // JMI     " in part " << fStaffPartUplink->getPartCombinedName () <<
      endl;

  // are there too many voices in this staff? 
  if (fRegisteredVoicesCounter > msrStaff::gMaxStaffVoices) {
    stringstream s;
    
    s <<
      "staff \"" << getStaffName () <<
      "\" is already filled up with " << msrStaff::gMaxStaffVoices <<
      " voices, voice " << externalVoiceNumber << " overflows it" <<
      endl;
      
    msrMusicXMLError (
// JMI    msrMusicXMLWarning ( JMI
      inputLineNumber,
      s.str());
  }

  // fetch the voice
  S_msrVoice
    voice =
      fStaffAllVoicesMap [fRegisteredVoicesCounter];
      
  // update it's voice number
  voice->
    setExternalVoiceNumber (externalVoiceNumber);

  // register it by its number
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Voice " << externalVoiceNumber <<
      " in staff " << getStaffName () <<
      " gets staff relative number " << fRegisteredVoicesCounter <<
      endl;
      
  fStaffVoicesCorrespondanceMap [externalVoiceNumber] =
    voice;

  return voice;
}

S_msrVoice msrStaff::fetchVoiceFromStaff (
  int inputLineNumber, int externalVoiceNumber)
{
  S_msrVoice result;

  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> fetching external voice number " << externalVoiceNumber <<
     " in staff \"" << getStaffName () <<
      "\", line " << inputLineNumber <<
      " in part " << fStaffPartUplink->getPartCombinedName () <<
      endl;

  for (
    map<int, S_msrVoice>::iterator i = fStaffVoicesCorrespondanceMap.begin();
    i != fStaffVoicesCorrespondanceMap.end();
    i++) {
    if (
      (*i).second->getExternalVoiceNumber ()
        ==
      externalVoiceNumber  ) {
      if (gGeneralOptions->fDebug) {
        cerr << idtr <<
          "--> voice " << externalVoiceNumber <<
          " in staff \"" << getStaffName () << "\"" <<
          " has staff relative number " << (*i).first <<
          endl;
      }
        
      result = (*i).second;
      break;
    }
  } // for

  return result;
}

void msrStaff::registerVoiceInStaff (
  int inputLineNumber, S_msrVoice voice)
{
  // take this new voice into account
  fRegisteredVoicesCounter++;

  // are there too many voices in this staff? 
  if (fRegisteredVoicesCounter > msrStaff::gMaxStaffVoices) {
    stringstream s;
    
    s <<
      "staff \"" << getStaffName () <<
      "\" is already filled up with " << msrStaff::gMaxStaffVoices <<
      " voices, voice " << voice->getVoiceName () << " overflows it" <<
      endl;
      
    msrMusicXMLError (
// JMI    msrMusicXMLWarning ( JMI
      inputLineNumber,
      s.str());
  }

  // register voice in this staff
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Registering voice \"" << voice->getVoiceName () <<
      "\" as relative voice " << fRegisteredVoicesCounter <<
      " of staff \"" << getStaffName () <<
      "\", line " << inputLineNumber <<
// JMI       " in part " << fStaffPartUplink->getPartCombinedName () <<
      endl;

  // register is by its relative number
  fStaffAllVoicesMap [fRegisteredVoicesCounter] =
    voice;

  // register it by its number
  fStaffVoicesCorrespondanceMap [voice->getExternalVoiceNumber ()] =
    voice;
}

void msrStaff::setStaffClef (S_msrClef clef)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Setting staff clef '" << clef->clefAsString () <<
      "' in staff " << fStaffNumber <<
      " in part " << fStaffPartUplink->getPartCombinedName () <<
      endl;

  // set staff clef
  fStaffClef = clef;

  // is this a tablature or percussion staff?
  if (clef->clefIsATablatureClef ())
    fStaffKind = kTablatureStaff;
  else if (clef->clefIsAPercussionClef ())
    fStaffKind = kPercussionStaff;
  
  // propagate clef to all voices
  appendClefToAllStaffVoices (clef);
}

void msrStaff::setStaffKey  (S_msrKey  key)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Setting key '" << key->keyAsString () <<
      "' in staff " << fStaffNumber <<
      " in part " << fStaffPartUplink->getPartCombinedName () <<
      endl;

  // set staff key
  fStaffKey = key;

  // propagate it to all voices
  appendKeyToAllStaffVoices (key);
}

void msrStaff::setStaffTime (S_msrTime time)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Setting time '" << time->timeAsString () <<
      "' in staff " << fStaffNumber <<
      " in part " << fStaffPartUplink->getPartCombinedName () <<
      endl;

  // set staff time
  fStaffTime = time;

  // propagate it to all voices
  appendTimeToAllStaffVoices (time);
}    

void msrStaff::appendRepeatToStaff (int inputLineNumber)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending repeat to staff " << fStaffNumber <<
      " in part " << fStaffPartUplink->getPartCombinedName () <<
      endl;

  for (
    map<int, S_msrVoice>::iterator i = fStaffAllVoicesMap.begin();
    i != fStaffAllVoicesMap.end();
    i++) {
    (*i).second->appendRepeatToVoice (inputLineNumber);
  } // for
}

void msrStaff::appendRepeatendingToStaff (
  int       inputLineNumber,
  string    repeatendingNumber, // may be "1, 2"
  msrRepeatending::msrRepeatendingKind
            repeatendingKind)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending repeat ending to staff " << fStaffNumber <<
      " in part " << fStaffPartUplink->getPartCombinedName () <<
      endl;

  for (
    map<int, S_msrVoice>::iterator i = fStaffAllVoicesMap.begin();
    i != fStaffAllVoicesMap.end();
    i++) {
    (*i).second->appendRepeatendingToVoice (
      inputLineNumber,
      repeatendingNumber,
      repeatendingKind);
  } // for
}

void msrStaff::appendRepeatCloneToStaff (
  int         inputLineNumber,
  S_msrRepeat repeatCLone)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending repeat clone to staff " << fStaffNumber <<
      " in part " << fStaffPartUplink->getPartCombinedName () <<
      endl;

  for (
    map<int, S_msrVoice>::iterator i = fStaffAllVoicesMap.begin();
    i != fStaffAllVoicesMap.end();
    i++) {
    (*i).second->appendRepeatCloneToVoice (
      inputLineNumber, repeatCLone);
  } // for
}

void msrStaff::appendRepeatendingCloneToStaff (
  S_msrRepeatending repeatendingClone)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending repeat ending clone to staff " << fStaffNumber <<
      " in part " << fStaffPartUplink->getPartCombinedName () <<
      endl;

  for (
    map<int, S_msrVoice>::iterator i = fStaffAllVoicesMap.begin();
    i != fStaffAllVoicesMap.end();
    i++) {
    (*i).second->appendRepeatendingCloneToVoice (repeatendingClone);
  } // for
}

void msrStaff::appendBarlineToStaff (S_msrBarline barline)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending barline '" << barline->barlineAsString () <<
      "' to staff " << fStaffNumber <<
      " in part " << fStaffPartUplink->getPartCombinedName () <<
      endl;

  for (
    map<int, S_msrVoice>::iterator i = fStaffAllVoicesMap.begin();
    i != fStaffAllVoicesMap.end();
    i++) {
    (*i).second->appendBarlineToVoice (barline);
  } // for
}

void msrStaff::setStaffTranspose (S_msrTranspose transpose)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Setting transpose '" << transpose->transposeAsString () <<
      "' in staff " << fStaffNumber <<
      " in part " << fStaffPartUplink->getPartCombinedName () <<
      endl;

  // set staff transpose
  fStaffTranspose = transpose;

  // propagate it to all voices
  appendTransposeToAllStaffVoices (transpose);
}

void msrStaff::appendClefToAllStaffVoices (S_msrClef clef)
{
  for (
    map<int, S_msrVoice>::iterator i = fStaffAllVoicesMap.begin();
    i != fStaffAllVoicesMap.end();
    i++) {
    (*i).second->appendClefToVoice (clef);
  } // for
}

void msrStaff::appendKeyToAllStaffVoices (S_msrKey  key)
{
  for (
    map<int, S_msrVoice>::iterator i = fStaffAllVoicesMap.begin();
    i != fStaffAllVoicesMap.end();
    i++) {
    (*i).second->appendKeyToVoice (key);
  } // for
}

void msrStaff::appendTimeToAllStaffVoices (S_msrTime time)
{
  for (
    map<int, S_msrVoice>::iterator i = fStaffAllVoicesMap.begin();
    i != fStaffAllVoicesMap.end();
    i++) {
    (*i).second->appendTimeToVoice (time);
  } // for
}

void msrStaff::appendHarmonyToStaff (S_msrHarmony harmony)
{
  for (
    map<int, S_msrVoice>::iterator i = fStaffAllVoicesMap.begin();
    i != fStaffAllVoicesMap.end();
    i++) {
    (*i).second->appendHarmonyToVoice (harmony);
  } // for
}

void msrStaff::appendTransposeToAllStaffVoices (S_msrTranspose transpose)
{
  for (
    map<int, S_msrVoice>::iterator i = fStaffAllVoicesMap.begin();
    i != fStaffAllVoicesMap.end();
    i++) {
    (*i).second->appendTransposeToVoice (transpose);
  } // for
}

void msrStaff::setAllStaffVoicesMeasureNumber (
  int inputLineNumber,
  int measureNumber)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "### --> setAllStaffVoicesMeasureNumber(), " <<
      ", line " << inputLineNumber <<
      ", measureNumber = " << measureNumber <<
      ", in staff \"" << getStaffName () << "\"" <<
      endl;

  for (
    map<int, S_msrVoice>::iterator i = fStaffAllVoicesMap.begin();
    i != fStaffAllVoicesMap.end();
    i++) {
    (*i).second->
      setVoiceMeasureNumber (
        inputLineNumber, measureNumber);
  } // for
}

void msrStaff::removeStaffEmptyVoices ()
{
  for (
    map<int, S_msrVoice>::iterator i = fStaffAllVoicesMap.begin();
    i != fStaffAllVoicesMap.end();
    i++) {
 // JMI   if (! (*i).second->getVoiceActualNotesCounter ()) {
    if (! (*i).second->getMusicHasBeenInsertedInVoice ()) {
// XXL
      fStaffAllVoicesMap.erase (i);
    }
  } // for
}

void msrStaff::finalizeLastMeasureOfStaff (int inputLineNumber)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "### --> finalizing last measure in staff " <<
      getStaffName () <<
      ", line " << inputLineNumber <<
      endl;

  for (
    map<int, S_msrVoice>::iterator i = fStaffAllVoicesMap.begin();
    i != fStaffAllVoicesMap.end();
    i++) {
    (*i).second->finalizeLastMeasureOfVoice (inputLineNumber);
  } // for
}

void msrStaff::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrStaff::acceptIn()" << endl;
      
  if (visitor<S_msrStaff>*
    p =
      dynamic_cast<visitor<S_msrStaff>*> (v)) {
        S_msrStaff elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrStaff::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrStaff::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrStaff::acceptOut()" << endl;

  if (visitor<S_msrStaff>*
    p =
      dynamic_cast<visitor<S_msrStaff>*> (v)) {
        S_msrStaff elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrStaff::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrStaff::browseData (basevisitor* v)
{
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrStaff::browseData()" << endl;

  /*
    fStaffClef, fStaffKey and fStaffTime are used to populate
    newly created voices, not to create music proper:
    they're thus not browsed
  */

  if (fStafftuningsList.size ()) {
    for (
      list<S_msrStafftuning>::iterator i = fStafftuningsList.begin();
      i != fStafftuningsList.end();
      i++) {
      // browse the voice
      msrBrowser<msrStafftuning> browser (v);
      browser.browse (*(*i));
    } // for
    idtr--;
  }

  if (fStaffAllVoicesMap.size ()) {
    for (
      map<int, S_msrVoice>::iterator i = fStaffAllVoicesMap.begin();
      i != fStaffAllVoicesMap.end();
      i++) {
 // JMI     if ((*i).second->getStaffRelativeVoiceNumber () != 0) {
        // browse the voice, but not if it is the master voice JMI
        msrBrowser<msrVoice> browser (v);
        browser.browse (*((*i).second));
  //    }
    } // for
  }

  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "<== msrStaff::browseData()" << endl;
}

ostream& operator<< (ostream& os, const S_msrStaff& elt)
{
  elt->print (os);
  return os;
}


string msrStaff::staffKindAsString (
  msrStaffKind staffKind)
{
  string result;
  
  switch (staffKind) {
    case msrStaff::kRegularStaff:
      result = "regular";
      break;
    case msrStaff::kTablatureStaff:
      result = "tablature";
      break;
    case msrStaff::kPercussionStaff:
      result = "percussion";
      break;
    case msrStaff::kHarmonyStaff:
      result = "harmony";
      break;
  } // switch

  return result;
}

string msrStaff::staffKindAsString () const
{
  return staffKindAsString (fStaffKind);
}

void msrStaff::print (ostream& os)
{
  os <<
    "Staff" " " << getStaffName () <<
    ", " << staffKindAsString () <<
    " (" <<
    singularOrPlural (
      fStaffAllVoicesMap.size(), "voice", "voices") <<
    ")" <<
    endl;

  idtr++;

  if (fStaffClef)
    os << idtr << fStaffClef;
  else
    os << idtr << "NO_CLEF" << endl;

  if (fStaffKey)
    os << idtr << fStaffKey;
  else
    os << idtr << "NO_KEY" << endl;

  if (fStaffTime)
    os << idtr << fStaffTime;
  else
    os << idtr << "NO_TIME" << endl;

/* JMI
  os <<
    idtr << "StaffInstrumentName: \"" <<
    fStaffInstrumentName << "\"" << endl;
*/

  if (fStafftuningsList.size ()) {
    os <<
      idtr << "Staff tunings:" <<
      endl;
      
    list<S_msrStafftuning>::const_iterator
      iBegin = fStafftuningsList.begin(),
      iEnd   = fStafftuningsList.end(),
      i      = iBegin;
      
    idtr++;
    for ( ; ; ) {
      os << idtr <<
        (*i)->stafftuningAsString ();
      if (++i == iEnd) break;
      os << endl;
    } // for
    os << endl;
    idtr--;
  }

  os << endl;

  // print the voices
  if (fStaffAllVoicesMap.size ()) {
    map<int, S_msrVoice>::const_iterator
      iBegin = fStaffAllVoicesMap.begin(),
      iEnd   = fStaffAllVoicesMap.end(),
      i      = iBegin;
      
    for ( ; ; ) {
      os << idtr << (*i).second;
      if (++i == iEnd) break;
      os << endl;
    } // for
  }

  idtr--;
}

void msrStaff::printStructure (ostream& os)
{
  os <<
    "Staff" " " << getStaffName () <<
    ", " << staffKindAsString () <<
    " (" <<
    singularOrPlural (
      fStaffAllVoicesMap.size(), "voice", "voices") <<
    ")" <<
    endl;

  idtr++;

  if (fStaffClef)
    os << idtr << fStaffClef;
  else
    os << idtr << "NO_CLEF" << endl;

  if (fStaffKey)
    os << idtr << fStaffKey;
  else
    os << idtr << "NO_KEY" << endl;

  if (fStaffTime)
    os << idtr << fStaffTime;
  else
    os << idtr << "NO_TIME" << endl;

/* JMI
  os <<
    idtr << "StaffInstrumentName: \"" <<
    fStaffInstrumentName << "\"" << endl;
*/

  if (fStafftuningsList.size ()) {
    os <<
      idtr << "Staff tunings:" <<
      endl;
      
    list<S_msrStafftuning>::const_iterator
      iBegin = fStafftuningsList.begin(),
      iEnd   = fStafftuningsList.end(),
      i      = iBegin;
      
    idtr++;
    for ( ; ; ) {
      os << idtr << (*i)->stafftuningAsString ();
      if (++i == iEnd) break;
      os << endl;
    } // for
    os << endl;
    idtr--;
  }

  // print the registered voices names
  if (fStaffAllVoicesMap.size ()) {
    os << idtr <<
      "Voices:" <<
      endl;
  
    idtr++;
    
    map<int, S_msrVoice>::const_iterator
      iBegin = fStaffAllVoicesMap.begin(),
      iEnd   = fStaffAllVoicesMap.end(),
      i      = iBegin;
      
    for ( ; ; ) {
      S_msrVoice
        voice =
          (*i).second;
          
      os << idtr << left <<
        setw(30) << voice->getVoiceName () <<
        " (" <<
        singularOrPlural (
          voice->getVoiceActualNotesCounter (),
          "actual note",
          "actual notes") <<
        ", " <<
        singularOrPlural (
          voice->getVoiceStanzasMap ().size(),
          "stanza",
          "stanzas") <<
        ")";
      if (++i == iEnd) break;
      os << endl;
    } // for

    idtr --;
  }

  idtr--;
}

//______________________________________________________________________________ 
S_msrPart msrPart::create (
  int            inputLineNumber,
  string         partID,
  S_msrPartgroup partPartgroupUplink)
{
  msrPart* o =
    new msrPart (
      inputLineNumber, partID, partPartgroupUplink);
  assert(o!=0);
  return o;
}

msrPart::msrPart (
  int            inputLineNumber,
  string         partID,
  S_msrPartgroup partPartgroupUplink)
    : msrElement (inputLineNumber)
{
  // replace spaces in part ID
  for_each (
    partID.begin(),
    partID.end(),
    stringSpaceReplacer (fPartID, '_'));
 
  fPartPartgroupUplink = partPartgroupUplink;

  // is this part name in the part renaming map?
  map<string, string>::iterator
    it =
      gMsrOptions->fPartsRenaming.find (fPartID);
        
  if (it != gMsrOptions->fPartsRenaming.end ()) {
    // yes, rename the part accordinglingly
    fPartMSRName = (*it).second;
  }
  else {
    // coin the name from the argument
    fPartMSRName =
      "P_"+stringNumbersToEnglishWords (fPartID);
  }
    
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Creating part " << getPartCombinedName () << endl;

  fPartDivisionsPerWholeNote = 0;

  fMeasureZeroHasBeenMetInPart = false;
  
  fPartMeasurePositionHighTide = 1;

  fPartMeasureNumberMin = INT_MAX;
  fPartMeasureNumberMax = INT_MIN;

  // create the part harmony staff
  const int partHarmonyStaffNumber = -1;

  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> creating the harmony staff " <<
      " with number " << partHarmonyStaffNumber <<
      " for part \"" <<
      getPartName () <<
      "\", line " << inputLineNumber <<
      endl;

  fPartHarmonyStaff =
    addStaffToPartByItsNumber (
      inputLineNumber,
      msrStaff::kHarmonyStaff,
      partHarmonyStaffNumber);
    
  // create the part harmony voice
  const int partHarmonyVoiceNumber = -1;
  
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> creating the harmony voice for part \"" <<
      getPartName () <<
      "\", line " << inputLineNumber <<
      endl;

  fPartHarmonyVoice =
    msrVoice::create (
      inputLineNumber,
      msrVoice::kHarmonyVoice,
      partHarmonyVoiceNumber, // JMI
      fPartHarmonyStaff);

  fPartHarmonyStaff->
    registerVoiceInStaff (
      inputLineNumber,
      fPartHarmonyVoice );

/* JMI
  // create a first staff for the part
  this->
    addStaffToPart (
      inputLineNumber, 1);

  // create the part voice master
  S_msrStaff
    hiddenMasterStaff =
      msrStaff::create (
        0,            // inputLineNumber
        0,            // staffNumber
        this);        // fStaffPartUplink

  fPartVoicemaster =
    msrVoice::create (
      0,            // inputLineNumber
      0,            // staffRelativeVoiceNumber
      hiddenMasterStaff); // voiceStaffUplink
      *
*/
}

msrPart::~msrPart() {}

S_msrPart msrPart::createPartBareClone (S_msrPartgroup clonedPartgroup)
{
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> Creating a bare clone of part " <<
      getPartCombinedName () <<
      endl;

  S_msrPart
    clone =
      msrPart::create (
        fInputLineNumber,
        fPartID,
        clonedPartgroup);

  clone->fPartName =
    fPartName;
  clone->fPartAbbreviation =
    fPartAbbreviation;
  
  clone->fPartInstrumentName =
    fPartInstrumentName;
  clone->fPartInstrumentAbbreviation =
    fPartInstrumentAbbreviation;

  clone->fPartMeasureNumberMin =
    fPartMeasureNumberMin;
  clone->fPartMeasureNumberMax =
    fPartMeasureNumberMax;
    
  return clone;
}

void msrPart::updatePartMeasurePositionHighTide (
  int inputLineNumber,
  int measurePosition)
{
  if (measurePosition > fPartMeasurePositionHighTide)
    fPartMeasurePositionHighTide = measurePosition;
}

void msrPart::setPartMSRName (string partMSRName)
{
  // is this part name in the part renaming map?
  map<string, string>::iterator
    it =
      gMsrOptions->fPartsRenaming.find (fPartMSRName);
        
  if (it != gMsrOptions->fPartsRenaming.end ()) {
    // yes, rename the part accordinglingly
    fPartMSRName = (*it).second;

    if (gGeneralOptions->fTrace)
      cerr << idtr <<
        "Setting part name of " << getPartCombinedName () <<
        " to \"" << fPartMSRName << "\"" <<
         endl;
  }
  else {
    // use the argument
    fPartMSRName = partMSRName;

    if (gGeneralOptions->fTrace)
      cerr << idtr <<
        "Keeping partID \"" << partMSRName <<
        "\" as part name  for " << getPartCombinedName () <<
      endl;
  }
}

string msrPart::getPartCombinedName () const
{
  return
    "\"" + fPartMSRName + "\"" + " (" + fPartID + ")";
}

void msrPart::setPartDivisionsPerWholeNote (
  int divisionsPerWholeNote)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> setting part divisions per whole note to " <<
      divisionsPerWholeNote <<
      " in part " << getPartCombinedName () <<
      endl;

  fPartDivisionsPerWholeNote =
    divisionsPerWholeNote;

  setAllPartStavesDivisionsPerWholeNote (
    divisionsPerWholeNote);
}

void msrPart::setPartMeasureNumber (
  int inputLineNumber,
  int measureNumber)
{
  if (gGeneralOptions->fDebug)
    cerr <<
      endl <<
      idtr <<
        "### --> setPartMeasureNumber()" <<
        ", line " << inputLineNumber <<
        ", measureNumber = " << measureNumber <<
        ", in part " << getPartCombinedName () <<
        endl << endl;

  // set part measure location
  fPartMeasureNumber = measureNumber;

  if (measureNumber == 0) {  
    fMeasureZeroHasBeenMetInPart = true;
  }

  // propagate it to all staves
  setAllPartStavesMeasureNumber (
    inputLineNumber, measureNumber);

  // compute min and max measure numbers
  if (measureNumber < fPartMeasureNumberMin)
    fPartMeasureNumberMin = measureNumber;
  if (measureNumber > fPartMeasureNumberMax)
    fPartMeasureNumberMax = measureNumber;
}

void msrPart::setPartClef (S_msrClef clef)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Setting part clef \"" << clef->clefAsString () <<
      "\" in part " << getPartCombinedName () <<
    endl;

  // set part clef
  fPartClef = clef;

  // propagate it to all staves
  setAllPartStavesClef (clef);
}

void msrPart::setPartKey  (S_msrKey  key)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Setting part key \"" << key->keyAsString () <<
      "\" in part " << getPartCombinedName () <<
    endl;

  // set part key
  fPartKey = key;

  // propagate it to all staves
  setAllPartStavesKey (key);
}

void msrPart::setPartTime (S_msrTime time)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Setting part time \"" << time->timeAsString () <<
      "\" in part " << getPartCombinedName () <<
    endl;

  // set part time
  fPartTime = time;

  // propagate it to all staves
  setAllPartStavesTime (time);
}

void msrPart::setPartTranspose (S_msrTranspose transpose)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Setting part transpose \"" << transpose->transposeAsString () <<
      "\" in part " << getPartCombinedName () <<
    endl;

  // set part transpose
  fPartTranspose = transpose;

  // propagate it to all staves
  setAllPartStavesTranspose (transpose);
}

void msrPart::setAllPartStavesDivisionsPerWholeNote (
  int divisionsPerWholeNote)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> setting segment divisions per whole note to " <<
      divisionsPerWholeNote <<
      endl;

  fPartDivisionsPerWholeNote =
    divisionsPerWholeNote;
  
  for (
    map<int, S_msrStaff>::iterator i = fPartStavesMap.begin();
    i != fPartStavesMap.end();
    i++) {
    (*i).second->
      setStaffDivisionsPerWholeNote (
        divisionsPerWholeNote);
  } // for
}

void msrPart::setAllPartStavesMeasureNumber (
  int inputLineNumber,
  int measureNumber)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "### --> setAllPartStavesMeasureNumber()" <<
      ", line " << inputLineNumber <<
      ", measureNumber = " << measureNumber <<
      ", in part " << getPartCombinedName () <<
      endl;

  for (
    map<int, S_msrStaff>::iterator i = fPartStavesMap.begin();
    i != fPartStavesMap.end();
    i++) {
    (*i).second->
      setStaffMeasureNumber (
        inputLineNumber, measureNumber);
  } // for
}

void msrPart::setAllPartStavesClef (S_msrClef clef)
{
  for (
    map<int, S_msrStaff>::iterator i = fPartStavesMap.begin();
    i != fPartStavesMap.end();
    i++) {
    (*i).second->setStaffClef (clef);
  } // for
}

void msrPart::setAllPartStavesKey (S_msrKey  key)
{
  for (
    map<int, S_msrStaff>::iterator i = fPartStavesMap.begin();
    i != fPartStavesMap.end();
    i++) {
    (*i).second->setStaffKey (key);
  } // for
}
          
void msrPart::setAllPartStavesTime  (S_msrTime time)
{
  for (
    map<int, S_msrStaff>::iterator i = fPartStavesMap.begin();
    i != fPartStavesMap.end();
    i++) {
    (*i).second->setStaffTime (time);
  } // for
}

void msrPart::appendRepeatToPart (int inputLineNumber)
{
  for (
    map<int, S_msrStaff>::iterator i = fPartStavesMap.begin();
    i != fPartStavesMap.end();
    i++) {
    (*i).second->appendRepeatToStaff (inputLineNumber);
  } // for
}

void msrPart::appendRepeatendingToPart (
  int       inputLineNumber,
  string    repeatendingNumber, // may be "1, 2"
  msrRepeatending::msrRepeatendingKind
            repeatendingKind)
{
  for (
    map<int, S_msrStaff>::iterator i = fPartStavesMap.begin();
    i != fPartStavesMap.end();
    i++) {
    (*i).second->appendRepeatendingToStaff (
      inputLineNumber,
      repeatendingNumber,
      repeatendingKind);
  } // for
}

void msrPart::appendRepeatCloneToPart (
  int         inputLineNumber,
  S_msrRepeat repeatCLone)
{
  for (
    map<int, S_msrStaff>::iterator i = fPartStavesMap.begin();
    i != fPartStavesMap.end();
    i++) {
    (*i).second->appendRepeatCloneToStaff (
      inputLineNumber, repeatCLone);
  } // for
}

void msrPart::appendRepeatendingCloneToPart (
  S_msrRepeatending repeatendingCLone)
{
  for (
    map<int, S_msrStaff>::iterator i = fPartStavesMap.begin();
    i != fPartStavesMap.end();
    i++) {
    (*i).second->appendRepeatendingCloneToStaff (repeatendingCLone);
  } // for
}

void msrPart::appendBarlineToPart (S_msrBarline barline)
{
  for (
    map<int, S_msrStaff>::iterator i = fPartStavesMap.begin();
    i != fPartStavesMap.end();
    i++) {
    (*i).second->appendBarlineToStaff (barline);
  } // for
}
     
void msrPart::setAllPartStavesTranspose (S_msrTranspose transpose)
{
  for (
    map<int, S_msrStaff>::iterator i = fPartStavesMap.begin();
    i != fPartStavesMap.end();
    i++) {
    (*i).second->setStaffTranspose (transpose);
  } // for
}

S_msrStaff msrPart::addStaffToPartByItsNumber (
  int                    inputLineNumber,
  msrStaff::msrStaffKind staffKind,
  int                    staffNumber)
{
  if (fPartStavesMap.count (staffNumber)) {
    cerr << idtr <<
      "### Internal error: staffNumber " << staffNumber <<
      " already exists in part " << " " << getPartCombinedName () <<
      endl;

    return fPartStavesMap [staffNumber];
  }

// JMI  if (gGeneralOptions->fForceDebug || gGeneralOptions->fTrace)
    cerr << idtr <<
      "Adding " <<
      msrStaff::staffKindAsString (staffKind) <<
      " staff " << staffNumber <<
      " to part " << getPartCombinedName () <<
      endl;
  
  // create the staff
  S_msrStaff
    staff =
      msrStaff::create (
        inputLineNumber,
        staffKind,
        staffNumber,
        this);

  // register it in this part
  fPartStavesMap [staffNumber] = staff;

  // return it
  return staff;
}

void msrPart::addStaffToPartClone (S_msrStaff staff)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Adding staff \"" << staff->getStaffName () <<
      "\" to part clone " << getPartCombinedName () <<
      endl;

  // register staff in this part
  fPartStavesMap [staff->getStaffNumber ()] = staff;
}

S_msrStaff msrPart::fetchStaffFromPart (
  int staffNumber)
{
  S_msrStaff result;
  
  if (fPartStavesMap.count (staffNumber)) {
    result = fPartStavesMap [staffNumber];
  }

  return result;
}

void msrPart::appendHarmonyToPart (S_msrHarmony harmony)
{
  int inputLineNumber =
    harmony->getInputLineNumber ();
    
// JMI  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> appending harmony " <<
      harmony->harmonyAsString () <<
      " to part \"" <<
      getPartName () <<
      "\", line " << inputLineNumber <<
      endl;

  fPartHarmonyVoice->
    appendHarmonyToVoice (harmony);
}

void msrPart:: handleBackup (int divisions)
{
 // JMI 
}

void msrPart::removePartEmptyVoices ()
{
  for (
    map<int, S_msrStaff>::iterator i = fPartStavesMap.begin();
    i != fPartStavesMap.end();
    i++) {
    (*i).second->removeStaffEmptyVoices ();
  } // for
}

void msrPart::finalizeLastMeasureOfPart (int inputLineNumber)
{
  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "### --> finalizing last measure in part " <<
      getPartName () <<
      ", line " << inputLineNumber <<
      endl;

  for (
    map<int, S_msrStaff>::iterator i = fPartStavesMap.begin();
    i != fPartStavesMap.end();
    i++) {
    (*i).second->finalizeLastMeasureOfStaff (inputLineNumber);
  } // for
}

void msrPart::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrPart::acceptIn()" << endl;
      
  if (visitor<S_msrPart>*
    p =
      dynamic_cast<visitor<S_msrPart>*> (v)) {
        S_msrPart elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrPart::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrPart::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrPart::acceptOut()" << endl;

  if (visitor<S_msrPart>*
    p =
      dynamic_cast<visitor<S_msrPart>*> (v)) {
        S_msrPart elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrPart::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrPart::browseData (basevisitor* v)
{
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrPart::browseData()" << endl;

/* JMI
  if (fPartHarmonyStaff) {
    // browse the harmony staff
    msrBrowser<msrStaff> browser (v);
    browser.browse (*fPartHarmonyStaff);
  }
  */
  
  for (
    map<int, S_msrStaff>::iterator i = fPartStavesMap.begin();
    i != fPartStavesMap.end();
    i++) {
    // browse the staff
    msrBrowser<msrStaff> browser (v);
    browser.browse (*((*i).second));
  } // for

  if (gGeneralOptions->fDebug)
    cerr << idtr <<
      "<== msrPart::browseData()" << endl;
}

ostream& operator<< (ostream& os, const S_msrPart& elt)
{
  elt->print (os);
  return os;
}

void msrPart::print (ostream& os)
{
  os <<
    "Part" << " " << getPartCombinedName () <<
    " (" <<
    singularOrPlural (
      fPartStavesMap.size(), "staff", "staves") <<
    ", measures " <<
      fPartMeasureNumberMin << ".." << fPartMeasureNumberMax <<
    ", position high tide " << fPartMeasurePositionHighTide <<
    ")" <<
    endl;
    
  idtr++;
  
  os << left <<
    idtr <<
      setw(25) << "PartDivisionsPerWholeNote" << ": " <<
      fPartDivisionsPerWholeNote << endl <<
    idtr <<
      setw(25) << "PartMSRName" << ": \"" <<
      fPartMSRName << "\"" << endl <<
    idtr <<
      setw(25) << "PartName" << ": \"" <<
      fPartName << "\"" << endl <<
    idtr <<
      setw(25) << "PartAbbrevation" << ": \"" <<
      fPartAbbreviation << "\"" << endl <<
    idtr <<
      setw(25) << "PartInstrumentName" << ": \"" <<
      fPartInstrumentName << "\"" << endl;

/*
  // print the harmony staff
  if (fPartHarmonyStaff) {
    os <<
      endl <<
      idtr <<
        "Harmony staff:" <<
      endl;
            
    idtr++;
    os << idtr << fPartHarmonyStaff;
    idtr--;
  }
*/

  // print the staves
  if (fPartStavesMap.size()) {
    os << endl;
    for (
      map<int, S_msrStaff>::iterator i = fPartStavesMap.begin();
      i != fPartStavesMap.end();
      i++) {
      os <<
        idtr << (*i).second <<
        endl;
    } // for
  }

  idtr--;
}

void msrPart::printStructure (ostream& os)
{
  os <<
    "Part" << " " << getPartCombinedName () <<
    " (" <<
    singularOrPlural (
      fPartStavesMap.size(), "staff", "staves") <<
    ", measures " <<
      fPartMeasureNumberMin << ".." << fPartMeasureNumberMax <<
    ", position high tide " << fPartMeasurePositionHighTide <<
    ")" <<
    endl;
    
  idtr++;
  
  os << left <<
    idtr <<
      setw(25) << "PartDivisionsPerWholeNote" << ": " <<
      fPartDivisionsPerWholeNote << endl <<
    idtr <<
      setw(25) << "PartMSRName" << ": \"" <<
      fPartMSRName << "\"" << endl <<
    idtr <<
      setw(25) << "PartName" << ": \"" <<
      fPartName << "\"" << endl <<
    idtr <<
      setw(25) << "PartAbbrevation" << ": \"" <<
      fPartAbbreviation << "\"" << endl <<
    idtr <<
      setw(25) << "PartInstrumentName" << ": \"" <<
      fPartInstrumentName << "\"" << endl;

/*
  // print the harmony staff
  if (fPartHarmonyStaff) {
    os <<
      endl <<
      idtr <<
        "Harmony staff" <<
      endl;
            
    idtr++;
    os << idtr << fPartHarmonyStaff;
    idtr--;
  }
*/

  // print the staves
  if (fPartStavesMap.size()) {
    os << endl;
    for (
      map<int, S_msrStaff>::iterator i = fPartStavesMap.begin();
      i != fPartStavesMap.end();
      i++) {
      os <<
        idtr;
        (*i).second->printStructure (os);
        os <<
          endl;
    } // for
  }

  idtr--;
}

//______________________________________________________________________________
int msrPartgroup::gPartgroupsCounter = 0;

S_msrPartgroup msrPartgroup::create (
  int                    inputLineNumber,
  int                    partgroupNumber,
  string                 partgroupName,
  string                 partgroupDisplayText,
  string                 partgroupAccidentalText,
  string                 partgroupAbbreviation,
  msrPartgroupSymbolKind partgroupSymbolKind,
  int                    partgroupSymbolDefaultX,
  bool                   partgroupBarline,
  S_msrPartgroup         partgroupPartgroupUplink)
{
  msrPartgroup* o =
    new msrPartgroup (
      inputLineNumber,
      partgroupNumber,
      partgroupName,
      partgroupDisplayText,
      partgroupAccidentalText,
      partgroupAbbreviation,
      partgroupSymbolKind,
      partgroupSymbolDefaultX,
      partgroupBarline,
      partgroupPartgroupUplink);
  assert(o!=0);
  return o;
}

msrPartgroup::msrPartgroup (
  int                    inputLineNumber,
  int                    partgroupNumber,
  string                 partgroupName,
  string                 partgroupDisplayText,
  string                 partgroupAccidentalText,
  string                 partgroupAbbreviation,
  msrPartgroupSymbolKind partgroupSymbolKind,
  int                    partgroupSymbolDefaultX,
  bool                   partgroupBarline,
  S_msrPartgroup         partgroupPartgroupUplink)
    : msrElement (inputLineNumber)
{
  fPartgroupAbsoluteNumber = ++gPartgroupsCounter;
  
  fPartgroupNumber = partgroupNumber;
        
  fPartgroupName = partgroupName;

  fPartgroupDisplayText    = partgroupDisplayText;
  fPartgroupAccidentalText = partgroupAccidentalText;
  
  fPartgroupAbbreviation = partgroupAbbreviation;

  fPartgroupSymbolKind = partgroupSymbolKind;
  fPartgroupSymbolDefaultX = partgroupSymbolDefaultX;

  fPartgroupBarline = partgroupBarline;

  fPartgroupPartgroupUplink = partgroupPartgroupUplink;
  
  if (gGeneralOptions->fTrace)
    cerr <<
      idtr <<
      "--------------------------------------------" <<
      endl <<
      idtr <<
      "Creating part group " << fPartgroupNumber <<
      endl;
}

msrPartgroup::~msrPartgroup()
{}

S_msrPartgroup msrPartgroup::createPartgroupBareClone (
  S_msrPartgroup clonedPartgroup)
{
  if (gGeneralOptions->fTrace)
    cerr <<
      idtr <<
      "--------------------------------------------" <<
      endl <<
      idtr <<
      "Creating a bare clone part group " <<
      getPartgroupCombinedName () <<
      endl;

  S_msrPartgroup
    clone =
      msrPartgroup::create (
        fInputLineNumber,
        fPartgroupNumber,
        fPartgroupName,
        fPartgroupDisplayText,
        fPartgroupAccidentalText,
        fPartgroupAbbreviation,
        fPartgroupSymbolKind,
        fPartgroupSymbolDefaultX,
        fPartgroupBarline,
        clonedPartgroup);

  // avoid part group clone to keep its (new) absolute number
  clone->fPartgroupAbsoluteNumber =
    fPartgroupAbsoluteNumber;
  
  return clone;
}

string msrPartgroup::getPartgroupCombinedName () const
{
  stringstream s;

  s <<
    "PG_" << fPartgroupAbsoluteNumber <<
    " (" << fPartgroupNumber << ")";

  return s.str();
}

S_msrPart msrPartgroup::addPartToPartgroupByItsID (
  int    inputLineNumber,
  string partID)
{
  if (fPartgroupPartsMap.count (partID)) {
    stringstream s;

    s <<
      "partID \"" << partID <<
      "\" already exists in part group " <<
      getPartgroupCombinedName ();

    msrMusicXMLWarning ( // JMI
      inputLineNumber,
      s.str ());

    return fPartgroupPartsMap [partID];
  }

  // create the part
  S_msrPart
    part =
      msrPart::create (
        inputLineNumber,
        partID,
        this);

  // register it in this part group
  if (gGeneralOptions->fTrace) {
    cerr << idtr <<
      "Adding part " <<
      part->getPartCombinedName () <<
      " to part group " << fPartgroupNumber <<
      endl;
  }
  
  fPartgroupPartsMap [partID] = part;
  fPartgroupElements.push_back (part);

  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebugDebug) {
    cerr <<
    endl <<
    idtr <<
      "==> After addPartToPartgroupByItsID, fPartgroupPartsMap contains:" << endl;
    idtr++;
    for (
        map<string, S_msrPart>::const_iterator i = fPartgroupPartsMap.begin();
        i != fPartgroupPartsMap.end();
        i++) {
      cerr << idtr <<
        "\"" << (*i).first << "\" ----> " <<
        (*i).second->getPartCombinedName() <<
        endl;
    } // for
    idtr--;
    cerr << idtr <<
      "<== addPartToPartgroup" <<
      endl << endl <<

    idtr <<
      "==> After addPartToPartgroupByItsID, fPartgroupPartsList contains:" <<
      endl;
    if (fPartgroupElements.size()) {
      list<S_msrElement>::const_iterator
        iBegin = fPartgroupElements.begin(),
        iEnd   = fPartgroupElements.end(),
        i      = iBegin;
        
      idtr++;
      for ( ; ; ) {
        cerr << idtr << (*i);
        if (++i == iEnd) break;
        cerr << endl;
      } // for
      idtr--;
    }
    cerr <<
      idtr << "<== addPartToPartgroupByItsID" <<
      endl << endl;
  }
  
  // return the part
  return part;
}

void msrPartgroup::addPartToPartgroup (S_msrPart part)
{
  // register part in this part group
  if (gGeneralOptions->fTrace) {
    cerr << idtr <<
      "Adding part " <<
      part->getPartCombinedName () <<
      " to part group " << fPartgroupNumber <<
      endl;
  }
  
  fPartgroupPartsMap [part->getPartID ()] = part;
  fPartgroupElements.push_back (part);
}

void msrPartgroup::prependSubPartgroupToPartgroup (
  S_msrPartgroup partgroup)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Prepending (sub-)part group " << partgroup->getPartgroupNumber () <<
      " to part group " << getPartgroupNumber ()  << endl;

  // register it in this part group
  fPartgroupElements.push_front (partgroup);
}

void msrPartgroup::appendSubPartgroupToPartgroup (
  S_msrPartgroup partgroup)
{
  if (gGeneralOptions->fTrace)
    cerr << idtr <<
      "Appending (sub-)part group " << partgroup->getPartgroupNumber () <<
      " to part group " << getPartgroupNumber ()  << endl;

  // register it in this part group
  fPartgroupElements.push_back (partgroup);
}

S_msrPart msrPartgroup::fetchPartFromPartgroup (
  string partID)
{
  if (gGeneralOptions->fDebugDebug) {
    cerr << idtr <<
      "==> fetchPartFromPartgroup, fPartgroupPartsMap contains:" << endl;
    for (
        map<string, S_msrPart>::const_iterator i = fPartgroupPartsMap.begin();
        i != fPartgroupPartsMap.end();
        i++) {
      cerr << idtr <<
        (*i).first << " ----> " <<
        (*i).second->getPartCombinedName() <<
        endl;
    } // for
    cerr << idtr <<
      "<== fetchPartFromPartgroup" <<
      endl;
  }
  
  S_msrPart result;
  
  if (fPartgroupPartsMap.count (partID)) {
    result = fPartgroupPartsMap [partID];
  }

  return result;
}

void msrPartgroup::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrPartgroup::acceptIn()" << endl;
      
  if (visitor<S_msrPartgroup>*
    p =
      dynamic_cast<visitor<S_msrPartgroup>*> (v)) {
        S_msrPartgroup elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrPartgroup::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrPartgroup::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrPartgroup::acceptOut()" << endl;

  if (visitor<S_msrPartgroup>*
    p =
      dynamic_cast<visitor<S_msrPartgroup>*> (v)) {
        S_msrPartgroup elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrPartgroup::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrPartgroup::browseData (basevisitor* v)
{
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrPartgroup::browseData()" << endl;
  
  for (
    list<S_msrElement>::iterator i = fPartgroupElements.begin();
    i != fPartgroupElements.end();
    i++) {
    // browse the part element
    msrBrowser<msrElement> browser (v);
    browser.browse (*(*i));
  } // for

  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "<== msrPartgroup::browseData()" << endl;
}

ostream& operator<< (ostream& os, const S_msrPartgroup& elt)
{
  elt->print (os);
  return os;
}

string msrPartgroup::pargroupSymbolKindAsString (
  msrPartgroupSymbolKind partgroupSymbolKind)
{
  string result;
  
  switch (partgroupSymbolKind) {
    case k_NoPartgroupSymbol:
      result = "none";
      break;
    case kBracePartgroupSymbol:
      result = "brace";
      break;
    case kBracketPartgroupSymbol:
      result = "bracket";
      break;
    case kLinePartgroupSymbol:
      result = "line";
      break;
    case kSquarePartgroupSymbol:
      result = "square";
      break;
  } // switch

  return result;
}

void msrPartgroup::print (ostream& os)
{
  os <<
    "Partgroup" " \"" << getPartgroupCombinedName () <<
    "\" (" <<
    singularOrPlural (
      fPartgroupPartsMap.size(), "part", "parts") <<
    ")" <<
    endl;
    
  idtr++;

  os << left <<
    idtr <<
      setw(24) << "PartgroupName" << " : \"" <<
      fPartgroupName <<
      "\"" <<
      endl <<
    idtr <<
      setw(24) << "PartgroupDisplayText" << " : \"" <<
      fPartgroupDisplayText <<
      "\"" <<
      endl <<
    idtr <<
      setw(24) << "PartgroupAccidentalText" << " : \"" <<
      fPartgroupAccidentalText <<
      "\"" <<
      endl <<
    idtr <<
      setw(24) << "PartgroupAbbrevation" << " : \"" <<
      fPartgroupAbbreviation <<
      "\"" <<
      endl <<
    idtr <<
      setw(24) << "fPartgroupSymbolDefaultX" << " : " <<
      fPartgroupSymbolDefaultX <<
        endl <<
    idtr <<
      setw(24) << "fPartgroupSymbolKind" << " : \"" <<
      pargroupSymbolKindAsString (fPartgroupSymbolKind) <<
      "\"" <<
      endl;
    
  os <<
    idtr << "PartgroupBarline         : ";
  if (fPartgroupBarline)
    os << "true";
  else
    os << "false";
  os << endl;

  if (fPartgroupElements.size()) {
    os << endl;
    list<S_msrElement>::const_iterator
      iBegin = fPartgroupElements.begin(),
      iEnd   = fPartgroupElements.end(),
      i      = iBegin;
      
    idtr++;
    for ( ; ; ) {
      os << idtr << (*i);
      if (++i == iEnd) break;
      os << endl;
    } // for
    idtr--;
  }
  
  idtr--;
}

void msrPartgroup::printStructure (ostream& os)
{
  os <<
    "Partgroup" " \"" << getPartgroupCombinedName () <<
    "\" (" <<
    singularOrPlural (
      fPartgroupPartsMap.size(), "part", "parts") <<
    ")" <<
    endl;
    
  idtr++;

  os << left <<
    idtr <<
      setw(24) << "PartgroupName" << " : \"" <<
      fPartgroupName <<
      "\"" <<
      endl <<
    idtr <<
      setw(24) << "PartgroupAbbrevation" << " : \"" <<
      fPartgroupAbbreviation <<
      "\"" <<
      endl <<
    idtr <<
      setw(24) << "fPartgroupSymbolDefaultX" << " : " <<
      fPartgroupSymbolDefaultX <<
        endl <<
    idtr <<
      setw(24) << "fPartgroupSymbolKind" << " : \"" <<
      pargroupSymbolKindAsString (fPartgroupSymbolKind) <<
      "\"" <<
      endl;
    
  os <<
    idtr << "PartgroupBarline         : ";
  if (fPartgroupBarline)
    os << "true";
  else
    os << "false";
  os << endl;

  if (fPartgroupElements.size()) {
    os << endl;
    list<S_msrElement>::const_iterator
      iBegin = fPartgroupElements.begin(),
      iEnd   = fPartgroupElements.end(),
      i      = iBegin;
      
    idtr++;
    for ( ; ; ) {
      os << idtr;
      (*i)->printStructure (os);
      if (++i == iEnd) break;
      os << endl;
    } // for
    idtr--;
  }
  
  idtr--;
}

//______________________________________________________________________________
S_msrIdentification msrIdentification::create (
  int           inputLineNumber)
{
  msrIdentification* o =
    new msrIdentification (
      inputLineNumber);
  assert(o!=0);
  return o;
}

msrIdentification::msrIdentification (
  int           inputLineNumber)
    : msrElement (inputLineNumber)
{}

msrIdentification::~msrIdentification() {}

void msrIdentification::setWorkNumber (
  int    inputLineNumber,
  string val)
  {
  fWorkNumber =
    msrVarValAssoc::create (
      inputLineNumber,
      "work-number", val);
  }

void msrIdentification::setWorkTitle (
  int    inputLineNumber,
  string val)
  {
  fWorkTitle =
    msrVarValAssoc::create (
      inputLineNumber,
      "work-title", val);
  }

void msrIdentification::setMovementNumber (
  int    inputLineNumber,
  string val)
  {
  fMovementNumber =
    msrVarValAssoc::create (
      inputLineNumber,
      "movement-number", val);
  }

void msrIdentification::setMovementTitle (
  int    inputLineNumber,
  string val)
{
  fMovementTitle =
    msrVarValAssoc::create (
      inputLineNumber,
      "movement-title", val);
}

void msrIdentification::addCreator (
  int    inputLineNumber,
  string type,
  string val)
{
  fCreators.push_back(
    msrVarValAssoc::create (
      inputLineNumber,
      type, val)
  );
}

void msrIdentification::setRights (
  int    inputLineNumber,
  string val)
  {
  fRights =
    msrVarValAssoc::create (
      inputLineNumber,
      "rights", val);
  }

void msrIdentification::addSoftware (
  int    inputLineNumber,
  string val)
{
  fSoftwares.push_back(
    msrVarValAssoc::create (
      inputLineNumber,
      "software", val)
  );
}

void msrIdentification::setEncodingDate (
  int    inputLineNumber,
  string val)
{
  fEncodingDate =
    msrVarValAssoc::create (
      inputLineNumber,
      "encoding-date", val);
}

void msrIdentification::setScoreInstrumentAssoc (
  int    inputLineNumber,
  string val)
{
  fScoreInstrumentAssoc =
    msrVarValAssoc::create (
      inputLineNumber,
      "score-instrument", val);
}

void msrIdentification::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrIdentification::acceptIn()" << endl;
      
  if (visitor<S_msrIdentification>*
    p =
      dynamic_cast<visitor<S_msrIdentification>*> (v)) {
        S_msrIdentification elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrIdentification::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrIdentification::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrIdentification::acceptOut()" << endl;

  if (visitor<S_msrIdentification>*
    p =
      dynamic_cast<visitor<S_msrIdentification>*> (v)) {
        S_msrIdentification elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrIdentification::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrIdentification::browseData (basevisitor* v)
{
  if (fWorkNumber) {
    // browse fWorkNumber
    msrBrowser<msrVarValAssoc> browser (v);
    browser.browse (*fWorkNumber);
  }

  if (fWorkTitle) {
    // browse fWorkTitle
    msrBrowser<msrVarValAssoc> browser (v);
    browser.browse (*fWorkTitle);
  }

  if (fMovementNumber) {
    // browse fMovementNumber
    msrBrowser<msrVarValAssoc> browser (v);
    browser.browse (*fMovementNumber);
  }

  if (fMovementTitle) {
    // fMovementTitle fMovementTitle
    msrBrowser<msrVarValAssoc> browser (v);
    browser.browse (*fMovementTitle);
  }

  if (!fCreators.empty()) {
    vector<S_msrVarValAssoc>::const_iterator i;
    for (i=fCreators.begin(); i!=fCreators.end(); i++) {
      // browse creator
      msrBrowser<msrVarValAssoc> browser (v);
      browser.browse (*(*i));
    } // for
  }
    
  if (fRights) {
    // browse rights
    msrBrowser<msrVarValAssoc> browser (v);
    browser.browse (*fRights);
  }

  if (!fSoftwares.empty()) {
    vector<S_msrVarValAssoc>::const_iterator i;
    for (i=fSoftwares.begin(); i!=fSoftwares.end(); i++) {
      // browse software
      msrBrowser<msrVarValAssoc> browser (v);
      browser.browse (*(*i));
    } // for
  }

  if (fEncodingDate) {
    // browse encoding date
    msrBrowser<msrVarValAssoc> browser (v);
    browser.browse (*fEncodingDate);
  }

  if (fScoreInstrumentAssoc) {
    // browse score instrument
    msrBrowser<msrVarValAssoc> browser (v);
    browser.browse (*fScoreInstrumentAssoc);
  }
}

ostream& operator<< (ostream& os, const S_msrIdentification& elt)
{
  elt->print (os);
  return os;
}

void msrIdentification::print (ostream& os)
{
  os << "Identification" << endl;

  bool emptyIdentification = true;

  idtr++;
  
  if (fWorkNumber) {
    os << idtr << fWorkNumber;
    emptyIdentification = false;
  }
  
  if (fWorkTitle) {
    os << idtr << fWorkTitle;
    emptyIdentification = false;
  }
    
  if (fMovementNumber) {
    os << idtr << fMovementNumber;
    emptyIdentification = false;
  }
    
  if (fMovementTitle) {
    os << idtr << fMovementTitle;
    emptyIdentification = false;
  }
    // JMI for   ; ; 
  if (!fCreators.empty()) {
    vector<S_msrVarValAssoc>::const_iterator i1;
    for (i1=fCreators.begin(); i1!=fCreators.end(); i1++) {
      os << idtr << (*i1);
    } // for
    emptyIdentification = false;
  }
    
  if (fRights) {
    os << idtr << fRights;
    emptyIdentification = false;
  }
    
  if (!fSoftwares.empty()) {
    vector<S_msrVarValAssoc>::const_iterator i2;
    for (i2=fSoftwares.begin(); i2!=fSoftwares.end(); i2++) {
      os << idtr << (*i2);
    } // for
    emptyIdentification = false;
  }
    
  if (fEncodingDate) {
    os << idtr << fEncodingDate;
    emptyIdentification = false;
  }

  if (emptyIdentification)
    os << idtr <<
      " " << "nothing specified" << endl;

  os << endl;
  
  idtr--;
}

//______________________________________________________________________________
S_msrScore msrScore::create (
  int inputLineNumber)
{
  msrScore* o =
    new msrScore (
      inputLineNumber);
  assert(o!=0);
  return o;
}

msrScore::msrScore (
  int inputLineNumber)
    : msrElement (inputLineNumber)
{
  fIdentification =
    msrIdentification::create (
      inputLineNumber);
      
  fPageGeometry =
    msrPageGeometry::create (
      inputLineNumber);
}

msrScore::~msrScore() {}

S_msrScore msrScore::createScoreBareClone ()
{
  if (gGeneralOptions->fForceDebug || gGeneralOptions->fDebug)
    cerr << idtr <<
      "--> Creating a bare clone of a score" <<
      endl;

  S_msrScore
    clone =
      msrScore::create (
        fInputLineNumber);

  return clone;
}

void msrScore::addPartgroupToScore (S_msrPartgroup partgroup)
{
  /* JMI
  if (fScorePartgroupsMap.count (partgroupNumber)) {
    cerr << idtr <<
      "### Internal error: part group " << partgroupNumber <<
      " already exists in this score" << endl;

    return fScorePartgroupsMap [partgroupNumber];
  }
*/

  // register it in this score
  fPartgroupsList.push_back (partgroup);
}

/*
S_msrPartgroup msrScore::fetchScorePartgroup (
  int partgroupNumber)
{
  S_msrPartgroup result;
  
  if (fScorePartgroupsMap.count (partgroupNumber)) {
    result = fScorePartgroupsMap [partgroupNumber];
  }

  return result;
}
*/

void msrScore::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrScore::acceptIn()" << endl;
      
  if (visitor<S_msrScore>*
    p =
      dynamic_cast<visitor<S_msrScore>*> (v)) {
        S_msrScore elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrScore::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrScore::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrScore::acceptOut()" << endl;

  if (visitor<S_msrScore>*
    p =
      dynamic_cast<visitor<S_msrScore>*> (v)) {
        S_msrScore elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrScore::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrScore::browseData (basevisitor* v)
{
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrScore::browseData()" << endl;
    
  if (fIdentification) {
    // browse identification
    msrBrowser<msrIdentification> browser (v);
    browser.browse (*fIdentification);
  }

  if (fPageGeometry) {
    // browse page geometry
    msrBrowser<msrPageGeometry> browser (v);
    browser.browse (*fPageGeometry);
  }

  for (
    list<S_msrPartgroup>::iterator i = fPartgroupsList.begin();
    i != fPartgroupsList.end();
    i++) {
    // browse the part group
    msrBrowser<msrPartgroup> browser (v);
    browser.browse (*(*i));
  } // for

  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "<== msrScore::browseData()" << endl;
  }

ostream& operator<< (ostream& os, const S_msrScore& elt)
{
  elt->print (os);
  return os;
}

void msrScore::print (ostream& os)
{
  os <<
    "MSR Score" <<
    " (" <<
    singularOrPlural (
      fPartgroupsList.size(),
      "part group",
      "part groups") <<
    ")" <<
    endl << endl;

  idtr++;
  
  if (fIdentification) {
    os << idtr << fIdentification;
  }
  
  if (fPageGeometry) {
    os << idtr << fPageGeometry;
  }
  
  for (
    list<S_msrPartgroup>::iterator i = fPartgroupsList.begin();
    i != fPartgroupsList.end();
    i++) {
    os << idtr << (*i);
  } // for
  
  idtr--;
}

void msrScore::printStructure (ostream& os)
{
  os <<
    "MSR structure" <<
    " (" <<
    singularOrPlural (
      fPartgroupsList.size(),
      "part group",
      "part groups") <<
    ")" <<
    endl << endl;

  idtr++;
  
  if (fIdentification) {
    os << idtr << fIdentification;
  }
  
  if (fPageGeometry) {
    os << idtr << fPageGeometry;
  }
  
  for (
    list<S_msrPartgroup>::iterator i = fPartgroupsList.begin();
    i != fPartgroupsList.end();
    i++) {
    os << idtr;
    (*i)->printStructure (os);
  } // for
  
  idtr--;
}

//______________________________________________________________________________
S_msrMidi msrMidi::create (
  int    inputLineNumber,
  string midiTempoDuration,
  int    midiTempoPerSecond)
{
  msrMidi* o =
    new msrMidi (
      inputLineNumber,
      midiTempoDuration,
      midiTempoPerSecond);
  assert(o!=0);
  return o;
}

msrMidi::msrMidi (
  int    inputLineNumber,
  string midiTempoDuration,
  int    midiTempoPerSecond)
    : msrElement (inputLineNumber)
{
  fMidiTempoDuration = midiTempoDuration;
  fMidiTempoPerSecond = midiTempoPerSecond;
}

msrMidi::~msrMidi() {}

void msrMidi::acceptIn (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrMidi::acceptIn()" << endl;
      
  if (visitor<S_msrMidi>*
    p =
      dynamic_cast<visitor<S_msrMidi>*> (v)) {
        S_msrMidi elem = this;
        
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrMidi::visitStart()" << endl;
        p->visitStart (elem);
  }
}

void msrMidi::acceptOut (basevisitor* v) {
  if (gGeneralOptions->fDebugDebug)
    cerr << idtr <<
      "==> msrMidi::acceptOut()" << endl;

  if (visitor<S_msrMidi>*
    p =
      dynamic_cast<visitor<S_msrMidi>*> (v)) {
        S_msrMidi elem = this;
      
        if (gGeneralOptions->fDebugDebug)
          cerr << idtr <<
            "==> Launching msrMidi::visitEnd()" << endl;
        p->visitEnd (elem);
  }
}

void msrMidi::browseData (basevisitor* v)
{}

ostream& operator<< (ostream& os, const S_msrMidi& elt)
{
  elt->print (os);
  return os;
}

void msrMidi::print (ostream& os)
{
  os << "Midi" << endl;

  idtr++;

  os <<
    idtr <<
      setw(18) << "fMidiTempoDuration" << " = " << fMidiTempoDuration <<
      endl <<
    idtr <<
      setw(18) << "fMidiTempoPerSecond" << " = " << fMidiTempoPerSecond <<
      endl <<
    endl;
      
  idtr--;
}


}
