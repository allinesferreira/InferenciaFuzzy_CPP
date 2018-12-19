/* 
 * File:   PreparacaoDaBase.h
 * Author: allinesf
 *
 * Created on 7 de Junho de 2015, 16:13
 *
*/

#ifndef PREPARACAODABASE_H
#define	PREPARACAODABASE_H

#include "PreparacaoDaBase.h"
#include "PreparaBase.h"
#include "utilitarios.h"
#include "GeraArquivosClasse.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>

class PreparacaoDaBase {
public:
    PreparacaoDaBase();
    PreparacaoDaBase(const PreparacaoDaBase& orig);
    virtual ~PreparacaoDaBase();
    void PreProcessamento();
private:

};

#endif	/* PREPARACAODABASE_H */

