// Aluno: Marcos Rodolfo Cruvinel Goulart Querino
// Fundamentos da computacao 4
// Prof. Roldao

#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

void conversao(char *num, int base)
{
	int i, j, cont_total= 0, cont_antes_virg= 0;
	double total= 0;
	for (i= 0; num[i]!='\0'; i++)
	{
		if(num[i]!='.')
		{
			cont_total++; // total de casas decimais apenas, n conta a virgula
		}
	}
	
	for (i= 0; num[i]!='.' && num[i]!='\0'; i++)
	{
		cont_antes_virg++; // quantidade de casas decimais antes da virgula
	}
	
	cout << endl;
	
	if(cont_total==cont_antes_virg) // o numero e inteiro
	{
		for (i= 0; i<cont_total; i++)
		{
			if(i<cont_total-1)
			{
				cout << num[i] << "x" << base << "^" << cont_antes_virg-i-1 << " + ";
			}
			if(i==cont_total-1)
			{
				cout << num[i] << "x" << base << "^" << cont_antes_virg-i-1 << endl;
			}	
		}
	}
	else // o numero e fracionado
	{
		for (i= 0, j= 0; i<=cont_total; i++, j++)
		{
			if(i==cont_total)
			{
				cout << num[i] << "x" << base << "^" << cont_antes_virg-j-1 << endl;
			}
			else
			{
				if(num[i]!='.') 
				{
					cout << num[i] << "x" << base << "^" << cont_antes_virg-j-1 << " + ";
				}
				if(num[i]=='.') // quando acha a virgula, "pula" para o proximo espaco do vetor
				{
					i++;
					if(i==cont_total)
					{
						cout << num[i] << "x" << base << "^" << cont_antes_virg-j-1 << endl;
					}
					else
					{
						cout << num[i] << "x" << base << "^" << cont_antes_virg-j-1 << " + ";
					}					
				}				
			}				
		}
	}
	for(i= 0; i<cont_total; i++)
	{
		total += (num[i]-48)*pow(base,cont_antes_virg-i-1);
	}
	cout << "\nTotal= " << total << endl;	
}

void base_10_para_2(int n)
{
	int resto, i= 0, vet[36]= {0};
	
	while(n!=0)
	{
		resto= n%2;
		n= n/2;
		vet[i]= resto;
		i++;
	}
	
	for(i= i-1; i>=0; i--)
	{
		cout << vet[i];
	}
	cout << endl;
}

int base_2_para_10 (char n[])
{
	int i, cont= 0;
	int total= 0;
	
	for (i= 0; n[i]!='\0'; i++)
	{
		cont++;
	}
	
	for(i= cont-1; i>=0; i--)
	{
		total += (n[i]-48)*pow(2,cont-i-1);
	}
	return total;
}

void base_10_para_8(int n) // mesma coisa que converter da base 10 para 2
{  
    int num8[100]; 
    int i= 0;
	 
    while (n!=0) 
	{ 
        num8[i] = n%8; // o que muda e o divisor
        n= n/8; 
        i++; 
    } 
    
    cout << "\nNumero convertido da base 10 para base 8: ";
    
    for (i= i-1; i>=0; i--)
	{
		cout << num8[i];
	} 
    cout << endl;     
} 

int base_8_para_10 (string n) // mesma coisa que converter da base 2 para 10
{
	int i, cont= 0, total= 0;
	string num= "";
	
	for (i= 0; i<n.size(); i++)
	{
		cont++;
	}
	
	for(i= cont-1; i>=0; i--)
	{
		total += (n[i]-48)*pow(8,cont-i-1); // o que muda e a base da potencia
	}
	
	return total;	 
}

string base_8_para_2(string num) 
{
	int i= 0; 
  
    string binario= ""; // esvazia a string
  
    while (num[i]) 
	{ 
        switch (num[i]) 
		{ 
	        case '0': 
	            binario += "000"; 
	            break; 
	        case '1': 
	            binario += "001"; 
	            break; 
	        case '2': 
	            binario += "010"; 
	            break; 
	        case '3': 
	            binario += "011"; 
	            break; 
	        case '4': 
	            binario += "100"; 
	            break; 
	        case '5': 
	            binario += "101"; 
	            break; 
	        case '6': 
	            binario += "110"; 
	            break; 
	        case '7': 
	            binario += "111"; 
	            break; 
	        default: 
	            cout << "\nNumero invalido para a base 8: " << num[i] << endl; 
	            break; 
        } 
        i++; 
    } 
    return binario;
}

