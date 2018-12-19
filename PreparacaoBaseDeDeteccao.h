/* 
 * File:   PreparacaoBaseDeDeteccao.h
 * Author: allinesf
 *
 * Created on 2 de Novembro de 2015, 05:54
 */

#ifndef PREPARACAOBASEDEDETECCAO_H
#define	PREPARACAOBASEDEDETECCAO_H

#include <vector>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <stdlib.h> 

using namespace std;
class PreparacaoBaseDeDeteccao {
public:
    PreparacaoBaseDeDeteccao();
    PreparacaoBaseDeDeteccao(const PreparacaoBaseDeDeteccao& orig);
    virtual ~PreparacaoBaseDeDeteccao();
    void  PreProcessamentoBaseDeteccao(char nomeArquivoDeteccao[50]);
    
private:

};

#endif	/* PREPARACAOBASEDEDETECCAO_H */

