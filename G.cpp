

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Paciente
{
private:
    string CPF;
    string Nome;
    string Nascimento;

public:
    Paciente(const string &CPF, const string &Nome, const string &Nascimento)
    {
        this->CPF = CPF;
        this->Nome = Nome;
        this->Nascimento = Nascimento;
    }

    string getCPF() const
    {
        return CPF;
    }

    string getNome() const
    {
        return Nome;
    }

    string getNascimento() const
    {
        return Nascimento;
    }

    void setCPF(const string &CPF)
    {
        this->CPF = CPF;
    }

    void setNome(const string &Nome)
    {
        this->Nome = Nome;
    }

    void setNascimento(const string &Nascimento)
    {
        this->Nascimento = Nascimento;
    }
};
class Medico
{
private:
    string CRM;
    string Nome;
    string Especialidade;

public:
    Medico(const string &CRM, const string &Nome, const string &Especialidade)
    {
        this->CRM = CRM;
        this->Nome = Nome;
        this->Especialidade = Especialidade;
    }

    string getCRM() const
    {
        return CRM;
    }

    string getNome() const
    {
        return Nome;
    }

    string getEspecialidade() const
    {
        return Especialidade;
    }

    void Medico::setCRM(const string &CRM)
    {
        this->CRM = CRM;
    }

    void Medico::setNome(const string &Nome)
    {
        this->Nome = Nome;
    }

    void setEspecialidade(const string &Especialidade)
    {
        this->Especialidade = Especialidade;
    }
};
class Consulta
{
private:
    string CPF;
    string CRM;
    string data;
    string hora;
    int duracao;
    bool realizada;

public:
    Consulta(const string &CPF, const string &CRM, const string &data, const string &hora, const int &duracao, const bool realizada)
    {

        this->CPF = CPF;
        this->CRM = CRM;
        this->data = data;
        this->hora = hora;
        this->duracao = duracao;
        this->realizada = false;
    }

    string getCPF() const
    {
        return CPF;
    }

    string getCRM() const
    {
        return CRM;
    }

    string getData() const
    {
        return data;
    }

    string getHora() const
    {
        return hora;
    }

    int getDuracao() const
    {
        return duracao;
    }

    bool isRealizada() const
    {
        return realizada;
    }

    void marcarRealizada()
    {
        realizada = true;
    }

    void setData(const string& data)
    {
        this->data = data;
    }

    void setHora(const string& hora)
    {
        this->hora = hora;
    }

