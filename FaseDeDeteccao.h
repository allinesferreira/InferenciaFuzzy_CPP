/* 
 * File:   FaseDeDeteccao.h
 * Author: allinesf
 *
 * Created on 4 de Novembro de 2015, 12:13
 */

#ifndef FASEDEDETECCAO_H
#define	FASEDEDETECCAO_H

class FaseDeDeteccao {
public:
    FaseDeDeteccao();
    FaseDeDeteccao(const FaseDeDeteccao& orig);
    virtual ~FaseDeDeteccao();
    void FaseDeteccao(double limiarPBaixa, bool ABC_Extendida, char nomeADeteccao[100], double limiarClassificacao);
private:
    void CalculaEstimativa(char nomeArqResultado[50], bool tipoDetec_E, double limiarClas);
    void CalculaEstimativaMamdani(char nomeArqResultado[50], bool tipoDetec_E, double limiarClas);

};

#endif	/* FASEDEDETECCAO_H */

