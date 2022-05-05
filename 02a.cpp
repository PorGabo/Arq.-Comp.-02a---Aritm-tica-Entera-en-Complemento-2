//Gabriel Ivan Rodriguez Postigo
//operaciones al comienzo y al final Q y A con otros datos para complementar

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    cout<<"OPERACIONES SEGUN DIAGRAMA"<<endl<<endl;
    
    //cantidad de bits (cambiable)
    const int n_bits = 10;

	int A = 0; //                         <---------------   sera mi residuo
    int q = 100; //                       <---------------   dividendo (cambiable)
    //bitset<n_bits> binaryq (q);
    int Q = q; //                         <---------------   sera mi cociente
    int M = 6; //                         <---------------   divisor (cambiable)
    int count = n_bits;

	bitset<n_bits> binaryQ (Q);
	bitset<n_bits> binaryA (A);

	while(count > 0)
    {
		binaryA <<= 1; //desplazador

		binaryA[0] = binaryQ[n_bits-1];

		A = binaryA.to_ulong(); //binario a decimal
		
        cout<<"Shift left"<<endl;
		binaryQ <<= 1; //desplazador
        cout<<binaryQ<<endl<<endl;

		A = A - M;
        cout<<"A = A - M"<<endl<<"A = "<<A<<endl<<endl;
		
        cout<<"¿A<0?"<<endl;
		if (A >= 0)
        {
            cout<<"yes  Q0 = 1"<<endl<<endl;
			binaryQ[0] = 1; //Q0 = 1
		}
		else
        {
            cout<<"no  Q0 = 0   y   A = A + M       A = ";
            binaryQ[0] = 0; //Q0 = 0
			A = A + M;
            cout<<A<<endl<<endl;
		}
		
		bitset<n_bits> aaa(A);
		binaryA = aaa;
		count = count - 1;
        cout<<"count = count - 1            count = "<<count<<endl<<endl;
	}
	
	Q = binaryQ.to_ulong(); //binario a decimal

    cout<<endl<<"RESULTADOS"<<endl;

	cout<<endl<<"Gabriel Ivan Rodriguez Postigo"<<endl<<endl;

    cout<<"Dividiendo  "<< q <<" / "<< M <<endl;

	cout<<"Cociente:   "<< binaryQ <<"     "<< Q <<endl;
	cout<<"Residuo:    "<< binaryA <<"     "<< A <<endl<<endl;

    cout<<Q<<" x "<<M<<" + "<<A<<" = "<<q;

    return 0;
}