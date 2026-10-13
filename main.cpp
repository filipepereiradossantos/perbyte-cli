
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Tarefa
{
    string descricao;
    int prioridade;
};

int main()
{
    vector<Tarefa> tarefas;
    string novaTarefa;
    int prioridade, op;

    do
    {
        cout << "\n=== PERBYTE CLI ===" << endl;
        cout << "1. Adicionar tarefas a lista" << endl;
        cout << "2. Listar tarefas" << endl;
        cout << "3. Sair" << endl;

        cout << "\nEscolha uma opcao: ";
        cin >> op;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida! Digite uma opcao numerica.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (op)
        {
        case 1:
        {
            cout << "\nCadastro de tarefa selecionado" << endl;
            cout << "Digite a tarefa: ";
            getline(cin, novaTarefa);

            cout << "\n=== MENU DE PRIORIDADE ===" << endl;
            cout << "1. Alta" << endl;
            cout << "2. Media" << endl;
            cout << "3. Baixa" << endl;

            bool prioridadeValida = false;

            while (!prioridadeValida)
            {
                cout << "Escolha a prioridade: ";
                cin >> prioridade;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada invalida! Digite 1, 2 ou 3.\n";
                }
                else if (prioridade >= 1 && prioridade <= 3)
                {
                    prioridadeValida = true;
                }
                else
                {
                    cout << "Prioridade invalida! Digite 1, 2 ou 3.\n";
                }
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (prioridade)
            {
            case 1:
                cout << "Prioridade: Alta" << endl;
                break;

            case 2:
                cout << "Prioridade: Media" << endl;
                break;

            case 3:
                cout << "Prioridade: Baixa" << endl;
                break;
            }

            tarefas.push_back({novaTarefa, prioridade});
            cout << "Tarefa cadastrada com sucesso!" << endl;

            break;
        }

        case 2:
            if (tarefas.empty())
            {
                cout << "Nenhuma tarefa cadastrada." << endl;
            }
            else
            {
                int contador = 1;

                cout << "\n=== LISTA DE TAREFAS ===" << endl;

                for (const auto &item : tarefas)
                {
                    cout << contador << ". " << item.descricao;

                    if (item.prioridade == 1)
                    {
                        cout << " (Prioridade: Alta)" << endl;
                    }
                    else if (item.prioridade == 2)
                    {
                        cout << " (Prioridade: Media)" << endl;
                    }
                    else
                    {
                        cout << " (Prioridade: Baixa)" << endl;
                    }

                    contador++;
                }
            }
            break;

        case 3:
            cout << "Encerrando o PerByte..." << endl;
            break;

        default:
            cout << "Opcao invalida! Escolha de 1 a 3." << endl;
        }

    } while (op != 3);

    return 0;
}
