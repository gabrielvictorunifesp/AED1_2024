/* Enunciado:
O Professor solicitou que você escreva um programa que converta uma expressão na forma infixa (como usualmente conhecemos) para uma expressão na forma posfixa. 
Como você sabe, os termos in (no meio) e pos (depois) se referem à posição dos operadores. 
O programa terá que lidar somente com operadores binários +,-,*,/,^, parênteses, letras e números. 
Um exemplo seria uma expressão como:
(A*B+2*C^3)/2*A. O programa deve converter esta expressão (infixa) para a expressão posfixa: AB*2C3^*+2/A*
*/

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    bool p, f, fp;
    queue<int> fila;
    stack<int> pilha;
    int n, operacao, numero;
    priority_queue<int> filaPrioridade;

    while (cin >> n)
    {
        while (!pilha.empty())
            pilha.pop();
        while (!fila.empty())
            fila.pop();
        while (!filaPrioridade.empty())
            filaPrioridade.pop();

        p = true, f = true, fp = true;
        for (int i = 0; i < n; ++i)
        {
            cin >> operacao >> numero;

            if (operacao == 1)
            {
                if (p)
                    pilha.push(numero);
                if (f)
                    fila.push(numero);
                if (fp)
                    filaPrioridade.push(numero);
            }
            else
            {
                if (p)
                {
                    if (pilha.empty() || pilha.top() != numero)
                        p = false;
                    else
                        pilha.pop();
                }

                if (f)
                {
                    if (fila.empty() || fila.front() != numero)
                        f = false;
                    else
                        fila.pop();
                }

                if (fp)
                {
                    if (filaPrioridade.empty() || filaPrioridade.top() != numero)
                        fp = false;
                    else
                        filaPrioridade.pop();
                }
            }
        }

        if (p && !f && !fp)
            cout << "stack" << endl;
        else if (!p && f && !fp)
            cout << "queue" << endl;
        else if (!p && !f && fp)
            cout << "priority queue" << endl;
        else if (!p && !f && !fp)
            cout << "impossible" << endl;
        else
            cout << "not sure" << endl;
    }

    return 0;
}