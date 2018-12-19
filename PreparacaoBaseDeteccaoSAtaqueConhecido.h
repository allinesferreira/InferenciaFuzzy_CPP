/* 
 * File:   PreparacaoBaseDeteccaoSAtaqueConhecido.h
 * Author: allinesf
 *
 * Created on 1 de Dezembro de 2015, 20:28
 */

#ifndef PREPARACAOBASEDETECCAOSATAQUECONHECIDO_H
#define	PREPARACAOBASEDETECCAOSATAQUECONHECIDO_H

class PreparacaoBaseDeteccaoSAtaqueConhecido {
public:
    PreparacaoBaseDeteccaoSAtaqueConhecido();
    PreparacaoBaseDeteccaoSAtaqueConhecido(const PreparacaoBaseDeteccaoSAtaqueConhecido& orig);
    virtual ~PreparacaoBaseDeteccaoSAtaqueConhecido();
    void  PreProcessamentoAtaquesConhecidos(char nomeArquivoDeteccao[50]);
private:

};

#endif	/* PREPARACAOBASEDETECCAOSATAQUECONHECIDO_H */

