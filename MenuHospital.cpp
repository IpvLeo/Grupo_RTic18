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
    Paciente(string CPF, string Nome, string Nascimento);
    string getCPF() const;
    string getNome() const;
    string getNascimento() const;
    void setCPF(string CPF);
    void setNome(string Nome);
    void setNascimento(string Nascimento);
};

Paciente::Paciente(string CPF, string Nome, string Nascimento)
{
    this->CPF = CPF;
    this->Nome = Nome;
    this->Nascimento = Nascimento;
}

string Paciente::getCPF() const
{
    return CPF;
}

string Paciente::getNome() const
{
    return Nome;
}

string Paciente::getNascimento() const
{
    return Nascimento;
}

void Paciente::setCPF(string CPF)
{
    this->CPF = CPF;
}

void Paciente::setNome(string Nome)
{
    this->Nome = Nome;
}

void Paciente::setNascimento(string Nascimento)
{
    this->Nascimento = Nascimento;
}

class Medico
{
private:
    string CRM;
    string Nome;
    string Especialidade;

public:
    Medico(string CRM, string Nome, string Especialidade);
    string getCRM() const;
    string getNome() const;
    string getEspecialidade() const;
    void setCRM(string CRM);
    void setNome(string Nome);
    void setEspecialidade(string Especialidade);
};

Medico::Medico(string CRM, string Nome, string Especialidade)
{
    this->CRM = CRM;
    this->Nome = Nome;
    this->Especialidade = Especialidade;
}

string Medico::getCRM() const
{
    return CRM;
}

string Medico::getNome() const
{
    return Nome;
}

string Medico::getEspecialidade() const
{
    return Especialidade;
}

void Medico::setCRM(string CRM)
{
    this->CRM = CRM;
}

void Medico::setNome(string Nome)
{
    this->Nome = Nome;
}

void Medico::setEspecialidade(string Especialidade)
{
    this->Especialidade = Especialidade;
}

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
    Consulta(string CPF, string CRM, string data, string hora, int duracao);
    string getCPF() const;
    string getCRM() const;
    string getData() const;
    string getHora() const;
    int getDuracao() const;
    bool isRealizada() const;
    void marcarRealizada();
    void setData(string data);
    void setHora(string hora);
    void setDuracao(int duracao);
};

Consulta::Consulta(string CPF, string CRM, string data, string hora, int duracao)
{
    this->CPF = CPF;
    this->CRM = CRM;
    this->data = data;
    this->hora = hora;
    this->duracao = duracao;
    this->realizada = false;
}

string Consulta::getCPF() const
{
    return CPF;
}

string Consulta::getCRM() const
{
    return CRM;
}

string Consulta::getData() const
{
    return data;
}

string Consulta::getHora() const
{
    return hora;
}

int Consulta::getDuracao() const
{
    return duracao;
}

bool Consulta::isRealizada() const
{
    return realizada;
}

void Consulta::marcarRealizada()
{
    realizada = true;
}

void Consulta::setData(string data)
{
    this->data = data;
}

void Consulta::setHora(string hora)
{
    this->hora = hora;
}

