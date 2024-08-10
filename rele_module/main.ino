void setup()
{
  pinMode(2, INPUT);	// BOTAO
  pinMode(3, OUTPUT);	// RELE
  
}


/*
CASO APERTAR O BOTAO E FICAR SEGURANDO
NAO VAI ACONTECER NADA.
ISSO EVITA 2 COISAS
- DELAY
- REPETIÇÃO MUITO GRANDE DE CODIGO (LOOP DO BOTAO)
ISSO IRIA FAZER O RELE ARMAR E DESARMAR MUITO RAPIDO NUMA
VELOCIDADE ALTISSIMA E PARA RESOLVER EU FIZ ESSE CODIGO:

bool ligado = false;

if (BOTAO == true){
	if (!ligado){
    	ligado = true;	// AQUI O CODIGO EXECUTA 1x POR CLIQUE
        // BLOCO DE CODIGO
    }
}

*/


bool ligado = false;
void loop()
{
  if (digitalRead(2)){	// SE APERTERO BOTAO
      if (!ligado){		// SE LIGADO = FALSE
          ligado = true;	// LIGADO = TRUE	
          digitalWrite(3, !digitalRead(3));	// TOGGLE
      }
  }
  else{
      ligado = false;
  }
}