/* 
 * File:   PreparaBaseDeteccaoSAtaquesDesconhecidos.h
 * Author: allinesf
 *
 * Created on 15 de Janeiro de 2016, 16:27
 */

#ifndef PREPARABASEDETECCAOSATAQUESDESCONHECIDOS_H
#define	PREPARABASEDETECCAOSATAQUESDESCONHECIDOS_H

class PreparaBaseDeteccaoSAtaquesDesconhecidos {
public:
    PreparaBaseDeteccaoSAtaquesDesconhecidos();
    PreparaBaseDeteccaoSAtaquesDesconhecidos(const PreparaBaseDeteccaoSAtaquesDesconhecidos& orig);
    void PreProcessamentoAtaquesDesconhecidos(char nomeArquivoDeteccao[50]);
    virtual ~PreparaBaseDeteccaoSAtaquesDesconhecidos();
private:

};

#endif	/* PREPARABASEDETECCAOSATAQUESDESCONHECIDOS_H */