string base_2_para_8(string num) 
{
    string octogonal= ""; // esvazia a string
   
    for(int i= 0; i<num.size(); i= i+3)
    {
    	if(num[i]=='0'&&num[i+1]=='0'&&num[i+2]=='0')
    	{
    		octogonal+="0"; 
		}
		else
		{
			if(num[i]=='0'&&num[i+1]=='0'&&num[i+2]=='1')
        	{
        		octogonal+="1"; 
			}
			else
			{
				if(num[i]=='0'&&num[i+1]=='1'&&num[i+2]=='0')
	        	{
	        		octogonal+="2"; 
				}
				else
				{
					if(num[i]=='0'&&num[i+1]=='1'&&num[i+2]=='1')
		        	{
		        		octogonal+="3"; 
					}
					else
					{
						if(num[i]=='1'&&num[i+1]=='0'&&num[i+2]=='0')
			        	{
			        		octogonal+="4"; 
						}
						else
						{
							if(num[i]=='1'&&num[i+1]=='0'&&num[i+2]=='1')
				        	{
				        		octogonal+="5"; 
							}
							else
							{
								if(num[i]=='1'&&num[i+1]=='1'&&num[i+2]=='0')
					        	{
					        		octogonal+="6"; 
								}
								else
								{
									if(num[i]=='1'&&num[i+1]=='1'&&num[i+2]=='1')
						        	{
						        		octogonal+="7"; 
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
    return octogonal;
}

void base_10_para_hexa(int n) 
{     
    char hexa[100]; // guarda o numero hexadecimal  
    int i= 0; 
    
    while(n!=0) 
    {    
        int resto= 0;           
        resto= n%16; // sistema similar a conversao de numero da base 10 para outra
           
        if(resto<10) 
        { 
            hexa[i]= resto+48; // converte o numero inteiro para numero em char
            i++; 
        } 
        else
        { 
            hexa[i]= resto + 55; // converte o numero em uma letra hexadecimal (A= 10, B= 11, C= 12, D= 13, E= 14, F= 15)
            i++; 
        } 
          
        n= n/16; 
    }   
    
	for(int j=i-1; j>=0; j--) 
    {
    	cout << hexa[j];
	}
	cout << endl;      
} 

int base_hexa_para_10(char hexa[]) 
{    
    int i, tam= strlen(hexa); // tamanho do vetor de char
      
    int base= 1; 
      
    int valorbase10= 0; 
      
    for (i= tam-1; i>=0; i--) // varre de tras para frente
    {     
        if (hexa[i]>='0' && hexa[i]<='9') // se o valor estiver entre 0 a 9
        { 
            valorbase10 += (hexa[i] - 48)*base; // no primeiro for, base= 1, resulta no proprio numero
                   
            base= base * 16; // segundo for= 16^1, depois 16^2=16*16, etc...
        } 
  
        else if (hexa[i]>='A' && hexa[i]<='F') // se o valor estiver entre A a F
        { 
            valorbase10 += (hexa[i] - 55)*base; 
           
            base= base*16; 
        } 
    } 
      
    return valorbase10; 
} 

void base_hexa_para_8(string hexa) 
{ 
    string binario= ""; // esvazia a string
  
    // conversao de hexa para binario 
    for (int i= 0; i<hexa.size(); i++) 
	{   
        switch (hexa[i]) 
		{ 
	        case '0': 
	            binario += "0000"; 
	            break; 
	        case '1': 
	            binario += "0001"; 
	            break; 
	        case '2': 
	            binario += "0010"; 
	            break; 
	        case '3': 
	            binario += "0011"; 
	            break; 
	        case '4': 
	            binario += "0100"; 
	            break; 
	        case '5': 
	            binario += "0101"; 
	            break; 
	        case '6': 
	            binario += "0110"; 
	            break; 
	        case '7': 
	            binario += "0111"; 
	            break; 
	        case '8': 
	            binario += "1000"; 
	            break; 
	        case '9': 
	            binario += "1001"; 
	            break; 
	        case 'a': 
	        case 'A': 
	            binario += "1010"; 
	            break; 
	        case 'b': 
	        case 'B': 
	            binario += "1011"; 
	            break; 
	        case 'c': 
	        case 'C': 
	            binario += "1100"; 
	            break; 
	        case 'd': 
	        case 'D': 
	            binario += "1101"; 
	            break; 
	        case 'e': 
	        case 'E': 
	            binario += "1110"; 
	            break; 
	        case 'f': 
	        case 'F': 
	            binario += "1111"; 
	            break; 
	        default: 
	            cout << "\nValor hexadecimal invalido.\n"; 
        } 
    } 
  	cout << "Numero hexadecimal convertido para octogonal: " << base_2_para_8(binario) << endl;
} 

void base_8_para_hexa(string num)
{
	int n= base_8_para_10(num); // converte da 8 para 10
	cout << "\nNumero convertido da base octogonal para hexadecimal: ";
	base_10_para_hexa(n);
}

void base_hexa_para_2(char hexa[])
{
	base_10_para_2(base_hexa_para_10(hexa));
}

void base_2_para_hexa(char n[])
{
	base_10_para_hexa(base_2_para_10 (n)); 
}

void Ponto_Flutuante_IEEE_754 (float num)
{
	int resto, exp_norma= 0, contador_mantissa= 0, mantissa[23]= {0}, representacao[32]; // mantissa recebe 0 em todas as posicoes porque se for inferior a 23 digitos, os demais deverao ser preenchidos com 0
	// Essa funcao altera o valor original de 'num', entao "pegaremos" seu sinal agora
	if(num<0)
	{
		representacao[0]= 1;
		cout << "\nO numero e negativo, recebe " << representacao[0] << endl;
	}
	else
	{
		representacao[0]= 0;
		cout << "\nO numero e positivo, recebe " << representacao[0] << endl;
	}
	
	// 1ª etapa- normaliza o 'num' 
	float fracao; 
	if(num<1) // exemplo 0,9
	{
		while(num<1)
		{
			num= num*2; // vai para 1,6
			exp_norma++; // 1
		} // 'num' normalizado= 1,6 * 2^1
	}
	else // exemplo 25,5
	{
		while(num>2)
		{
			num= num/2; // etapas do while: 12,75 -> 6,375 -> 3,1875 -> 1,59375
			exp_norma++; // 4
		} // 'num' normalizado= 1,59375 * 2^4
	}
	cout << "\nO numero normalizado e: " << num << " * 2^" << exp_norma << endl; 
	
	// 2ª etapa- calcular mantissa baseado na parte fracionada no 'num' normalizado
	cout << "\nEtapas do calculo da mantissa:\n\n";
	fracao= num - (int)num; // 1º - removendo a parte inteira de 'num'
	cout << "Remove a parte inteira do numero normalizado= " << fracao << endl;
	while(fracao!=0 && contador_mantissa<23) // multiplica a parte fracionada por 2 ate que o resultado seja 0 ou ate o maximo de 23 multiplicacoes
	{										 // 'contador_mantissa<23' porque trabalharei com os valores de 0 a 22
		fracao= fracao*2; // 2º - multiplica por 2
		cout << "Multiplica a parte fracionada por 2= " << fracao << endl;
		cout << "Insere a parte inteira desse numero na mantissa: " << (int)fracao << endl;
		mantissa[contador_mantissa]= (int)fracao; // 3º - insere apenas a parte inteira na mantissa
		fracao= fracao - (int)fracao; // 4º - remove a parte inteira para repetir a partir do passo 2
		cout << "Remove a parte inteira desse numero= " << fracao << endl;
		contador_mantissa++; // incrementa o contador a cada execução dos passos acima
	}
	cout << "\nMantissa completa: ";
	for(int i= 0; i<23; i++)
	{
		cout << mantissa[i];
	}
	cout << endl;
	
	// 3ª etapa- coletar informacoes para criar a representacao binaria de 'num'
	// 3.1- ja obtemos o sinal
	// 3.2- obter o expoente no padrao IEEE e convertido para binario
	exp_norma= exp_norma + 127; // + 127 devido ao padrao IEEE 
	int i, j= 8; // 'j' inicia em 8 porque a insercao do numero binario e de tras para frente
	while(exp_norma!=0)
	{
		resto= exp_norma%2; // resto da divisao por 2, so pode ser 1 ou 0
		exp_norma= exp_norma/2; // divide por 2
		representacao[j]= resto; // guarda o resto na representacao
		j--;
	}
	cout << "\nExpoente no padrao IEEE e convertido para binario: ";
	for(i= 1; i<9; i++)
	{
		cout << representacao[i];
	}
	cout << endl;
	
	// 3.3- unir o sinal (feito), expoente em binario (feito) e mantissa num unico numero binario de 32 bits
	for(i= 9, j= 0; i<32; i++, j++) // 'i' comeca em 9 porque as posicoes 0 a 8 ja foram preenchidas
	{
		representacao[i]= mantissa[j];
	}
	
	// imprimir resultado
	cout << "\nRepresentacao binaria de ponto flutuante:\n";
	for(i= 0; i<32; i++)
	{
		cout << representacao[i];
	}
	cout << endl;
}

int main()
{
	char num[1024]; // vetor de tamanho super valorado
	int base, n, op1, op2;
	float numr;
	string numero;
	bool flag1= true, flag2= true;
	while(flag1)
	{
		flag1= true, flag2= true;
		op1= 0; op2= 0;
		cout << "\t\t\t\tEscolha a operacao:\n1- Conversao para qualquer base.\t\t2- Conversao da base 10 para 2.\n";
		cout << "\n3- Conversao da base 2 para 10.\t\t\t4- Conversao da base 10 para 8.\n";
		cout << "\n5- Conversao da base 8 para 10.\t\t\t6- Conversao da base 8 para 2.\n";
		cout << "\n7- Conversao da base 2 para 8.\t\t\t8- Conversao da base 10 para hexadecimal.\n";
		cout << "\n9- Conversao da base hexadecimal para 10.\t10- Conversao da base hexadecimal para 8.\n";
		cout << "\n11- Conversao da base 8 para hexadecimal.\t12- Conversao da base hexadecimal para 2.\n";
		cout << "\n14- Conversao da base 2 para hexadecimal.\t15- Representacao de Ponto Flutuante.\n";
		cout << "\n16- Sair do programa.\n";
		cout << "\nOpcao: ";
		cin >> op1;
		switch(op1)
		{
			case 1:
			{
				while(flag2)
				{				
					cout << "\nDigite o valor: ";
					cin >> num;
					cout << "Digite a base: ";
					cin >> base;
					conversao(num, base);
					cout << "\nDeseja realizar outra operacao? 1-SIM ou 2-NAO: ";
					cin >> op2;
					if(op2==2)
					{
						flag2= false;
					}										
				}
			 break;
			}
			case 2:
			{
				while(flag2)
				{				
					cout << "\nDigite o valor: ";
					cin >> n;
					cout << "\nNumero convertido da base 10 para base 2: ";
					base_10_para_2(n);	
					cout << "\nDeseja realizar outra operacao? 1-SIM ou 2-NAO: ";
					cin >> op2;
					if(op2==2)
					{
						flag2= false;
					}					
				}
				break;
			}
			case 3:
			{
				while(flag2)
				{				
					cout << "\nDigite o valor: ";
					cin >> num;
					cout << "\nNumero convertido da base 2 para base 10: " << base_2_para_10(num);
					cout << "\n\nDeseja realizar outra operacao? 1-SIM ou 2-NAO: ";
					cin >> op2;
					if(op2==2)
					{
						flag2= false;
					}					
				}
				break;
			}
			case 4:
			{
				while(flag2)
				{				
					cout << "\nDigite o valor: ";
					cin >> n;
					base_10_para_8(n);
					cout << "\nDeseja realizar outra operacao? 1-SIM ou 2-NAO: ";
					cin >> op2;
					if(op2==2)
					{
						flag2= false;
					}					
				}
				break;
			}
			case 5:
			{
				while(flag2)
				{				
					cout << "\nDigite o valor: ";
					cin >> numero;
					cout << "\nNumero convertido da base 8 para base 10= " << base_8_para_10(numero);
					cout << "\n\nDeseja realizar outra operacao? 1-SIM ou 2-NAO: ";
					cin >> op2;
					if(op2==2)
					{
						flag2= false;
					}					
				}
				break;
			}
			case 6:
			{
				while(flag2)
				{				
					cout << "\nDigite o valor: ";					
					cin >> numero;
					cout << "\nNumero convertido da base 8 para base 2= " << base_8_para_2(numero) << endl;
					cout << "\nDeseja realizar outra operacao? 1-SIM ou 2-NAO: ";
					cin >> op2;
					if(op2==2)
					{
						flag2= false;
					}					
				}
				break;
			}
			case 7:
			{
				while(flag2)
				{				
					cout << "\nDigite o valor: ";					
					cin >> numero;
					cout << "\nNumero convertido da base 8 para base 2= " << base_2_para_8(numero) << endl;
					cout << "\nDeseja realizar outra operacao? 1-SIM ou 2-NAO: ";
					cin >> op2;
					if(op2==2)
					{
						flag2= false;
					}					
				}
				break;
			}
			case 8:
			{
				while(flag2)
				{				
					cout << "\nDigite o valor: ";
					cin >> n;
					cout << "\nNumero convertido da base 10 para base hexadecimal: ";
					base_10_para_hexa(n);
					cout << "\nDeseja realizar outra operacao? 1-SIM ou 2-NAO: ";
					cin >> op2;
					if(op2==2)
					{
						flag2= false;
					}					
				}
				break;
			}
			case 9:
			{
				while(flag2)
				{				
					cout << "\nDigite o valor: ";
					cin >> num;
					cout << "\nNumero convertido da base hexadecimal para base 10= " << base_hexa_para_10(num) << endl;
					cout << "\nDeseja realizar outra operacao? 1-SIM ou 2-NAO: ";
					cin >> op2;
					if(op2==2)
					{
						flag2= false;
					}					
				}
				break;
			}
			case 10:
			{
				while(flag2)
				{				
					cout << "\nDigite o valor: ";					
					cin >> numero;
					base_hexa_para_8(numero);
					cout << "\nDeseja realizar outra operacao? 1-SIM ou 2-NAO: ";
					cin >> op2;
					if(op2==2)
					{
						flag2= false;
					}					
				}
				break;
			}
			case 11:
			{
				while(flag2)
				{				
					cout << "\nDigite o valor: ";					
					cin >> numero;
					base_8_para_hexa(numero);
					cout << "\nDeseja realizar outra operacao? 1-SIM ou 2-NAO: ";
					cin >> op2;
					if(op2==2)
					{
						flag2= false;
					}					
				}
				break;
			}
			case 12:
			{
				while(flag2)
				{				
					cout << "\nDigite o valor: ";
					cin >> num;
					cout << "\nNumero convertido da base hexadecimal para binario: "; 
					base_hexa_para_2(num);
					cout << "\nDeseja realizar outra operacao? 1-SIM ou 2-NAO: ";
					cin >> op2;
					if(op2==2)
					{
						flag2= false;
					}					
				}
				break;
			}
			case 13:
			{
				cout << "\nPelo amor de Deus, nao digite esse numero, da azar.\n";
				break;
			}
			case 14:
			{
				while(flag2)
				{				
					cout << "\nDigite o valor: ";
					cin >> num;
					cout << "\nNumero convertido da base binario para hexadecimal: "; 
					base_2_para_hexa(num);
					cout << "\nDeseja realizar outra operacao? 1-SIM ou 2-NAO: ";
					cin >> op2;
					if(op2==2)
					{
						flag2= false;
					}					
				}
				break;
			}
			case 15:
			{                                                                       
				while(flag2)
				{				
					cout << "\nDigite um numero racional positivo ou negativo: ";
					cin >> numr;																			
                                                                   
			    	Ponto_Flutuante_IEEE_754 (numr);
					
					cout << "\nDeseja realizar outra operacao? 1-SIM ou 2-NAO: ";
					cin >> op2;
					if(op2==2)
					{
						flag2= false;
					}					
				}
				break;
			}
			case 16:
			{
				flag1= false;
				break;
			}
		}		
		cout << endl;		
	}		
}

		