    void setDuracao(const int& duracao)
    {
        this->duracao = duracao;
    }
};
// Função para incluir um novo paciente
void IncluirPaciente(vector<Paciente> &pacientes)
{
    string CPF, Nome, Nascimento;
    cout << "CPF: ";
    cin >> CPF;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, Nome);
    cout << "Data de Nascimento: ";
    cin >> Nascimento;

    Paciente novoPaciente(CPF, Nome, Nascimento);
    pacientes.push_back(novoPaciente);
    cout << "Paciente incluido com sucesso!" << endl;
}
// Função para excluir um paciente
void ExcluirPaciente(vector<Paciente> &pacientes)
{
    string ExcluirCPF;
    cout << "Digite o CPF do Paciente que deseja excluir: ";
    cin >> ExcluirCPF;

    for (auto it = pacientes.begin(); it != pacientes.end(); ++it)
    {
        if (it->getCPF() == ExcluirCPF)
        {
            pacientes.erase(it);
            cout << "Paciente excluido com sucesso!" << endl;
            return;
        }
    }

    cout << "CPF nao encontrado. Nenhum paciente excluido." << endl;
}
// Função para alterar dados do paciente
void AlterarPaciente(vector<Paciente> &pacientes)
{
    string AlterarCPF;
    cout << "Digite o CPF do paciente que deseja alterar: ";
    cin >> AlterarCPF;

    for (auto &paciente : pacientes)
    {
        if (paciente.getCPF() == AlterarCPF)
        {
            cout << "Dados atuais do paciente:" << endl;
            cout << "CPF: " << paciente.getCPF() << endl;
            cout << "Nome: " << paciente.getNome() << endl;
            cout << "Data de Nascimento: " << paciente.getNascimento() << endl;

            char opcao;
            cout << "Deseja alterar o nome do paciente? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's')
            {
                cout << "Informe o novo nome: ";
                cin.ignore();
                string Nome;
                getline(cin, Nome);
                paciente.setNome(Nome);
            }

            cout << "Deseja alterar a data de nascimento do paciente? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's')
            {
                cout << "Informe a nova data de nascimento: ";
                string Nascimento;
                cin >> Nascimento;
                paciente.setNascimento(Nascimento);
            }

            cout << "Paciente alterado com sucesso!" << endl;
            return;
        }
    }

    cout << "CPF nao encontrado." << endl;
}
// Função para listar todos os pacientes
void ListarPaciente(const vector<Paciente> &pacientes)
{
    if (pacientes.empty())
    {
        cout << "Nenhum paciente cadastrado." << endl;
        return;
    }

    cout << "Lista de pacientes:" << endl;
    for (const Paciente &paciente : pacientes)
    {
        cout << "CPF: " << paciente.getCPF() << endl;
        cout << "Nome: " << paciente.getNome() << endl;
        cout << "Data de Nascimento: " << paciente.getNascimento() << endl;
        cout << "---------------------------" << endl;
    }
}
// Função para localizar um paciente
void LocalizarPaciente(const vector<Paciente> &pacientes)
{
    string LocalizarCPF;
    cout << "Digite o CPF do paciente que deseja localizar: ";
    cin >> LocalizarCPF;

    for (const Paciente &paciente : pacientes)
    {
        if (paciente.getCPF() == LocalizarCPF)
        {
            cout << "CPF: " << paciente.getCPF() << endl;
            cout << "Nome: " << paciente.getNome() << endl;
            cout << "Data de Nascimento: " << paciente.getNascimento() << endl;
            return;
        }
    }

    cout << "CPF nao encontrado." << endl;
}
// Função para incluir um novo medico
void IncluirMedico(vector<Medico> &medicos)
{
    string CRM, Nome, Especialidade;
    cout << "CRM: ";
    cin >> CRM;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, Nome);
    cout << "Especialidade: ";
    cin >> Especialidade;

    Medico novoMedico(CRM, Nome, Especialidade);
    medicos.push_back(novoMedico);
    cout << "Medico incluido com sucesso!" << endl;
}
// Função para excluir um medico
void ExcluirMedico(vector<Medico> &medicos)
{
    string ExcluirCRM;
    cout << "Digite o CRM do Medico que deseja excluir: ";
    cin >> ExcluirCRM;

    for (auto it = medicos.begin(); it != medicos.end(); ++it)
    {
        if (it->getCRM() == ExcluirCRM)
        {
            medicos.erase(it);
            cout << "Medico excluido com sucesso!" << endl;
            return;
        }
    }

    cout << "CRM nao encontrado. Nenhum medico excluído." << endl;
}
// Função para alterar dados de um medico
void AlterarMedico(vector<Medico> &medicos)
{
    string AlterarCRM;
    cout << "Digite o CRM do medico que deseja alterar: ";
    cin >> AlterarCRM;

    for (auto &medico : medicos)
    {
        if (medico.getCRM() == AlterarCRM)
        {
            cout << "Dados atuais do medico:" << endl;
            cout << "CRM: " << medico.getCRM() << endl;
            cout << "Nome: " << medico.getNome() << endl;
            cout << "Especialidade: " << medico.getEspecialidade() << endl;

            char opcao;
            cout << "Deseja alterar o nome do medico? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's')
            {
                cout << "Informe o novo nome: ";
                cin.ignore();
                string Nome;
                getline(cin, Nome);
                medico.setNome(Nome);
            }

            cout << "Deseja alterar a especialidade do medico? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's')
            {
                cout << "Informe a nova Especialidade: ";
                cin.ignore();
                string Especialidade;
                getline(cin, Especialidade);
                medico.setEspecialidade(Especialidade);
            }

            cout << "Medico alterado com sucesso!" << endl;
            return;
        }
    }

    cout << "CRM nao encontrado." << endl;
}
// Função para listar todos os medicos
void ListarMedico(const vector<Medico> &medicos)
{
    if (medicos.empty())
    {
        cout << "Nenhum medico cadastrado." << endl;
        return;
    }

    cout << "Lista de medicos:" << endl;
    for (const Medico &medico : medicos)
    {
        cout << "CRM: " << medico.getCRM() << endl;
        cout << "Nome: " << medico.getNome() << endl;
        cout << "Especialidade: " << medico.getEspecialidade() << endl;
        cout << "---------------------------" << endl;
    }
}
// Função para localizar um medico
void LocalizarMedico(const vector<Medico> &medicos)
{
    string LocalizarCRM;
    cout << "Digite o CRM do medico que deseja localizar: ";
    cin >> LocalizarCRM;

    for (const Medico &medico : medicos)
    {
        if (medico.getCRM() == LocalizarCRM)
        {
            cout << "CRM: " << medico.getCRM() << endl;
            cout << "Nome: " << medico.getNome() << endl;
            cout << "Especialidade: " << medico.getEspecialidade() << endl;
            return;
        }
    }

    cout << "CRM nao encontrado." << endl;
}

/* Inicio da parte em Grupo

Função para incluir uma nova consulta
Função para excluir uma consulta
Função para alterar uma consulta
Função para listar todas as consultas*/

int main()
{
   
   
}