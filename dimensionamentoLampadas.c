#include <stdio.h>
#include <stdlib.h>

int dimensiona(float x, float y, float area, float *areaRestante, int *num100, int *num60, int resposta){
    int lamp_inc = 0;

    if(!resposta)
      area = x*y;
  
    if(area<6){
      *num100 = 1;
      return lamp_inc = 100;
    }
  
    if(area>=6){
      lamp_inc += 100;
      area -= 6;
      *num100 = 1;
    }

    while(area>=4){
      lamp_inc += 60;
      area -= 4;
      *num60 += 1;
    }
  
    *areaRestante = area;
    return lamp_inc;
}

int main(){
  
  int resposta;
  int total;
  float area;
  float comprimento;
  float largura;
  int num_lamp100 = 0;
  int num_lamp60 = 0;
  float areaRestante;

  printf("\nJa possui a Area total?\n");
  printf("\n( 0 ) Nao\n( 1 ) Sim\n\nSelecione: ");
  scanf("%d", &resposta);
  
  if(resposta != 0 && resposta != 1){
    printf("\nNumero invalido. Reinicie o programa.\n");
    exit(1);
  }

  if(resposta){
    printf("\nDigite a Area total (m2) do comodo: ");
    scanf("%f", &area);
    printf("\n---------------------------------------------\n");
  } else{
    printf("\nDigite o valor do comprimento do comodo: ");
    scanf("%f", &comprimento);
    printf("\nDigite o valor da largura do comodo: ");
    scanf("%f", &largura);
    printf("\n---------------------------------------------\n");
    area = comprimento*largura;
    printf("\nArea total: %.2f m2", area);
  }

  total = dimensiona(largura, comprimento, area, &areaRestante, &num_lamp100, &num_lamp60, resposta);
  
  printf("\nDimensionamento das Lampadas incandescentes: %d VA\n", total);
  printf("\n---------------------------------------------\n");

  printf("\nSera %d lampada de 100 VA (primeiros 6m2) e %d lampadas de 60 VA (para cada 4m2) cada\n", num_lamp100,num_lamp60);
  printf("\n---------------------------------------------\n");
  printf("\nCom area restante de %.2f m2\n", areaRestante);
  printf("\n---------------------------------------------\n");

  if(!resposta)
    printf("\n\n\n*OBS.: calculos realizados considerando-se comodo de 4 dimensoes.");

  printf("\n\n\n*OBS.: calculos realizados conforme o Manual da Prysmian.");
  
  return 0;
}