#include <functional>
#include <utility>
#include <vector>

class Registrar
{
public:
    typedef std::function<void()> ExampleFunction;

    void RegisterFunction(const std::string& name, ExampleFunction fnc)
    {
        m_Examples.push_back(std::make_pair(name, fnc));
    }

    std::string GetName(unsigned int index) const
    {
        return m_Examples[index].first;
    }

    void Invoke(unsigned int index) const
    {
        m_Examples[index].second();
    }
    
    size_t Size() const
    {
        return m_Examples.size();
    }

protected:
    typedef std::pair<std::string, ExampleFunction> NameAndFunctionPair;
    std::vector<NameAndFunctionPair> m_Examples;
};