void Consulta::setDuracao(int duracao)
{
    this->duracao = duracao;
}

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

    for (auto it = pacientes.begin(); it != pacientes.end();)
    {
        if (it->getCPF() == ExcluirCPF)
        {
            it = pacientes.erase(it);
            cout << "Paciente excluido com sucesso!" << endl;
        }
        else
        {
            ++it;
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

    for (auto it = medicos.begin(); it != medicos.end();)
    {
        if (it->getCRM() == ExcluirCRM)
        {
            it = medicos.erase(it);
            cout << "Medico excluido com sucesso!" << endl;
        }
        else
        {
            ++it;
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

// Função para incluir uma nova consulta
void IncluirConsulta(vector<Consulta> &consultas, const vector<Paciente> &pacientes, const vector<Medico> &medicos)
{
    string CPF, CRM, data, hora;
    int duracao;
    bool pacienteEncontrado = false, medicoEncontrado = false;

    cout << "CPF do Paciente: ";
    cin >> CPF;
    cout << "CRM do Médico: ";
    cin >> CRM;

    for (const Paciente &paciente : pacientes)
    {
        if (paciente.getCPF() == CPF)
        {
            pacienteEncontrado = true;
            break;
        }
    }

    for (const Medico &medico : medicos)
    {
        if (medico.getCRM() == CRM)
        {
            medicoEncontrado = true;
            break;
        }
    }

    if (!pacienteEncontrado)
    {
        cout << "CPF de paciente nao encontrado. Consulta nao pode ser marcada." << endl;
        return;
    }

    if (!medicoEncontrado)
    {
        cout << "CRM de medico nao encontrado. Consulta nao pode ser marcada." << endl;
        return;
    }

    cout << "Data da consulta (DD/MM/AAAA): ";
    cin >> data;
    cout << "Hora da consulta (HH:MM): ";
    cin >> hora;
    cout << "Duração da consulta (em minutos): ";
    cin >> duracao;

    Consulta novaConsulta(CPF, CRM, data, hora, duracao);
    consultas.push_back(novaConsulta);
    cout << "Consulta marcada com sucesso!" << endl;
}
// Função para excluir uma consulta
void ExcluirConsulta(vector<Consulta> &consultas, const string &CRM, const string &CPF)
{
    for (auto it = consultas.begin(); it != consultas.end(); ++it)
    {
        if (it->getCRM() == CRM && it->getCPF() == CPF)
        {
            consultas.erase(it);
            cout << "Consulta excluida com sucesso!" << endl;
            return;
        }
    }
    cout << "Consulta nao encontrada. Nenhum registro excluido." << endl;
}
// Função para alterar uma consulta
void AlterarConsulta(vector<Consulta> &consultas, const string &CRM, const string &CPF)
{
    string AlterarCRM, AlterarCPF;
    cout << "Digite o CRM do medico da consulta que deseja alterar: ";
    cin >> AlterarCRM;
    cout << "Digite o CPF do paciente da consulta que deseja alterar: ";
    cin >> AlterarCPF;

    for (auto &consulta : consultas)
    {
        if (consulta.getCRM() == AlterarCRM && consulta.getCPF() == AlterarCPF)
        {
            cout << "Dados atuais da consulta:" << endl;
            cout << "CRM do Médico: " << consulta.getCRM() << endl;
            cout << "CPF do Paciente: " << consulta.getCPF() << endl;
            cout << "Data da Consulta: " << consulta.getData() << endl;
            cout << "Hora da Consulta: " << consulta.getHora() << endl;
            cout << "Duração da Consulta: " << consulta.getDuracao() << " minutos" << endl;
            cout << "Realizada: " << (consulta.isRealizada() ? "Sim" : "Não") << endl;

            char opcao;
            cout << "Deseja marcar a consulta como realizada? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's')
            {
                consulta.marcarRealizada();
                cout << "Consulta marcada como realizada!" << endl;
            }
            else
            {
                cout << "Deseja alterar a data da consulta? (S/N): ";
                cin >> opcao;
                if (opcao == 'S' || opcao == 's')
                {
                    cout << "Informe a nova data da consulta (DD/MM/AAAA): ";
                    cin >> AlterarCRM;
                    consulta.setData(AlterarCRM);
                }

                cout << "Deseja alterar a hora da consulta? (S/N): ";
                cin >> opcao;
                if (opcao == 'S' || opcao == 's')
                {
                    cout << "Informe a nova hora da consulta (HH:MM): ";
                    cin >> AlterarCRM;
                    consulta.setHora(AlterarCRM);
                }

                cout << "Deseja alterar a duracao da consulta? (S/N): ";
                cin >> opcao;
                if (opcao == 'S' || opcao == 's')
                {
                    cout << "Informe a nova duracao da consulta (em minutos): ";
                    cin >> AlterarCPF;
                    consulta.setDuracao(stoi(AlterarCPF));
                }
            }
            return;
        }
    }

    cout << "Consulta nao encontrada." << endl;
}
// Função para listar todas as consultas
void ListarConsultas(const vector<Consulta> &consultas)
{
    if (consultas.empty())
    {
        cout << "Nenhuma consulta marcada." << endl;
        return;
    }

    cout << "Lista de consultas:" << endl;
    for (const Consulta &consulta : consultas)
    {
        cout << "CRM do Medico: " << consulta.getCRM() << endl;
        cout << "CPF do Paciente: " << consulta.getCPF() << endl;
        cout << "Data da Consulta: " << consulta.getData() << endl;
        cout << "Hora da Consulta: " << consulta.getHora() << endl;
        cout << "Duração da Consulta: " << consulta.getDuracao() << " minutos" << endl;
        cout << "Realizada: " << (consulta.isRealizada() ? "Sim" : "Nao") << endl;
        cout << "---------------------------" << endl;
    }
}

int main()
{
    vector<Paciente> pacientes;
    vector<Medico> medicos;
    vector<Consulta> consultas;

    int MenuInicial;

    do
    {
        cout << endl << "Menu Inicial:" << endl;
        cout << "1. Gestao de Pacientes" << endl;
        cout << "2. Gestao de Medicos" << endl;
        cout << "3. Gestao de Consultas" << endl;
        cout << "0. Sair do Programa" << endl;
        cout << "Escolha uma opcao: ";
        cin >> MenuInicial;

        switch (MenuInicial)
        {
            case 1:
                while (MenuInicial)
                {
                    // Menu de Gestão de Pacientes
                    int MenuInicialPacientes;

                    cout << "\nMENU DE PACIENTES\n";
                    cout << "1. Incluir Paciente\n";
                    cout << "2. Excluir Paciente\n";
                    cout << "3. Alterar Paciente\n";
                    cout << "4. Listar Pacientes\n";
                    cout << "5. Localizar Paciente\n";
                    cout << "0. Sair\n";
                    cout << "Escolha a opcao: ";
                    cin >> MenuInicialPacientes;

                    if (MenuInicialPacientes == 0)
                    {
                        break;
                    }
                    else if (MenuInicialPacientes == 1)
                    {
                        IncluirPaciente(pacientes);
                    }
                    else if (MenuInicialPacientes == 2)
                    {
                        ExcluirPaciente(pacientes);
                    }
                    else if (MenuInicialPacientes == 3)
                    {
                        AlterarPaciente(pacientes);
                    }
                    else if (MenuInicialPacientes == 4)
                    {
                        ListarPaciente(pacientes);
                    }
                    else if (MenuInicialPacientes == 5)
                    {
                        LocalizarPaciente(pacientes);
                    }
                    else
                    {
                        cout << "Opcao invalida. Tente novamente." << endl;
                    }
                }
                break;
            case 2:
                // Menu de Gestão de Médicos
                int MenuInicialMedicos;
                do
                {
                    cout << endl << "Menu de Gestao de Medicos:" << endl;
                    cout << "1. Incluir Medico" << endl;
                    cout << "2. Excluir Medico" << endl;
                    cout << "3. Alterar Medico (Apenas por CRM)" << endl;
                    cout << "4. Listar Medicos" << endl;
                    cout << "5. Localizar Medico (Apenas por CRM)" << endl;
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opcao: ";
                    cin >> MenuInicialMedicos;

                    switch (MenuInicialMedicos)
                    {
                        case 1:
                            IncluirMedico(medicos);
                            break;
                        case 2:
                            ExcluirMedico(medicos);
                            break;
                        case 3:
                            AlterarMedico(medicos);
                            break;
                        case 4:
                            ListarMedico(medicos);
                            break;
                        case 5:
                            LocalizarMedico(medicos);
                            break;
                        case 0:
                            cout << "Voltando ao Menu Inicial." << endl;
                            break;
                        default:
                            cout << "Opcao invalida." << endl;
                    }
                } while (MenuInicialMedicos != 0);
                break;
            case 3:
                
    } while (MenuInicial != 0);

    return 0;
}
